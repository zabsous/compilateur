#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "contexte.hh"

class Driver {
public:
    Driver();
    ~Driver();

    const   Contexte& getContexte() const {return _variables;};
    std::shared_ptr<Variable>  getVariable(const std::string& name) const {return _variables.get(name);};
    void    setVariable(const std::string& name, std::shared_ptr<Variable> value) {_variables[name] = value;};


private:
    Contexte _variables;
};

#endif
