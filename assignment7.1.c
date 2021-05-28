#include <stdio.h>
#include <stdlib.h>
void bubble();
void selection();
void insertion();
void input();
void display();
int *ptr;
int size;
int main()
{
    int choice;
    printf("\n Enter 1 to Bubble sort");
    printf("\n Enter 2 to Selection Sort");
    printf("\n Enter 3 to Insertion sort");
    printf("\n Enter 4 to exit\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        input();
        bubble();
        display();
        break;
    case 2:
        input();
        selection();
        display();
        break;
    case 3:
        input();
        insertion();
        display();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("Wrong Choice");
        break;
    }
}
void input()
{
    int i;
    printf("Enter the size of the array you want to create\n");
    scanf("%d", &size);
    ptr = (int *)calloc(size, sizeof(int));
    printf("Enter the value for this array\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", ptr + i);
    }
}
void display()
{
    printf("The array after sorting is:\t");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", *(ptr + i));
    }
    free(ptr);
}
void bubble()
{
    int i, j, k;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (*(ptr + j) > *(ptr + j + 1))
            {
                k = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = k;
            }
        }
    }
}
void insertion()
{
    int key, j, k;
    for (k = 1; k < size; k++)
    {
        key = *(ptr + k);
        j = k - 1;
        while (j >= 0 && *(ptr + j) >= key)
        {
            *(ptr + j + 1) = *(ptr + j);
            j = j - 1;
        }
        *(ptr + j + 1) = key;
    }
}
void selection()
{
    int small, i, j, k;
    for (i = 0; i < size; i++)
    {
        small = i;
        for (j = i + 1; j < size; j++)
        {
            if (ptr[j] < ptr[small])
            {
                small = j;
            }
        }
        if (i != small)
        {
            k = *(ptr + i);
            *(ptr + i) = *(ptr + small);
            *(ptr + small) = k;
        }
    }
}