#include <stdio.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char *word);

int main(void)
{
    // Get input word from player 1
    char wordPlayer1[20];
    printf("Enter word for player 1: ");
    scanf("%s", wordPlayer1);
    printf("Player 1 word is '%s'\n", wordPlayer1);

    // Get input word from player 2
    char wordPlayer2[20];
    printf("Enter word for player 2: ");
    scanf("%s", wordPlayer2);
    printf("Player 2 word is '%s'\n", wordPlayer2);

    // Score both words
    int score1 = compute_score(wordPlayer1);
    printf("Player 1 score is: %d\n", score1);
    int score2 = compute_score(wordPlayer2);
    printf("Player 2 score is: %d\n", score2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int compute_score(char *word)
{
    int i = 0;
    int score = 0;
    while (word[i] != '\0')
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
        i++;
    }
    return score;
}
