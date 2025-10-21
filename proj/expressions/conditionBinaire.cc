#include "conditionBinaire.hh"

ConditionBinaire::ConditionBinaire(ConditionPtr gauche, ConditionPtr droite, OperateurBinaireBool op):
    _gauche(gauche), _droite(droite), _op(op) {

}

bool ConditionBinaire::calculer(const Contexte& contexte) const {
    bool gauche = _gauche->calculer(contexte), droite = _droite->calculer(contexte);
    switch (_op) {
        case OperateurBinaireBool::et: return gauche and droite;
        case OperateurBinaireBool::ou: return gauche or droite;
        default: return false;
    }
}
