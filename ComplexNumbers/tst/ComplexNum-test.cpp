#include "gtest/gtest.h"
#include "ComplexNum.h"
#include <iostream>

TEST(testSubtract, test1)
{
    ComplexNum c1(1,1);
    ComplexNum c2(3,4);
    EXPECT_EQ (c1 - c2, ComplexNum(-2,-3));
}

TEST(testAdd, test2)
{
    ComplexNum c1(1,1);
    ComplexNum c2(3,4);
    EXPECT_EQ (c1 + c2, ComplexNum(4,5));
}

TEST(testComplex, test3)
{
    ComplexNum c1(1,1);
    EXPECT_EQ (c1, ComplexNum(1,1));
}

TEST(testEmptyComplex, test4)
{
    ComplexNum c1;
    EXPECT_EQ (c1, ComplexNum(0,0));
}

TEST(testMultiplicationByConst, test5)
{
    ComplexNum c1(10,10);
    ComplexNum result;
    result = (ComplexNum)10 * c1;
    EXPECT_EQ (result, ComplexNum(100,100));
}

TEST(testMultiplicationByComplexNum, test6)
{
    ComplexNum c1(10,10);
    ComplexNum c2(2,1);
    EXPECT_EQ (c1 * c2, ComplexNum(10,30));
}

TEST(testDivisionByConst, test7)
{
    ComplexNum c1(10,10);
    ComplexNum result;
    result = c1 / (ComplexNum)10;
    EXPECT_EQ (result, ComplexNum(1,1));
}

TEST(testDivisionByComplexNum, test8)
{
    ComplexNum c1(4,6);
    ComplexNum c2(1,-5);
    EXPECT_EQ (c1 / c2, ComplexNum(-1,1));
}

TEST(testDivisionByZero, test9)
{
    ComplexNum c1(4,4);
    ComplexNum c2(0,0);
    EXPECT_THROW(c1/c2, std::exception);
}

TEST(testPrintingComplexNum, test10)
{
    ComplexNum c1(4,4);
    ComplexNum c2(0,-4);
    ComplexNum c3(4,0);
    std::stringstream sts;
    sts << c1;
    EXPECT_EQ ("(4+4i)", sts.str());

    sts = std::stringstream();
    sts << c2;
    EXPECT_EQ ("(-4i)", sts.str());

    sts = std::stringstream();
    sts << c3;
    EXPECT_EQ ("(4)", sts.str());
}

TEST(testGetingComplexNum, test11)
{
    ComplexNum c1;
    std::stringstream ist;

    ist << "(4+4.67i)";
    ist >> c1;
    EXPECT_EQ (c1, ComplexNum(4,4.67));
    ist = std::stringstream();

    ist << "(0-4i)";
    ist >> c1;
    EXPECT_EQ (c1, ComplexNum(0,-4));
    ist = std::stringstream();
    
    ist << "(420.12345+0i)";
    ist >> c1;
    EXPECT_EQ (c1, ComplexNum(420.12345,0));
    ist = std::stringstream();


    ist = std::stringstream();
    ist << "(420+0.i)";
    ist >> c1;
    EXPECT_EQ(c1, ComplexNum(420,0));
    ist = std::stringstream();
}

TEST(testErrorThrows, test12)
{
    ComplexNum c1;
    std::stringstream ist;

    ist = std::stringstream();
    ist << "420.12345+0i";
    EXPECT_THROW(ist >> c1, std::exception);

    ist = std::stringstream();
    ist << "(42+0i";
    EXPECT_THROW(ist >> c1, std::exception);

    ist = std::stringstream();
    ist << "42+0i)";
    EXPECT_THROW(ist >> c1, std::exception);

    ist = std::stringstream();
    ist << "(42g0i)";
    EXPECT_THROW(ist >> c1, std::exception);

    ist = std::stringstream();
    ist << "(t + 4i)";
    EXPECT_THROW(ist >> c1, std::exception);

    ist = std::stringstream();
    ist << "(420+0.0)";
    EXPECT_THROW(ist >> c1, std::exception);

}

TEST (testShowInformationAboutComplexNum, test13) {
    ComplexNum z1(2, 5);
    ComplexNum z2(0, -3);
    ComplexNum z3(-5, 0);
    ComplexNum z4(0, -1);
    ComplexNum z5(3, 1);
    ComplexNum z6(0, 1);
    ComplexNum z7(10, -7);
    std::stringstream os;

    os << z1;
    ASSERT_EQ("(2+5i)", os.str());

    os = std::stringstream();
    os << z2;
    ASSERT_EQ("(-3i)", os.str());

    os = std::stringstream();
    os << z3;
    ASSERT_EQ("(-5)", os.str());

    os = std::stringstream();
    os << z4;
    ASSERT_EQ("(-i)", os.str());

    os = std::stringstream();
    os << z5;
    ASSERT_EQ("(3+i)", os.str());

    os = std::stringstream();
    os << z6;
    ASSERT_EQ("(i)", os.str());

    os = std::stringstream();
    os << z7;
    ASSERT_EQ("(10-7i)", os.str());
}

TEST (testGetComplexFromCin, test14) {
    ComplexNum z1;
    std::stringstream is;

    is << "(51+55.2i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNum(51, 55.2));
    is = std::stringstream();

    is << "(10-5i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNum(10, -5));
    is = std::stringstream();


    is << "(-3-1i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNum(-3, -1));
    is = std::stringstream();


    is << "(0-1i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNum(0, -1));
    is = std::stringstream();


    is << "(1.5+0i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNum(1.5, 0));
    is = std::stringstream();
}

TEST (testShorterVersionComplex, test15) {
    ComplexNum z1;
    std::stringstream is;

    is << "(i)";
    is >> z1;
    ASSERT_EQ(z1, ComplexNum(0, 1));
    z1 = ComplexNum();
    is = std::stringstream();


    is << "(-i)";
    is >> z1;
    ASSERT_EQ(z1, ComplexNum(0, -1));
    is = std::stringstream();
    z1 = ComplexNum();

    is << "(2i)";
    is >> z1;
    ASSERT_EQ(z1, ComplexNum(0, 2));
    is = std::stringstream();
    z1 = ComplexNum();

    is << "(2)";
    is >> z1;
    ASSERT_EQ(z1, ComplexNum(2, 0));
    is = std::stringstream();
    z1 = ComplexNum();

    is << "(-4i)";
    is >> z1;
    EXPECT_EQ(z1, ComplexNum(0, -4));
    is = std::stringstream();
    z1 = ComplexNum();

    is << "(3-i)";
    is >> z1;
    EXPECT_EQ(z1, ComplexNum(3, -1));
    is = std::stringstream();
    z1 = ComplexNum();
}

TEST (testUnfamiliarSyntaxErrorComplex, test16) {
    ComplexNum z1;
    std::stringstream is;

    is << "5+6i)";
    EXPECT_THROW(is >> z1, std::exception);
    is = std::stringstream();

    is << "(5+6i";
    EXPECT_THROW(is >> z1, std::exception);
    is = std::stringstream();

    is << "(5+6";
    EXPECT_THROW(is >> z1, std::exception);
    is = std::stringstream();

    is << "(5+6)";
    EXPECT_THROW(is >> z1, std::exception);
    is = std::stringstream();

    is << "(5%6i";
    EXPECT_THROW(is >> z1, std::exception);
    is = std::stringstream();

    is << "(a+6i)";
    EXPECT_THROW(is >> z1, std::exception);
    is = std::stringstream();
}

TEST (testEqualityCompareComplex, test17) {
    ComplexNum z1 = ComplexNum(2,5);
    ComplexNum z2 = ComplexNum(2.000111,5.0004234);

    
    ASSERT_EQ(z1, z2);
}


TEST (testConjugation, test18) {
    ComplexNum z1 = ComplexNum(2,5);
    ComplexNum z2 = z1.conjugation();

    
    ASSERT_EQ(z2, ComplexNum(2,-5));
}

TEST (testModulus, test19) {
    ComplexNum z1 = ComplexNum(3,4);
    double modulus = z1.modulus();

    
    ASSERT_EQ(modulus, 5);
}