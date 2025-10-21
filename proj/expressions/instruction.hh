#pragma once
#include <memory>
#include "driver.hh"

class Instruction {
public :
    Instruction() =default;
    Instruction(const Instruction & I) =default;
    
    virtual std::string evaluate(Driver & driver) const =0;
};

using InstructionPtr = std::shared_ptr<Instruction>;
