#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 12

char * encode(char *, int);
char * decode(char *);

int main(int argc, char *argv[]) {
    
    // We allocate memory for a string of size STRING_SIZE
    // with the calloc function. Then we copy the string
    // into the variable.
    char *string = (char *)calloc(STRING_SIZE, sizeof(char));
    strcpy(string, "AAAABBACCZAZ");
    
    printf("%s\n", encode(string, STRING_SIZE));
    printf("%s\n", decode(encode(string, STRING_SIZE)));
}

char * encode(char *string, int string_size) {
    int index = 0;
    int jndex = 0;
    int count = 0;
    
    // We allocate memory for the output string encoded by
    // the function. And a static buffer for the creation
    // of the element [CHARACHTER - NUMBER].
    char *encoded = (char *)calloc(STRING_SIZE, sizeof(char));
    char buffer[10];
    
    // Before the loop, we set the jndex with the index+1. So
    // jndex starts to the next element of the index element.
    jndex = index+1;
    
    // The loop continues until index and jndex are lower
    // than the size of the array.
    while(index <= string_size && jndex <= string_size) {
        
        // We check if the index element is equal to the jndex
        // element of the string, if yes, so we increment the
        // counter, the index and the jndex.
        //
        // Else, if are not equal, we should create the element
        // [CHARACHTER - NUMBER] of the new encoded string.
        // So the code use sprintf function to convert the
        // counter+1 number into character and concatenate it
        // to the encoded string. We make the same operations
        // for the index character of the string to encode.
        if(string[index] == string[jndex]) {
            count++;
            index++;
            jndex++;
        } else {
            sprintf(buffer, "%d", count+1);
            strcat(encoded, buffer);
            
            sprintf(buffer, "%c", string[index]);
            strcat(encoded, buffer);
            
            // After that, we initialize the variables because we
            // need to iterate the string starting with the first
            // different element from the previous.
            index = jndex;
            jndex = index+1;
            count = 0;
        }
    }
    
    return encoded;
}

char * decode(char *string) {
    int index = 0;
    int jndex = 0;
    int size  = 0;
    
    // First of all, we need the size of the decoded string,
    // so we iterate on the encoded string to catch the number
    // of each element.
    for(index = 0; string[index] != '\0'; index+=2) {
        size += atoi(&string[index]);
    }
    
    // So we allocate memory for the decoded string with
    // the size obtained with the previous loop.
    char *decoded = (char *)calloc(size, sizeof(char));
    
    // We start with the first element of the string until the end.
    // Into the while loop, we declare a buffer of a size equal to
    // the number of that particular element to decode.
    index = 0;
    while(string[index] != '\0') {
        char buffer[atoi(&string[index])];
        
        // We need to get all the character based on the number
        // before it. For example, if we have 4A, we need to get
        // with the loop, AAAA, so the index is equal to 4 and
        // index+1 is equal to A. And for each character, we call
        // sprintf and concatenate it to the decoded string.
        for(jndex = 0; jndex < atoi(&string[index]); jndex++) {
            sprintf(buffer, "%c", string[index+1]);
            strcat(decoded, buffer);
        }
        
        index++;
    }
    
    return decoded;
}
