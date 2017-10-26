#include <cstdlib>   // Provides NULL
#include <iostream>  // Provides ostream
#include "poly2.h"

namespace main_savitch_5
{

  void polynomial::set_recent(unsigned int exponent) const { 
    if (exponent > current_degree) {
      cout << "ERROR: void set_recent(unsigned int exponent)" << endl 
          << "exponent = " << exponent <<" | " << "current_degree = " << current_degree << endl;
      exit(-1);
    }
    polynode* result = head; 
    while(result->exponent()!=exponent) result = result->fore();
    return result;
  }

  
    
  polynomial::polynomial(double c, unsigned int exponent){}
  polynomial::polynomial(const polynomial& source){}
  polynomial::~polynomial( ){}

  // MODIFICATION MEMBER FUNCTIONS
  polynomial& polynomial::operator =(const polynomial& source) {return *this;}
  void polynomial::add_to_coef(double amount, unsigned int exponent) {}
  void polynomial::assign_coef(double coefficient, unsigned int exponent) {}
  void polynomial::clear( ) {}
  
  // CONSTANT MEMBER FUNCTIONS
  double polynomial::coefficient(unsigned int exponent) const {return 0;}
  
  //unsigned int polynomial::degree( ) const { return current_degree; }
  
  polynomial polynomial::derivative( ) const {return *this;}
  double polynomial::eval(double x) const {return 0;}
  void polynomial::find_root(
      double& answer,
      bool& success,
      unsigned int& iterations,
      double guess,
      unsigned int maximum_iterations,
      double epsilon
      ) const {return;}
  unsigned int polynomial::next_term(unsigned int e) const {return 0;}
  unsigned int polynomial::previous_term(unsigned int e) const {return 0;}
  
  // CONSTANT OPERATORS
  //double polynomial::operator( ) (double x) const { return eval(x); }


  
  // NON-MEMBER BINARY OPERATORS
  polynomial operator +(const polynomial& p1, const polynomial& p2) {
    return p1;
  }
  polynomial operator -(const polynomial& p1, const polynomial& p2) {
    return p1;
  } 
  polynomial operator *(const polynomial& p1, const polynomial& p2) {
    return p1;
  }
  
  // NON-MEMBER OUTPUT FUNCTION
  std::ostream& operator << (std::ostream& out, const polynomial& p) {
    return out;
  }

}