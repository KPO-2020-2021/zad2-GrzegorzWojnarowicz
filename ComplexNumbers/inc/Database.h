#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "ComplexExp.h"


#ifndef Database_DATABASE_H
#define Database_DATABASE_H


class Data {
private:
    std::string filename;
    std::ifstream file;
    int goodAnswers, badAnswers;

public:
    Data(std::string filename);
    ComplexExp loadFromFile();
    void testAllData();

};
#endif //Database_DATABASE_H