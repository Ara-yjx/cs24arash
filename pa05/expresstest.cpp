// expresstest.cpp - tests express.cpp functions

#include <iostream>
#include "express.h"
using namespace std;

void test1() {
    cout << "test1: basic constructor and evaluate simple\n";
    double x;
    cout << "enter one double value\n";
    cin >> x;
    ExpressionTree e(x);
    cout << "value of expression = " << e.evaluate() << endl;
}

void test2() {
    cout << "test2: construct and evaluate x + y\n";
    double x, y;
    cout << "enter two double values, x then y\n";
    cin >> x >> y;
    ExpressionTree e1(x), e2(y), sum = e1 + e2;
    cout << "x + y = " << sum.evaluate() << endl;
}

void test3() {
    cout << "test3: construct and evaluate x * y\n";
    double x, y;
    cout << "enter two double values, x then y\n";
    cin >> x >> y;
    ExpressionTree e1(x), e2(y), product = e1 * e2;
    cout << "x * y = " << product.evaluate() << endl;
}

ExpressionTree buildComplex() {
    double x, y, z;
    cout << "enter three double values, x, then y, then z\n";
    cin >> x >> y >> z;
    ExpressionTree ex(x), ey(y), ez(z), e2(2),
        yz = ey * ez,
        y2 = e2 * ey,
        sum1 = ex + yz,
        full = sum1 + y2;
    return full;
}

void test4() {
    cout << "test4: construct and evaluate more complex\n";
    ExpressionTree e = buildComplex();
    cout << "x + y * z + 2 * y = " << e.evaluate() << endl;
}

void print3ways(const ExpressionTree &e) {
    cout << "pre-order: ";
    e.printPre();
    cout << "\npost-order: ";
    e.printPost();
    cout << "\nin-order: ";
    e.printIn();
    cout << endl;
}

void test5() {
    cout << "test5: print simple multiply three ways\n";
    double x, y;
    cout << "enter two double values, x then y\n";
    cin >> x >> y;
    ExpressionTree e1(x), e2(y), product = e1 * e2;
    print3ways(product);
}

void test6() {
    cout << "test6: print simple add three ways\n";
    double x, y;
    cout << "enter two double values, x then y\n";
    cin >> x >> y;
    ExpressionTree e1(x), e2(y), sum = e1 + e2;
    print3ways(sum);
}

void test7() {
    cout << "test7: print complex expression three ways\n";
    ExpressionTree e = buildComplex();
    print3ways(e);
}

void printOriginalAndCopy(ExpressionTree &original,
                          ExpressionTree &copy) {
    cout << "original in pre-order: ";
    original.printPre();
    cout << "\n    copy in pre-order: ";
    copy.printPre();
    cout << endl;
}

void test8() {
    cout << "test8: copy constructor\n";
    ExpressionTree o = buildComplex();
    ExpressionTree c(o);
    printOriginalAndCopy(o, c);
    ExpressionTree mult(10);
    o = o * mult;
    cout << "after multiplying original by 10 -\n";
    printOriginalAndCopy(o, c);
}

void test9() {
    cout << "test9: assignment operator\n";
    ExpressionTree o = buildComplex();
    ExpressionTree c;
    c = o;
    printOriginalAndCopy(o, c);
    ExpressionTree mult(10);
    o = o * mult;
    cout << "after multiplying original by 10 -\n";
    printOriginalAndCopy(o, c);
}

// executes one test based on user input
int main() {
    typedef void (*testfunc)();
    testfunc tests[] =  // array of function pointers
    {   test1, test2, test3, test4, test5,
        test6, test7, test8, test9};
    
    int testnum;
    cout << "enter test number (1..9):\n";
    cin >> testnum;
    if (testnum > 0 && testnum < 10)
        tests[testnum-1]();
    
    return 0;
}
