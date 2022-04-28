#include <stdio.h> 
  

int binarySearch(int arr[], int l, int r, int x) 
{ 
   while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        if (arr[m] == x) 
            return m; 
  
        else if (arr[m] < x) 
            l = m + 1; 
        else{
            r = m - 1; 
        }
    }
    return -1;    
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

    result = binarySearch(arr, 0, n - 1, ele); 
    
     if(result == -1){
         printf("Element is NOT PRESENT in Array\n");
     }  
     else{
        printf("Element is PRESENT at position %d\n", result+1);  
     }                     
} 