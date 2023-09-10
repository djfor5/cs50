#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <cs50.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET "\e[0;39m"

// user-defined function prototypes
void get_guess(int wordsize, char *str);
int check_word(string guess, int wordsize, int status[], string choice, char *str);
void print_word(string guess, int wordsize, int status[], char *str);

int main(int argc, string argv[])
{
    // ensure proper usage
    // (DONE) TODO #1
    int i = 0;
    if (argc != 2)
    {
        printf("Usage: ./wordle wordsize\n");
        return 1;
    }

    int wordsize = 0;

    // ensure argv[1] is either 5, 6, 7, or 8 and store that value in wordsize instead
    // (DONE) TODO #2
    while (atoi(argv[1]) < 5 || atoi(argv[1]) > 8)
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
        return 1;
    }
    wordsize = atoi(argv[1]);

    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];

    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN "This is WORDLE50" RESET "\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        char guess[9];
        get_guess(wordsize, guess);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // set all elements of status array initially to 0, aka WRONG
        // (DONE) TODO #4
        for (int i = 0; i < wordsize; i++)
        {
            status[i] = 0;
        }

        // Calculate score for the guess
        int score = check_word(guess, wordsize, status, choice, guess);

        printf("Guess %i: ", i + 1);

        // Print the guess
        print_word(guess, wordsize, status, guess);
        printf("\n");

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    // Print the game's result
    // (DONE) TODO #7
    if (won == true)
    {
        printf("You won!\n");
    }
    else
    {
        printf("You lost. The correct word is '%s'.\n", choice);
    }

    // that's all folks!
    return 0;
}

// string get_guess(int wordsize)
void get_guess(int wordsize, char *str)
{
    // ensure users actually provide a guess that is the correct length
    // (DONE) TODO #3
    int len;
    do
    {
        printf("Enter a word with exactly %d letters: ", wordsize);
        fgets(str, 9, stdin);
        str[strcspn(str, "\n")] = '\0'; // replace '\n' with null terminator
        len = strlen(str);
    } while (len != wordsize);
}

int check_word(string guess, int wordsize, int status[], string choice, char *str)
{
    int score = 0;

    // compare guess to choice and score points as appropriate, storing points in status
    // (DONE) TODO #5
    // printf("Word is: %s\n", choice); // TODO - Remove
    for (int i = 0; i < wordsize; i++) // loop through each letter of guess
    {
        if (str[i] == choice[i]) // same letter at same index
        {
            status[i] = 2;
            score += 2;
            continue;
        }
        for (int j = 0; j < wordsize; j++) // for each letter of guess, loop through each letter of choice
            if (str[i] == choice[j])       // same letter at different index
            {
                status[i] = 1;
                score += 1;
                break;
            } // no match, status[i] = 0 which is already the default value
    }

    // HINTS
    // iterate over each letter of the guess
    // iterate over each letter of the choice
    // compare the current guess letter to the current choice letter
    // if they're the same position in the word, score EXACT points (green) and break so you don't compare that letter further
    // if it's in the word, but not the right spot, score CLOSE point (yellow)
    // keep track of the total score by adding each individual letter's score from above

    return score;
}

void print_word(string guess, int wordsize, int status[], char *str)
{
    // print word character-for-character with correct color coding, then reset terminal font to normal
    // (DONE) TODO #6
    for (int i = 0; i < wordsize; i++)
    {
        if (status[i] == WRONG)
        {
            printf(RED "%c" RESET, str[i]);
        }
        else if (status[i] == CLOSE)
        {
            printf(YELLOW "%c" RESET, str[i]);
        }
        else if (status[i] == EXACT)
        {
            printf(GREEN "%c" RESET, str[i]);
        }
    }

    printf("\n");
    return;
}
