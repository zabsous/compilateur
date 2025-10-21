#pragma once
#include "instruction.hh"
#include <iostream>

enum class nomPropriete {encodage,icone,css,langue,titre};

class Define : public Instruction {
public:
    Define(nomPropriete propriete, std::string const & valeur)
        :_identifiant(propriete), _valeur(valeur.substr(1, valeur.size()-2)){}

    std::string evaluate(Driver & driver) const override; 
    nomPropriete getIdentifiant() const {return _identifiant;}; 

private:
    nomPropriete _identifiant;
    std::string _valeur;
};
