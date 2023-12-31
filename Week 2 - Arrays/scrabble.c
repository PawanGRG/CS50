#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char ALPHA[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int compute_score(string word);

int main(void)
{

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    char upper[strlen(word)];

    for (int a = 0; a < strlen(word); a++)
    {
        upper[a] = toupper(word[a]);
    }

    upper[strlen(word)] = '\0';

    // TODO: Compute and return score for string
    for (int i = 0; i < strlen(upper); i++)
    {
        // printf("UPPER: %c\n", upper[i]);
        for (int j = 0; j < strlen(ALPHA); j++)
        {
            if (upper[i] == ALPHA[j])
            {
                score += POINTS[j];
                break;
            }
            else if (ispunct(upper[i]))
            {
                score += 0;
            }
        }
    }
    return score;
}