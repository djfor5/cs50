#include <stdio.h>

int main()
{
    // Prompt for start size
    int initialSize, finalSize, numberOfYears = 0;
    do
    {
        printf("Provide an initial population size (9 or greater): ");
        scanf("%d", &initialSize);
    } while (initialSize < 9);

    // Prompt for end size
    do
    {
        printf("Provide a final population size (greater than initial population size of %d): ", initialSize);
        scanf("%d", &finalSize);
    } while (finalSize <= initialSize);

    // Calculate number of years to get from start size to end size
    int currentSize = initialSize;
    while (currentSize < finalSize)
    {
        currentSize = currentSize + currentSize / 3 - currentSize / 4;
        numberOfYears++;
    }

    printf("Number of years: %i\n", numberOfYears);

    return 0;
}