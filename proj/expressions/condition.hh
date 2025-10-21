#pragma once
#include <memory>
#include "contexte.hh"

enum class OperateurBinaireBool {
    et,
    ou
};

enum class OperateurBool {
    plusgrand,
    pluspetit,
    egal,
    different,
    plusgrandouegal,
    pluspetitouegal
};

class Condition {
public:
    virtual bool calculer(const Contexte & contexte) const = 0;
};

using ConditionPtr = std::shared_ptr<Condition>;
