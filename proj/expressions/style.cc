#include "style.hh"
#include <iostream>

std::string Attribut::getTypeStr() const{
    switch (_type){
    case TAttributs::couleurFond:
        return "background-color";
        break;
    case TAttributs::couleurTexte:
        return "color";
        break;
    case TAttributs::opacite:
        return "opacity";
        break;
    case TAttributs::hauteur:
        return "height";
        break;
    case TAttributs::largeur:
        return "width";
        break;
    case TAttributs::style:
        return "style";
        break;
    }
}

std::string Style::evaluate() const{
    std::string res = " style='";
    for (size_t i = 0; i < _attributs.size(); i++)
    {
        res += _attributs[i]->evaluate();
        res += ";";
    }
    res += "'";
    return res;
}
