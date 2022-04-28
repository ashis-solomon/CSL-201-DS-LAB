#include<stdio.h>  
#include<stdlib.h>  

typedef struct node{  
    int data;  
    struct node *next;   
}listNode;  

listNode *front;  

void display(){  
    listNode *ptr;  
    ptr = front;  
    if(front == NULL){  
        printf("EMPTY!!");  
    }     
    else{  
        printf("The List : ");       
        while(ptr->next != front){  
            printf("  %d  ", ptr -> data);  
            ptr = ptr->next;  
        }  
        printf("  %d\n", ptr -> data);  
    }  
}  

void insert_begin(){ 
    listNode *ptr,*temp;   
    int item;   
    ptr = (listNode*)malloc(sizeof(listNode));  
    if(ptr == NULL)  
    {  
        printf("OVERFLOW!!!");  
    }  
    else   
    {  
        printf("Enter the element to be inserted : ");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL){  
            front = ptr;  
            ptr->next = front;  
        }  
        else{     
            temp = front;  
            while(temp->next != front)  
                temp = temp->next;  
            ptr->next = front;   
            temp -> next = ptr;   
            front = ptr;  
        }    
    }  
              
}  
void insert_last(){  
    listNode *ptr,*temp;   
    int item;  
    ptr = (listNode *)malloc(sizeof(listNode));  
    if(ptr == NULL){  
        printf("OVERFLOW");  
    }  
    else{  
        printf("Enter the element to be inserted : ");  
        scanf("%d",&item);  
        ptr->data = item;  
        if(front == NULL){  
            front = ptr;  
            ptr->next = front;    
        }  
        else{  
            temp = front;  
            while(temp -> next != front){  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr->next = front;  
        }  
    }  
  
}  
  
void delete_begin(){  
    listNode *ptr;   
    if(front == NULL){  
        printf("UNDERFLOW!!!");    
    }  
    else if(front->next == front){  
        front = NULL;  
        free(front);  
    }  
    else{   
        ptr = front;   
        while(ptr->next != front)  
            ptr = ptr->next;   

        ptr->next = front->next;  
        free(front);  
        front = ptr->next;  
    }  
    display();
}  
void delete_last(){  
    listNode *ptr, *temp;  
    if(front == NULL){  
        printf("UNDERFLOW!!!");  
    }  
    else if(front->next == front){  
        front = NULL;  
        free(front);  
    }  
    else{  
        ptr = front;  
        while(ptr->next != front){  
            temp=ptr;  
            ptr = ptr->next;  
        }  
        temp->next = ptr->next;  
        free(ptr);  
    }  
    display();
}  

void main(){  
    int choice =0;  
    printf("\n***MENU***\n");  
    printf("\n1.Insert at Begining\n2.Insert at End");
    printf("\n3.Delete from Beginning\n4.Delete from last\n5.Display\n6.Exit\n\n");
    while(choice!=6){  
        printf("\nEnter the Menu choice : ");         
        scanf("%d",&choice);  
        switch(choice){  
            case 1 :    insert_begin();
                        break;  
            case 2 :    insert_last();
                        break;  
            case 3 :    delete_begin();
                        break;  
            case 4 :    delete_last();
                        break;  
            case 5 :    display();
                        break;  
            case 6 :    return;
                        break;  
            default:    printf("\nEnter a valid choice !!\n");  
        }  
    }  
}  