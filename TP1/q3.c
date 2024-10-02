//
// Created by matthieu on 01/10/24.
//

#include "main.h"

typedef struct Node NODE;

struct Node{
    int data;
    NODE* next;
    NODE* previous;
};

NODE* create_node(int data) {
    NODE* new_node = malloc(sizeof(NODE));
    new_node->data = data;
    new_node->next = NULL;
    new_node->previous = NULL;
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
        current->next->previous = current;
        current = current->next;
    }


    // Make the list circular
    current->next = head;
    head->previous = current;

    return head;
}

int linked_list_length(NODE* head) {
    int length = 0;
    NODE* current = head;
    current = current->next;
    length++;

    while (current != head) {
        length++;
        current = current->next;
    }

    return length;
}

void print_linked_list(NODE* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }

    NODE* current = head;
    printf("<%p>, %d -> ", (void*)current, current->data);
    current = current->next;
    while (current != head) {
        printf("<%p>, %d -> ", (void*)current, current->data);
        current = current->next;
    };
    printf("<%p>, %d \n ", (void*)current, current->data);
}

void remove_first_node(NODE** head) {
    if (*head == NULL) {
        return;
    }

    NODE* last = (*head)->previous;
    NODE* tmp = *head;

    if (*head == (*head)->next) {
        *head = NULL;
    } else {
        *head = (*head)->next;
        (*head)->previous = last;
        last->next = *head;
    }

    free(tmp);
}

void remove_last_node(NODE** head) {
    if (*head == NULL) {
        return;
    }

    NODE* last = (*head)->previous;
    NODE* tmp = last;

    if (*head == last) {
        *head = NULL;
    } else {
        last->previous->next = *head;
        (*head)->previous = last->previous;
    }

    free(tmp);
}

void add_last_node(NODE** head, int data) {
    NODE* new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    NODE* last = (*head)->previous;

    last->next = new_node;
    new_node->previous = last;
    new_node->next = *head;
    (*head)->previous = new_node;
}

void add_first_node(NODE** head, int data) {
    NODE* new_node = create_node(data);

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    NODE* last = (*head)->previous;

    new_node->next = *head;
    new_node->previous = last;
    last->next = new_node;
    (*head)->previous = new_node;
    *head = new_node;
}

//concatenate two circular linked list
void concatenate_linked_list(NODE** head1, NODE** head2) {
    if (*head1 == NULL) {
        *head1 = *head2;
        return;
    }

    if (*head2 == NULL) {
        return;
    }

    NODE* last1 = (*head1)->previous;
    NODE* last2 = (*head2)->previous;

    last1->next = *head2;
    (*head2)->previous = last1;
    last2->next = *head1;
    (*head1)->previous = last2;
}

int square(int x) {
    return x * x;
}


void apply_function(NODE **head, int(*func)(int)) {
    if (*head == NULL) {
        return;
    }

    NODE* current = *head;
    do {
        current->data = func(current->data);
        current = current->next;
    } while (current != *head);
}

void check_double_chained(NODE* head) {
    NODE* current = head;
    NODE* last = NULL;

    if (current != NULL) {
        printf("<%p>, %d -> ", (void*)current, current->data);
        last = current;
        current = current->next;
        while (current != head) {
            printf("<%p>, %d -> ", (void*)current, current->data);
            last = current;
            current = current->next;
        }
        printf("<%p>, %d \n ", (void*)current, current->data);

        current = last;
        printf("<%p>, %d <- ", (void*)current, current->data);
        current = current->previous;
        while (current != last) {
            printf("<%p>, %d <- ", (void*)current, current->data);
            current = current->previous;
        }
        printf("<%p>, %d \n ", (void*)current, current->data);
    }
}


int q3_main() {
    //printf("Hello, World!\n");
    printf("Create first linked list\n");
    NODE* head1 = create_linked_list(10);
    print_linked_list(head1);
    printf("Length of the linked list: %d\n", linked_list_length(head1));
    printf("\n");


    printf("Remove first node\n");
    remove_first_node(&head1);
    print_linked_list(head1);
    printf("Length of the linked list: %d\n", linked_list_length(head1));
    printf("\n");

    printf("Remove last node\n");
    remove_last_node(&head1);
    print_linked_list(head1);
    printf("Length of the linked list: %d\n", linked_list_length(head1));
    printf("\n");

    printf("Add last node\n");
    add_last_node(&head1,42);
    print_linked_list(head1);
    printf("Length of the linked list: %d\n", linked_list_length(head1));
    printf("\n");

    printf("Add first node\n");
    add_first_node(&head1,0);
    print_linked_list(head1);
    printf("Length of the linked list: %d\n", linked_list_length(head1));
    printf("\n");

    printf("Create second linked list\n");
    NODE* head2 = create_linked_list(5);
    print_linked_list(head2);
    printf("Length of the linked list: %d\n", linked_list_length(head2));
    printf("\n");

    printf("Concatenate linked list\n");
    concatenate_linked_list(&head1,&head2);
    print_linked_list(head1);
    printf("Length of the linked list: %d\n", linked_list_length(head1));
    printf("\n");

    printf("Apply square function\n");
    apply_function(&head1,square);
    print_linked_list(head1);
    printf("\n");

    printf("Check if the list is double chained\n");
    check_double_chained(head1);

    return 0;
}
