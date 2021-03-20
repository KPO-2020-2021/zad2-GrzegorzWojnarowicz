#include <iostream>
#include "ComplexNum.h"

std::string argErrorHandling(int argc, char **argv);

int main(int argc, char** argv) {

    std::string level = argErrorHandling(argc, argv);

    ComplexNum Complex;
    std::cout << "Give complex number \n";
    std::cin >> Complex;
    std::cout << argv[1] << "; \n" << Complex << std::endl;

}

std::string argErrorHandling(int argc, char **argv){
    if(argc < 2){
        throw std::invalid_argument("Additional argument required");
    } else if(argc > 2){
        throw std::invalid_argument("Too many arguments");
    }

    std::string level = argv[1];

    if (level != "easy" && level != "hard"){
        throw std::invalid_argument("Unknown argument");
    }

    return level;
}