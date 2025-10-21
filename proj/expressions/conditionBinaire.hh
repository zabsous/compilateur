#pragma once
#include "condition.hh"

class ConditionBinaire : public Condition {
public:
    ConditionBinaire(const ConditionBinaire &) = default;
    ConditionBinaire(ConditionPtr gauche, ConditionPtr droite, OperateurBinaireBool op);
    ConditionBinaire(ConditionPtr gauche, ConditionPtr droite, OperateurBinaireBool op);
    ~ConditionBinaire() = default;

    bool calculer(const Contexte& contexte) const override;

private:
    ConditionPtr _gauche;
    ConditionPtr _droite;
    OperateurBinaireBool _op;
};
