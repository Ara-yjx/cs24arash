// FILE: express.h
// CLASS PROVIDED: ExpressionTree
//   This class provides only NONEMPTY expression trees 
//   from Project 1 of Chapter 10 in first edition of 
//   "Data Structures and Other Objects Using C++".
//   This current version just slightly modified for CS 24
//   by cmc, 11/17/2016.
//
// CONSTRUCTORS for the ExpressionTree class:
//   ExpressionTree(double value = 0.0)
//     Postcondition: The ExpressionTree has one leaf node with the specified
//     value. The default argument is 0.0.
//
// CONST Member Functions for the ExpressionTree class:
//   double evaluate( ) const
//     Postcondition: The return value is the value of the expression tree.
//
//   void printPre() const;
//     Postcondition: The expression is printed in prefix form to standard output.
//
//   void printPost() const;
//     Postcondition: The expression is printed in postfix form to standard output.
//
//   void printIn() const;
//     Postcondition: The expression is printed in infix form to standard output,
//     with add operations enclosed in parentheses.
//
// NONMEMBER FUNCTIONS for the ExpressionTree class:
//   ExpressionTree operator +(const ExpressionTree& e1, const ExpressionTree& e2)
//     Postcondition: The ExpressionTree returned has '+' at the root, e1 as the
//     left subtree, and e2 as the right subtree.
//
//   ExpressionTree operator *(const ExpressionTree& e1, const ExpressionTree& e2)
//     Postcondition: The ExpressionTree returned has '*' at the root, e1 as the
//     left subtree, and e2 as the right subtree.
//
// VALUE SEMANTICS for the ExpressionTree class:
//    Assignments and the copy constructor may be used with ExpressionTree
//    objects.

#ifndef EXPRESS_H 
#define EXPRESS_H

#include <cstdlib> // Provides NULL

class ExpressionTree
{
public:
    // CONSTRUCTORS and DESTRUCTOR
    ExpressionTree(double value = 0.0);
    ExpressionTree(const ExpressionTree& source);
    ~ExpressionTree( );
    // ASSIGNMENT OPERATOR
    ExpressionTree& operator =(const ExpressionTree& source);
    // CONSTANT MEMBER FUNCTIONS
    double evaluate( ) const;
    void printPre() const;
    void printPost() const;
    void printIn() const;
    // NONMEMBER FUNCTIONS FOR BUILDING BIGGER EXPRESSION TREES:
    friend
    ExpressionTree operator +(const ExpressionTree& e1, const ExpressionTree& e2);
    friend
    ExpressionTree operator *(const ExpressionTree& e1, const ExpressionTree& e2);
    
private:
    double data;            // Used for leaf nodes only.
    char operation;         // Used for non-leaf nodes only.
    ExpressionTree *left;   // Will be NULL for a leaf.
    ExpressionTree *right;  // Will be NULL for a leaf.
};
 
#endif
