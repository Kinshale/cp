#define MAXLENGTH 50
#include <stdio.h>

int removeDuplicates(int *array, int n, int *uniqueArray)
{
    int i, j, m;

    m = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m && array[i] != uniqueArray[j]; j++)
        {
        }

        if (j == m)
            uniqueArray[m++] = array[i];
    }

    return m;
};

int main()
{
    int i, n, array[MAXLENGTH], m, uniqueArray[MAXLENGTH];

    n = -1;

    while (++n < MAXLENGTH)
    {
        scanf("%d", &array[n]);
        if (array[n] <= 0)
            break;
    }

    // After the loop, n is the length of array;

    m = removeDuplicates(array, n, uniqueArray); // returns the length of uniqueArray.

    printf("Unique Array is: \n");

    for (i = 0; i < m; i++)
        printf("%d  ", uniqueArray[i]);

    printf("\n");

    return 0;
}