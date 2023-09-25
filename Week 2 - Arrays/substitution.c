#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string s);
bool unique(string str);
void cipher(string key, string input);
char sub(string substitution, char character);

int main(int argc, string argv[])
{
    string cipher_key;

    if (argc != 2 || !valid(argv[1]) || !unique(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    else if (valid(argv[1]) && strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        cipher_key = argv[1];
    }

    string plain = get_string("plaintext: ");
    cipher(cipher_key, plain);
    return 0;
}

bool valid(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

bool unique(string str)
{
    bool checker[128] = {false};
    int length = strlen(str);

    for (int i = 0; i < length; i++)
    {
        int current = (int) str[i];

        if (!isalpha(str[i]) || checker[current])
        {
            return false;
        }
        checker[current] = true;
    }
    return true;
}

void cipher(string key, string input)
{
    char encrypted[strlen(input) + 1];
    int counter = 0;

    for (int i = 0; i < strlen(input); i++)
    {
        char current_char = input[i];
        char ciphered = sub(key, current_char);
        encrypted[i] = ciphered;
        counter++;
    }
    encrypted[counter] = '\0';
    printf("ciphertext: %s\n", encrypted);
}

char sub(string substitution, char character)
{
    char ciphertext;
    if (isalpha(character))
    {
        if (islower(character))
        {
            character = tolower(substitution[character - 'a']);
            ciphertext = character;
        }
        else if (isupper(character))
        {
            character = toupper(substitution[character - 'A']);
            ciphertext = character;
        }
        else
        {
            ciphertext = character;
        }
    }
    else
    {
        ciphertext = character;
    }
    return ciphertext;
}