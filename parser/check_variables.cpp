#include "check_variables.hpp"
#include <iostream>
#include "spdlog/spdlog.h"

namespace ParaCL
{

void ParserNameTable::new_scope()
{
    spdlog::debug("paracl: parser: nametable: create new scope (depth {})", 
                  scopes_.size() + 1);
    scopes_.emplace_back();
}

void ParserNameTable::leave_scope()
{
    spdlog::debug("paracl: parser: nametable: leave scope (depth {})", 
                  scopes_.size());

    if (scopes_.empty())
    {
        spdlog::warn("paracl: parser: nametable: try to leave non-existent scope");
        return;
    }
    scopes_.pop_back();
}

bool ParserNameTable::is_declare(std::string_view variable) const
{
    spdlog::debug("paracl: parser: nametable: check declaration of: \"{}\"", variable);

    for (auto it = scopes_.rbegin(); it != scopes_.rend(); ++it)
    {
        if (it->count(std::string(variable)))
        {
            spdlog::debug("paracl: parser: nametable: \"{}\" FOUND → already declared, return true", 
                          variable);
            return true;
        }
    }

    spdlog::debug("paracl: parser: nametable: \"{}\" NOT found", variable);
    return false;
}

bool ParserNameTable::is_not_declare(std::string_view variable) const
{
    return !is_declare(variable);
}

void ParserNameTable::declare_or_do_nothing_if_already_declared(std::string_view variable)
{
    spdlog::debug("paracl: parser: nametable: try to declare: \"{}\"", variable);

    if (is_declare(variable))
    {
        spdlog::info("Parser nametable msg: Variable \"{}\" already exists", variable);
        return;
    }

    if (scopes_.empty())
    {
        spdlog::error("paracl: parser: nametable: ERROR: no active scope!");
        return;
    }

    scopes_.back().insert(std::string(variable));
    spdlog::debug("Parser nametable msg: DECLARED \"{}\" in scope depth {}", 
                  variable, scopes_.size());
}

} // namespace ParaCL
