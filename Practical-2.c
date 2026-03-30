// ID : D24CE175
#include <stdio.h>
#include <string.h>

int main()
{
    int symbolsCount, statesCount;
    int start, finalCount;
    int finals[10];
    int table[10][10];
    char alpha[10];
    char str[50];

    int state;
    int i, k;
    int isAccepted = 0;

    // Input number of symbols
    printf("Number of input symbols : ");
    scanf("%d", &symbolsCount);

    printf("Input symbols : ");
    for (i = 0; i < symbolsCount; i++)
        scanf(" %c", &alpha[i]);

    // Input number of states
    printf("Enter number of states : ");
    scanf("%d", &statesCount);

    // Initial state
    printf("Initial state : ");
    scanf("%d", &start);

    // Accepting states
    printf("Number of accepting states : ");
    scanf("%d", &finalCount);

    printf("Accepting states : ");
    for (i = 0; i < finalCount; i++)
        scanf("%d", &finals[i]);

    // Transition table
    printf("Transition table :\n");
    for (i = 1; i <= statesCount; i++)
    {
        for (k = 0; k < symbolsCount; k++)
        {
            printf("%d -- %c --> ", i, alpha[k]);
            scanf("%d", &table[i][k]);
        }
    }

    // Input string
    printf("\nInput string : ");
    scanf("%s", str);

    state = start;

    // Process string
    for (i = 0; i < strlen(str); i++)
    {
        int move = -1;

        for (k = 0; k < symbolsCount; k++)
        {
            if (str[i] == alpha[k])
            {
                move = table[state][k];
                break;
            }
        }

        if (move == -1)
        {
            printf("Invalid String");
            return 0;
        }

        state = move;
    }

    // Check final state
    for (i = 0; i < finalCount; i++)
    {
        if (state == finals[i])
        {
            isAccepted = 1;
            break;
        }
    }

    if (isAccepted)
        printf("Valid String");
    else
        printf("Invalid String");

    return 0;
}
