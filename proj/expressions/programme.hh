#pragma once
#include <vector>
#include "programme.hh"
#include "instruction.hh"
#include "selecteurModifier.hh"

class Programme {
public:
    std::vector<InstructionPtr> const & getInstruction() const {return _instructions;};
    // std::vector<std::shared_ptr<SelecteurModifier>> const & getSelecteurs() const {return _selecteurs;};
    void ajouter(InstructionPtr i) {_instructions.push_back(i);};
    // void ajouter(std::shared_ptr<SelecteurModifier> s) {_selecteurs.push_back(s);};

    void eval(Driver & driver) ;

private:
    std::vector<InstructionPtr> _instructions;
    // std::vector<std::shared_ptr<SelecteurModifier>> _selecteurs;
};