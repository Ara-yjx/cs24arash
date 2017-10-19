// alph.cpp - some recursive print functions
// NAME(S), DATE

#include <iostream>
using namespace std;

// recursively prints letter sequence 'a'..c
void alph(char c) {
    if (islower(c)) {
        if (c > 'a')
            alph(c - 1);
        cout << c;
    }
}

// recursively prints letter sequence c..'a'
void ralph(char c) {
    // IMPLEMENT
}

// recursively prints letter sequence c..'z'
void zalph(char c) {
    // IMPLEMENT
}

// recursively prints letter sequence 'z'..c
void zralph(char c) {
    // IMPLEMENT
}

int main() {
    char letter;
    cout << "enter letter:" << endl;
    cin >> letter;

    alph(letter);
    cout << endl;

    ralph(letter);
    cout << endl;

    zalph(letter);
    cout << endl;

    zralph(letter);
    cout << endl;
}
