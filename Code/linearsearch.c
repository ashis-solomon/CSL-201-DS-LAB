#include<stdio.h>

int lsearch(int arr[], int n, int x) 
{ 

    for (int i=0;i<n;i++) 
        if (arr[i] == x) 
            return i; 
    
    return 0; 
} 
  
void main() 
{ 
    int ele,n,result;
    int arr[100]; 
     
     printf("Enter the Size of the Array : \n");
     scanf("%d",&n);

     printf("Enter the Array : \n");
     for(int i=0;i<n;i++){
         scanf("%d",&arr[i]);
     }

     printf("Enter the Element to be Searched for : \n");
     scanf("%d",&ele);

     result = lsearch(arr, n, ele); 
    
    if(result == 0){
        printf("Element is NOT PRESENT in Array\n");
    }
    else{
        printf("Element is PRESENT at position %d\n", result+1); 
    }
} 