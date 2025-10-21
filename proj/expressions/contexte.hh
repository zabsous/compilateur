#pragma once

#include <string>
#include <map>
#include "variable.hh"
#include <memory>

class Contexte {
public:
    Contexte() = default;
    Contexte(const Contexte & autre) = default;

    std::shared_ptr<Variable>&  get(const std::string & nom) {return _variables[nom];};
    const std::shared_ptr<Variable>& get(const std::string & nom) const {return _variables.at(nom);};

    std::shared_ptr<Variable>& operator[](const std::string & nom) {return _variables[nom];};
    const std::shared_ptr<Variable>& operator[](const std::string & nom) const {return _variables.at(nom);};

private:
    std::map<std::string, std::shared_ptr<Variable>> _variables;
};
