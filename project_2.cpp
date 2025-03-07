#include <iostream>
#include <cassert>

//This function prints a pattern of asterisks.
void pattern(unsigned int n){
 if (n == 0) {
        std::cout << "*" << std::endl;
        return;
    }
//For each line, the number of spaces required to center the asterisks is calculated by subtracting the current number of asterisks from the maximum width, then dividing by 2 (to split the extra space evenly on both sides).
unsigned int max_width = 2 * n + 1;

      // Part 1: Loop to print the decreasing rows of asterisks
      for (int i = max_width; i > 0; i -= 2) {
        unsigned int spaces = (max_width - i) / 2;
        // Print leading spaces
        for (unsigned int s = 0; s < spaces; ++s) {
            std::cout << " ";
        }
        // Print asterisks
        for (unsigned int j = 0; j < static_cast<unsigned int>(i); ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

 // Part 2: Loop to print the increasing rows of asterisks
for (unsigned int i = 3; i <= max_width; i += 2) {
        unsigned int spaces = (max_width - i) / 2;
        // Print leading spaces
        for (unsigned int s = 0; s < spaces; ++s) {
            std::cout << " ";
        }
        // Print asterisks
        for (unsigned int j = 0; j < i; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

}


//This function calculates the largest exponent m such that 10^m<=n
unsigned int log10(unsigned int n);
unsigned int log10(unsigned int n) {
   assert(n != 0);  // Ensure n is not zero because log10(0) is undefined.

   unsigned int exponent = 0;  // Initialize the exponent

    // While n >= 10, divide n by 10 until it is less than 10.
    while (n >= 10) {
        n /= 10;  // Divide n by 10
        exponent++;  // Increment the exponent by 1. We pre-increment the value of exponent before using it in the expression.
    }
    return exponent;  // Return the final exponent
}

unsigned int count(unsigned int n, unsigned int bit);
unsigned int count(unsigned int n, unsigned int bit) {
unsigned num_bits = 32;
assert(bit == 0 || bit == 1);  // Ensure bit is either 0 or 1
int count = 0;
for (unsigned i = 0; i < num_bits; ++i) {
    count += (((n >> i) & 1) == bit);
}
    return count;
}


unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1);
unsigned int swap_bytes(unsigned int n, unsigned int b0, unsigned int b1){
    assert(0 <= b0 && b0 <= 3);
    assert(0 <= b1 && b1 <= 3);

    if (b0==b1) {
        return n;
    }
    
      unsigned int byte0 = (n >> (b0 * 8)) & 255;  
    unsigned int byte1 = (n >> (b1 * 8)) & 255;  

    // Clear the bytes at positions b0 and b1 in n
    n &= ~(255 << (b0 * 8));  
    n &= ~(255 << (b1 * 8));  

    // Swap the extracted bytes and place them back into the cleared positions
    n |= (byte0 << (b1 * 8));  
    n |= (byte1 << (b0 * 8));  
    return n;
}


   

    
