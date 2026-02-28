// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hpp"


// Unqualified %code blocks.
#line 24 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"

#include "parse_error.hpp"

#include "lexer.hpp"
#include "check_variables.hpp"

ParaCL::front::AST::ProgramAST program;
ParaCL::ParserNameTable name_table;

int yylex(yy::parser::semantic_type* yylval, yy::parser::location_type* yylloc);

#line 58 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 6 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
namespace yy {
#line 151 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_combined_assignment: // combined_assignment
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_while_statement: // while_statement
      case symbol_kind::S_condition_statement: // condition_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_else_statement: // else_statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_one_stmt_scope: // one_stmt_scope
      case symbol_kind::S_string_constant: // string_constant
        value.copy< ParaCL::front::AST::AnonNode > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_print_args: // print_args
      case symbol_kind::S_elif_statements: // elif_statements
        value.copy< std::vector<ParaCL::front::AST::AnonNode> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_combined_assignment: // combined_assignment
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_while_statement: // while_statement
      case symbol_kind::S_condition_statement: // condition_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_else_statement: // else_statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_one_stmt_scope: // one_stmt_scope
      case symbol_kind::S_string_constant: // string_constant
        value.move< ParaCL::front::AST::AnonNode > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_print_args: // print_args
      case symbol_kind::S_elif_statements: // elif_statements
        value.move< std::vector<ParaCL::front::AST::AnonNode> > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_combined_assignment: // combined_assignment
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_while_statement: // while_statement
      case symbol_kind::S_condition_statement: // condition_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_else_statement: // else_statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_one_stmt_scope: // one_stmt_scope
      case symbol_kind::S_string_constant: // string_constant
        value.YY_MOVE_OR_COPY< ParaCL::front::AST::AnonNode > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_STRING: // STRING
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_print_args: // print_args
      case symbol_kind::S_elif_statements: // elif_statements
        value.YY_MOVE_OR_COPY< std::vector<ParaCL::front::AST::AnonNode> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_combined_assignment: // combined_assignment
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_while_statement: // while_statement
      case symbol_kind::S_condition_statement: // condition_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_else_statement: // else_statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_one_stmt_scope: // one_stmt_scope
      case symbol_kind::S_string_constant: // string_constant
        value.move< ParaCL::front::AST::AnonNode > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUM: // NUM
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_print_args: // print_args
      case symbol_kind::S_elif_statements: // elif_statements
        value.move< std::vector<ParaCL::front::AST::AnonNode> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_combined_assignment: // combined_assignment
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_while_statement: // while_statement
      case symbol_kind::S_condition_statement: // condition_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_else_statement: // else_statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_one_stmt_scope: // one_stmt_scope
      case symbol_kind::S_string_constant: // string_constant
        value.copy< ParaCL::front::AST::AnonNode > (that.value);
        break;

      case symbol_kind::S_NUM: // NUM
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_STRING: // STRING
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_print_args: // print_args
      case symbol_kind::S_elif_statements: // elif_statements
        value.copy< std::vector<ParaCL::front::AST::AnonNode> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_combined_assignment: // combined_assignment
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_while_statement: // while_statement
      case symbol_kind::S_condition_statement: // condition_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_else_statement: // else_statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_one_stmt_scope: // one_stmt_scope
      case symbol_kind::S_string_constant: // string_constant
        value.move< ParaCL::front::AST::AnonNode > (that.value);
        break;

      case symbol_kind::S_NUM: // NUM
        value.move< int > (that.value);
        break;

      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_STRING: // STRING
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_print_args: // print_args
      case symbol_kind::S_elif_statements: // elif_statements
        value.move< std::vector<ParaCL::front::AST::AnonNode> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_combined_assignment: // combined_assignment
      case symbol_kind::S_print_statement: // print_statement
      case symbol_kind::S_while_statement: // while_statement
      case symbol_kind::S_condition_statement: // condition_statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_else_statement: // else_statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_assignment_expression: // assignment_expression
      case symbol_kind::S_logical_or_expression: // logical_or_expression
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_scope: // scope
      case symbol_kind::S_one_stmt_scope: // one_stmt_scope
      case symbol_kind::S_string_constant: // string_constant
        yylhs.value.emplace< ParaCL::front::AST::AnonNode > ();
        break;

      case symbol_kind::S_NUM: // NUM
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_VAR: // VAR
      case symbol_kind::S_STRING: // STRING
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_statements: // statements
      case symbol_kind::S_print_args: // print_args
      case symbol_kind::S_elif_statements: // elif_statements
        yylhs.value.emplace< std::vector<ParaCL::front::AST::AnonNode> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: create_global_scope statements leave_global_scope
#line 66 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                      {
        program = ParaCL::front::AST::ProgramAST(std::move(yystack_[1].value.as < std::vector<ParaCL::front::AST::AnonNode> > ()));
    }
#line 914 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 3: // create_global_scope: %empty
#line 72 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
           { name_table.new_scope(); }
#line 920 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 4: // leave_global_scope: %empty
#line 76 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
           { name_table.leave_scope(); }
#line 926 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 5: // statements: %empty
#line 80 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
           { yylhs.value.as < std::vector<ParaCL::front::AST::AnonNode> > () = std::vector<ParaCL::front::AST::AnonNode>(); }
#line 932 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 6: // statements: statements statement
#line 81 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                           {
        yystack_[1].value.as < std::vector<ParaCL::front::AST::AnonNode> > ().push_back(std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()));
        yylhs.value.as < std::vector<ParaCL::front::AST::AnonNode> > () = std::move(yystack_[1].value.as < std::vector<ParaCL::front::AST::AnonNode> > ());
    }
#line 941 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 7: // statements: statements LCUB scope RCUB
#line 85 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                 {
        yystack_[3].value.as < std::vector<ParaCL::front::AST::AnonNode> > ().push_back(std::move(yystack_[1].value.as < ParaCL::front::AST::AnonNode > ()));
        yylhs.value.as < std::vector<ParaCL::front::AST::AnonNode> > () = std::move(yystack_[3].value.as < std::vector<ParaCL::front::AST::AnonNode> > ());
    }
#line 950 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 8: // statement: assignment SC
#line 92 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                           { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[1].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 956 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 9: // statement: combined_assignment SC
#line 93 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                             { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[1].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 962 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 10: // statement: print_statement SC
#line 94 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                           { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[1].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 968 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 11: // statement: while_statement
#line 95 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                           { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 974 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 12: // statement: condition_statement
#line 96 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                           { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 980 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 13: // statement: SC
#line 97 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                           { yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::Scope>(); }
#line 986 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 14: // assignment: VAR AS expression
#line 101 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                      {
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::ASGN,
            ParaCL::front::AST::make_node<ParaCL::front::AST::Variable>(yystack_[2].value.as < std::string > ()),
            std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
        name_table.declare_or_do_nothing_if_already_declared(yystack_[2].value.as < std::string > ());
    }
#line 1000 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 15: // assignment: VAR AS error
#line 110 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                   {
        std::cerr << "paracl: parser: assignment -> VAR AS error\n";
        ErrorHandler::throwError(yystack_[0].location, "expected expression after assignment");
        YYABORT;
    }
#line 1010 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 16: // combined_assignment: VAR ADDASGN expression
#line 118 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                           {
        if (name_table.is_not_declare(yystack_[2].value.as < std::string > ())) {
            std::cerr << "using undeclared variable: " << yystack_[2].value.as < std::string > () << "\n";
            ErrorHandler::throwError(yystack_[2].location, "using undeclared variable: " + yystack_[2].value.as < std::string > ());
            YYABORT;
        }
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::ADDASGN,
            ParaCL::front::AST::make_node<ParaCL::front::AST::Variable>(yystack_[2].value.as < std::string > ()),
            std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1028 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 17: // combined_assignment: VAR SUBASGN expression
#line 131 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                             {
        if (name_table.is_not_declare(yystack_[2].value.as < std::string > ())) {
            std::cerr << "using undeclared variable: " << yystack_[2].value.as < std::string > () << "\n";
            ErrorHandler::throwError(yystack_[2].location, "using undeclared variable: " + yystack_[2].value.as < std::string > ());
            YYABORT;
        }
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::SUBASGN,
            ParaCL::front::AST::make_node<ParaCL::front::AST::Variable>(yystack_[2].value.as < std::string > ()),
            std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1046 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 18: // combined_assignment: VAR MULASGN expression
#line 144 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                             {
        if (name_table.is_not_declare(yystack_[2].value.as < std::string > ())) {
            std::cerr << "using undeclared variable: " << yystack_[2].value.as < std::string > () << "\n";
            ErrorHandler::throwError(yystack_[2].location, "using undeclared variable: " + yystack_[2].value.as < std::string > ());
            YYABORT;
        }
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::MULASGN,
            ParaCL::front::AST::make_node<ParaCL::front::AST::Variable>(yystack_[2].value.as < std::string > ()),
            std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1064 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 19: // combined_assignment: VAR DIVASGN expression
#line 157 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                             {
        if (name_table.is_not_declare(yystack_[2].value.as < std::string > ())) {
            std::cerr << "using undeclared variable: " << yystack_[2].value.as < std::string > () << "\n";
            ErrorHandler::throwError(yystack_[2].location, "using undeclared variable: " + yystack_[2].value.as < std::string > ());
            YYABORT;
        }
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::DIVASGN,
            ParaCL::front::AST::make_node<ParaCL::front::AST::Variable>(yystack_[2].value.as < std::string > ()),
            std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1082 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 20: // combined_assignment: VAR ADDASGN error
#line 171 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                        { ErrorHandler::throwError(yystack_[0].location, "expected expression after '+='"); YYABORT; }
#line 1088 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 21: // combined_assignment: VAR SUBASGN error
#line 172 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                        { ErrorHandler::throwError(yystack_[0].location, "expected expression after '-='"); YYABORT; }
#line 1094 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 22: // combined_assignment: VAR MULASGN error
#line 173 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                        { ErrorHandler::throwError(yystack_[0].location, "expected expression after '*='"); YYABORT; }
#line 1100 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 23: // combined_assignment: VAR DIVASGN error
#line 174 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                        { ErrorHandler::throwError(yystack_[0].location, "expected expression after '/='"); YYABORT; }
#line 1106 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 24: // print_statement: PRINT print_args
#line 178 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                     {
        auto p = ParaCL::front::AST::Print(std::move(yystack_[0].value.as < std::vector<ParaCL::front::AST::AnonNode> > ()));
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::Print>(std::move(p));
    }
#line 1115 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 25: // print_statement: PRINT error
#line 182 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                  {
        ErrorHandler::throwError(yystack_[0].location, "expected expressions after print");
        YYABORT;
    }
#line 1124 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 26: // print_args: %empty
#line 189 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
           { yylhs.value.as < std::vector<ParaCL::front::AST::AnonNode> > () = std::vector<ParaCL::front::AST::AnonNode>(); }
#line 1130 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 27: // print_args: print_args expression
#line 190 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                          { yystack_[1].value.as < std::vector<ParaCL::front::AST::AnonNode> > ().push_back(std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())); yylhs.value.as < std::vector<ParaCL::front::AST::AnonNode> > () = std::move(yystack_[1].value.as < std::vector<ParaCL::front::AST::AnonNode> > ()); }
#line 1136 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 28: // print_args: print_args string_constant
#line 191 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                          { yystack_[1].value.as < std::vector<ParaCL::front::AST::AnonNode> > ().push_back(std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())); yylhs.value.as < std::vector<ParaCL::front::AST::AnonNode> > () = std::move(yystack_[1].value.as < std::vector<ParaCL::front::AST::AnonNode> > ()); }
#line 1142 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 29: // print_args: print_args COMMA expression
#line 192 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                          { yystack_[2].value.as < std::vector<ParaCL::front::AST::AnonNode> > ().push_back(std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())); yylhs.value.as < std::vector<ParaCL::front::AST::AnonNode> > () = std::move(yystack_[2].value.as < std::vector<ParaCL::front::AST::AnonNode> > ()); }
#line 1148 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 30: // print_args: print_args COMMA string_constant
#line 193 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                          { yystack_[2].value.as < std::vector<ParaCL::front::AST::AnonNode> > ().push_back(std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())); yylhs.value.as < std::vector<ParaCL::front::AST::AnonNode> > () = std::move(yystack_[2].value.as < std::vector<ParaCL::front::AST::AnonNode> > ()); }
#line 1154 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 31: // while_statement: WH LCIB expression RCIB LCUB scope RCUB
#line 197 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                            {
        auto w = ParaCL::front::AST::While(std::move(yystack_[4].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[1].value.as < ParaCL::front::AST::AnonNode > ()));
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::While>(std::move(w));
    }
#line 1163 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 32: // while_statement: WH LCIB expression RCIB one_stmt_scope
#line 201 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                             {
        auto w = ParaCL::front::AST::While(std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()));
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::While>(std::move(w));
    }
#line 1172 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 33: // while_statement: WH LCIB error RCIB LCUB scope RCUB
#line 205 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                         { ErrorHandler::throwError(yystack_[4].location, "expected condition in while"); YYABORT; }
#line 1178 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 34: // while_statement: WH LCIB expression error LCUB scope RCUB
#line 206 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                               { ErrorHandler::throwError(yystack_[3].location, "expected ')' after while condition"); YYABORT; }
#line 1184 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 35: // while_statement: WH LCIB expression RCIB error
#line 207 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                    { ErrorHandler::throwError(yystack_[0].location, "expected scope after while"); YYABORT; }
#line 1190 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 36: // while_statement: WH error
#line 208 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
               { ErrorHandler::throwError(yystack_[0].location, "expected '(' after while"); YYABORT; }
#line 1196 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 37: // condition_statement: if_statement elif_statements else_statement
#line 212 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                {
        ParaCL::front::AST::Condition cond;
        cond.addIf(std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()));
        for (auto&& e : yystack_[1].value.as < std::vector<ParaCL::front::AST::AnonNode> > ()) cond.addIf(std::move(e));
        if (yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()) cond.setElse(std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()));
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::Condition>(std::move(cond));
    }
#line 1208 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 38: // if_statement: IF LCIB expression RCIB LCUB scope RCUB
#line 222 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                            {
        auto i = ParaCL::front::AST::If(std::move(yystack_[4].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[1].value.as < ParaCL::front::AST::AnonNode > ()));
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::If>(std::move(i));
    }
#line 1217 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 39: // if_statement: IF LCIB expression RCIB one_stmt_scope
#line 226 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                             {
        auto i = ParaCL::front::AST::If(std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()));
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::If>(std::move(i));
    }
#line 1226 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 40: // if_statement: IF LCIB error RCIB LCUB scope RCUB
#line 231 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                         { ErrorHandler::throwError(yystack_[4].location, "expected condition in if"); YYABORT; }
#line 1232 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 41: // if_statement: IF LCIB expression error LCUB scope RCUB
#line 232 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                               { ErrorHandler::throwError(yystack_[3].location, "expected ')' after if"); YYABORT; }
#line 1238 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 42: // if_statement: IF LCIB expression RCIB error
#line 233 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                    { ErrorHandler::throwError(yystack_[0].location, "expected scope after if"); YYABORT; }
#line 1244 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 43: // if_statement: IF error
#line 234 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
               { ErrorHandler::throwError(yystack_[0].location, "expected '(' after if"); YYABORT; }
#line 1250 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 44: // elif_statements: %empty
#line 238 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
           { yylhs.value.as < std::vector<ParaCL::front::AST::AnonNode> > () = std::vector<ParaCL::front::AST::AnonNode>(); }
#line 1256 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 45: // elif_statements: elif_statements ELIF LCIB expression RCIB LCUB scope RCUB
#line 239 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                                {
        auto e = ParaCL::front::AST::If(std::move(yystack_[4].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[1].value.as < ParaCL::front::AST::AnonNode > ()));
        yystack_[7].value.as < std::vector<ParaCL::front::AST::AnonNode> > ().push_back(ParaCL::front::AST::make_node<ParaCL::front::AST::If>(std::move(e)));
        yylhs.value.as < std::vector<ParaCL::front::AST::AnonNode> > () = std::move(yystack_[7].value.as < std::vector<ParaCL::front::AST::AnonNode> > ());
    }
#line 1266 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 46: // elif_statements: elif_statements ELIF LCIB expression RCIB one_stmt_scope
#line 244 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                               {
        auto e = ParaCL::front::AST::If(std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()));
        yystack_[5].value.as < std::vector<ParaCL::front::AST::AnonNode> > ().push_back(ParaCL::front::AST::make_node<ParaCL::front::AST::If>(std::move(e)));
        yylhs.value.as < std::vector<ParaCL::front::AST::AnonNode> > () = std::move(yystack_[5].value.as < std::vector<ParaCL::front::AST::AnonNode> > ());
    }
#line 1276 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 47: // else_statement: %empty
#line 253 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
           { yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::AnonNode(); }
#line 1282 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 48: // else_statement: ELSE LCUB scope RCUB
#line 254 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                           {
        auto e = ParaCL::front::AST::Else(std::move(yystack_[1].value.as < ParaCL::front::AST::AnonNode > ()));
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::Else>(std::move(e));
    }
#line 1291 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 49: // else_statement: ELSE one_stmt_scope
#line 258 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                          {
        auto e = ParaCL::front::AST::Else(std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()));
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::Else>(std::move(e));
    }
#line 1300 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 50: // else_statement: ELSE error
#line 262 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                 { ErrorHandler::throwError(yystack_[0].location, "expected scope after else"); YYABORT; }
#line 1306 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 51: // expression: assignment_expression
#line 265 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                  { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 1312 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 52: // assignment_expression: logical_or_expression
#line 268 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                          { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 1318 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 53: // assignment_expression: VAR AS assignment_expression
#line 269 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                            {
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::ASGN,
            ParaCL::front::AST::make_node<ParaCL::front::AST::Variable>(yystack_[2].value.as < std::string > ()),
            std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
        name_table.declare_or_do_nothing_if_already_declared(yystack_[2].value.as < std::string > ());
    }
#line 1332 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 54: // logical_or_expression: logical_and_expression
#line 282 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                           { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 1338 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 55: // logical_or_expression: logical_or_expression OR logical_and_expression
#line 283 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                               {
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::OR,
            std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1350 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 56: // logical_and_expression: equality_expression
#line 293 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                        { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 1356 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 57: // logical_and_expression: logical_and_expression AND equality_expression
#line 294 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                               {
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::AND,
            std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1368 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 58: // equality_expression: relational_expression
#line 305 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                          { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 1374 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 59: // equality_expression: equality_expression ISEQ relational_expression
#line 306 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                                {
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::ISEQ,
            std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1386 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 60: // equality_expression: equality_expression ISNE relational_expression
#line 313 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                                {
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::ISNE,
            std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1398 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 61: // relational_expression: additive_expression
#line 323 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                        { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 1404 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 62: // relational_expression: relational_expression ISAB additive_expression
#line 324 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                                {
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::ISAB,
            std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1416 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 63: // additive_expression: multiplicative_expression
#line 335 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                              { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 1422 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 64: // additive_expression: additive_expression ADD multiplicative_expression
#line 336 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                                  {
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::ADD,
            std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1434 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 65: // additive_expression: additive_expression SUB multiplicative_expression
#line 343 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                                  {
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::SUB,
            std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1446 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 66: // multiplicative_expression: unary_expression
#line 353 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                     { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 1452 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 67: // multiplicative_expression: multiplicative_expression MUL unary_expression
#line 354 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                               {
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::MUL,
            std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1464 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 68: // multiplicative_expression: multiplicative_expression DIV unary_expression
#line 361 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                               {
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::DIV,
            std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1476 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 69: // multiplicative_expression: multiplicative_expression REM unary_expression
#line 368 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                               {
        auto binop = ParaCL::front::AST::BinaryOperator(
            ParaCL::front::AST::BinaryOperator::BinaryOperatorT::REM,
            std::move(yystack_[2].value.as < ParaCL::front::AST::AnonNode > ()), std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(binop)>(std::move(binop));
    }
#line 1488 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 70: // unary_expression: factor
#line 378 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
           { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 1494 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 71: // unary_expression: SUB unary_expression
#line 379 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                     {
        auto unop = ParaCL::front::AST::UnaryOperator(
            ParaCL::front::AST::UnaryOperator::UnaryOperatorT::MINUS,
            std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(unop)>(std::move(unop));
    }
#line 1506 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 72: // unary_expression: NOT unary_expression
#line 386 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                     {
        auto unop = ParaCL::front::AST::UnaryOperator(
            ParaCL::front::AST::UnaryOperator::UnaryOperatorT::NOT,
            std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ())
        );
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<decltype(unop)>(std::move(unop));
    }
#line 1518 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 73: // unary_expression: ADD unary_expression
#line 393 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                     { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[0].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 1524 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 74: // factor: NUM
#line 397 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
        { yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::NumberLiteral>(yystack_[0].value.as < int > ()); }
#line 1530 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 75: // factor: VAR
#line 398 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
          {
        if (name_table.is_not_declare(yystack_[0].value.as < std::string > ())) {
            std::cerr << "using undeclared variable: " << yystack_[0].value.as < std::string > () << "\n";
            ErrorHandler::throwError(yystack_[0].location, "using undeclared variable: " + yystack_[0].value.as < std::string > ());
            YYABORT;
        }
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::Variable>(yystack_[0].value.as < std::string > ());
    }
#line 1543 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 76: // factor: LCIB expression RCIB
#line 406 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                           { yylhs.value.as < ParaCL::front::AST::AnonNode > () = std::move(yystack_[1].value.as < ParaCL::front::AST::AnonNode > ()); }
#line 1549 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 77: // factor: IN
#line 407 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
         { yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::Scan>(); }
#line 1555 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 78: // factor: STRING
#line 408 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
             { yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::StringLiteral>(yystack_[0].value.as < std::string > ()); }
#line 1561 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 79: // scope: scope_enter_action statements scope_leave_action
#line 412 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                     {
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::Scope>(std::move(yystack_[1].value.as < std::vector<ParaCL::front::AST::AnonNode> > ()));
    }
#line 1569 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 80: // one_stmt_scope: scope_enter_action statement scope_leave_action
#line 418 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                                                    {
        std::vector<ParaCL::front::AST::AnonNode> vec{std::move(yystack_[1].value.as < ParaCL::front::AST::AnonNode > ())};
        yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::Scope>(std::move(vec));
    }
#line 1578 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 81: // scope_enter_action: %empty
#line 424 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                           { name_table.new_scope(); }
#line 1584 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 82: // scope_leave_action: %empty
#line 425 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
                           { name_table.leave_scope(); }
#line 1590 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;

  case 83: // string_constant: STRING
#line 428 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
           { yylhs.value.as < ParaCL::front::AST::AnonNode > () = ParaCL::front::AST::make_node<ParaCL::front::AST::StringLiteral>(yystack_[0].value.as < std::string > ()); }
#line 1596 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"
    break;


#line 1600 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "OR", "AND", "ISEQ", "ISNE",
  "ISAB", "ISABE", "ISLS", "ISLSE", "ADD", "SUB", "MUL", "DIV", "REM",
  "NEG", "NOT", "AS", "ADDASGN", "SUBASGN", "MULASGN", "DIVASGN", "NUM",
  "VAR", "LCIB", "RCIB", "LCUB", "RCUB", "WH", "IN", "PRINT", "IF", "ELIF",
  "ELSE", "SC", "COMMA", "STRING", "$accept", "program",
  "create_global_scope", "leave_global_scope", "statements", "statement",
  "assignment", "combined_assignment", "print_statement", "print_args",
  "while_statement", "condition_statement", "if_statement",
  "elif_statements", "else_statement", "expression",
  "assignment_expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "factor", "scope", "one_stmt_scope", "scope_enter_action",
  "scope_leave_action", "string_constant", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -96;

  const signed char parser::yytable_ninf_ = -82;

  const short
  parser::yypact_[] =
  {
     -96,    46,   -96,   -96,   232,   260,   -96,    18,    33,    34,
     -96,   -96,   -96,   -17,    -8,    19,   -96,   -96,   -96,    60,
      75,    90,   105,   120,    25,   -96,   -96,   135,   -96,   198,
     -96,   150,   -96,   -96,   -96,   -28,   -96,   201,   201,   201,
     -96,    37,   225,   -96,   -96,   -96,   -96,    57,    58,    27,
      66,     9,    23,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   232,    48,    15,   228,   -96,   -96,
     -96,    49,    16,    53,   154,   -96,   -96,   -96,   -96,   -96,
     225,    54,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   -96,    52,    55,   167,   -96,   -96,    61,    62,
     176,   225,   -96,   -96,   -96,   242,   -96,   -96,    58,    27,
      66,    66,     9,    23,    23,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,    67,    68,
     -96,    76,    80,    81,    82,    83,    91,    96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,    97,   -96
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,     5,     1,     4,     0,    81,     0,     0,     0,
      13,     2,     6,     0,     0,     0,    11,    12,    44,     0,
       0,     0,     0,     0,     0,     5,    36,     0,    25,    24,
      43,     0,     8,     9,    10,    47,    15,     0,     0,     0,
      74,    75,     0,    77,    78,    14,    51,    52,    54,    56,
      58,    61,    63,    66,    70,    20,    16,    21,    17,    22,
      18,    23,    19,     7,    82,     0,     0,     0,    78,    27,
      28,     0,     0,     0,     0,    37,    75,    73,    71,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,    29,    30,     0,     0,
       0,     0,    50,    81,    49,     0,    53,    76,    55,    57,
      59,    60,    62,    64,    65,    67,    68,    69,    81,    81,
      35,    81,    32,    81,    81,    42,    81,    39,     0,     0,
      82,     0,     0,     0,     0,     0,     0,    81,    48,    80,
      33,    34,    31,    40,    41,    38,    81,    46,     0,    45
  };

  const signed char
  parser::yypgoto_[] =
  {
     -96,   -96,   -96,   -96,    69,   -10,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -20,    38,   -96,    21,    41,
     -45,    40,   -39,   -25,   -96,   -95,   -85,   -70,     3,    71
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     1,     2,    11,     4,    12,    13,    14,    15,    29,
      16,    17,    18,    35,    75,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    24,   104,    25,    92,    70
  };

  const short
  parser::yytable_[] =
  {
      56,    58,    60,    62,   105,    73,    74,    66,   129,    69,
     122,    72,    77,    78,    79,   127,    94,    99,    32,    26,
      87,    88,    81,   131,   132,   105,   133,    33,   134,   135,
     105,   136,    84,    85,    28,    30,    89,    90,    91,   110,
     111,    95,   100,    27,   -26,   -26,     3,    96,   113,   114,
     -26,   148,   147,    63,    34,    80,   -26,   -26,   -26,    31,
      82,    36,    83,   -26,   115,   116,   117,   105,   -26,   -26,
     -26,    37,    38,    86,    93,    98,    55,    39,   101,   118,
     107,   128,   119,    40,    41,    42,    37,    38,   123,   124,
      43,    57,    39,   137,    64,   130,   138,    44,    40,    41,
      42,    37,    38,   108,   140,    43,    59,    39,   141,   142,
     143,   144,    44,    40,    41,    42,    37,    38,   106,   145,
      43,    61,    39,   146,   109,   149,   112,    44,    40,    41,
      42,    37,    38,   139,     0,    43,    65,    39,    97,     0,
       0,     0,    44,    40,    41,    42,    37,    38,     0,     0,
      43,    71,    39,     0,     0,   102,     0,    44,    40,    41,
      42,    37,    38,     0,     0,    43,     0,    39,   120,     0,
       0,     0,    44,    40,    41,    42,     0,   125,   -81,     0,
      43,   103,     0,   -81,     0,   -81,   -81,    44,     0,   -81,
       0,   -81,     0,     0,   121,     0,   -81,     0,   -81,   -81,
     -81,     0,   -81,   126,     0,   -81,     0,   -81,   -81,    37,
      38,   -81,    37,    38,     0,    39,     0,     0,    39,     0,
       0,    40,    41,    42,    40,    76,    42,     0,    43,     0,
       0,    43,     0,     0,    67,    68,    37,    38,    44,    37,
      38,     0,    39,     0,     0,    39,     0,     0,    40,    41,
      42,    40,    41,    42,     0,    43,     5,     0,    43,     6,
       0,     7,    44,     8,     9,    68,     5,    10,     0,     0,
       0,     7,     0,     8,     9,     0,     0,    10,    19,    20,
      21,    22,    23
  };

  const short
  parser::yycheck_[] =
  {
      20,    21,    22,    23,    74,    33,    34,    27,   103,    29,
      95,    31,    37,    38,    39,   100,     1,     1,    35,     1,
      11,    12,    42,   118,   119,    95,   121,    35,   123,   124,
     100,   126,     5,     6,     1,     1,    13,    14,    15,    84,
      85,    26,    26,    25,    11,    12,     0,    67,    87,    88,
      17,   146,   137,    28,    35,    18,    23,    24,    25,    25,
       3,     1,     4,    30,    89,    90,    91,   137,    35,    36,
      37,    11,    12,     7,    26,    26,     1,    17,    25,    27,
      26,   101,    27,    23,    24,    25,    11,    12,    27,    27,
      30,     1,    17,    26,    25,   105,    28,    37,    23,    24,
      25,    11,    12,    82,    28,    30,     1,    17,    28,    28,
      28,    28,    37,    23,    24,    25,    11,    12,    80,    28,
      30,     1,    17,    27,    83,    28,    86,    37,    23,    24,
      25,    11,    12,   130,    -1,    30,     1,    17,    67,    -1,
      -1,    -1,    37,    23,    24,    25,    11,    12,    -1,    -1,
      30,     1,    17,    -1,    -1,     1,    -1,    37,    23,    24,
      25,    11,    12,    -1,    -1,    30,    -1,    17,     1,    -1,
      -1,    -1,    37,    23,    24,    25,    -1,     1,    24,    -1,
      30,    27,    -1,    29,    -1,    31,    32,    37,    -1,    35,
      -1,    24,    -1,    -1,    27,    -1,    29,    -1,    31,    32,
      24,    -1,    35,    27,    -1,    29,    -1,    31,    32,    11,
      12,    35,    11,    12,    -1,    17,    -1,    -1,    17,    -1,
      -1,    23,    24,    25,    23,    24,    25,    -1,    30,    -1,
      -1,    30,    -1,    -1,    36,    37,    11,    12,    37,    11,
      12,    -1,    17,    -1,    -1,    17,    -1,    -1,    23,    24,
      25,    23,    24,    25,    -1,    30,    24,    -1,    30,    27,
      -1,    29,    37,    31,    32,    37,    24,    35,    -1,    -1,
      -1,    29,    -1,    31,    32,    -1,    -1,    35,    18,    19,
      20,    21,    22
  };

  const signed char
  parser::yystos_[] =
  {
       0,    39,    40,     0,    42,    24,    27,    29,    31,    32,
      35,    41,    43,    44,    45,    46,    48,    49,    50,    18,
      19,    20,    21,    22,    63,    65,     1,    25,     1,    47,
       1,    25,    35,    35,    35,    51,     1,    11,    12,    17,
      23,    24,    25,    30,    37,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     1,    53,     1,    53,     1,
      53,     1,    53,    28,    42,     1,    53,    36,    37,    53,
      67,     1,    53,    33,    34,    52,    24,    61,    61,    61,
      18,    53,     3,     4,     5,     6,     7,    11,    12,    13,
      14,    15,    66,    26,     1,    26,    53,    67,    26,     1,
      26,    25,     1,    27,    64,    65,    54,    26,    56,    57,
      58,    58,    59,    60,    60,    61,    61,    61,    27,    27,
       1,    27,    64,    27,    27,     1,    27,    64,    53,    63,
      43,    63,    63,    63,    63,    63,    63,    26,    28,    66,
      28,    28,    28,    28,    28,    28,    27,    64,    63,    28
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    38,    39,    40,    41,    42,    42,    42,    43,    43,
      43,    43,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    45,    46,    46,    47,    47,    47,    47,
      47,    48,    48,    48,    48,    48,    48,    49,    50,    50,
      50,    50,    50,    50,    51,    51,    51,    52,    52,    52,
      52,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      57,    58,    58,    59,    59,    59,    60,    60,    60,    60,
      61,    61,    61,    61,    62,    62,    62,    62,    62,    63,
      64,    65,    66,    67
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,     0,     0,     0,     2,     4,     2,     2,
       2,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     0,     2,     2,     3,
       3,     7,     5,     7,     7,     5,     2,     3,     7,     5,
       7,     7,     5,     2,     0,     8,     6,     0,     4,     2,
       2,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     2,     1,     1,     3,     1,     1,     3,
       3,     0,     0,     1
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    66,    66,    72,    76,    80,    81,    85,    92,    93,
      94,    95,    96,    97,   101,   110,   118,   131,   144,   157,
     171,   172,   173,   174,   178,   182,   189,   190,   191,   192,
     193,   197,   201,   205,   206,   207,   208,   212,   222,   226,
     231,   232,   233,   234,   238,   239,   244,   253,   254,   258,
     262,   265,   268,   269,   282,   283,   293,   294,   305,   306,
     313,   323,   324,   335,   336,   343,   353,   354,   361,   368,
     378,   379,   386,   393,   397,   398,   406,   407,   408,   412,
     418,   424,   425,   428
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
    };
    // Last valid token kind.
    const int code_max = 292;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 6 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"
} // yy
#line 2203 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/build/generated/bison/parser.tab.cpp"

#line 431 "/home/matvey/work/Vladimirov/ParaCL/paracl_compiler/front/parser/src/parser.y"

