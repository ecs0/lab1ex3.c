#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *data;
    struct node* next;
};

struct node* makeNode(const char* data, struct node* n);
void printll(struct node* n);

void insertData(const char* data, struct node** ptrToHead, int location);

int main() {
    struct node* head=NULL;
    head = makeNode("Bob",NULL);

//    head->next = makeNode("Sue",NULL);
//    head->next->next = makeNode("Arya",NULL);

    printll(head);

    insertData("Sue",&head,0);
    printll(head);
    insertData("Jack",&head,1);
    printll(head);
    insertData("Arya",&head,1);
    printll(head);
    insertData("Tyrion",&head,0);
    printll(head);
// insert bad data
    insertData("Tyrion",&head,9);
    printll(head);

    return 0;
}
/*
 * Insert data into singly linked list
 * location 0 inserts at the beginning of the list
 * location 1 inserts at the end of the list
 * Error if location not 0 or 1.
 */
void insertData(const char* data, struct node** ptrToHead, int location) {
        struct node* temp;
        struct node* tmp;
        temp = makeNode(data, NULL);
    if(location == 0) {
        temp->next = (*ptrToHead);
        (*ptrToHead) = temp;
    } else if(location == 1) {
        tmp = *ptrToHead;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = temp;
    } else {
        printf("Invalid Location");
        exit(1);
    }
}

struct node* makeNode(const char* data, struct node* n) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = (char*)malloc((strlen(data)+1)*sizeof(char));
    strcpy(temp->data, data);
    temp->next = n;
    return temp;
}

void printll(struct node* n) {
    while(n!=NULL && n->next !=NULL) {
        printf("%s ---> ",n->data);
        n = n->next;
    }
    if(n!=NULL) printf("%s\n",n->data);
}
