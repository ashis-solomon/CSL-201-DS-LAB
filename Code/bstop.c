#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}treeptr;


treeptr *newNode(int value){
    treeptr *node = (treeptr*)malloc(sizeof(treeptr));
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

treeptr *insert(treeptr *node,int value){
    if(node==NULL){          //tree empty condition
        return newNode(value);
    }
    if(value<node->data){    
        node->left = insert(node->left,value);
    }
    else if(value>node->data){
        node->right = insert(node->right,value);
    }
    return node;
}

treeptr *findMin(treeptr* node)
{
	while(node->left != NULL) 
        node = node->left;
	return node;
}

treeptr *delete(treeptr *node, int data) {
	if(node == NULL) 
        return node; 
	else if(data < node->data) 
        node->left = delete(node->left,data);
	else if (data > node->data) 
        node->right = delete(node->right,data);

	else {
		if(node->left == NULL && node->right == NULL) { 
			free(node);
			node = NULL;
		}
		else if(node->left == NULL) {
			treeptr *temp = node;
			node = node->right;
			free(temp);
		}
		else if(node->right == NULL) {
			treeptr *temp = node;
			node = node->left;
			free(temp);
		}
		else { 
			treeptr *temp = findMin(node->right);
			node->data = temp->data;
			node->right = delete(node->right,temp->data);
		}
	}
	return node;
}

void inorderTrav(treeptr *node){
    if(!node) return;
    inorderTrav(node->left);
    printf("%d  ",node->data);
    inorderTrav(node->right);
}

treeptr *search(treeptr *node,int value){
    if(node == NULL || node->data==value){  
        return node;
    }
    if(node->data>value){
        return search(node->left,value);
    }
    if(node->data<value){
        return search(node->right,value);
    }
}


void preorderTrav(treeptr *node){
    if(!node) return;
    printf("%d  ",node->data);
    preorderTrav(node->left);
    preorderTrav(node->right);
}

void postorderTrav(treeptr *node){
    if(!node) return;
    postorderTrav(node->left);
    postorderTrav(node->right);
    printf("%d  ",node->data);
}

void main(){
    treeptr *root = NULL;
    treeptr *srch = NULL;
    int choice,c=1;
    int ele;
    inorderTrav(root);
    printf("*****MENU*****\n\n");
    printf("1.Insert Node\n");
    printf("2.Preorder Traversal\n");
    printf("3.Inorder Traversal\n");
    printf("4.Postorder Traversal\n");
    printf("5.Delete Node\n");
    printf("6.Search for Element\n");
    printf("7.Exit\n");
    while(c>=1){
        printf("\nEnter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the element to be inserted : ");
                    scanf("%d",&ele);
                    if(c==1){root = insert(root,ele);c++;}
                    else{
                        insert(root,ele);
                    }
                    break;
            case 2: printf("\nPreorder :\n");
                    preorderTrav(root);
                    break;
            case 3: printf("\nInorder :\n");
                    inorderTrav(root);
                    break;
            case 4: printf("\nPostorder :\n");
                    postorderTrav(root);
                    break;
            case 5: printf("\nEnter the element to be Deleted : ");
                    scanf("%d",&ele);
                    delete(root,ele);
                    printf("\nDeleted !!");
                    break;
            case 6: printf("\nEnter the element to be searched : ");
                    scanf("%d",&ele);
                    srch = search(root,ele);
                    if(srch == NULL){
                        printf("\nElement Not Found !!!");
                    }
                    else{
                        printf("\nElement Found !!!");
                    }
                    break;
            case 7: return;
            default: printf("\nEnter a Valid Choice !!!");
        }
    }
    
}