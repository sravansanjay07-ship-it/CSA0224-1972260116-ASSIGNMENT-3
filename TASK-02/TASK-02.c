#include <stdio.h>

int main()
{
    int a[5] = {5, 1, 4, 2, 3};
    int b[5], c[5];
    int i, j, temp, min;
    int comp, swaps;

    for (i = 0; i < 5; i++)
    {
        b[i] = a[i];
        c[i] = a[i];
    }

    /* Bubble Sort */
    comp = 0;
    swaps = 0;

    for (i = 0; i < 4; i++)
    {
        int flag = 0;

        for (j = 0; j < 4 - i; j++)
        {
            comp++;

            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;

                swaps++;
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }

    printf("Bubble Sort: ");
    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);

    printf("\nComparisons = %d, Swaps = %d\n", comp, swaps);

    /* Selection Sort */
    comp = 0;
    swaps = 0;

    for (i = 0; i < 4; i++)
    {
        min = i;

        for (j = i + 1; j < 5; j++)
        {
            comp++;

            if (b[j] < b[min])
                min = j;
        }

        if (min != i)
        {
            temp = b[i];
            b[i] = b[min];
            b[min] = temp;
            swaps++;
        }
    }

    printf("Selection Sort: ");
    for (i = 0; i < 5; i++)
        printf("%d ", b[i]);

    printf("\nComparisons = %d, Swaps = %d\n", comp, swaps);

    /* Insertion Sort */
    comp = 0;
    swaps = 0;

    for (i = 1; i < 5; i++)
    {
        temp = c[i];
        j = i - 1;

        while (j >= 0)
        {
            comp++;

            if (c[j] > temp)
            {
                c[j + 1] = c[j];
                swaps++;
                j--;
            }
            else
                break;
        }

        c[j + 1] = temp;
    }

    printf("Insertion Sort: ");
    for (i = 0; i < 5; i++)
        printf("%d ", c[i]);

    printf("\nComparisons = %d, Shifts = %d\n", comp, swaps);

    return 0;
}
