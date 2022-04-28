
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *head = NULL;

void display(){
    struct Node *ptr = head;
    if (ptr == NULL){
        printf("\nList empty");
        return;
    }
    while (ptr != NULL){
        printf("%d\t", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void insertAtBeginning(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = head;
    head = newNode;
}

void insertAtEnd(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    struct Node *end = head;
    if (end != NULL){
        while (end->link != NULL){
            end = end->link;
        }
        end->link = newNode;
    }
    else
        head = newNode;
}

void insertAfterPosition(int position, int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    struct Node *curr = head;
    while (curr != NULL && --position)
        curr = curr->link;
    if (curr == NULL){
        printf("\nPosition exceeded list size");
        return;
    }
    newNode->link = curr->link;
    curr->link = newNode;
}

void deleteElement(int element){
    struct Node *curr = head, *prev = NULL;
    while (curr != NULL && curr->data != element){
        prev = curr;
        curr = curr->link;
    }
    if (curr == NULL){
        printf("Element not found!\n");
        return;
    }
    if (prev == NULL)
        head = head->link;
    else
        prev->link = curr->link;

    free(curr);
}

int main()
{
    int ch, element, pos;
	printf("\n***MENU***");
    printf("\n1.Insert at beginning");
    printf("\n2.Insert at end");
    printf("\n3.Insert at position");
    printf("\n4.Delete node containing a particular element ");
    printf("\n5.Display linked list");
    printf("\n\n");
    do
    {
        printf("Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to insert : ");
            scanf("%d", &element);
            insertAtBeginning(element);
            break;
        case 2:
            printf("Enter element to insert : ");
            scanf("%d", &element);
            insertAtEnd(element);
            break;
        case 3:
            printf("Enter the position after which node will be inserted : ");
            scanf("%d", &pos);
            printf("Enter element to insert : ");
            scanf("%d", &element);
            insertAfterPosition(pos, element);
            break;
        case 4:
            printf("Enter element to delete : ");
            scanf("%d", &element);
            deleteElement(element);
            break;
        case 5:
            display();
            break;
        }
    } while (ch < 6);

    return 0;
}
