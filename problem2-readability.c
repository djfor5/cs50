#include <stdio.h>
#include <ctype.h>
#include <math.h> // use '-lm' option when compiling to link math.h header file
#include <string.h>

int main(void)
{
    char text[100]; // final element is for \0 NULL
    printf("Enter a sentence: ");
    fgets(text, 100, stdin);
    printf("%s", text);

    int letterCount = 0;
    int wordCount = 1;
    int sentenceCount = 0;

    // int i = 0; // remove if using for loop
    // while (text[i] != '\0') // remove if using for loop
    for (int i = 0; i < strlen(text); i++) // remove if using while loop. for loop requires <string.h>
    {
        if (toupper(text[i]) >= 'A' && toupper(text[i]) <= 'Z') // alternatively can use "if (tolower(text[i]) >= 'a' && tolower(text[i]) <= 'z')"
        {
            letterCount++;
        }
        if (text[i] == ' ')
        {
            wordCount++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentenceCount++;
        }
        // i++; // remove if using for loop
    }
    printf("%i letters\n", letterCount);
    printf("%i words\n", wordCount);
    printf("%i sentences\n", sentenceCount);

    float L = letterCount / (float)wordCount * 100;   // letters per 100 words
    float S = sentenceCount / (float)wordCount * 100; // sentences per 100 words
    float calculation = 0.0588 * L - 0.296 * S - 15.8;
    printf("%f\n", calculation);
    int index = round(calculation);

    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
        return 0;
    }
}

// EXAMPLE TEXT TO USE AS STRING INPUT
// One fish. Two fish. Red fish. Blue fish.
// It was a bright cold day in April, and the clocks were striking thirteen. Winston Smith, his chin nuzzled into his breast in an effort to escape the vile wind, slipped quickly through the glass doors of Victory Mansions, though not quickly enough to prevent a swirl of gritty dust from entering along with him.
// A large class of computational problems involve the determination of properties of graphs, digraphs, integers, arrays of integers, finite families of finite sets, boolean formulas and elements of other countable domains.
// When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow. When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury. His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.
