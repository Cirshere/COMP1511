// Compare two Note structs
// list_compare.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// A struct note * IS a Note
typedef struct note *Note;

//There are 10 octaves (0 to 9) and 12 notes (0 to 11)
struct note {
    int octave;
    int key;
    struct note *next;
};

int note_compare(Note a, Note b);

//Returns 1 if a is higher than b
//       -1 if b is higher than a
//        0 if they are equal
int note_compare(Note a, Note b) {

    int result = 0;

    if(a->octave == b->octave && a->key == b->key) {
        result = 0;
    }        
    else if (a->octave > b->octave) {
        result = 1;
    }
    else if (a->octave == b->octave && a->key > b->key) {
        result = 1;
    }
    else {
        result = -1;
    }
    
    return result;

}
int main(void) {

    int octave, key;
    scanf("%d %d", &octave, &key);
    // NOTE: the {octave, key, NULL} syntax is short for
    // a.octave = octave; a.key = key; a.next = NULL;
    struct note a = {octave, key, NULL};
    scanf("%d %d", &octave, &key);
    struct note b = {octave, key, NULL};
    int compared = note_compare(&a, &b);
    if (compared == 1) {
        printf("a is higher than b\n");
    } else if (compared == -1) {
        printf("b is higher than a\n");
    } else {
        printf("a and b are equal\n");
    }
    

    return 0;
}
