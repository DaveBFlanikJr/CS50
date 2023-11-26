#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get the starting text:
    string passage = get_string("Passage: ");

    // Call count_letters and store the result
    int letter_count = count_letters(passage);

    // same as above for words
    int word_count = count_words(passage);

    // same for sentences
    int sentence_count = count_sentences(passage);

    // print result for now
    printf("Number of letters: %d\n", letter_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of sentences: %d\n", sentence_count);

    // Now we calculate the grade level
    float l = 100 * (letter_count / (float) word_count);
    float s = 100 * (sentence_count / (float) word_count);

    // Calculate Coleman-Liau index
    int index = round(0.0588 * l - 0.296 * s - 15.8);

    if (index <= 1) // if its equal to 1 OR less
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16) // if its 16 OR higher
    {
        printf("Grade 16+\n");
    }
    else // print the Grade: level
    {
        printf("Grade %i\n", index);
    }

    return 0;
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 97 && text[i] <= 122) || (text[i] >= 65 && text[i] <= 90))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int word_count = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 32)
        {
            word_count++;
        }
    }
    return word_count;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentence_count++;
        }
    }
    return sentence_count;
}
