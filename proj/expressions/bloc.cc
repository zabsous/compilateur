#include "bloc.hh"
#include <stdexcept>

std::string Bloc::evaluate(Driver & driver) const {
    return _inner_texte;
};

std::string BlocTitre::evaluate(Driver & driver) const {
    std::string res = "<h";
    res += std::to_string(_hniveau);

    if (getStyle() != nullptr){
        res += getStyle()->evaluate();
    } else {
        try{
            res += driver.getVariable("titre" + std::to_string(_hniveau))->evaluate();
        } catch (const std::out_of_range & err){
            try{
                res += driver.getVariable("page")->evaluate();
            }
            catch (const std::out_of_range &err){}
        }
        
    }

    res += ">" + Bloc::evaluate(driver) + "</h" + std::to_string(_hniveau) + ">\n";

    
    return res;
}

std::string BlocParagraphe::evaluate(Driver & driver) const{
    std::string res = "<p";

    if (getStyle() != nullptr)
    {
        res += getStyle()->evaluate();
    } else{
        try{
            res += driver.getVariable("paragraphe")->evaluate();
        } catch (const std::out_of_range & err){
            try{
                res += driver.getVariable("page")->evaluate();
            }
            catch (const std::out_of_range &err){}
        }
    }

    res += ">" + Bloc::evaluate(driver) + "</p>\n";

    return res;
}

std::string BlocImage::evaluate(Driver & driver) const
{
    std::string res = "<img";

    if (getStyle() != nullptr)
    {
        res += getStyle()->evaluate();
    } else {
        try{
            res += driver.getVariable("page")->evaluate();
        } catch (const std::out_of_range & err){
        }
    }

    res += " src='" + Bloc::evaluate(driver) + "'>\n";

    return res;
}