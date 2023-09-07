#include <stdio.h>

int main(void)
{
    int rows;
    do
    {
        printf("Enter number of rows (between 1 and 8 inclusive): ");
        scanf("%d", &rows);
    } while (rows < 1 || rows > 8);

    for (int i = 1; i <= rows; i++)
    {
        for (int j = rows - i; j >= 1; j--)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = i; j >= 1; j--)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}