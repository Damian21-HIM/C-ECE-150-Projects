#include <iostream>
#include <cassert>
#include "p_4_header.hpp"

std::size_t length(const char *a) {
    std::size_t renz = 0;
    while (a[renz] != '\0') {  //While renz is not a null character, increment it by 1 thereby counting it.
        ++renz;
    }
    return renz;
}

int compare( char const *str1, char const *str2 ) {
    int index = 0;

    // Loop until characters differ or until the end of one string
    while (str1[index] != '\0' && str2[index] != '\0') {
        if (str1[index] < str2[index]) {
            return -1;  // a negative integer if string str1 comes in the dictionary before string str2.
        } 
        if (str1[index] > str2[index]) {
            return 1;   // a positive integer if string str2 comes in the dictionary before string str1.
        }
        index++; //move the comparison to the next character in both str1 and str2.
    }

    // if both strings are equal meaning they are equal)
    if (str1[index] == '\0' && str2[index] == '\0') {
        return 0;
    } 
// If we reached the end of one string first, that string is "lesser(comes before)" 
if (str1[index] == '\0') { //If str1 is shorter than str2, str1 will reach '\0' first.
    return -1; //If str1 ends first, it means str1 comes first before str2 in the dictionary because shorter words come first if they share the same initial characters.
} else {
return 1; //If str1 did not end first, it must be that str2 ended first.
}
}

void assign(char *str1, char const *str2) {
    // Using a `for` loop to copy characters
    for (unsigned int n = 0; true; ++n) { //Initializing n to start at the beginning of both str1 and str2.  By setting the loop condition to true, the loop runs infinitely and then use the condition if (str2[n] == '\0') to check if we've reached the end of str2. The ++n allows us to move to the next character in BOTH str1 and str2.
        if (str2[n] == '\0') {    
            str1[n] = '\0';       // If we reach the null terminator in str2, we assign '\0' to str1[n]
            return;               // Exit the function
        }
        str1[n] = str2[n];         // This line copies each character from str2[n] to str1[n]. The loop keeps running until it encounters the null character ('\0') in str2.
    }
}

unsigned int distance(const char *str1, const char *str2) {
//The base cases handle situations where one of the strings is empty.
if (length(str1) == 0){
    return length(str2);
} 
if (length(str2) == 0) {
    return length(str1);
}
//If the first characters of both strings are the same, then skip them and recursively call distance on the remaining characters of both strings.
if (str1[0] == str2[0]) {
    return distance(str1 + 1, str2 + 1); //There is no need to edit these first characters as they are the same, so proceed to the next characters in both strings.
} else{
 // Calculation of the distances for the three possible scenarios
        unsigned int inputDistance = distance(str1, str2 + 1);       // Insertion scencario
        unsigned int deleteDistance = distance(str1 + 1, str2);       // Deletion scencario
        unsigned int replaceDistance = distance(str1 + 1, str2 + 1); // Substitution scencario
        
        // Return 1 + the minimum of the three operations
        return 1 + std::min({inputDistance, deleteDistance, replaceDistance});
    }
}


std::size_t is_sorted(char *array[], std::size_t capacity) {
    if (capacity <= 1) {
        return capacity; // If there is 0 or 1 string, trivially sort it.
    }
    //The function repeats over the array of strings up to capacity - 1, comparing each pair of consecutive strings.
    for (std::size_t n = 0; n < capacity - 1; ++n) {
        // Use compare to check dictionary ordering
        if (compare(array[n], array[n + 1]) > 0) { // We don't straight up do direct comparison array [n]> array [n +1] because it checks memory addresses. We are using compare which is used to check alphabetical order and has its own syntax which is what we need in this case.
            return n + 1; // When array[n] is greater than array[n + 1], the function returns n, which is the index of the first unsorted pair.
        }
    }
    return capacity; //If the loop completes without finding any unsorted elements, it returns capacity, indicating that the array is sorted.
}

void insert(char *array[], std::size_t capacity) {
     // Manually find the length of the string at array[capacity - 1]
    std::size_t length = 0;
    while (array[capacity - 1][length] != '\0') {
        ++length;
    }

    char *value = new char[length + 1];  // Dynamically allocate memory for the new string

    // Copy characters from array[capacity - 1] to the value.
    for (std::size_t n = 0; n <= length; ++n) {
        value[n] = array[capacity - 1][n];
    }

    //n is set to capacity - 1 and it will help keep track of where the value needs to be moved when iterating backwards.
    std::size_t n = capacity - 1; 
    while (n > 0 && compare(array[n - 1], value) > 0) { //n > 0 to make sure that we don’t go out of bounds. //compare(array[n - 1], value) > 0: makes sure that we're only shifting elements that come after value in dictionary order using the compare function and its syntax.
        array[n] = array[n - 1]; //If array[i - 1] is greater than value, then shift array[n - 1] to the right (to array[n]) and decrement n to continue the process.
        --n; //The while loop moves backward through the array, shifting each entry one position to the right until we find the correct place for value.
    }
    //After the loop ends, n will be the correct index where value should go, so I've assign array[n] = value. Now, array is sorted up to capacity - 1.
    array[n] = value; 
}


void insertion_sort(char *array[], std::size_t capacity) {
    //The loop starts at n = 1 and goes up to capacity - 1.
    for (std::size_t n = 1; n < capacity; ++n) {
        //Insert(array, n + 1) takes the index from 0 up to n(including n) and assumes it’s already sorted. The n+1th element is then inserted into the correct position within this sorted section.
        insert(array, n + 1);
    }
}


std::size_t remove_duplicates(char *array[], std::size_t capacity) {
     if (capacity == 0) {
        return 0; // If the array has no elements, there are no unique entries to count so we just return 0.
    }
    std::size_t distinct_count = 1; //We start counting unique entries with the first element (index 0). Because it’s the first entry, it can be considered as unique by default, so I intialized distint_count to 1 off rip.
   //Starting from the second element (index 1), we iterate through the entire array.
    for (std::size_t n = 1; n < capacity; ++n) {
//For each entry array[n], compare it with the previous unique element, array[distinct_count - 1], using the compare function.
        if (compare(array[n], array[distinct_count - 1]) != 0) { //If compare returns 0, it means the two elements are the same, so this element is skipped. 
    //If compare returns a non-zero value, it means array[n] is a distinct value so we assign this unique element to array[disgtinct_count] and increment distinct_count.
             array[distinct_count] = array[n]; 
            ++distinct_count; 
        }
    }
//After going through the array, distinct_count will hold the number of unique entries. This value, distinct_count, will serve as the new capacity of the array, only now containing only unique entries.
    return distinct_count;
}

std::size_t find(char *array[], std::size_t capacity, const char *str) {
   //mini_index is initialized to 0. It will hold the index of the string with the smallest distance to str.
    std::size_t mini_index = 0; 
    //min_distance is set to be the distance between the first string in the array (array[0]) and str.
    unsigned int mini_distance = distance(array[0], str);  

    //Loop through each string in the array, calculating the distance between array[n] and str using the distance() function as given in the instructions.
    for (std::size_t n = 0; n < capacity; ++n) {
        if (compare(array[n], str) == 0) return n;
// current_distance is the calculated distance between the current string and str.
        unsigned int current_distance = distance(array[n], str);
        //If current_distance is 0, it means array[n] matches str exactly, so we return n immediately.
        if (current_distance == 0) {
    return n;
}
//If the current_distance is less than the mini_distance recorded thus far, update mini_distance to current_distance and set mini_index to n.
        if (current_distance < mini_distance) {
            mini_distance = current_distance;
            mini_index = n;
        }
    }
    //If the loop completes without finding an exact match, return closest_index.
    return mini_index;
}

/// @brief Frees the memory allocated by read_words_from_file
/// @param word_array the word array to deallocate
void free_word_array(char **word_array) {
    // Deallocate the memory block
    delete[] word_array[0];
    
    // Deallocate the array of pointers 
    delete[] word_array;
} 


