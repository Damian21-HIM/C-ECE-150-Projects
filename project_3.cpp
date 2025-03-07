#include <iostream>
#include <cassert>

double *geometric(double a, double ratio, std::size_t cap) {
    double* array = new double[cap];  // Perform dynamical allocation for the array
    if (cap > 0) {
        array[0] = a;  // Setting the first entry equal to the initial value
    }
    for (std::size_t i = 1; i < cap; ++i) {
        array[i] = array[i - 1] * ratio;  // Calculate the following elements
    }
    return array;  // Returning the pointer to the array(standard)
}


double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1) {
    assert(cap0 + cap1 >= 1);
    std::size_t result_cap = cap0 + cap1 - 1;
    double* result = new double[result_cap]();  

    for (std::size_t i = 0; i < cap0; ++i) {
        for (std::size_t j = 0; j < cap1; ++j) {
            result[i + j] += array0[i] * array1[j];
        }
    }
    return result;
}


std::size_t shift_duplicates(int array[], std::size_t capacity) {
    bool isSame = false;
    std::size_t distinctCount = capacity; // Initial count of unique/distinct elements
    int temporaryArray[capacity];            // Temporary array to store elements

    std::size_t frontIndex = 0;         // Index to store unique elements at the front
    std::size_t backIndex = capacity - 1; // Index to store duplicates at the back

    
    for (std::size_t n = 0; n < capacity; ++n) {
        isSame = false;

        for (std::size_t p = 0; p < n; ++p) {
            if (array[n] == array[p]) {
                isSame = true;
                distinctCount--; // Decrement unique count if a duplicate is found
                break;
            }
        }

        if (!isSame) {         // If not a duplicate, store it at the front If it is, store it at the back.
            temporaryArray[frontIndex++] = array[n];
        } else {
            temporaryArray[backIndex--] = array[n];
        }
    }

    for (std::size_t n = 0; n < capacity; ++n) {
        array[n] = temporaryArray[n];
    }

    return distinctCount; // Return the count of distinct elements
}


void deallocate(double *&ptr, bool is_array, std::size_t capacity = 0) {
    if (is_array) {

        if (ptr != nullptr) {
    for (std::size_t n = 0; n < capacity; ++n) {
                ptr[n] = 0;  
            }
            delete[] ptr; 
        }
    } else {
       
        if (ptr != nullptr) {
            *ptr = 0;  
            delete ptr; 
        }
    }
    ptr = nullptr;  
}