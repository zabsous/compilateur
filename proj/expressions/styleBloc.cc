#include "styleBloc.hh"

std::string StyleBloc::evaluate(Driver & driver) const {
    driver.setVariable(_nomBloc, _style);
    return "";
}