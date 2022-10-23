#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void matrixOutput(int** Matrix, int line, int column) {
	printf("\nMatrix:\n");
	if (line <= 30 && column <= 30) {
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < column; j++)
				printf("%d	", Matrix[i][j]);
			printf("\n");
		}
	}
	return;
}

void matrixGenerator(int** Matrix,int line, int column) {
	srand(time(NULL));
	for (int i = 0; i < line; i++)
		for (int j = 0; j < column; j++)
			Matrix[i][j] = -9 + rand() % 19;
	matrixOutput(Matrix, line, column);
	return;
}

void matrixMultiplication(int** Matrix1, int** Matrix2, int** MatrixRes, int line, int column, int qwe) {
	 for (int i = 0; i < line; i++)
		 for (int j = 0; j < column; j++) {
			 MatrixRes[i][j] = 0;
			 for (int count = 0; count < qwe; count++)
				 MatrixRes[i][j] += Matrix1[i][count] * Matrix2[count][j];
		 }
	 matrixOutput(MatrixRes, line, column);
	 return;
}

void matrixExtension(int** Matrix, int line, int column, int size) {
	for (int i = 0; i < size; i++) {
		if (i >= line)
			for (int g = 0; g < size; g++)
				Matrix[i][g] = 0;
		else
			for (int j = column; j < size; j++)
				Matrix[i][j] = 0;
	}
	return;
}

void matrixAddition(int** Matrix1, int** Matrix2, int** MatrixRes, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			MatrixRes[i][j] = Matrix1[i][j] + Matrix2[i][j];
	return;
}

void matrixSubstraction(int** Matrix1, int** Matrix2, int** MatrixRes, int size) {
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			MatrixRes[i][j] = Matrix1[i][j] - Matrix2[i][j];
	return;
}

void shtrassenAlgorithm(int** Matrix1, int** Matrix2, int** MatrixRes, int size,int k) {
	int** A11, ** A12, ** A21, ** A22;
	int** B11, ** B12, ** B21, ** B22;
	int** C11, ** C12, ** C21, ** C22;
	int** D, ** D1, ** D2, ** D11, ** D111, ** D112, ** D12, ** D121, ** D122, ** H1, ** H11, ** H2, ** H21, ** V1, ** V11, ** V2, ** V21;
	int i, j;

	D = (int**)malloc(size/2 * sizeof(int*));
	D1 = (int**)malloc(size/2 * sizeof(int*));
	D2 = (int**)malloc(size/2 * sizeof(int*));
	D11 = (int**)malloc(size/2 * sizeof(int*));
	D111 = (int**)malloc(size/2 * sizeof(int*));
	D112 = (int**)malloc(size/2 * sizeof(int*));
	D12 = (int**)malloc(size/2 * sizeof(int*));
	D121 = (int**)malloc(size/2 * sizeof(int*));
	D122 = (int**)malloc(size/2 * sizeof(int*));

	H1 = (int**)malloc(size/2 * sizeof(int*));
	H11 = (int**)malloc(size/2 * sizeof(int*));
	H2 = (int**)malloc(size/2 * sizeof(int*));
	H21 = (int**)malloc(size/2 * sizeof(int*));

	V1 = (int**)malloc(size/2 * sizeof(int*));
	V11 = (int**)malloc(size/2 * sizeof(int*));
	V2 = (int**)malloc(size/2 * sizeof(int*));
	V21 = (int**)malloc(size/2 * sizeof(int*));

	A11 = (int**)malloc(size/2 * sizeof(int*));
	A12 = (int**)malloc(size/2 * sizeof(int*));
	A21 = (int**)malloc(size/2 * sizeof(int*));
	A22 = (int**)malloc(size/2 * sizeof(int*));

	B11 = (int**)malloc(size/2 * sizeof(int*));
	B12 = (int**)malloc(size/2 * sizeof(int*));
	B21 = (int**)malloc(size/2 * sizeof(int*));
	B22 = (int**)malloc(size/2 * sizeof(int*));

	C11 = (int**)malloc(size/2 * sizeof(int*));
	C12 = (int**)malloc(size/2 * sizeof(int*));
	C21 = (int**)malloc(size/2 * sizeof(int*));
	C22 = (int**)malloc(size/2 * sizeof(int*));
	for (i = 0; i < size/2; i++) {
		D = (int*)malloc(size/2 * sizeof(int));
		D1 = (int*)malloc(size/2 * sizeof(int));
		D2 = (int*)malloc(size/2 * sizeof(int));
		D111 = (int*)malloc(size/2 * sizeof(int));
		D11 = (int*)malloc(size/2 * sizeof(int));
		D112 = (int*)malloc(size/2 * sizeof(int));
		D121 = (int*)malloc(size/2 * sizeof(int));
		D122 = (int*)malloc(size/2 * sizeof(int));
		D12 = (int*)malloc(size/2 * sizeof(int));

		H1 = (int*)malloc(size/2 * sizeof(int));
		H11 = (int*)malloc(size/2 * sizeof(int));
		H2 = (int*)malloc(size/2 * sizeof(int));
		H21 = (int*)malloc(size/2 * sizeof(int));

		V1 = (int*)malloc(size/2 * sizeof(int));
		V11 = (int*)malloc(size/2 * sizeof(int));
		V2 = (int*)malloc(size/2 * sizeof(int));
		V21 = (int*)malloc(size/2 * sizeof(int));

		A11 = (int*)malloc(size/2 * sizeof(int));
		A12 = (int*)malloc(size/2 * sizeof(int));
		A21 = (int*)malloc(size/2 * sizeof(int));
		A22 = (int*)malloc(size/2 * sizeof(int));

		B11 = (int*)malloc(size/2 * sizeof(int));
		B12 = (int*)malloc(size/2 * sizeof(int));
		B21 = (int*)malloc(size/2 * sizeof(int));
		B22 = (int*)malloc(size/2 * sizeof(int));

		C11 = (int*)malloc(size/2 * sizeof(int));
		C12 = (int*)malloc(size/2 * sizeof(int));
		C21 = (int*)malloc(size/2 * sizeof(int));
		C22 = (int*)malloc(size/2 * sizeof(int));
	}

	/*if (size <= k || size == 1) {
		matrixMultiplication(Matrix1, Matrix2, MatrixRes, size, size,size);
		return;
	}
	else {
		for (i = 0; i < (size / 2); i++) {
			for (j = 0; j < (size / 2); j++) {
				A11[i][j] = Matrix1[i][j];
				A12[i][j] = Matrix1[i][j + (size / 2)];
				A21[i][j] = Matrix1[i + (size / 2)][j];
				A22[i][j] = Matrix1[i + (size / 2)][j + (size / 2)];

				B11[i][j] = Matrix2[i][j];
				B12[i][j] = Matrix2[i][j + (size / 2)];
				B21[i][j] = Matrix2[i + (size / 2)][j];
				B22[i][j] = Matrix2[i + (size / 2)][j + (size / 2)];
			}
		}
	}
	*/

	if (size >= k) {
		for (i = 0; i < size / 2; i++) {
			for (j = 0; j < size / 2; j++) {
				A11[i][j] = Matrix1[i][j];
				B11[i][j] = Matrix2[i][j];
			}
			for (j = size / 2; j < size; j++) {
				A12[i][j - size / 2] = Matrix1[i][j];
				B12[i][j - size / 2] = Matrix2[i][j];
			}
		}
		for (i = size/2; i < size; i++) {
			for (j = 0; j < size / 2; j++) {
				A21[i-size/2][j] = Matrix1[i][j];
				B21[i-size/2][j] = Matrix2[i][j];
			}
			for (j = size / 2; j < size; j++) {
				A22[i-size/2][j - size / 2] = Matrix1[i][j];
				B22[i-size/2][j - size / 2] = Matrix2[i][j];
			}
		}
	}
	else {
		matrixMultiplication(Matrix1, Matrix2, MatrixRes, size, size, size);
		return;
	}
	
	//D
	matrixAddition(A11, A22, D1,size/2);
	matrixAddition(B11, B22, D2, size/2);
	shtrassenAlgorithm(D1, D2, D, size / 2,k);
	//D11
	matrixSubstraction(A12, A22, D111, size / 2);
	matrixAddition(B21, B22, D112, size / 2);
	shtrassenAlgorithm(D111, D112, D11, size / 2,k);
	//D12
	matrixSubstraction(A21, A11, D121, size / 2);
	matrixAddition(B11, B12, D122, size / 2);
	shtrassenAlgorithm(D121, D122, D12, size / 2,k);
	//H1
	matrixAddition(A11, A12, H11, size / 2);
	shtrassenAlgorithm(H11, B22, H1, size / 2,k);
	//H2
	matrixAddition(A21, A22, H21, size / 2);
	shtrassenAlgorithm(H21, B22, H2, size / 2,k);
	//V1
	matrixSubstraction(B21, B11, V11, size / 2);
	shtrassenAlgorithm(A22, V11, V1, size / 2,k);
	//V2
	matrixSubstraction(B12, B22, V21, size / 2);
	shtrassenAlgorithm(A11, V21, V2, size / 2,k);
	//C11
	matrixAddition(D, D11, C11, size / 2);
	matrixAddition(C11,V1, C11, size / 2);
	matrixSubstraction(C11, H1, C11, size / 2);
	//C12
	matrixAddition(V2, H1, C12, size / 2);
	//C21
	matrixAddition(V1, H2, C21, size / 2);
	//C22
	matrixAddition(D, D12, C22, size / 2);
	matrixAddition(C22, V2, C22, size / 2);
	matrixSubstraction(C22, H2, C22, size / 2);

	for (i = 0; i < size / 2; i++) {
		for (j = 0; j < size / 2; j++)
			MatrixRes[i][j] = C11[i][j];
		for (j = size / 2; j < size; j++)
			MatrixRes[i][j] = C12[i][j - size / 2];
	}
	for (i = size / 2; i < size; i++) {
		for (j = 0; j < size / 2; j++) 
			MatrixRes[i][j] = C21[i - size / 2][j];
		for (j = size / 2; j < size; j++)
			MatrixRes[i][j] = C22[i - size / 2][j - size / 2];
	}
	return;
}

int main() {
	int m, n, p, k, i, j, newsize;
	int** A;
	int** B;
	int** C;
	
	printf("Enter size of  matrix A (m x n): ");
	scanf("%d%d", &m, &n);

	printf("\nEnter size of  matrix B (n x p): ");
	scanf("%d%d", &n, &p);

	printf("\nEnter paremeter k: ");
	scanf("%d", &k);

	if (m >= n)
		newsize = m;
	else
		newsize = n;

	if (newsize > k) {
		while(newsize/k < 2)
			if (newsize % k != 0) {
				newsize++;
			}
	}
	// выделение памяти
	A = (int**)malloc(sizeof(int*) * newsize);
	if (A == NULL) {
		printf("Error: Memory not allocated\n");
		return 1;
	}
	for (i = 0; i < newsize; i++) {
		A[i] = (int*)malloc(sizeof(int) * newsize);
		if (A[i] == NULL) {
			printf("Error: Memory not allocated\n");
			return 1;
		}
	}
	B = (int**)malloc(sizeof(int*) * newsize);
	if (B == NULL) {
		printf("Error: Memory not allocated\n");
		return 1;
	}
	for (i = 0; i < newsize; i++) {
		B[i] = (int*)malloc(sizeof(int) * newsize);
		if (B[i] == NULL) {
			printf("Error: Memory not allocated\n");
			return 1;
		}
	}
	C = (int**)malloc(sizeof(int*) * newsize);
	if (C == NULL) {
		printf("Error: Memory not allocated\n");
		return 1;
	}
	for (i = 0; i < newsize; i++) {
		C[i] = (int*)malloc(sizeof(int) * newsize);
		if (C[i] == NULL) {
			printf("Error: Memory not allocated\n");
			return 1;
		}
	}

	srand(time(NULL));

	matrixGenerator(A, m, n);

	matrixGenerator(B, n, p);

	matrixMultiplication(A, B, C, m, p, n);

	matrixExtension(A, m, n, newsize);

	matrixExtension(B, n, p, newsize);
	
	matrixOutput(A, newsize, newsize);

	matrixOutput(B, newsize, newsize);
	
	shtrassenAlgorithm(A, B, C, newsize,k);

	matrixOutput(C, newsize, newsize);

	return 0;
}