#include <stdio.h>

#define DISTRICTS 38
#define MONTHS 12

void readRainfall(float rain[DISTRICTS][MONTHS])
{
    int i, j;

    printf("Enter rainfall for 38 districts and 12 months:\n");

    for (i = 0; i < DISTRICTS; i++)
    {
        for (j = 0; j < MONTHS; j++)
        {
            scanf("%f", &rain[i][j]);
        }
    }
}

void annualTotals(float rain[DISTRICTS][MONTHS])
{
    int i, j;
    float total;

    printf("\nAnnual Rainfall:\n");

    for (i = 0; i < DISTRICTS; i++)
    {
        total = 0;

        for (j = 0; j < MONTHS; j++)
        {
            total += rain[i][j];
        }

        printf("District %d = %.2f\n", i + 1, total);
    }
}

void monthlyAverages(float rain[DISTRICTS][MONTHS])
{
    int i, j;
    float total;

    printf("\nMonthly State Averages:\n");

    for (j = 0; j < MONTHS; j++)
    {
        total = 0;

        for (i = 0; i < DISTRICTS; i++)
        {
            total += rain[i][j];
        }

        printf("Month %d = %.2f\n", j + 1,
               total / DISTRICTS);
    }
}

float stateAverage(float rain[DISTRICTS][MONTHS])
{
    int i, j;
    float total = 0;

    for (i = 0; i < DISTRICTS; i++)
    {
        for (j = 0; j < MONTHS; j++)
        {
            total += rain[i][j];
        }
    }

    return total / (DISTRICTS * MONTHS);
}

void wettestMonth(float rain[DISTRICTS][MONTHS])
{
    int i, j;
    int district = 0, month = 0;
    float maximum = rain[0][0];

    for (i = 0; i < DISTRICTS; i++)
    {
        for (j = 0; j < MONTHS; j++)
        {
            if (rain[i][j] > maximum)
            {
                maximum = rain[i][j];
                district = i;
                month = j;
            }
        }
    }

    printf("\nWettest District = %d\n", district + 1);
    printf("Wettest Month = %d\n", month + 1);
    printf("Maximum Rainfall = %.2f\n", maximum);
}

void deficientDistricts(float rain[DISTRICTS][MONTHS],
                        float average)
{
    int i, j;
    float total;
    int found = 0;

    printf("\nDistricts below 60%% of state average:\n");

    for (i = 0; i < DISTRICTS; i++)
    {
        total = 0;

        for (j = 0; j < MONTHS; j++)
        {
            total += rain[i][j];
        }

        if ((total / MONTHS) < (average * 0.60))
        {
            printf("District %d\n", i + 1);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("No deficient districts\n");
    }
}

int main()
{
    float rain[DISTRICTS][MONTHS];
    float average;

    readRainfall(rain);

    annualTotals(rain);

    monthlyAverages(rain);

    average = stateAverage(rain);

    printf("\nState Average = %.2f\n", average);

    wettestMonth(rain);

    deficientDistricts(rain, average);

    return 0;
}
