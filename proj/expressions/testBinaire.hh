#pragma once
#include "expression.hh"
#include "condition.hh"



class TestBinaire : public Condition {
public:
    TestBinaire(const TestBinaire &) = default;
    TestBinaire(ExpressionPtr gauche, ExpressionPtr droite, OperateurBool op);
    ~TestBinaire() = default;

    bool calculer(const Contexte& contexte) const override;

private:
    ExpressionPtr _gauche;
    ExpressionPtr _droite;
    OperateurBool _op;
};
