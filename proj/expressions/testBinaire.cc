#include "testBinaire.hh"

TestBinaire::TestBinaire(ExpressionPtr gauche, ExpressionPtr droite, OperateurBool op):
    _gauche(gauche), _droite(droite), _op(op) { }

bool TestBinaire::calculer(const Contexte& contexte) const {
    double gauche = _gauche->calculer(contexte), droite = _droite->calculer(contexte);
    switch (_op) {
        case OperateurBool::plusgrand: return gauche > droite;
        case OperateurBool::pluspetit: return gauche < droite;
        case OperateurBool::egal: return gauche == droite;
        case OperateurBool::different: return gauche != droite;
        case OperateurBool::plusgrandouegal: return gauche >= droite;
        case OperateurBool::pluspetitouegal: return gauche <= droite;
        default: return false;
    }
}
