// words1.h - version 1 of class Words
// See Lab03 instructions for details.

#include <string>

#ifndef WORDS1_H
#define WORDS1_H

namespace lab03_1
{
    class Words
    {
    public:
        Words();
        
        void append(std::string word);
        std::string& operator[] (unsigned int index);
        
        unsigned int size() const;
        unsigned int get_capacity() const;
        std::string operator[] (unsigned int index) const;
        
    private:
        std::string data[10]; // max words is 10 in ver. 1
        unsigned int used;
        unsigned int capacity;
    };

}

#endif
