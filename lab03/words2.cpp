// words1.cpp - implements class Words
// (fixed size array version)

#include <cassert>
#include <string>
#include "words2.h"
#include "iostream"

using std::string;
// using std::cout;
// using std::endl;

namespace lab03_2
{
    Words::Words(unsigned int initial_capacity) {
      used = 0;
      capacity = initial_capacity;
      data = new string[capacity];
    }

    Words::Words(const Words &source) : Words(source.get_capacity()) {
      //cout<<endl<<"IN-CONSTRUCT SIZE():"<<size()<<endl<<"CAPA():"<<get_capacity()<<endl;/////
      
      for (int i = 0; i < source.size(); i++) {
        //cout<<"APPEND  "<<i<<"   "<<source[i]<<endl;//////////////
        append (source[i]);
        
      }
      //cout<<endl<<"IN-CONSTRUCT SIZE():"<<size()<<endl<<"CAPA():"<<get_capacity()<<endl;/////
      
    }
    
    
    Words::~Words() {
      delete [] data;
    }

    void Words::append(string word) {
        //assert(used < capacity);

        if(used < capacity) {
          data[used] = word;
          ++used;
          //cout<<"SIZE "<<size()<<endl;////////////////
        }
        else {
          capacity++;
          string* new_data = new string[capacity];
          for (int i = 0; i < size(); i++) {
            new_data[i] = data[i];   
          }

          data = new_data;
          
          append(word);
        }
    
    }
    
    string& Words::operator[] (unsigned int index) {
        assert(index < used);
        return data[index];
    }

    Words& Words::operator= (const Words &source) {
      //if(data!=NULL) delete data;
      used = 0;
      capacity = source.capacity;
      data = new string[capacity];

      for (int i = 0; i < source.size(); i++) {
        //cout<<"APPEND  "<<i<<"   "<<source[i]<<endl;//////////////
        append (source[i]);
        
      }
      return *this;
    }
    
    unsigned int Words::size() const {
        return used;
    }
    
    unsigned int Words::get_capacity() const {
        return capacity;
    }
    
    string Words::operator[] (unsigned int index) const {
        assert(index < used);
        return data[index];
    }

    
    
}
