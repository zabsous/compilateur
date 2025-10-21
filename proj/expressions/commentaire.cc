#include "commentaire.hh"

std::string Commentaire::evaluate(Driver & driver) const {
    std::string res = _texte;
    if (_texte.size() >= 3 && _texte.substr(0, 3) == "%%%"){
        res = res.substr(3, res.size()-1-3*2);
    } else {
        res = res.substr(2, res.size()-1);
    }
    return "<!--" + res + "-->\n";
}