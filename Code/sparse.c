#include<stdio.h>

int A[50][3], B[50][3], sum[50][3], AT[50][3], BT[50][3];

void matrixtotuple(int m[50][50], int r, int c, int t[50][3]) {
	t[0][0] = r;
	t[0][1] = c;
	t[0][2] = 0;
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(m[i][j] != 0) {
				t[0][2]++;
				t[t[0][2]][0] = i;
				t[t[0][2]][1] = j;
				t[t[0][2]][2] = m[i][j];
			}
		}
	}
}


void displaytupleform(int m[50][3]) {
	for(int i=0; i<=m[0][2]; i++)
		printf("%d  %d  %d \n", m[i][0], m[i][1], m[i][2]);
}


void transpose(int m[50][3], int t[50][3]) {
	t[0][0] = m[0][1];
	t[0][1] = m[0][0];
	t[0][2] = 0;
	
	for(int i=0; i<m[0][1]; i++) {
		for(int j=1; j<=m[0][2]; j++) {
			if(m[j][1]==i) {
				t[0][2]++;
				t[t[0][2]][0] = m[j][1];
				t[t[0][2]][1] = m[j][0];
				t[t[0][2]][2] = m[j][2];
			}
		}
	}
}


void add() {
	sum[0][0] = A[0][0];
	sum[0][1] = A[0][1];
	sum[0][2] = 0;
	
	int a = 1;
	int b = 1;
	
	while( (a<=A[0][2]) && (b<=B[0][2]) ) {
		
		if( (A[a][0]==B[b][0]) && (A[a][1]==B[b][1]) ) {
			if(A[a][2]+B[b][2] != 0) {
				sum[0][2]++;
				sum[sum[0][2]][0] = A[a][0];
				sum[sum[0][2]][1] = A[a][1];
				sum[sum[0][2]][2] = A[a][2]+B[b][2];
			}
			a++;
			b++;
		}
		
		else {
			if( A[a][0] < B[b][0] ) {
				sum[0][2]++;
				sum[sum[0][2]][0] = A[a][0];
				sum[sum[0][2]][1] = A[a][1];
				sum[sum[0][2]][2] = A[a][2];
				a++;
			}
			else if( B[b][0] < A[a][0] ) {
				sum[0][2]++;
				sum[sum[0][2]][0] = B[b][0];
				sum[sum[0][2]][1] = B[b][1];
				sum[sum[0][2]][2] = B[b][2];
				b++;
			}
			else {
				if( A[a][1] < B[b][1] ) {
					sum[0][2]++;
					sum[sum[0][2]][0] = A[a][0];
					sum[sum[0][2]][1] = A[a][1];
					sum[sum[0][2]][2] = A[a][2];
					a++;
				}
				else {
					sum[0][2]++;
					sum[sum[0][2]][0] = B[b][0];
					sum[sum[0][2]][1] = B[b][1];
					sum[sum[0][2]][2] = B[b][2];
					b++;
				}
			}
		}
		
	}
	
	while ( a<=A[0][2] ) {
		sum[0][2]++;
		sum[sum[0][2]][0] = A[a][0];
		sum[sum[0][2]][1] = A[a][1];
		sum[sum[0][2]][2] = A[a][2];
		a++;
	}
	
	while ( b<=B[0][2] ) {
		sum[0][2]++;
		sum[sum[0][2]][0] = B[b][0];
		sum[sum[0][2]][1] = B[b][1];
		sum[sum[0][2]][2] = B[b][2];
		b++;
	}
}


void main() {
	int a[50][50], b[50][50], ar, ac, br, bc;
	
	printf("Number of Rows in A : ");
	scanf("%d", &ar);
	printf("Number of Columns in A : ");
	scanf("%d", &ac);
	printf("Enter Matrix A \n");
	for(int i=0; i<ar; i++)
		for(int j=0; j<ac; j++)
			scanf("%d", &a[i][j]);
			
	printf("Number of Rows in B : ");
	scanf("%d", &br);
	printf("Number of Columns in B : ");
	scanf("%d", &bc);
	printf("Enter Matrix B :\n");
	for(int i=0; i<br; i++)
		for(int j=0; j<bc; j++)
			scanf("%d", &b[i][j]);
	
	matrixtotuple(a, ar, ac, A);
	matrixtotuple(b, br, bc, B);
	
	printf("Matrix A in Tuple Form : \n");
	displaytupleform(A);
	printf("Matrix B in Tuple Form : \n");
	displaytupleform(B);
	
	transpose(A, AT);
	transpose(B, BT);
	
	printf("A Transpose : \n");
	displaytupleform(AT);
	printf("B Transpose : \n");
	displaytupleform(BT);
	
	if( (A[0][0]==B[0][0]) && (A[0][1]==B[0][1]) ) {
		printf("\nA + B = \n");
		add();
		displaytupleform(sum);
	}
	else
		printf("Matrices Cannot be Added \n");
}