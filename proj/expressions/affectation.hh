#pragma once
#include "instruction.hh"
#include "expression.hh"
#include "variable.hh"
#include <iostream>

class Affectation : public Instruction {
public:
    Affectation(std::string const & identifiant, std::shared_ptr<Variable> valeur)
        :_identifiant(identifiant), _valeur(valeur) { }
    Affectation(std::string const & identifiant, std::string const & valeur)
        :_identifiant(identifiant), _valeur(nullptr),_valeurStr(valeur) { }

    std::string evaluate(Driver & driver) const override;
    std::string const & getIdentifiant() const {return _identifiant;};
    std::shared_ptr<Variable> getValeur() const {return _valeur;};
    std::string getValeurStr() const {return _valeurStr;};

private:
    std::string _identifiant;
    std::shared_ptr<Variable> _valeur;
    std::string _valeurStr;
};
