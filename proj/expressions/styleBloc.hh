#include "instruction.hh"
#include "style.hh"
#include "variable.hh"

// style bloc est une instruction qui défini un style pour un type de bloc
class StyleBloc : public Instruction{
public:
    StyleBloc(std::string const & nomBloc, std::shared_ptr<Style> style)
        :_nomBloc(nomBloc), _style(style){}

    std::string evaluate(Driver & driver) const override;

private:
    std::string _nomBloc;
    std::shared_ptr<Style> _style;
};
