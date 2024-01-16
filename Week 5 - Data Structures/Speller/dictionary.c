// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Global variable for the word counter
unsigned int counter = 0;

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value += (unsigned char) tolower(word[i]);
    }
    return hash_value % N;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{

    char lower_case[LENGTH + 1];
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        lower_case[i] = tolower(word[i]);
    }

    lower_case[length] = '\0';

    unsigned int index = hash(lower_case);

    node *cursor = table[index];

    // Traverse the linked list at the bucket
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, lower_case) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");

    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    // Read words from dictionary
    while (fscanf(file, "%s", word) != EOF)
    {
        // Allocate memory for new node
        node *new_node = malloc(sizeof(node));
        
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        strcpy(new_node->word, word);

        // Hash word to obtain a hash index
        unsigned int index = hash(word);

        // Insert node into hash table
        new_node->next = table[index];
        table[index] = new_node;

        // Counts the number of words in dictonary
        counter++;
    }

    // Close dictionary file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

bool unload(void)
{
    // Iterate through each bucket in the hash table
    for (int i = 0; i < N; i++)
    {
        // Set cursor to the head of the list
        node *cursor = table[i];

        // Traverse the linked list and free nodes
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }

    return true;
}
