#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int capacity;
    int last_index;
    int *ptr;
} SmartArray;

SmartArray* createArray(int cap);
void insertItem(SmartArray *arr, int index, int value);
int getItem(SmartArray *arr, int index);
void appendItem(SmartArray *arr, int value);
void deleteItem(SmartArray *arr, int index);
int isEmpty(SmartArray *arr);
int isFull(SmartArray *arr);
int countItems(SmartArray *arr);
void searchItem(SmartArray *arr, int value);

void searchItem(SmartArray *arr, int value)
{
  printf("%d",arr->last_index);
    int i, found = 0;
    if(arr->last_index < 0)
        printf("\nNo item found");
    else
    {
        for(i = 0; i <= arr->last_index; i++)
        {
            if(value == arr->ptr[i])
            {
                found = 1;
                break;
            }
        }
    }

    if(found == 1)
      printf("%d has in items", value);
    else
      printf("%d has not in items", value);
}

int countItems(SmartArray *arr)
{
    if(arr->last_index < 0)
        return 0;

    return arr->last_index += 1;
}

int isFull(SmartArray *arr)
{
    if(arr->last_index + 1 == arr->capacity)
        return 0;

    return 1;
}

int isEmpty(SmartArray *arr)
{
    if(arr->last_index < 0)
        return 0;

    return 1;
}

void deleteItem(SmartArray *arr, int index)
{
    int i;

    if(index < 0 || index > arr->last_index)
        printf("\n Invalid Index");
    else
    {
        for(i = index; i < arr->last_index; i++)
            arr->ptr[i] = arr->ptr[i + 1];

        arr->last_index -= 1;
    }
}

int getItem(SmartArray *arr, int index)
{
    if(index < 0 || index > arr->last_index)
    {
        printf("\nInvalid Index");
        return 0;
    }

    return arr->ptr[index];
}

void insertItem(SmartArray *arr, int index, int value)
{
    int i;
    if(index < 0 || index > arr->last_index + 1)
        printf("\nInvalid Index");
    else if(arr->last_index + 1 == arr->capacity)
        printf("\nOverflow");
    else
    {
        for(i = arr->last_index; i >= index; i--)
            arr->ptr[i + 1] = arr->ptr[i];

        arr->ptr[index] = value;
        arr->last_index += 1;
    }
}

void appendItem(SmartArray *arr, int value)
{
    if(arr->last_index + 1 == arr->capacity)
        printf("\nOverflow");
    else
    {
        arr->last_index += 1;
        arr->ptr[arr->last_index] = value;
    }
}


SmartArray* createArray(int cap)
{
    SmartArray *arr;

    arr = (SmartArray*) malloc(sizeof(SmartArray));
    arr->capacity = cap;
    arr->last_index = -1;
    arr->ptr = (int *) malloc(sizeof(int) * cap);

    return arr;
}


