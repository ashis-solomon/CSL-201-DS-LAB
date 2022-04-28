#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}treeptr;


treeptr* create(int val){
	treeptr* node = (treeptr*)malloc(sizeof(treeptr));
	node->data = val;
	node->left = node->right =  NULL;
	return node;
}

treeptr* insert(treeptr* node,int val){
	if(node==NULL)
		return create(val);

	if(node->data>val){
		node->left = insert(node->left,val);
	}
	else if(node->data<val){
		node->right = insert(node->right,val);
	}
	return node;
}

void inorder(treeptr* node){
	if(!node){return;}
	inorder(node->left);
	printf("%d\t",node->data);
	inorder(node->right);
}

void preorder(treeptr* node){
	if(!node){return;}
	printf("%d\t",node->data);
	preorder(node->left);	
	preorder(node->right);
}

void postorder(treeptr* node){
	if(!node){return;}
	postorder(node->left);
	postorder(node->right);
	printf("%d\t",node->data);
}

void search(treeptr* node,int ele){
	if(node==NULL){
		printf("Element not found !!!\n");
		return;
	}
	if(node->data == ele){
		printf("Element found !!!\n");
		return;
	}
	else if(node->data < ele){search(node->right,ele);}
	else if(node->data > ele){search(node->right,ele);}
}

treeptr* findMin(treeptr* node){
	while(node->left!=NULL)
		node = node->left;
	return node;
}

treeptr* delete(treeptr* node,int ele){
	if(node==NULL){
		printf("BST is empty!!\n");
		return node;
	}
	if(ele<node->data){
		node->left = delete(node->left,ele);
	}
	else if(ele>node->data){
		node->right = delete(node->right,ele);
	}
	else{
		if(node->right==NULL && node->left==NULL){
			free(node);  
			node = NULL;
 		}
		else if(node->left == NULL){
			treeptr* temp = node;
			node = node->right;
			free(temp);
		}
		else if(node->right == NULL){
			treeptr* temp = node;
			node = node->left;
			free(temp);
		}
		else{
			treeptr* temp = findMin(node->right);
			node->data = temp->data;
			node->right = delete(node->right,temp->data);
		}
	}
	return node;
}

int no_Leafnode(treeptr* node){
	if(node==NULL)
		return 0;
	if(node->left==NULL && node->right==NULL)
		return 1;
	else 
		return no_Leafnode(node->right) + no_Leafnode(node->left);
}

int no_Nodes(treeptr* node){
	if(node==NULL)
		return 0;
	else return 1 + no_Nodes(node->left) + no_Nodes(node->right);
}

int height(treeptr* node){
	if(node==NULL)
		return -1;
	else{
		int l_height = height(node->left);
		int r_height = height(node->right);
		if(r_height>l_height)
			return r_height + 1;
		else
			return l_height + 1;
	}
}

void main(){

	treeptr* root=NULL;

	printf("***MENU***\n\n");
	printf("1.Insert\n2.Inorder Traversal\n3.Preorder Traversal\n4.Postorder Traversal\n");
	printf("5.Search\n6.Delete\n7.No of Leaf Nodes\n8.No of Nodes\n9.Height\n10.Exit\n");
	printf("\n\n");
	int choice,ele,num;
	repeat:
	printf("Enter the menu choice : ");
	scanf("%d",&choice);
	switch(choice){
		case 1: printf("Enter the element to be inserted : ");
			  scanf("%d",&ele);
			  root = insert(root,ele);
			  break;
		case 2: printf("\nINORDER TRAVERSAL :\n");
			  inorder(root);
			  printf("\n");
			  break;
		case 3: printf("\nPREORDER TRAVERSAL :\n");
			  preorder(root);
			  printf("\n");
			  break;
		case 4: printf("\nPOSTORDER TRAVERSAL :\n");
			  postorder(root);
			  printf("\n");
			  break;
		case 5: printf("Enter the element to search for : ");
			  scanf("%d",&ele);
			  search(root,ele);
			  break;
		case 6: printf("Enter the element to delete : ");
			  scanf("%d",&ele);
			  delete(root,ele);
			  break;
		case 7: num = no_Leafnode(root);
			  printf("No of Leaf nodes = %d .\n",num);
			  break;
		case 8: num = no_Nodes(root);
			  printf("No of Nodes = %d .\n",num);
			  break;
		case 9: num = height(root);
			  printf("Height of BST = %d .\n",num);
			  break;
		case 10: return;
	}
	goto repeat;
}















