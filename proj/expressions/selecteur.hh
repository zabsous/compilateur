#pragma once
#include "variable.hh"
#include "instruction.hh"
#include "bloc.hh"
#include <vector>

class Selecteur : public Variable{
public:
    Selecteur(int id, std::vector<InstructionPtr> const & instr)
        :_id(id), _instructions(instr){}
    
    int getId() const {return _id;};
    void setId(int id) {_id = id;};

    std::vector<InstructionPtr> const & getInstructions() const {return _instructions;};

    virtual std::shared_ptr<Bloc> bloc() const =0;

private:
    int _id;
    std::vector<InstructionPtr> _instructions;
};

class SelecteurParagraphe : public Selecteur{
public:
    SelecteurParagraphe(int id, std::vector<InstructionPtr> const & instr)
        :Selecteur(id, instr){}

    virtual std::string evaluate() const override;

    std::shared_ptr<Bloc> bloc() const;
};

class SelecteurTitre : public Selecteur{
public:
    SelecteurTitre(int id, std::vector<InstructionPtr> const & instr, int hniveau)
        :Selecteur(id, instr), _hniveau(hniveau){}

    virtual std::string evaluate() const override;

    std::shared_ptr<Bloc> bloc() const;

private:
    unsigned int _hniveau;
};

class SelecteurImage : public Selecteur{
public:
    SelecteurImage(int id, std::vector<InstructionPtr> const & instr)
        :Selecteur(id, instr){}

    virtual std::string evaluate() const override;

    std::shared_ptr<Bloc> bloc() const;
};

