// Assignment 2 20T1 COMP1511: CS bEats
// test_beats.c
//
// This program was written by YOUR-NAME-HERE (z5555555)
// on INSERT-DATE-HERE
//
// Version 1.0.0: Assignment released.
#include <stdio.h>
#include <stdlib.h>

#include "test_beats.h"
#include "beats.h"


// Test function for `add_note_to_beat`
int test_add_note_to_beat(void) {
    // Test 1: Rejecting negative inputs.
    Beat test_beat = create_beat();
    if (add_note_to_beat(test_beat, -1, -1) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, -1, 0) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 1, -1) != INVALID_KEY) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2: Rejecting inputs larger than specified
    // Octaves > 9, Keys > 11
    if (add_note_to_beat(test_beat, 12, 4) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 12, 12) != INVALID_OCTAVE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 5, 15) != INVALID_KEY) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 3: Rejecting notes smaller or equal to previous notes
    add_note_to_beat(test_beat, 1, 6);
    if (add_note_to_beat(test_beat, 1, 6) != NOT_HIGHEST_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }    
    if (add_note_to_beat(test_beat, 0, 10) != NOT_HIGHEST_NOTE) {
        return DOES_NOT_MEET_SPEC;
    }
    if (add_note_to_beat(test_beat, 1, 4) != NOT_HIGHEST_NOTE) {
        return DOES_NOT_MEET_SPEC;
    } 

    return MEETS_SPEC;
}

// Test function for `count_notes_in_octave`
int test_count_notes_in_octave(void){
    // Test 1: Counting invalid octaves.
    Beat test_beat = create_beat();
    add_note_to_beat(test_beat, 1, 1);
    if (count_notes_in_octave(test_beat, -1) != 0) {
        return DOES_NOT_MEET_SPEC;
    }
    if (count_notes_in_octave(test_beat, 11) != 0) {
        return DOES_NOT_MEET_SPEC;
    }

    // Test 2: Counting in an empty list (?) 
    // TODO: Write Test 2

    // Test 3: 
    // TODO: Write Test 3
    return MEETS_SPEC;
}

// Test function for `add_beat_to_track`
int test_add_beat_to_track(void){
    // Test 1: Adding when to track when there is no current beat
    Beat test_beat = create_beat();
    
    /*if () {
        return DOES_NOT_MEET_SPEC;
    }*/

    // Test 2: Adding to track when there is a current beat
    // TODO: Write Test 2

    // Test 3: Adding an empty beat to the track
    // TODO: Write Test 3

    return MEETS_SPEC;
}

// Test function for `remove_selected_beat`
int test_remove_selected_beat(void){
    // Test 1: When list is empty, do nothing
    

    // Test 2: ???
    // TODO: Write Test 2

    // Test 3: ???
    // TODO: Write Test 3

    return MEETS_SPEC;
}

// Test function for `add_musical_note_to_beat`
int test_add_musical_note_to_beat(void){
    // Test 1: ???
    // TODO: Write Test 1

    // Test 2: ???
    // TODO: Write Test 2

    // Test 3: ???
    // TODO: Write Test 3

    return MEETS_SPEC;
}
