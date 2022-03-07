// Reads a string for a serialized RB tree, deserializes it,
// performs some insertions, then serializes the revised tree.

//Name: Abdulla Sakallah                                         

// Compiling instructions on Omega:-
//==================================
// gcc driver.c
// ./a.out < a.txt
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RB.c"

int main()
{
    int inputBytes;
    char *inputString, *outputString;
    char formatString[100];
    int insertKeys, i, key;

    scanf("%d", &inputBytes);

    inputString = (char *)malloc(inputBytes);
    if (!inputString)
    {
        printf("malloc failed %d\n", __LINE__);
        exit(0);
    }
    sprintf(formatString, "%%%ds", inputBytes);
    scanf(formatString, inputString);

    STinit();
    STdeserialize(inputString);
    free(inputString);

    scanf("%d", &insertKeys);
    for (i = 0; i < insertKeys; i++)
    {
        scanf("%d", &key);
        STinsert(key);
    }


    outputString = (char*) malloc(sizeof(char)*400);

    STserialize(getHead(),outputString);

    printf("%lu %s\n", strlen(outputString) + 1, outputString);
    free(outputString);
    freeMemory(getHead());
}

