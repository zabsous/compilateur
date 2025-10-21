#pragma once
#include <vector>
#include <string>
#include <memory>
#include "couleur.hh"
#include "variable.hh"

enum class TAttributs {couleurFond, couleurTexte, opacite, largeur, hauteur, style};

class Attribut{
public:
    Attribut(TAttributs type)
        :_type(type){}

    TAttributs getType() const {return _type;};
    std::string getTypeStr() const;
    virtual std::string getVal() const =0;
    virtual std::string getExtension() const {return "";};
    std::string evaluate() const {return getTypeStr()+":"+getVal()+getExtension();};

private:
    TAttributs _type;
};

class AttributCouleur : public Attribut{
public:

    AttributCouleur(TAttributs type, std::shared_ptr<Couleur> const & coul)
        :Attribut(type), _couleur(coul){}


    std::string getVal() const override {return _couleur->evaluate();};

private:
    std::shared_ptr<Couleur> _couleur;
};

class AttributEntier : public Attribut{
public:
    AttributEntier(TAttributs type, int valeur, std::string const & extension)
        :Attribut(type), _valeur(valeur), _extension(extension){}

    AttributEntier(TAttributs type, int valeur)
        :Attribut(type), _valeur(valeur), _extension(""){}


    std::string getVal() const {return std::to_string(_valeur);};
    std::string getExtension() const {return _extension;};

private:
    int _valeur;
    std::string _extension;
};

class Style : public Variable{
public:
    Style() =default;

    void ajouterAttr(std::shared_ptr<Attribut> attr) {_attributs.push_back(attr);};
    const std::vector<std::shared_ptr<Attribut>> &getAttributs() const { return _attributs;}
    std::string evaluate() const override;

private:
    std::vector<std::shared_ptr<Attribut>> _attributs;
};

