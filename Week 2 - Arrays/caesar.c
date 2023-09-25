#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int num = 26;

void cipher(string plain, int key);
bool valid(string s);

int main(int argc, string argv[])
{
    int number;
    if (argc != 2 || !valid(argv[1]))
    {
        printf("Usage: %s key \n", argv[0]);
        return 1;
    }
    else
    {
        number = atoi(argv[1]);
    }
    string text = get_string("plaintext: ");
    cipher(text, number);
}

void cipher(string plain, int key)
{
    char encrypted[strlen(plain) + 1]; // +1 for the null-terminator
    int counter = 0;

    for (int i = 0; i < strlen(plain); i++)
    {
        char current_char = plain[i];

        if (isalpha(current_char))
        {
            if (islower(current_char))
            {
                current_char = ((current_char - 'a' + key) % num) + 'a';
            }
            else if (isupper(current_char))
            {
                current_char = ((current_char - 'A' + key) % num) + 'A';
            }
        }

        encrypted[counter] = current_char;
        counter++;
    }
    encrypted[counter] = '\0'; // Null-terminate the encrypted string
    printf("ciphertext: %s\n", encrypted);
}

bool valid(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            return false;
        }
    }
    return true;
}