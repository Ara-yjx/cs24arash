#include <cstdlib>   // Provides NULL
#include <iostream>  // Provides ostream
#include "poly2.h"

using std::cout;
using std::endl;


namespace main_savitch_5
{

  void polynomial::set_recent(unsigned int exponent) const { 
    if (exponent > current_degree) {
      cout << "ERROR: void set_recent(unsigned int exponent)" << endl 
          << "exponent = " << exponent <<" | " << "current_degree = " << current_degree << endl;
      exit(-1);
    }
    
    this->recent_ptr = this->head_ptr;
    while(this->recent_ptr->exponent()!=exponent)
      this->recent_ptr = this->recent_ptr->fore();
  }

  
    
  polynomial::polynomial(double c, unsigned int exponent){

    polynode* nextNode = NULL;
    polynode* thisNode = NULL;

    for (int i = 0; i < exponent; i++) {
      nextNode = new polynode(0, i, NULL, thisNode);

      if (i==0) this->head_ptr = nextNode;
      
      thisNode->set_fore(nextNode);
      thisNode = nextNode;
    }

    nextNode = new polynode(c, exponent, NULL, thisNode);
    this->tail_ptr = nextNode;
  }

  polynomial::polynomial(const polynomial& source){
    this->head_ptr = source.head_ptr;
    this->tail_ptr = source.tail_ptr;
    this->recent_ptr = source.recent_ptr;
    this->current_degree = source.current_degree;
  }

  polynomial::~polynomial( ){
    for (polynode *toDel = this->head_ptr, *nextToDel = NULL; toDel != NULL; toDel = nextToDel) {
      nextToDel = toDel -> fore();
      delete(toDel);
    }
  }

  // MODIFICATION MEMBER FUNCTIONS
  polynomial& polynomial::operator =(const polynomial& source) {
    this->head_ptr = source.head_ptr;
    this->tail_ptr = source.tail_ptr;
    this->recent_ptr = source.recent_ptr;
    this->current_degree = source.current_degree;
  }

  void polynomial::add_to_coef(double amount, unsigned int exponent) {}
  void polynomial::assign_coef(double coefficient, unsigned int exponent) {}
  void polynomial::clear( ) {}
  
  // CONSTANT MEMBER FUNCTIONS
  double polynomial::coefficient(unsigned int exponent) const {
    this->set_recent(exponent);
    return this->recent_ptr->coef();
  }
  
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