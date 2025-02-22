#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int subset_of(struct node *head1, struct node *head2);
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

    int result = subset_of(head1, head2);
    printf("%d\n", result);

    return 0;
}

// subset_of should return 1 if every value in the first list occurs
// in the second.
// subset_of should return 0 otherwise
int subset_of(struct node *head1, struct node *head2) {

    struct node *list1 = head1;
    struct node *list2 = head2;
    
    
    
    while (list1 != NULL) {
    
        while (list2 != NULL && list1->data != list2->data) {
            list2 = list2->next;
        }
        
        if (list2 == NULL) {
            return 0;
        }
        
        list1 = list1 ->next;
        list2 = head2;
    }

    return 1;

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
