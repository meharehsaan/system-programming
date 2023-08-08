// Making a 2D array on heap


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, cols;

    rows = 2;
    cols = 4;

    // allocating heap
    int **twoDArray = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; ++i)
    {
        twoDArray[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize the elements
    int value = 1;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            twoDArray[i][j] = value++;
        }
    }

    printf("2D Array:\n");
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%d ", twoDArray[i][j]);
        }
        printf("\n");
    }

    // free memory at the end
    for (int i = 0; i < rows; ++i)
    {
        free(twoDArray[i]);
    }
    free(twoDArray);

    return 0;
}
