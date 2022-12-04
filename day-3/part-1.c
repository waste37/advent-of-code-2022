#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define ALPHABET 26
#define ITEM_TYPES 2*ALPHABET 

uint8_t counter[ITEM_TYPES] = {0}; 

uint8_t 
letter_value (char c) 
{
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 27;
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 1;
    }
    return -1;
}

uint8_t
letter_index(char c) 
{
    if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 26;
    }
}


int 
main (void)
{
    char *backpack = NULL;
    size_t nread = 0, result = 0, len = 0;
    size_t lines_count = 0;
    while ((nread = 
                getline (&backpack, &len, stdin)) != -1) {
        lines_count ++;
        for (size_t i = 0; i < nread / 2; ++i) {
            char item = backpack[i];
            if (counter[letter_index (item)] == 0) {
                counter[letter_index (item)]++; 
            }
        } 

        for (size_t i = nread / 2; i < nread; ++i) {
            char item = backpack[i];
            if (counter[letter_index (item)] + 1 == 2) {
                printf ("backpack: %.*s\nlength of the backpack is %zu\nthe double item was %c, of value %u\n", 
                        nread - 1, backpack, nread - 1, item, letter_value (item));
                result += letter_value (item);
                break;
            }
        }

        memset (counter, 0, ITEM_TYPES * sizeof (uint8_t));
    }

    printf ("the total amount of priorities is %lu, after %lu lines", result, lines_count);

    return 0;
}
