#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *getReverse(char *word)
{
    // Appoach 1 - Using Swapping Modifying original string
    // int i, j, len = strlen(word);
    // for (i = 0, j = len - 1; i < j; i++, j--)
    // {
    //     char temp = word[i];
    //     word[i] = word[j];
    //     word[j] = temp;
    // }
    // return word;

    // Appraoch 2 - Using Temp Memory in heap & passing its address
    int len = strlen(word);
    char *ptrcpy = malloc(sizeof(char) * len);
    int i, idx = 0;
    for (i = len - 1; i >= 0; i--)
        ptrcpy[idx++] = word[i];

    return ptrcpy;
}

int main()
{
    // char word[] = "akash";  // Pass directly char array to function, it will work

    // Convert char* to char array
    char *word = "akash"; // it only store address of 0th char , So convert char* to char array
    int i, len = strlen(word);
    char *ptr = malloc(sizeof(char) * len); // Allocate memory in Heap for char array
    for (i = 0; i < len; i++)
        ptr[i] = word[i]; // copy elements from char* to char array

    char *result = getReverse(ptr); // we are passing address of newly created char array
    printf("Revese of word = %s\n", result);

    free(ptr);
    free(result);

    // Print Char*
    //--- 1st Way
    // printf("%s",name);
    //--- 2nd Way
    // int i;
    // for (i = 0; i < 5; i++)
    //     printf("%c ", name[i]);

    return 0;
}
