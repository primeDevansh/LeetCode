#include <stdio.h>
#include <stdlib.h>

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
    struct ListNode* l3 = NULL;
    struct ListNode* h3 = NULL;
    int carry = 0, sum = 0;

    while(l1 != NULL || l2 != NULL || carry > 0) {
        sum = 0;

        if(l1 != NULL) {
            sum += l1 -> val;
            l1 = l1 -> next;
        }
        if(l2 != NULL) {
            sum += l2 -> val;
            l2 = l2 -> next;
        }

        sum += carry;
        carry = sum / 10;

        if(l3 == NULL) {
            l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
            l3 -> val = sum % 10;
            l3 -> next = NULL;
            h3 = l3;
        }
        else {
            l3 -> next = (struct ListNode*)malloc(sizeof(struct ListNode));
            l3 = l3 -> next;
            l3 -> val = sum % 10;
            l3 -> next = NULL;
        }
    }
    return h3;
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