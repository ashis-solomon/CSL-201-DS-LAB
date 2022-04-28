#include <stdio.h>  
  
#define MAX_SIZE 101

void heapify(int a[], int n, int i)  
{  
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2; 
    if (left < n && a[left] > a[largest])  
        largest = left;  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    if (largest != i) {  
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
          
        heapify(a, n, largest);  
    }  
}  
void heapSort(int a[], int n)  
{  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  
    for (int i = n - 1; i >= 0; i--) {  
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
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
    heapSort(a,n);  
    printf("\nAfter sorting array elements are - \n");    
    display(a, n);  
    printf("\n");
    return 0;  
} 