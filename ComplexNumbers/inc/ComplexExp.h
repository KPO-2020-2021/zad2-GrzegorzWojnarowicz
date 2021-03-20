#include <iostream>
#include "ComplexNum.h"

#ifndef ComplexNum_COMPLEXEXP_H
#define ComplexNum_COMPLEXEXP_H


class ComplexExp {
private:
    ComplexNum Com1;
    ComplexNum Com2;
    char op;
    ComplexNum result;

    void calculateResult();

public:
    ComplexExp();
    ComplexExp(ComplexNum Com1, ComplexNum Com2, char oper);

    friend std::ostream & operator<<(std::ostream & ost, const ComplexExp &ComExp);
    friend std::istream & operator>>(std::istream & ist, ComplexExp &ComExp);
    friend bool operator==(const ComplexExp &ComExp1, const ComplexExp &ComExp2);


    void setCom1(ComplexNum C);
    void setCom2(ComplexNum C);
    void setOp(char op);
    void setResult(ComplexNum C);
    ComplexNum getResult();

};
#endif //ComplexNum_COMPLEXEXP_H