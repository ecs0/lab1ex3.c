#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *data;
    struct node* next;
};

// Two functions already implemented
struct node* makeNode(const char* data, struct node* n);
void printll(struct node* n);

// A function you will implement
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

    return 0;
}
void insertData(const char* data, struct node** ptrToHead, int location) {
        struct node* temp;
        struct node* tmp;
        temp = makeNode(data, NULL);
    if(location == 0) {
        tmp = (*ptrToHead);
        (*ptrToHead) = temp;
        (*ptrToHead)->next = tmp;
    } else {
        tmp = *ptrToHead;
        while((*ptrToHead)->next != NULL) {
            *ptrToHead = (*ptrToHead)->next;
        }
//        while(tmp->next != NULL) {
//            tmp = tmp->next;
//        }
//        tmp->next = temp;
//        (*ptrToHead) = tmp;
        (*ptrToHead)->next = temp;
        (*ptrToHead) = tmp;
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



