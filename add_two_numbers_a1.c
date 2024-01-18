#include <stdio.h>
#include <stdlib.h>

/*
 * The logic is cool for small numbers (represented as linked lists) but fails miserably when applied for large numbers because of the size limitation of an integer variable.
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

void addNode(struct ListNode** head) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* current = NULL;

    printf("Enter value of node : ");
    scanf(" %d", &(temp -> val));
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* c3 = l3; //current node for l3 list
    unsigned long i = 1;
    unsigned long sum = 0;

    l3 -> val = 0;
    l3 -> next = NULL;

    while(l1 != NULL || l2 != NULL) {
        if(l1 != NULL) {
            sum += i * (l1 -> val);
            l1 = l1 -> next;
        }
        if(l2 != NULL) {
            sum += i * (l2 -> val);
            l2 = l2 -> next;
        }
        i *= 10;
    }

    while(sum) {
        c3 -> val = sum % 10;
        sum /= 10;
        if(sum) {
            c3 -> next = (struct ListNode*)malloc(sizeof(struct ListNode));
            c3 = c3 -> next;
            c3 -> next = NULL;
        }
    }
    return l3;
}

int main() {
    struct ListNode* h1 = NULL;
    struct ListNode* h2 = NULL;
    struct ListNode* h3 = NULL;

    printf("Enter elements of list 1 : \n");
    addNodes(&h1);
    printf("Enter elements of list 2 : \n");
    addNodes(&h2);

    h3 = addTwoNumbers(h1, h2);
    printf("\nElements of List 3 (RESULT LIST) are : \n"); 
    displayNodes(h3);
    printf("\n");
    return 0;
}