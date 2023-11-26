#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int isWinner(int score1, int score2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    // comepare the two words
    // then print winner
    isWinner(score1, score2);
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    // Return the number of points for the word (iterate over the string given)
    // need to create a function for the score

    int score = 0; // initilize to 0
                   // convert the letters position on the ASCII to the proper index for the points array

    for (int i = 0; i < strlen(word); i++)
    {
        // if(word[i])
        // {

        // }
        if (isupper(word[i]))
        {
            score = score + POINTS[word[i] - 65];
        }
        if (islower(word[i]))
        {
            score = score + POINTS[word[i] - 97];
        }
    }
    return score;
}

int isWinner(score1, score2)
{
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("Its a tie!\n");
    }
    return 0;
}
