#include "parser.hpp"
#include "scanner.hh"
#include "driver.hh"

#include <iostream>
#include <fstream>

#include <cstring>

#include "programme.hh"
#include "bloc.hh"


int main( int  argc, char* argv[]) {
    Driver * driver = new Driver;
    Scanner * scanner = new Scanner(std::cin, std::cout);
    Programme p;
    yy::Parser * parser = new yy::Parser(*scanner, *driver, p);

    parser->parse();

    std::cout << std::endl << std::endl << "---------------------------------------------------------" << std::endl << std::endl;

    p.eval(*driver);

    return 0;
}
