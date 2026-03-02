module;

#include <string>
#include <variant>
#include <vector>
#include <memory>
#include <iostream>
#include <assert.h>

export module ast;

export namespace ParaCL::front::AST
{

template <typename ReturnT, typename NodeT, typename... Args>
ReturnT visit(const NodeT& node, Args&&... args);




// Type-Erased class + Visitor pattern
// Required for storing classes of absolutely different types
// Read about it here https://habr.com/ru/articles/706450/?ysclid=mlzkvs6r2x343771650
class UniversalNode
{
    class INode
    {
    public:

        virtual ~INode() = default;
        virtual std::unique_ptr<INode> clone() const = 0;
        virtual const std::type_info& type() const = 0;
    };

    template<typename RetT, typename... Args>
    class IVisitable
    {
    public:

        virtual ~IVisitable() = default;
        virtual RetT visit(Args... args) const = 0;
    };


    template<typename NodeT, typename RetT, typename... Args>
    class Node final : public INode, public IVisitable<RetT, Args...>
    {
    public:
        
        NodeT data_;

        Node(NodeT nodeObj) : data_(std::move(nodeObj)) {}
        
        std::unique_ptr<INode> clone() const override
        {
            return std::unique_ptr<INode>(
                new Node<NodeT, RetT, Args...>(data_)
            );
        }

        const std::type_info& type() const override
        {
            return typeid(NodeT);
        }

        RetT visit(Args... args) const override
        {
            return ::ParaCL::front::AST::visit<RetT, NodeT>(data_, std::forward<Args>(args)...);
        }
    };

    std::unique_ptr<INode> pimpl_;

public:
    UniversalNode() = default;
    
    template<typename NodeT, typename RetT = void, typename... Args>
    explicit UniversalNode(NodeT node)
        : pimpl_(new Node<NodeT, RetT, Args...>(std::move(node))) {}

    template<typename NodeT, typename RetT, typename... Args>
    static UniversalNode create(NodeT&& node)
    {
        UniversalNode an;

        an.pimpl_ = std::make_unique<Node<std::decay_t<NodeT>, RetT, Args...>>(
            std::forward<NodeT>(node)
        );

        return an;
    }
    
    UniversalNode(const UniversalNode& other)
        : pimpl_(other.pimpl_ ? other.pimpl_->clone() : nullptr) {}
    
    UniversalNode(UniversalNode&&) = default;
    
    UniversalNode& operator=(const UniversalNode& other)
    {
        if (this != &other && other.pimpl_)
            pimpl_ = other.pimpl_->clone();
        return *this;
    }
    
    UniversalNode& operator=(UniversalNode&&) = default;
    
    template<typename RetT, typename... Args>
    RetT visit(Args... args) const
    {
        if (!pimpl_) throw std::runtime_error("Empty node");
        
        using Visitable = IVisitable<RetT, Args...>;
        auto* visitable = dynamic_cast<const Visitable*>(pimpl_.get());
        
        if (!visitable)
            throw std::runtime_error(std::string("This node doesn't support visit with these arguments: ") + pimpl_->type().name());
        
        return visitable->visit(std::forward<Args>(args)...);
    }
    
    explicit operator bool() const noexcept { return static_cast<bool>(pimpl_); }
};


class NumberLiteral final
{
private:
    int value_;
public:
    explicit NumberLiteral(int value) : value_(value) {}
    
    int value() const noexcept { return value_; }
};


template<typename T>
concept ConvToStrView = std::convertible_to<T, std::string_view>;

class StringLiteral final
{
private:
    std::string value_;

public:

    template <ConvToStrView T>
    explicit StringLiteral(T&& value) : value_(value) {}
    
    std::string_view value() const & noexcept { return value_; }
};


class Variable final
{
private:
    std::string name_;
public:
    template <ConvToStrView T>
    Variable(T&& name) : name_(std::forward<T>(name)) {}
    
    std::string_view name() const & noexcept { return name_; }
};


class Scan final
{
public:
    Scan() = default;
};


class Print final
{
private:
    std::vector<UniversalNode> args_;
public:
    Print() = default;
    Print(std::vector<UniversalNode>&& args) : args_(std::move(args)) {}
    
    void addArg(UniversalNode&& arg) { args_.push_back(std::move(arg)); }
    
    const std::vector<UniversalNode>& args() const { return args_; }
};


class UnaryOperator final
{
public:
    enum class UnaryOperatorT
    {
        MINUS,
        PLUS,
        NOT
    };

private:
    UnaryOperatorT type_;
    UniversalNode arg_;

public:
    UnaryOperator(UnaryOperatorT type, UniversalNode&& arg)
        : type_(type), arg_(std::move(arg)) {}
    
    UnaryOperatorT type() const noexcept { return type_; }
    const UniversalNode& arg() const & noexcept { return arg_; }
};


class BinaryOperator final
{
public:
    enum class BinaryOperatorT
    {
        AND,        // &&
        OR,         // ||
        ADD,        // +
        SUB,        // -
        MUL,        // *
        DIV,        // /
        REM,        // %
        ISAB,       // >
        ISABE,      // >=
        ISLS,       // <
        ISLSE,      // <=
        ISEQ,       // ==
        ISNE,       // !=
        ASGN,       // =
        ADDASGN,    // +=
        SUBASGN,    // -=
        MULASGN,    // *=
        DIVASGN,    // /=
        REMASGN,    // %=
    };

private:
    BinaryOperatorT type_;
    UniversalNode larg_;
    UniversalNode rarg_;

public:
    BinaryOperator(BinaryOperatorT type, UniversalNode&& larg, UniversalNode&& rarg)
        : type_(type), larg_(std::move(larg)), rarg_(std::move(rarg)) {}
    
    BinaryOperatorT type() const noexcept { return type_; }
    const UniversalNode& larg() const & noexcept { return larg_; }
    const UniversalNode& rarg() const & noexcept { return rarg_; }
};


class ConditionWithBody
{
private:
    UniversalNode condition_;
    UniversalNode body_;

public:
    ConditionWithBody() = default;
    ConditionWithBody(UniversalNode&& condition, UniversalNode&& body)
        : condition_(std::move(condition)), body_(std::move(body)) {}
    
public:
    const UniversalNode& condition() const & noexcept { return condition_; }
    const UniversalNode& body() const & noexcept { return body_; }
};


class While final : public ConditionWithBody
{
public:
    using ConditionWithBody::ConditionWithBody;
};


class If final : public ConditionWithBody
{
public:
    using ConditionWithBody::ConditionWithBody;
};


class Else final
{
private:
    UniversalNode body_;

public:
    Else() = default;
    explicit Else(UniversalNode&& body) : body_(std::move(body)) {}
    
    const UniversalNode& body() const & noexcept { return body_; }
};


class Condition final
{
private:
    std::vector<UniversalNode> ifs_;
    UniversalNode else_;

public:
    Condition() = default;
    Condition(std::vector<UniversalNode>&& ifs, UniversalNode&& elseNode)
        : ifs_(std::move(ifs)), else_(std::move(elseNode)) {}
    
    void addIf(UniversalNode&& ifNode)
    {
        ifs_.push_back(std::move(ifNode));
    }
    
    void setElse(UniversalNode&& elseNode)
    {
        else_ = std::move(elseNode);
    }
    
    const std::vector<UniversalNode>& getIfs() const & noexcept { return ifs_; }
    const UniversalNode& getElse() const & noexcept { return else_; }
    
    bool hasElse() const { return static_cast<bool>(else_); }
};


class Scope final
{
private:
    std::vector<UniversalNode> statements_;

public:
    Scope() = default;
    explicit Scope(size_t size) : statements_(size) {}
    explicit Scope(UniversalNode&& node)
    {
        statements_.push_back(std::move(node));
    }
    explicit Scope(std::vector<UniversalNode>&& nodes) : statements_(std::move(nodes)) {}
    
    void addStatement(UniversalNode&& stmt)
    {
        statements_.push_back(std::move(stmt));
    }
    
    const std::vector<UniversalNode>& statements() const { return statements_; }
    
    auto begin() const { return statements_.begin(); }
    auto end() const { return statements_.end(); }
    size_t size() const { return statements_.size(); }
};


class ProgramAST final
{
private:
    std::vector<UniversalNode> statements_;

public:
    ProgramAST() = default;
    explicit ProgramAST(std::vector<UniversalNode>&& stmts) : statements_(std::move(stmts)) {}
    
    void addStatement(UniversalNode&& stmt)
    {
        statements_.push_back(std::move(stmt));
    }
    
    const std::vector<UniversalNode>& getStatements() const { return statements_; }
};

template<typename T, typename RetT, typename... Args>
UniversalNode make_node(Args&&... args)
{
    return UniversalNode::create<T, RetT>(T(std::forward<Args>(args)...));
}




































// json writer







































// json reader

// will be later




































// Max writer




} // namespace ParaCL::front::AST