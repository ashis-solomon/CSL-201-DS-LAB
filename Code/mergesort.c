#include <stdio.h>  
  
#define MAX_SIZE 101

void merge(int a[], int beg, int mid, int end)    
{    
    int i, j, k;  
    int n1 = mid - beg + 1;    
    int n2 = end - mid;    
      
    int LeftArray[n1], RightArray[n2]; 
      
   
    for (int i = 0; i < n1; i++)    
    LeftArray[i] = a[beg + i];    
    for (int j = 0; j < n2; j++)    
    RightArray[j] = a[mid + 1 + j];    
      
    i = 0; 
    j = 0;   
    k = beg; 
      
    while (i < n1 && j < n2)    
    {    
        if(LeftArray[i] <= RightArray[j])    
        {    
            a[k] = LeftArray[i];    
            i++;    
        }    
        else    
        {    
            a[k] = RightArray[j];    
            j++;    
        }    
        k++;    
    }    
    while (i<n1)    
    {    
        a[k] = LeftArray[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        a[k] = RightArray[j];    
        j++;    
        k++;    
    }    
}    
  
void mergeSort(int a[], int beg, int end)  
{  
    if (beg < end)   
    {  
        int mid = (beg + end) / 2;  
        mergeSort(a, beg, mid);  
        mergeSort(a, mid + 1, end);  
        merge(a, beg, mid, end);  
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
    mergeSort(a,0,n-1);  
    printf("\nAfter sorting array elements are - \n");    
    display(a, n);  
    printf("\n");
    return 0;  
}    