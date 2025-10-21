#include "programme.hh"
#include "define.hh"
#include "bloc.hh"
#include "commentaire.hh"
#include "affectation.hh"
#include "styleBloc.hh"
#include <iostream>

void Programme::eval(Driver & driver) {
    for (InstructionPtr const & instr : getInstruction()){
        auto pSelect = std::dynamic_pointer_cast<SelecteurModifier>(instr);
        auto pAffect = std::dynamic_pointer_cast<Affectation>(instr);
        if (pSelect)
            pSelect->evaluate(driver);
        else if (pAffect)
            pAffect->evaluate(driver);
    }
    // for (std::shared_ptr<SelecteurModifier> const & selectModif : getSelecteurs()){
    //     selectModif->evaluate(driver);
    // }
    bool lang = false;
    bool encodage = false;
    bool title = false;
    std::cout << "<!DOCTYPE html>" << std::endl;
    
    for (InstructionPtr const & instr : getInstruction()){
        auto pDef = std::dynamic_pointer_cast<Define>(instr);
        if (pDef && pDef->getIdentifiant() == nomPropriete::langue){
            std::cout << pDef->evaluate(driver);
            lang = true;
        }
    }
    if (!lang)
        std::cout << "<html lang='fr'>" << std::endl;

    std::string indent = "  ";
    std::cout << indent << "<head>" << std::endl;

    for (InstructionPtr const &instr : getInstruction()){
        auto pDef = std::dynamic_pointer_cast<Define>(instr);
        if (pDef && pDef->getIdentifiant() != nomPropriete::langue){
            std::cout << indent << indent << pDef->evaluate(driver);
            if (pDef->getIdentifiant() == nomPropriete::encodage)
                encodage = true;
            if (pDef->getIdentifiant() == nomPropriete::titre)
                title = true;
        }
    }
    if (!encodage)
        std::cout << indent << indent << "<meta charset='utf8'>" << std::endl;
    if (!title)
        std::cout << indent << indent << "<title></title>" << std::endl;

    std::cout << indent << "</head>" << std::endl;

    std::cout << indent << "<body>" << std::endl;
    for (InstructionPtr const & instr :getInstruction()){
        if (std::dynamic_pointer_cast<Bloc>(instr))
            std::cout << indent << indent << instr->evaluate(driver);
        else if (std::dynamic_pointer_cast<Commentaire>(instr)){
            std::cout << indent << indent << instr->evaluate(driver);
        } else if (std::dynamic_pointer_cast<StyleBloc>(instr)){
            instr->evaluate(driver);
        }
    }
    std::cout << indent << "</body>" << std::endl;

    std::cout << "</html>";
}
