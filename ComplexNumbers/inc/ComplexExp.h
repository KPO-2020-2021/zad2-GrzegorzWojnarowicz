#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include "ComplexNum.h"


#ifndef ComplexNum_COMPLEXEXP_H
#define ComplexNum_COMPLEXEXP_H


class ComplexExp {
private:
    ComplexNum Com1;
    ComplexNum Com2;
    char op;
    ComplexNum result;

    

public:
    ComplexExp();
    ComplexExp(ComplexNum Com1, ComplexNum Com2, char oper);

    friend std::ostream & operator<<(std::ostream & ost, const ComplexExp &ComExp);
    friend std::istream & operator>>(std::istream & ist, ComplexExp &ComExp);   
    friend bool operator==(const ComplexExp ComExp1, const ComplexExp ComExp2);

    ComplexNum calculateResult();
    void loadFromFile(std::ifstream & ifst, ComplexExp &ComExp);
    void setCom1(ComplexNum C);
    void setCom2(ComplexNum C);
    void setOp(char op);

};
#endif //ComplexNum_COMPLEXEXP_H