#pragma once
#include <memory>
#include "contexte.hh"
#include "instruction.hh"

class Expression : public Instruction {
public:
};

using ExpressionPtr = std::shared_ptr<Expression>;

