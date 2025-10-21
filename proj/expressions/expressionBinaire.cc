#include "expressionBinaire.hh"


ExpressionBinaire::ExpressionBinaire(ExpressionPtr gauche, ExpressionPtr droite, OperateurBinaire op):
    _gauche(gauche), _droite(droite), _op(op) {

}

// double ExpressionBinaire::calculer(const Contexte& contexte) const {
//     double gauche = _gauche->calculer(contexte), droite = _droite->calculer(contexte);
//     switch (_op) {
//         case OperateurBinaire::plus: return gauche + droite;
//         case OperateurBinaire::moins: return gauche - droite;
//         case OperateurBinaire::divise: return gauche / droite;
//         case OperateurBinaire::multiplie: return gauche * droite;
//         case OperateurBinaire::egal: return gauche == droite;
//         case OperateurBinaire::different: return gauche != droite;
//         case OperateurBinaire::plusgrand: return gauche > droite;
//         case OperateurBinaire::pluspetit: return gauche < droite;
//         case OperateurBinaire::ou: return gauche or droite;
//         case OperateurBinaire::et: return gauche and droite;
//         case OperateurBinaire::ouex:
//             if((gauche == 1 and droite == 0) or (gauche == 0 and droite == 1))
//                 return 1;
//             else
//                 return 0;
//         default: return 0;
//     }
// }
