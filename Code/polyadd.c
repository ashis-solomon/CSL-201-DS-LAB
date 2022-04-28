#include<stdio.h>

#define MAX_TERMS 100

typedef struct {
	int coeff;
	int exp;
} polynomial;

polynomial terms[100];
int available = 0;


void input(char p, int* start, int* finish); 
void output(char p, int start, int finish); 
int compare(int a, int b);
void attach(int ex, int co); 
void add(int startA, int finishA, int startB, int finishB, int* startS, int* finishS); 



void main() {
	int startA, finishA, startB, finishB, startS, finishS;
	char poly;
	
	poly = 'A';
	input(poly, &startA, &finishA);
	
	poly = 'B';
	input(poly, &startB, &finishB);
	
	
	
	poly = 'A';
	output(poly, startA, finishA);
	
	poly = 'B';
	output(poly, startB, finishB);
	
	
	add(startA, finishA, startB, finishB, &startS, &finishS);
	
	printf("\nA + B = S \n");
	poly = 'S';
	output(poly, startS, finishS);
}



void input(char p, int* start, int* finish) {
	int no;
	
	printf("number of terms in %c : ", p);
	scanf("%d", &no);
	printf("\n");
	
	*start = available;
	*finish = available + no - 1;
	available += no; 
	
	
	for(int i=*start; i<=*finish; i++) {
		printf("exponent : ");
		scanf("%d", &terms[i].exp);
		printf("coefficient : ");
		scanf("%d", &terms[i].coeff);
		printf("\n");
	}
}



void output(char p, int start, int finish) {
	printf("\n");
	printf("%c =  ", p);
	for(int i=start; i<=finish; i++) {
		if ((i != start) && (terms[i].coeff >= 0))
			printf("+");
		printf("%dx^%d ", terms[i].coeff, terms[i].exp);	
	}
	printf("\n");
}



void add(int startA, int finishA, int startB, int finishB, int* startS, int* finishS) {

	*startS = available;
	
	while ((startA <= finishA) && (startB <= finishB)) {
		switch(compare(terms[startA].exp, terms[startB].exp)) {
			case 0: if(terms[startA].coeff+terms[startB].coeff != 0)
						attach(terms[startA].exp, terms[startA].coeff+terms[startB].coeff);
					startA++;
					startB++;
					break;
			case 1: attach(terms[startA].exp, terms[startA].coeff);
					startA++;
					break;
			case -1: attach(terms[startB].exp, terms[startB].coeff);
					 startB++;
					 break;
		}
	}
	
	while(startA <= finishA) {
		attach(terms[startA].exp, terms[startA].coeff);
		startA++;
	}
	
	while(startB <= finishB) {
		attach(terms[startB].exp, terms[startB].coeff);
		startB++;
	}
	
	*finishS = available-1;
}



void attach(int ex, int co) {
	terms[available].exp = ex;
	terms[available].coeff = co;
	available++;
}



int compare(int a, int b) {
	// return 0 if a == b
	if ( a==b) 
		return 0;
	// return 1 if a > b
	if (a>b)
		return 1;
	// return -1 if a < b
	if (a<b)
		return -1;
}