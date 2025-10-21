#pragma once
#include <memory>
#include <string>
#include <vector>
#include "driver.hh"
#include "instruction.hh"
#include "couleur.hh"
#include "affectation.hh"
#include "style.hh"


class SelecteurModifier : public Affectation {
public :
    SelecteurModifier(std::string const & nomVar, std::shared_ptr<Variable> const & val, std::string const & param)
        :Affectation(nomVar, val), _parametre(param){}

    SelecteurModifier(std::string const & nomVar, std::string const & val, std::string const & param)
        :Affectation(nomVar, val), _parametre(param){}

    std::string evaluate(Driver & driver) const override; 
    TAttributs getType() const;

private:
    std::shared_ptr<Variable> getValeur(Driver const & driver) const;

private:
    std::string _parametre;

};