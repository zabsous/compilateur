#pragma once
#include <string>
#include "style.hh"
#include <string>
#include <memory>
#include "instruction.hh"
#include "variable.hh"

// un bloc peut être à la fois une instruction mais aussi passé comme variable, d'ou le double héritage
class Bloc : public Instruction, public Variable {
public :
    Bloc()
        :_style(nullptr){}
    Bloc(std::string const & texte)
        :_inner_texte(texte), _style(nullptr){}

    std::string const & getInnerTexte() const {return _inner_texte;};
    void setInnerTexte(std::string const & texte) {_inner_texte = texte.substr(1, texte.size()-2);};

    virtual std::string evaluate(Driver & driver) const override; 
    virtual std::string evaluate() const override {return _inner_texte;}; 
    
    void setStyle(std::shared_ptr<Style> style) {_style = style;};
    std::shared_ptr<Style> getStyle() const {return _style;};
    virtual std::string getContexte() const =0;

private:
    std::string _inner_texte;
    std::shared_ptr<Style> _style;
};

class BlocTitre : public Bloc {
public :
    BlocTitre(unsigned int hniv)
        :_hniveau(hniv){};

    unsigned int getHniveau() const {return _hniveau;};

    std::string evaluate(Driver & driver) const override; 
    std::string getContexte() const override {return "titre" + std::to_string(_hniveau);};
    
private :
    unsigned int _hniveau;
};

class BlocParagraphe : public Bloc {
public :
    BlocParagraphe()=default;

    std::string evaluate(Driver & driver) const override; 
    std::string getContexte() const override {return "paragraphe";};

private :
};

class BlocImage : public Bloc {
public :
    BlocImage()=default;

    std::string evaluate(Driver & driver) const override; 
    std::string getContexte() const override {return "image";};
private :
};
