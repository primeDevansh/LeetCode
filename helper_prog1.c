#include <stdio.h>
#include <stdlib.h>

/*
 * Helper Program for add_two_numbers' LINKED LIST element
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

void addNode(struct ListNode** head) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = NULL;
    temp -> val = 0;
    temp -> next = NULL;

    if(*head == NULL) {
        *head = temp;
    }
    else {
        current = *head;
        while(current -> next) {
            current = current -> next;
        }
        current -> next = temp;
    }
    return;
}

void addNodes(struct ListNode** head) {
    char choice;
    do {
        addNode(head);
        printf("Do you want to add another node? (y/n) : ");
        scanf(" %c", &choice);
    }while(choice == 'y' || choice == 'Y');
    return;
}

void displayNodes(struct ListNode* head) {
    struct ListNode* current = head;
    if(head) {
        while(current) {
            printf("%d\t", current -> val);
            current = current -> next;
        }
    }
    else {
        printf("\nLIST IS EMPTY!");
    }
}

int main() {
    struct ListNode* head = NULL;

    addNodes(&head);
    displayNodes(head);
    printf("\n");
    return 0;
}