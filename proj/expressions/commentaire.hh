#pragma once
#include <string>
#include "instruction.hh"

class Commentaire : public Instruction {
public:
    Commentaire(std::string const & texte)
        :_texte(texte){}

    std::string evaluate(Driver & driver) const override; 

private:
    std::string _texte;
};