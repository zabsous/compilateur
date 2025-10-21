#include "define.hh"


std::string Define::evaluate(Driver & driver) const{
    std::string res;
    switch(_identifiant){
        case nomPropriete::encodage:
            res = "<meta charset='" + _valeur + "'>";
            break;
        case nomPropriete::icone:
            res = "<link rel='icon' type='image/jpg' href='./" + _valeur + "'/>";
            break;
        case nomPropriete::css:
            res = "<link rel='stylesheet' href='" + _valeur + "'>";
            break;
        case nomPropriete::langue:
            res = "<html lang='" + _valeur + "'>";
            break;
        case nomPropriete::titre:
            res = "<title>" + _valeur + "</title>";
            break;
    }

    res += "\n";

    return res;
} 
