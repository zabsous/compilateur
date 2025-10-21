#pragma once
#include "variable.hh"

class Couleur : public Variable{
public :
    Couleur()=default;
    Couleur(std::string const & r,std::string const & v,std::string const & b, bool hexa)
        :_rouge(r), _vert(v), _bleu(b), _hexa(hexa){}
    std::string const & rouge() const {return _rouge;};
    std::string const & vert() const {return _vert;};
    std::string const & bleu() const {return _bleu;};

    std::string evaluate() const
    {
        if (_hexa)
            return "#" + _rouge + _vert + _bleu;
        else
            return "rgb(" + _rouge + "," + _vert + "," + _bleu + ")";
    }

private :
    std::string _rouge;
    std::string _vert;
    std::string _bleu;
    bool _hexa;
};