#include "selecteurModifier.hh"
#include "selecteur.hh"
#include "bloc.hh"
#include <iostream>

TAttributs SelecteurModifier::getType() const{
    if (_parametre == "couleurFond")
        return TAttributs::couleurFond;
    else if (_parametre == "couleurTexte")
        return TAttributs::couleurTexte;
    else if (_parametre == "opacite")
        return TAttributs::opacite;
    else if (_parametre == "hauteur")
        return TAttributs::hauteur;
    else if (_parametre == "largeur")
        return TAttributs::largeur;
    else
        return TAttributs::style;
}

std::shared_ptr<Variable> SelecteurModifier::getValeur(Driver const & driver) const{
    if (Affectation::getValeur()){
        return Affectation::getValeur();
    } else {
        try{
            std::shared_ptr<Variable> valeur = driver.getVariable(getValeurStr());
            return valeur;
        }
        catch (const std::out_of_range &err){
            std::cerr << "La variable " << getValeurStr() << " n'existe pas !" << std::endl;
        }
    }
}

std::string SelecteurModifier::evaluate(Driver & driver) const {
    try{
        std::shared_ptr<Variable> var = driver.getVariable(getIdentifiant());

        std::shared_ptr<Bloc> pBloc;
        auto pSelecteur = std::dynamic_pointer_cast<Selecteur>(var);
        if (pSelecteur)
            pBloc = pSelecteur->bloc();
        else
            pBloc = std::dynamic_pointer_cast<Bloc>(var);

        if (pBloc){
            auto style = pBloc->getStyle();
            TAttributs param = getType();
            if (style == nullptr)
            {
                auto newStyle = std::make_shared<Style>();
                if (param == TAttributs::couleurFond || param == TAttributs::couleurTexte){
                    auto pCouleur = std::dynamic_pointer_cast<Couleur>(getValeur(driver));
                    if (pCouleur){
                        auto attr = std::make_shared<AttributCouleur>(param, pCouleur);
                        newStyle->ajouterAttr(attr);
                    }
                }
                else if (param == TAttributs::largeur || param == TAttributs::hauteur || param == TAttributs::opacite){
                    auto pEntier = std::dynamic_pointer_cast<Entier>(getValeur(driver));
                    if (pEntier){
                        auto attr = std::make_shared<AttributEntier>(param, pEntier->getVal());
                        newStyle->ajouterAttr(attr);
                    }                }
                else{
                    newStyle = std::dynamic_pointer_cast<Style>(getValeur(driver));
                }
                pBloc->setStyle(newStyle);
            } else if (param == TAttributs::couleurFond || param == TAttributs::couleurTexte){
                auto pCouleur = std::dynamic_pointer_cast<Couleur>(getValeur(driver));
                if (pCouleur){
                    auto attr = std::make_shared<AttributCouleur>(param, pCouleur);
                    style->ajouterAttr(attr);
                }
            }
            else{
                auto pEntier = std::dynamic_pointer_cast<Entier>(getValeur(driver));
                if (pEntier){
                    auto attr = std::make_shared<AttributEntier>(param, pEntier->getVal());
                    style->ajouterAttr(attr);
                }
            }
        } else {
            std::cerr << "La variable " << getIdentifiant() << " n'est pas un bloc" << std::endl;
        }

    } catch (const std::out_of_range & err){
        std::cerr << "La variable " << getIdentifiant() << " n'existe pas !" << std::endl;
    }

    return "";
}