#include <stdio.h>

// O(log n)

int binarySearch(int Arr[], int lower, int upper, int x)
{
    int mid = lower + (upper - lower) / 2;
    if (upper >= lower)
    {
        if (Arr[mid] == x)
        {
            return mid;
        }
        else if (Arr[mid] < x)
        {
            return binarySearch(Arr, mid + 1, upper, x);
        }
        else
        {
            return binarySearch(Arr, lower, mid - 1, x);
        }
    }
    return -1; //  -1 if there is no such element in the list
}

int main()
{
    int length;
    int myArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    length = sizeof(myArray) / sizeof(myArray[0]);
    int index = binarySearch(myArray, 0, length - 1, 11);

    printf("The index of the element is: %d\n", index);
    return 0;
}
