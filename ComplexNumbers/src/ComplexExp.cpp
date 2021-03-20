#include "ComplexExp.h"


ComplexExp::ComplexExp() {
    this -> Com1 = ComplexNum();
    this -> Com2 = ComplexNum();
    this -> op = '+';
}

ComplexExp::ComplexExp(ComplexNum Com1, ComplexNum Com2, char op) {
    this -> Com1 = Com1;
    this -> Com2 = Com2;
    this -> op = op;
    calculateResult();
}

void ComplexExp::setCom1(ComplexNum C) {
    this -> Com1 = C;
}

void ComplexExp::setCom2(ComplexNum C) {
    this -> Com2 = C;
}

void ComplexExp::setOp(char op) {
    this -> op = op;
}

void ComplexExp::setResult(ComplexNum C) {
    this -> result = C;
}

bool operator==(const ComplexExp &ComExp1, const ComplexExp &ComExp2) {
    if (ComExp1.Com1 == ComExp2.Com1 && ComExp1.Com2 == ComExp2.Com2 && ComExp1.op == ComExp2.op){
        return true;
    }else{
        return false;
    }

}

std::istream &operator>>(std::istream &ist, ComplexExp &ComExp) {

    char tmp;

    ist >> ComExp.Com1;
    if (ist.fail()){
        throw std::invalid_argument("invalid argument");
    }
    tmp = ist.peek();
    if (tmp != '+' && tmp != '-' && tmp != '/' && tmp != '*'){
        throw std::invalid_argument("invalid argument");
    }
    ist >> ComExp.op;
    if (ist.fail()){
        throw std::invalid_argument("invalid argument");
    }
    ist >> ComExp.Com2;
    if (ist.fail()){
        throw std::invalid_argument("invalid argument");
    }
    return ist;
}

std::ostream &operator<<(std::ostream &ost, const ComplexExp &comExp) {

    ost << comExp.Com1;
    if(ost.fail()){
        throw std::system_error();
    }
    ost << comExp.op;
    if(ost.fail()){
        throw std::system_error();
    }
    ost << comExp.Com2;
    if(ost.fail()){
        throw std::system_error();
    }
    return ost;
}

void ComplexExp::calculateResult() {

    if (this -> op == '+'){
        this -> result = (this ->Com1) + (this -> Com2);
    }else if (this -> op == '-'){
        this -> result = (this -> Com1) - (this -> Com2);
    }else if (this -> op == '*'){
        this -> result = (this -> Com1) * (this -> Com2);
    } else if (this -> op == '/'){
        this -> result = (this -> Com1) / (this -> Com2);
    }else{
        throw std::invalid_argument("unknown operator");
    }
}

ComplexNum ComplexExp::getResult() {
    return this -> result;
}