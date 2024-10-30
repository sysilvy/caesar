#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string s);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    if (only_digits(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext and output ciphertext
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");

    // Iterate over the chars of plaintext
    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            // Uppercase values
            printf("%c", (plaintext[i] - 65 + key) % 26 + 65);
        }
        else if (islower(plaintext[i]))
        {
            // Lowercase values
            printf("%c", (plaintext[i] - 97 + key) % 26 + 97);
        }
        else
        {
            printf("%c", plaintext[i]);
        }

    }

    // Start a new line
    printf("\n");

}

// Check if the CLA is a digit or not
bool only_digits(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isdigit(s[i]))
        {
            return true;
        }
    }

    return false;
}