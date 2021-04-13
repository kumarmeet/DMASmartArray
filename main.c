#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct SmartArray *arr;

    arr = createArray(10);

    appendItem(arr, 4);
    appendItem(arr, 5);
    appendItem(arr, 6);
    appendItem(arr, 6);
    appendItem(arr, 6);
    appendItem(arr, 6);
    appendItem(arr, 6);
    appendItem(arr, 6);
    appendItem(arr, 6);


    searchItem(arr, 8);

    return 0;
}
