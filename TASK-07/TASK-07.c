#include <stdio.h>

int main()
{
    int votes[5000];
    int count[13] = {0};
    int candidates, totalVotes;
    int valid = 0, invalid = 0;
    int i, j, temp;
    int order[12];
    int tie = 0;

    printf("Enter number of candidates: ");
    scanf("%d", &candidates);

    printf("Enter number of votes: ");
    scanf("%d", &totalVotes);

    if (candidates < 1 || candidates > 12 ||
        totalVotes < 1 || totalVotes > 5000)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter votes:\n");

    for (i = 0; i < totalVotes; i++)
    {
        scanf("%d", &votes[i]);

        if (votes[i] >= 1 && votes[i] <= candidates)
        {
            count[votes[i]]++;
            valid++;
        }
        else
        {
            invalid++;
        }
    }

    for (i = 0; i < candidates; i++)
        order[i] = i + 1;

    /* Sort candidates by votes */
    for (i = 0; i < candidates - 1; i++)
    {
        for (j = 0; j < candidates - i - 1; j++)
        {
            if (count[order[j]] < count[order[j + 1]])
            {
                temp = order[j];
                order[j] = order[j + 1];
                order[j + 1] = temp;
            }
        }
    }

    printf("\nValid Votes = %d\n", valid);
    printf("Invalid Votes = %d\n", invalid);

    printf("\nCandidate Results:\n");

    for (i = 0; i < candidates; i++)
    {
        printf("Candidate %d = %d votes\n",
               order[i], count[order[i]]);
    }

    if (valid == 0)
    {
        printf("\nNo valid votes. No winner.\n");
    }
    else
    {
        printf("\nWinner Candidate = %d\n", order[0]);

        if (candidates > 1 &&
            count[order[0]] == count[order[1]])
        {
            tie = 1;
        }

        if (tie)
            printf("Election Result = Tie\n");
        else
            printf("Election Result = Winner\n");
    }

    return 0;
}
