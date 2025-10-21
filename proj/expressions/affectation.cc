#include "affectation.hh"


std::string Affectation::evaluate(Driver & driver) const{
    try {
        driver.setVariable(_identifiant, _valeur);
        std::cout << _identifiant << std::endl;
    } catch (const std::exception& err){
        std::cerr << "#-> " << err.what() << std::endl;
        return "erreur";
    }
    return ""; // retour dans le cas ou tout vas bien.
}
