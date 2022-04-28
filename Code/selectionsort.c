#include <stdio.h>  
  
#define MAX_SIZE 101
  
void selection(int arr[], int n)  
{  
    int i, j, small;  
      
    for (i = 0; i < n-1; i++)   
    {  
        small = i; 
          
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[small])  
            small = j;  
    int temp = arr[small];  
    arr[small] = arr[i];  
    arr[i] = temp;  
    }  
}  
  
void display(int a[], int n) 
{  
    int i;  
    for (i = 0; i < n; i++)  
        printf("%d\t", a[i]);  
}  
  
int main()  
{  
    int n,a[MAX_SIZE]; 
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);
	printf("\nEnter the elements of the array : \n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
    printf("Before sorting array elements are - \n");  
    display(a, n);  
    selection(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    display(a, n);  
    printf("\n");
    return 0;  
}    