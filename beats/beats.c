// Assignment 2 20T1 COMP1511: CS bEats
// beats.c
//
// This program was written by Christopher Hoang (z5259780)
// on 20/04/2020
//
// Version 1.0.0: Assignment released.
// Version 1.0.1: Fix default return value of add_musical_note_to_beat.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Add any extra #includes your code needs here.

#include "beats.h"

// Add your own #defines here.

#define OCTAVE_MAX 9
#define KEY_MAX 11

////////////////////////////////////////////////////////////////////////

// You don't have to use the provided struct track, you are free to
// make your own struct instead.
// If you use the provided struct track, you will have to add fields
// to store other information.

struct track {

    struct beat *head;
    struct beat *curr;
};

// You don't have to use the provided struct beat, you are free to
// make your own struct instead.
// If you use the provided struct beat, you may add fields
// to it to store other information.

struct beat {
    // You may choose to add or change fields in this struct.
    struct note *notes;
    struct beat *next;
};

// You don't have to use the provided struct note, you are free to
// make your own struct instead.
// If you use the provided struct note, you add fields
// to it to store other information.

struct note {
    // You may choose to add or change fields in this struct.
    int octave;
    int key;
    struct note *next;
};

// Add any other structs you define here.

////////////////////////////////////////////////////////////////////////

// Add prototypes for any extra functions you create here.



// Return a malloced Beat with fields initialized.
Beat create_beat(void) {
    Beat new_beat = malloc(sizeof (struct beat));
    assert(new_beat != NULL);

    new_beat->next = NULL;
    new_beat->notes = NULL;

    // You do not need to change this function, unless you change
    // the implementation of struct beat.

    return new_beat;    
}

// You need to implement the following functions.
// You can find descriptions of what each function should do in beats.h

////////////////////////////////////////////////////////////////////////
//                         Stage 1 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add a note to the end of a beat.
int add_note_to_beat(Beat beat, int octave, int key) {
         
    struct note *newNote = malloc(sizeof(struct note));    

    newNote->octave = octave;
    newNote->key = key;
    newNote->next = NULL;

    // Check if the octave and the key is valid
    if (octave < 0 || octave > OCTAVE_MAX) {
        return INVALID_OCTAVE;
    } else if (key < 0 || key > KEY_MAX) {
        return INVALID_KEY;
    }
    
    struct note *curr = beat->notes;
    
    // Check if this is first note
    if (curr == NULL) {
        beat->notes = newNote;
    } else {
        // Loop through until the end
        while (curr->next != NULL) {
            curr = curr->next;
        }
        // Check if octave is higher than octave of previous note
        if (curr->octave > octave) {
            return NOT_HIGHEST_NOTE;
        }
        //Check if octave is equal and if key is higher than previous note
        else if (curr->key >= key && beat->notes->octave == octave) {
            return NOT_HIGHEST_NOTE;
        // Else add note to the end of the list
        } else {       
            curr->next = newNote;                       
        }                
    }
              
    return VALID_NOTE;
}

// Print the contents of a beat.
void print_beat(Beat beat) {
    
    struct note *curr = beat->notes;
    
    // Loop through the list
    while (curr != NULL) {
        
        // Print octave and key of note
        printf("%d %02d", curr->octave, curr->key);
        
        if (curr->next != NULL) {
            printf (" | ");
        }
        
        curr = curr->next;
    
    }
    
    printf("\n");
    
    return;
}

// Count the number of notes in a beat that are in a given octave.
int count_notes_in_octave(Beat beat, int octave) {

    struct note *curr = beat->notes;
    int total = 0;
    
    while (curr != NULL) {
        // Counts note w/ octaves equal to given octave
        if(curr->octave == octave) {
            total++;
        }
        
        curr = curr->next;
        
    }    
    
    return total;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 2 Functions                          //
////////////////////////////////////////////////////////////////////////

// Return a malloced track with fields initialized.
Track create_track(void) {

    Track newTrack = malloc(sizeof(struct track));

    newTrack->head = NULL;
    newTrack->curr = NULL;

    return newTrack;
}

// Add a beat after the current beat in a track.
void add_beat_to_track(Track track, Beat beat) {   
    

    if (track->curr == NULL && track->head == NULL) {
        track->head = beat;

    } else if (track->curr == NULL) {
        beat->next = track->head;
        track->head = beat;

        
    } else {
        beat->next = track->curr->next;
        track->curr->next = beat;

    }
                   
    return;
}

// Set a track's current beat to the next beat.
int select_next_beat(Track track) {
    
    if (track->head == NULL) {
        return TRACK_STOPPED;
    }
    
    if (track->curr == NULL) {
        track->curr = track->head;
    } else if (track->curr->next == NULL) {
        track->curr = NULL;
        return TRACK_STOPPED;
    } else {
        track->curr = track->curr->next;
    }
    
    return TRACK_PLAYING;
}

// Print the contents of a track.
void print_track(Track track) {


    if (track->head == NULL) {
        return;
    }
    
    Beat beat = track->head;
    struct note *note = beat->notes;
    
    int noteNum = 1; 
        
    while (beat != NULL) {
        
        if (track->curr == beat) {
            printf (">[%d] ", noteNum);
        } else {
            printf (" [%d] ", noteNum);
        }
        
        while (note != NULL) {
            
            printf ("%d %02d", note->octave, note->key);
            
            if (note->next != NULL) {
                printf (" | ");
            }   
            
            note = note->next;       
        }
        
        printf("\n");
        
        noteNum++;
        beat = beat->next;
        if (beat != NULL) {
            note = beat->notes;
        }
    }    
        
    return;
}

// Count beats after the current beat in a track.
int count_beats_left_in_track(Track track) {
    
    Beat curr = track->curr;
    Beat head = track->head;
    
    int beatCount = 0;
    
    if (curr == NULL) {
        
        while (head != NULL) {
            
            beatCount++;            
            head = head->next;
        }    
        
    } else {    
        while (curr->next != NULL) {
            
            beatCount++;            
            curr = curr->next;    
        }
    }      
    
    return beatCount;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 3 Functions                          //
////////////////////////////////////////////////////////////////////////

// Free the memory of a beat, and any memory it points to.
void free_beat(Beat beat) {
    // Note: there is no printf in this function, as the
    // Stage 1 & 2 autotests call free_beat but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1 & 2, rather than exit).
    
    
    struct note *curr;
    
    while (beat->notes != NULL) {
    
        curr = beat->notes;
        beat->notes = beat->notes->next;
        free(curr);
    
    }
    
    free(beat);
    
    return;
}

// Free the memory of a track, and any memory it points to.
void free_track(Track track) {
    // Note: there is no printf in this function, as the
    // Stage 1 & 2 autotests call free_track but don't check whether
    // the memory has been freed (so this function should do nothing in
    // Stage 1 & 2, rather than print an error).
    return;
}

// Remove the currently selected beat from a track.
int remove_selected_beat(Track track) {
   
    Beat prev = NULL;
    Beat curr = track->head;
    
    if (track->curr == NULL) {
        return 0;
    }
    
    while (curr != track->curr) {
        prev = curr;
        curr = curr->next;
    }
    
    if (track->curr->next != NULL) {
        track->curr = track->curr->next;
        
        if (prev != NULL) {
            prev->next = curr->next;
        } else {
            track->head = curr->next;
        }
        
        return TRACK_PLAYING;
    
    } else {        
        if (track->curr == track->head) {
            track->head = NULL;
        }
        track->curr = NULL;       
    }
    
    if (track->curr == NULL) {
        return TRACK_STOPPED;
    }
    
    
    
    return TRACK_STOPPED;
}

////////////////////////////////////////////////////////////////////////
//                         Stage 4 Functions                          //
////////////////////////////////////////////////////////////////////////

// Add note to beat, given its 'musical notation'.
int add_musical_note_to_beat(Beat beat, char *musical_notation) {
    printf("add_musical_note_to_beat not implemented yet.");
    return VALID_NOTE;
}


////////////////////////////////////////////////////////////////////////
//                         Stage 5 Functions                          //
////////////////////////////////////////////////////////////////////////

// Cut a range of beats to the end of a track.
void cut_range_to_end(Track track, int range_length) {
    printf("cut_range_to_end not implemented yet.");
    return;
}

// Reverse a list of beats within a range of a track.
int reverse_range(Track track, int range_length) {
    printf("reverse_range not implemented yet.");
    return 0;
}
