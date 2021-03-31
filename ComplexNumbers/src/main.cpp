#include <iostream>
#include "ComplexNum.h"
#include "ComplexExp.h"
#include "Database.h"


std::string argErrorHandling(int argc, char **argv);

int main(int argc, char** argv) {

    std::string level = argErrorHandling(argc, argv);
    ComplexNum c1(2,5);
    std::cout << c1.conjugation();
    if (level == "easy")
    {
        Data dataFile("../dat/latwe.dat");
        dataFile.testAllData();
    }else if (level == "hard")
    {
        Data dataFile("../dat/trudne.dat");
        dataFile.testAllData();
    }else{
        throw std::system_error();
    } 
}

std::string argErrorHandling(int argc, char **argv){
    if(argc < 2){
        throw std::invalid_argument("Additional argument required");
    } else if(argc > 2){
        throw std::invalid_argument("Too many arguments");
    }

    std::string level = argv[1];

    if (level != "easy" && level != "hard"){
        throw std::invalid_argument("Unknown difficulty");
    }

    return level;
}