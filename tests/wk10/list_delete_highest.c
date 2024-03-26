#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *delete_highest(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct node *new_head = delete_highest(head);
    print_list(new_head);

    return 0;
}


//
// Delete the node(s) in the list that contain the highest value
// The deleted node(s) are freed.
// The head of the list is returned.
//
struct node *delete_highest(struct node *head) {

    struct node *curr = head;
    struct node *prev = NULL;
    
    int max = -10000;
    
    while (curr != NULL) {
        
        if (curr->data > max) {
            max = curr->data;
        }
        
        curr = curr->next;
    }
    
    curr = head;
    
    while (curr != NULL) {
        
        if (curr != NULL && curr->data == max) {
            head = curr->next;
            free(curr);
            curr = head;
        }
        
        while (curr != NULL && curr->data == max) {
            prev = curr;
            curr = curr->next;
        } 
        
        if (curr == NULL) {
            return head;
        }
        
        prev->next = curr->next;
        
        free(curr);
        
        curr = prev->next;
    }

    return head;

}


// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i -= 1;
    }   
    return head;
}

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");    
    struct node *n = head;
    while (n != NULL) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}
