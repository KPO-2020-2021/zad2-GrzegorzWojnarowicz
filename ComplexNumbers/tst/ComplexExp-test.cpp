#include "gtest/gtest.h"
#include "ComplexExp.h"
#include <iostream>

TEST(testComplexExp, testExp1)
{
    ComplexNum c1(1,1);
    ComplexNum c2(2,3);
    ComplexExp c3(c1, c2, '+');
    EXPECT_EQ (c3, ComplexExp(ComplexNum(1,1), ComplexNum(2,3), '+'));

    ComplexExp c4;
    EXPECT_EQ (c4, ComplexExp(ComplexNum(0,0), ComplexNum(0,0), '+'));

    ComplexNum c5(1,1);
    ComplexNum c6(3,3);
    ComplexExp c7(c5, c6, '-');
    EXPECT_EQ (c7, ComplexExp(ComplexNum(1,1), ComplexNum(3,3), '-'));

    ComplexNum c11(1,1);
    ComplexNum c22(5,4);
    ComplexExp c33(c11, c22, '*');
    EXPECT_EQ (c33, ComplexExp(ComplexNum(1,1), ComplexNum(5,4), '*'));

    ComplexNum c55(1,1);
    ComplexNum c66(7,5);
    ComplexExp c77(c55, c66, '/');
    EXPECT_EQ (c77, ComplexExp(ComplexNum(1,1), ComplexNum(7,5), '/'));
}

TEST(testExpEquality, testExp2)
{
    ComplexNum c1(1,1);
    ComplexNum c2(2,3);
    ComplexExp c3(c1, c2, '+');
    ComplexExp c4(c1, c2, '+');
    EXPECT_EQ (true, (c3==c4));
}

TEST(testGettingComExp, testExp3)
{
    ComplexExp c1;
    std::stringstream sst;
    sst << "(4-4i) - (5+4i)";
    sst >> c1;
    EXPECT_EQ (c1, ComplexExp(ComplexNum(4,-4), ComplexNum(5,4), '-'));
}

TEST(testPrintingComExp, testExp4)
{
    ComplexExp c1(ComplexNum(4,-4), ComplexNum(5,4), '-');
    std::stringstream sst;
    sst << c1;
    EXPECT_EQ ("(4-4i) - (5+4i)", sst.str());
}

TEST(testCalculateAdd, testExp5)
{
    ComplexExp c1(ComplexNum(4,-4), ComplexNum(5,4), '+');
    ComplexNum c2 = c1.calculateResult();
    EXPECT_EQ (ComplexNum(9,0), c2);
}

TEST(testCalculateSubtract, testExp6)
{
    ComplexExp c1(ComplexNum(4,-4), ComplexNum(5,4), '-');
    ComplexNum c2 = c1.calculateResult();
    EXPECT_EQ (ComplexNum(-1,-8), c2);
}

TEST(testCalculateMultiplication, testExp7)
{
    ComplexExp c1(ComplexNum(4,-4), ComplexNum(5,4), '*');
    ComplexNum c2 = c1.calculateResult();
    EXPECT_EQ (ComplexNum(36,-4), c2);
}

TEST(testCalculateDivision, testExp8)
{
    ComplexExp c1(ComplexNum(4,4), ComplexNum(2,2), '/');
    ComplexNum c2 = c1.calculateResult();
    EXPECT_EQ (ComplexNum(2,0), c2);
}

TEST(testCalculateDivisionZeroZero, testExp9)
{
    ComplexExp c1 = ComplexExp(ComplexNum(4,4), ComplexNum(0,0), '/');
    EXPECT_THROW(c1.calculateResult(), std::exception);
}

TEST(testCalculateWrongOper, testExp10)
{
    ComplexExp c1 = ComplexExp(ComplexNum(4,4), ComplexNum(0,0), ':');
    EXPECT_THROW(c1.calculateResult(), std::exception);
}



// double arg(LZespolona z); // wyswietlanie głównego argumentu liczby zespolonej; konieczny atan2
// LZespolona operator += (LZespolona &Arg1, LZespolona const &Arg2); // + testy (takie same, jak dla +)
// LZespolona operator /= (LZespolona &Arg1, LZespolona const &Arg2); // + testy (takie same, jak dla /)
