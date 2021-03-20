#include "ComplexNum.h"


ComplexNum::ComplexNum() {
    this -> Real = 0;
    this -> Imag = 0;
}

ComplexNum::ComplexNum(double Real, double Imag) {
    this -> Real = Real;
    this -> Imag = Imag;
}

void ComplexNum::setReal(double Real) {
    this -> Real = Real;
}

void ComplexNum::setImag(double Imag) {
    this ->Imag = Imag;
}

double ComplexNum::getReal() {
    return (this -> Real);
}

double ComplexNum::getImag() {
    return (this -> Imag);
}

ComplexNum ComplexNum::operator+ (const ComplexNum &complexObject) {
    ComplexNum result;
    result.setReal(Real + complexObject.Real);
    result.setImag(Imag + complexObject.Imag);
    return result;
}

ComplexNum ComplexNum::operator- (const ComplexNum &complexObject) {
    ComplexNum result;
    result.setReal(Real - complexObject.Real);
    result.setImag(Imag - complexObject.Imag);
    return result;
}

bool operator==(const ComplexNum &complexObject1, const ComplexNum &complexObject2) {

    if(std::abs((complexObject1.Real - complexObject2.Real) < MIN_THRESHOLD) &&
        (std::abs(complexObject1.Imag - complexObject2.Imag) < MIN_THRESHOLD)){
        return true;
    }else{
        return false;
    }
}

ComplexNum ComplexNum::operator*(const ComplexNum &complexObject) {
    ComplexNum result;
    result.setReal(Real * complexObject.Real - Imag * complexObject.Imag);
    result.setImag(Real * complexObject.Imag + Imag * complexObject.Real);
    return result;
}

ComplexNum ComplexNum::operator/(const ComplexNum &complexObject) {
    ComplexNum result;
    if(complexObject.Imag == 0 && complexObject.Real == 0){
        throw std::invalid_argument("zero division");
    }else {

        result.setReal((Real * complexObject.Real + Imag * complexObject.Imag) /
                       (complexObject.Real * complexObject.Real + complexObject.Imag * complexObject.Imag));
        result.setImag((-1 * Real * complexObject.Imag + Imag * complexObject.Real) /
                            (complexObject.Real * complexObject.Real +
                             complexObject.Imag * complexObject.Imag));
    }
    return result;
}

std::ostream &operator<<(std::ostream &ost, const ComplexNum &complexObject) {

    if(complexObject.Real == 0){
        if(complexObject.Imag == 1){
            ost << "(i)";
        } else if(complexObject.Imag == -1){
            ost <<"(-i)";
        }else{
            ost << "(" << complexObject.Imag << "i)";
        }

    }else{
        if(complexObject.Imag < 0 && complexObject.Imag != 1 && complexObject.Imag != -1){
            ost << "(" << complexObject.Real << complexObject.Imag << "i)";
        }else if(complexObject.Imag > 0 && complexObject.Imag != 1 && complexObject.Imag != -1){
            ost << "(" << complexObject.Real << "+" << complexObject.Imag << "i)";
        }else if(complexObject.Imag == 0){
            ost << "(" << complexObject.Real << ")";
        }else if(complexObject.Imag == 1){
            ost << "(" << complexObject.Real << "+" << "i" << ")";
        }else if(complexObject.Imag == -1){
            ost << "(" << complexObject.Real << "-" << "i" << ")";
        }
    }

    return ost;
}

std::istream &operator>>(std::istream &ist, ComplexNum &complexObject) {

    double real, Imag;
    char op, i, brackets, temp;

    if(ist.peek() != '('){
        throw std::invalid_argument("unknown argument1");
    }
    ist >> brackets ;
    if(ist.peek() == 'i'){ /* (-i)  (i) type */
        ist >> i;
        if (ist.peek() == ')'){
            ist >> temp;
            complexObject.Real = 0;
            complexObject.Imag = 1;
            return ist;
        }else{
            throw std::invalid_argument("unknown argument2");
        }

    }else if(ist.peek() == '-'){
        ist >> i;
        if(ist.peek() == 'i'){
            ist >> i;
            if(ist.peek() == ')'){
                ist >> temp;
                complexObject.Real = 0;
                complexObject.Imag = -1;
                return ist;
            }else{
                throw std::invalid_argument("unknown argument3");
            }
        }else{
            ist.putback(i);
        }
    }
    ist >> real;
    if(ist.peek() != '-' && ist.peek() != '+'){     /* type of (x) */
        if(ist.peek() == ')'){
            ist >> temp;
            complexObject.Real = real;
            complexObject.Imag = 0;
            return ist;
        }
        if(ist.peek() == 'i'){      /* type of (xi) */
            ist >> i;
            if(ist.peek() == ')'){
                ist >> temp;
                complexObject.Real = 0;
                complexObject.Imag = real;
                return ist;
            }
        }
        throw std::invalid_argument("unknown argument4");
    }
    ist >> op;
    if(ist.peek() == 'i') { /* type of (x+i) or (x-i)  */
        ist >> i;
        if (ist.peek() == ')') {
            ist >> temp;
            complexObject.Real = real;
            if(op == '-'){
                complexObject.Imag = -1;
            }else if(op == '+'){
                complexObject.Imag = 1;
            }
            return ist;
        } else {
            throw std::invalid_argument("unknown argument5");

        }
    }
    ist >> Imag;
    if(ist.peek() != 'i'){
        throw std::invalid_argument("unknown argument6");
    }
    ist >> i;
    if(ist.peek() != ')'){
        throw std::invalid_argument("unknown argument7");
    }
    ist >> temp;


    if(op == '-'){
        complexObject.Real = real;
        complexObject.Imag = Imag * (-1);
    }else{
        complexObject.Real = real;
        complexObject.Imag = Imag;
    }

    return ist;
}