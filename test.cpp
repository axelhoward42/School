#include <iostream>
using namespace std;

char toLower(char letter) { // If it is a Capital Letter, it will convert it to a lowercase and return it.
    if (letter >= 65 && letter <= 90) {
        return letter + 32; // The difference between Lowercase and Capital letters is the integer value 32.
    }
    return letter; // otherwise (a non-alphabet character in the ASCII table) it will return its' original
}



