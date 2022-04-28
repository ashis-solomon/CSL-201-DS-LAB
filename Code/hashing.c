#include <stdio.h>

#define SIZE 11

int hashTable[SIZE] = {0};

void performHash(int inputArr[], int inputSize){
    int key;
    for (int i = 0; i < inputSize; i++){
        key = inputArr[i] % SIZE;

        if (hashTable[key] == 0)          
            hashTable[key] = inputArr[i]; 
        else{
            int j;
            j = (key + 1) % SIZE; 
            while (1){
                if (hashTable[j] == 0){
                    hashTable[j] = inputArr[i]; 
                    break;                      
                }
                else{
                    j = (j + 1) % SIZE; 
                }
            }
        }
    }
}

void printHashTable();

int main(){
    int inputArr[SIZE];
    int inputSize;

    printf("Enter size of input array\n");
    scanf("%d", &inputSize);
    if (inputSize > SIZE){
        printf("\nSorry, Max size exceeded");
        return 0;
    }

    printf("Enter elements\n");
    for (int i = 0; i < inputSize; i++)
        scanf("%d", &inputArr[i]);

    performHash(inputArr, inputSize);
    printHashTable();

    return 0;
}

void printHashTable(){
    printf("\nHash table");
    printf("\nIndex:\t");
    for (int i = 0; i < SIZE; i++){
        printf("%d\t", i);
    }
    printf("\nValue:\t");
    for (int i = 0; i < SIZE; i++){
        hashTable[i] != 0 ? printf("%d\t", hashTable[i]) : printf("__\t");
    }
    printf("\n");
}