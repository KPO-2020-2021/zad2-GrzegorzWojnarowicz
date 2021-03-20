#include <iostream>

#ifndef COMPLEXNUM_COMPLEXNUM_H
#define COMPLEXNUM_COMPLEXNUM_H
const double MIN_THRESHOLD = 0.01;

class ComplexNum {
private:
    double Real;
    double Imag;
public:
    ComplexNum();
    ComplexNum(double Real, double Imag = 0);
    
    ComplexNum operator+ (const ComplexNum &complexObject);
    ComplexNum operator- (const ComplexNum &complexObject);
    ComplexNum operator* (const ComplexNum &complexObject);
    ComplexNum operator/ (const ComplexNum &complexObject);
    friend bool operator==(const ComplexNum &complexObject1, const ComplexNum &complexObject2);
    friend std::ostream & operator<<(std::ostream &ost, const ComplexNum &complexObject);
    friend std::istream & operator>>(std::istream &ist, ComplexNum &complexObject);

    void setReal(double Real);
    void setImag(double Imag);
    double getReal();
    double getImag();
};

#endif //COMPLEXNUM_COMPLEXNUMS_H