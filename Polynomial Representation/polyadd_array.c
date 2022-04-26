#include<stdio.h>

#define MAX_SIZE 100

int poly[MAX_SIZE][2];
int startA=0,finishA=-1,startB,finishB;
int rs_start,rs_finish;
int avail = 0;


void input_poly(int exp,int coeff,int num){
	if(num==0){
			poly[avail][0] = exp;
			poly[avail][1] = coeff; 
			avail++;
			finishA = avail-1;
	}
	if(num==1){
			startB = finishA+1;
			poly[avail][0] = exp;
			poly[avail][1] = coeff;
			avail++;
			finishB = avail-1;
	}
}

void display_poly(int num){
	int start,finish;
	if(num==0){
		printf("Polynomial A : \n");
		start = startA; finish = finishA;
	}
	if(num==1){
		printf("Polynomial B : \n");
		start = startB; finish = finishB;
	}
	if(num==2){
		printf("Resultant Polynomial : \n");
		start = rs_start; finish = rs_finish;
	}
	while(start<finish){
			printf("%dx^%d  +  ",poly[start][1],poly[start][0]);
			start++;
		}
		printf("%dx^%d",poly[start][1],poly[start][0]);
		start++;
		printf("\n\n");
}

int compare(int a, int b){
	if(a==b){return 0;}
	if(a<b){return -1;}
	if(a>b){return 1;}
}

void polyadd(){
	rs_start = avail;
	int a,b;
	a = startA; b = startB;
	while(a<=finishA && b<=finishB){
		switch(compare(poly[a][0],poly[b][0])){
			case 0 :	poly[avail][0] = poly[a][0];
					poly[avail][1] = poly[a][1] + poly[b][1];
					avail++; a++; b++;
					break;
			case 1 : 	poly[avail][0] = poly[a][0];
					poly[avail][1] = poly[a][1];
					avail++; a++;
					break;
			case -1: 	poly[avail][0] = poly[b][0];
					poly[avail][1] = poly[b][1];
					avail++; b++;
					break;
		}
	}
	while(a<=finishA){
		poly[avail][0] = poly[a][0];
		poly[avail][1] = poly[a][1];
		avail++; a++;
	}
	while(b<=finishB){
		poly[avail][0] = poly[b][0];
		poly[avail][1] = poly[b][1];
		avail++; b++;
	}
	rs_finish = avail-1;
}

void main(){
	int termsA,termsB,exp,coeff;
	printf("Enter the number of terms of Polynomial A : ");
	scanf("%d",&termsA);
	for(int i=0;i<termsA;i++){
		printf("\nEnter Exponent : ");
		scanf("%d",&exp);
		printf("Enter Coefficient : ");
		scanf("%d",&coeff);
		input_poly(exp,coeff,0);
	}
	printf("\n\nEnter the number of terms of Polynomial B : ");
	scanf("%d",&termsB);
	for(int i=0;i<termsB;i++){
		printf("\nEnter Exponent : ");
		scanf("%d",&exp);
		printf("Enter Coefficient : ");
		scanf("%d",&coeff);
		input_poly(exp,coeff,1);
	}
	printf("\n\n");
	display_poly(0);
	display_poly(1);
	
	polyadd();
	display_poly(2);

}