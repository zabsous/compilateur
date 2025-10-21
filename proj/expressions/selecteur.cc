#include "selecteur.hh"

std::string SelecteurParagraphe::evaluate() const {
    return bloc()->evaluate();
}

std::string SelecteurTitre::evaluate() const {
    return bloc()->evaluate();
}

std::string SelecteurImage::evaluate() const {
    return bloc()->evaluate();
}

std::shared_ptr<Bloc> SelecteurParagraphe::bloc() const{
    int i = 0;
    for (InstructionPtr instr : getInstructions()){
        auto pBloc = std::dynamic_pointer_cast<BlocParagraphe>(instr);
        if (pBloc && i < getId())
            i++;
        else if (pBloc && i == getId())
            return pBloc;
    }

    return nullptr;
}

std::shared_ptr<Bloc> SelecteurTitre::bloc() const{
    int i = 0;
    for (InstructionPtr instr : getInstructions()){
        auto pBloc = std::dynamic_pointer_cast<BlocTitre>(instr);
        if (pBloc && pBloc->getHniveau() == _hniveau && i < getId())
            i++;
        else if (pBloc && pBloc->getHniveau() == _hniveau && i == getId())
            return pBloc;
    }

    return nullptr;
}

std::shared_ptr<Bloc> SelecteurImage::bloc() const{
    int i = 0;
    for (InstructionPtr instr : getInstructions()){
        auto pBloc = std::dynamic_pointer_cast<BlocImage>(instr);
        if (pBloc && i < getId())
            i++;
        else if (pBloc && i == getId())
            return pBloc;
    }

    return nullptr;
}