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


bool operator==(const ComplexExp ComExp1, const ComplexExp ComExp2) {
    if ((ComExp1.Com1 == ComExp2.Com1) && (ComExp1.Com2 == ComExp2.Com2) && (ComExp1.op == ComExp2.op)){
        return true;
    }else{
        return false;
    }

}

std::istream &operator>>(std::istream &ist, ComplexExp &ComExp) {

    
    try
    {
        ist >> ComExp.Com1;
    }
    catch(const std::exception& e)
    {
        ist >> ComExp.op;
        ist >> ComExp.Com2;
        std::cerr << e.what() << '\n';
        return ist;
    }
    
    
    try
    {
        ist >> ComExp.op;
    }
    catch(const std::exception& e)
    {
        ist >> ComExp.Com2;
        std::cerr << e.what() << '\n';
        return ist;
    }

    try
    {
        ist >> ComExp.Com2;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return ist;
    }
    
    
    if (ComExp.op != '+' && ComExp.op != '-' && ComExp.op != '/' && ComExp.op != '*'){
        throw std::invalid_argument("invalid argument in operator of Complex Expression");
    }
   
    return ist;
}

std::ostream &operator<<(std::ostream &ost, const ComplexExp &comExp) {

    ost << comExp.Com1;
    if(ost.fail()){
        throw std::system_error();
    }
    ost << " ";
    ost << comExp.op;
    ost << " ";
    if(ost.fail()){
        throw std::system_error();
    }
    ost << comExp.Com2;
    if(ost.fail()){
        throw std::system_error();
    }
    return ost;
}

ComplexNum ComplexExp::calculateResult() {

    if (this -> op == '+'){
        this -> result = (this ->Com1) + (this -> Com2);
    }else if (this -> op == '-'){
        this -> result = (this -> Com1) - (this -> Com2);
    }else if (this -> op == '*'){
        this -> result = (this -> Com1) * (this -> Com2);
    } else if (this -> op == '/'){
        if ((this -> Com2) == ComplexNum(0,0))
        {
            throw std::invalid_argument("Division zero");
        }else{
            this -> result = (this -> Com1) / (this -> Com2);
        }
        
        
    }else{
        throw std::invalid_argument("Unknown operator");
    }
    return this -> result;
}

