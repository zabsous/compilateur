#pragma once
#include "expression.hh"
#include "couleur.hh"
#include "bloc.hh"

class Constante : public Expression {
public:
    Constante() = delete;
    Constante(const Constante&) = default;
};

// class ConstanteEntiere : public Constante {
//     ConstanteEntiere(double valeur);
//     virtual double calculer(const Contexte& contexte) const override;
//     private:
//     double _valeur;
// };

// class ConstanteCouleur : public Constante {
//     ConstanteCouleur(const Couleur & coul);
//     virtual Couleur calculer(const Contexte& contexte) const override;
//     private:
//     Couleur _valeur;
// };

// class ConstanteBloc : public Constante {
//     ConstanteBloc(const Bloc & bl);
//     virtual double calculer(const Contexte& contexte) const override;
//     private:
//     double _valeur;
// };

// class ConstanteStyle : public Constante {
//     ConstanteStyle(const Style & st);
//     virtual double calculer(const Contexte& contexte) const override;
//     private:
//     double _valeur;
// };