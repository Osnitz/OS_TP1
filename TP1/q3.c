//
// Created by matthieu on 01/10/24.
//

#include "main.h"

typedef struct Node NODE;

struct Node{
    int data;
    NODE* next;
};

NODE* create_node(int data) {
    NODE* new_node = malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// function to create and return a linked list containing integers from 1 to n
NODE* create_linked_list(int n) {
    if (n <= 0) {
        return NULL;
    }

    NODE* head = create_node(1);
    NODE* current = head;

    for (int i = 2; i <= n; i++) {
        current->next = create_node(i);
        current = current->next;
    }

    return head;
}

int linked_list_length(NODE* head) {
    int length = 0;
    NODE* current = head;

    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length;
}

void print_linked_list(NODE* head) {
    NODE* current = head;
    while (current != NULL) {
        printf("<%p>, %d -> ",(void*)current, current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void remove_first_node(NODE** head) {
    if (*head == NULL) {
        return;
    }

    NODE* tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void remove_last_node(NODE** head) {
    if (*head == NULL) {
        return;
    }

    NODE* current = *head;
    NODE* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        *head = NULL;
    } else {
        previous->next = NULL;
    }

    free(current);
}

void add_last_node(NODE** head, int data) {
    NODE* new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    NODE* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
}

void add_first_node(NODE** head, int data) {
    NODE* new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

void concatenate_linked_list(NODE** head1, NODE** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }

    NODE* current = *head1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = *head2;
}


int main() {
    //printf("Hello, World!\n");
    NODE* head1 = create_linked_list(10);
    print_linked_list(head1);
    printf("Length of the linked list: %d\n", linked_list_length(head1));

    remove_first_node(&head1);
    print_linked_list(head1);
    printf("Length of the linked list: %d\n", linked_list_length(head1));

    remove_last_node(&head1);
    print_linked_list(head1);
    printf("Length of the linked list: %d\n", linked_list_length(head1));

    add_last_node(&head1,42);
    print_linked_list(head1);
    printf("Length of the linked list: %d\n", linked_list_length(head1));

    add_first_node(&head1,0);
    print_linked_list(head1);
    printf("Length of the linked list: %d\n", linked_list_length(head1));

    NODE* head2 = create_linked_list(5);
    print_linked_list(head2);
    printf("Length of the linked list: %d\n", linked_list_length(head2));

    concatenate_linked_list(&head1,&head2);
    print_linked_list(head1);
    printf("Length of the linked list: %d\n", linked_list_length(head1));

    return 0;
}
