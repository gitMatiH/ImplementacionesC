/**
 *	An array is a lookup table if:
 *	1. We're indexing into it directly
 *	2. We're replacing computation with it
 */

#include <stdio.h>


const char *messages[] = {
    "Not a party. You are alone.",
    "One is the loneliest number.",
    "Not lonely, but not a party.",
    "Now we're talking.",
    "Now we're talking.",
    "Ah, yeah ... ",
    "Ah, yeah ... ",
    "Ah, yeah ... ",
    "Whoa. violated fire code!"
};

const int NUM_MESSAGES = (sizeof(messages) / sizeof(char *));
//now you can just update the array and the number is going to be
//actualized automatically

void print_party_size_info(size_t people) {
    if (people > NUM_MESSAGES-1) {
        printf("%s\n", messages[NUM_MESSAGES-1]);
    } else {
        printf("%s\n", messages[people]);
    }
}



int main() {

    print_party_size_info(0);
    print_party_size_info(1);
    print_party_size_info(2);
    print_party_size_info(3);
    print_party_size_info(4);
    print_party_size_info(5);
    print_party_size_info(7);
    print_party_size_info(35);
}