#include <stdio.h>  
  
#define MAX_SIZE 101
  
void insertion(int a[], int n)
{  
    int i, j, temp;  
    for (i = 1; i < n; i++) {  
        temp = a[i];  
        j = i - 1;  
  
        while(j>=0 && temp <= a[j])    
        {    
            a[j+1] = a[j];     
            j = j-1;    
        }    
        a[j+1] = temp;    
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
    insertion(a, n);  
    printf("\nAfter sorting array elements are - \n");    
    display(a, n);  
    printf("\n");
    return 0;  
} 