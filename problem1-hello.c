#include <stdio.h>

int main(void)
{
    // SPACES NOT ALLOWED
    // char name[5];
    // printf("What is your name: ");
    // scanf("%s", name);
    // printf("Hello, %s!\n", name);

    // SPACES ALLOWED
    char name[20]; // final element is for \0 NULL
    printf("What is your name: ");
    fgets(name, 20, stdin);
    printf("Hello, %s", name);

    return 0;
}