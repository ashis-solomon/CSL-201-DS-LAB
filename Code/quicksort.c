#include <stdio.h>  
  
#define MAX_SIZE 101
  
int partition (int a[], int start, int end)  
{  
    int pivot = a[end]; 
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  
    {  
        if (a[j] < pivot)  
        {  
            i++;
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
}  
  

void quick(int a[], int start, int end)  
{  
    if (start < end)  
    {  
        int p = partition(a, start, end);  
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
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
    quick(a,0,n-1);  
    printf("\nAfter sorting array elements are - \n");    
    display(a, n);  
    printf("\n");
    return 0;  
}    