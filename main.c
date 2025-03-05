#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int zeroStartNext = digitsSize - 1;
    // Find where the carry terminates
    while (zeroStartNext >= 0 && digits[zeroStartNext] == 9) --zeroStartNext;
    
    // It's a series of 9's - Early Exit
    if (zeroStartNext < 0)
    {
        *returnSize = digitsSize + 1;
        int *out = (int*)calloc(sizeof(int), *returnSize); // Calloc to 0-initialize fast
        out[0] = 1;
        return out;
    }

    // Regular case where carry doesn't make it all the way to the highest digit
    *returnSize = digitsSize;
    int *out = (int*)calloc(sizeof(int), *returnSize);
    for (int i = 0; i < zeroStartNext; ++i)
    {
        out[i] = digits[i]; // Copy values upto zeroStartNext - 1
    }
    out[zeroStartNext] = digits[zeroStartNext] + 1; // Apply carry to the last non-9 digit
    return out;
}

int main() {
    int digits1[] = {1, 2, 3};
    int size1;
    int* result1 = plusOne(digits1, 3, &size1);
    printf("Input: digits = [1,2,3]\n");
    printf("Output: [");
    for (int i = 0; i < size1; ++i) {
        printf("%d", result1[i]);
        if (i < size1 - 1) {
            printf(",");
        }
    }
    printf("]\n");
    free(result1);

    int digits2[] = {4, 3, 2, 1};
    int size2;
    int* result2 = plusOne(digits2, 4, &size2);
    printf("Input: digits = [4,3,2,1]\n");
    printf("Output: [");
    for (int i = 0; i < size2; ++i) {
        printf("%d", result2[i]);
        if (i < size2 - 1) {
            printf(",");
        }
    }
    printf("]\n");
    free(result2);

    int digits3[] = {9};
    int size3;
    int* result3 = plusOne(digits3, 1, &size3);
    printf("Input: digits = [9]\n");
    printf("Output: [");
    for (int i = 0; i < size3; ++i) {
        printf("%d", result3[i]);
        if (i < size3 - 1) {
            printf(",");
        }
    }
    printf("]\n");
    free(result3);

    return 0;
}
