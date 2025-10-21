#pragma once
#include <string>

class Variable {
public:
    Variable() =default;

    virtual std::string evaluate() const =0;
};

class Entier : public Variable{
public:
    Entier(int val)
        : _val(val) {}

    std::string evaluate() const override {return std::to_string(_val);};
    int getVal() const {return _val;};

private:
    int _val;
};

// class VariableEntiere : public Variable {
//     VariableEntiere(const std::string & nom,const InstructionPtr & inst);
//     virtual double calculer(const Contexte& contexte) const override;
// };

// class VariableCouleur : public Variable {
//     VariableCouleur(const std::string & nom,const Couleur & coul);
//     virtual double calculer(const Contexte& contexte) const override;
// };

// class VariableBloc : public Variable {
//     VariableBloc(const std::string & nom,const Bloc & bl);
//     virtual double calculer(const Contexte& contexte) const override;
// };

// class VariableStyle : public Variable {
//     VariableStyle(const std::string & nom,const Style & st);
//     virtual double calculer(const Contexte& contexte) const override;
// };