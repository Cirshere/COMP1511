#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int have_zeroes(struct node *head1, struct node *head2);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create two linked lists from command line arguments
    int dash_arg = argc - 1;
    while (dash_arg > 0 && strcmp(argv[dash_arg], "-") != 0) {
        dash_arg = dash_arg - 1;
    }
    struct node *head1 = strings_to_list(dash_arg - 1, &argv[1]);
    struct node *head2 = strings_to_list(argc - dash_arg - 1, &argv[dash_arg + 1]);

    int result = have_zeroes(head1, head2);
    printf("%d\n", result);

    return 0;
}

// have_zeroes should return 0 if neither list contains zero.
// have_zeroes should return 1 one list contains zero, but the other doesn't.
// have_zeroes should return 2 if both lists contain zeroes.
int have_zeroes(struct node *head1, struct node *head2) {
    
    // 0 for no zeroes, 1 for zeroes
    int result1 = 0;
    int result2 = 0; 
    
    struct node *list1 = head1;
    struct node *list2 = head2;
    
    while (list1 != NULL) {
        if (list1->data == 0) {
            result1 = 1;
        }
        list1 = list1->next;
    }
    while (list2 != NULL) {
        if (list2->data == 0) {
            result2 = 1;
        }
        list2 = list2->next;
    }
    
    if (result1 == 1 && result2 == 1) {
        return 2;
    } else if (result1 == 1 || result2 == 1) {
        return 1;    
    }

    return 0;

}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
