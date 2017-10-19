// words1.cpp - implements class Words
// (fixed size array version)

#include <cassert>
#include <string>
#include "words1.h"

using std::string;

namespace lab03_1
{
    Words::Words() {
        used = 0;
        capacity = 10;
    }
    
    void Words::append(string word) {
        assert(used < capacity);
        data[used] = word;
        ++used;
    }
    
    string& Words::operator[] (unsigned int index) {
        assert(index < used);
        return data[index];
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
