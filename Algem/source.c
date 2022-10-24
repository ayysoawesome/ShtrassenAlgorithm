#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int countAdd = 0, countMult = 0; // глобальные переменные для счетчиков (НЕ РАБОТАЮТ))_)_)_))))) XD XDX XD XDX XD

void matrixOutput(int** Matrix, int line, int column) { // функция вывода матриц
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < column; j++)
			printf("%d	", Matrix[i][j]);
		printf("\n");
	}
	return;
}

void matrixGenerator(int** Matrix,int line, int column) { // функция генерации матриц
	for (int i = 0; i < line; i++)
		for (int j = 0; j < column; j++)
			Matrix[i][j] = -9 + rand() % 19;
	return;
}

void matrixMultiplication(int** Matrix1, int** Matrix2, int** MatrixRes, int line, int column, int qwe) { // функция умножения матриц
	 for (int i = 0; i < line; i++)
		 for (int j = 0; j < column; j++) {
			 MatrixRes[i][j] = 0;
			 countAdd--;
			 for (int count = 0; count < qwe; count++) {
				 MatrixRes[i][j] += Matrix1[i][count] * Matrix2[count][j];
				 countAdd++;
				 countMult++;
			 }
		 }
	 return;
}

void matrixExtension(int** Matrix, int line, int column, int size) { // функция дополнения матриц нулевыми строками
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

void matrixAddition(int** Matrix1, int** Matrix2, int** MatrixRes, int size) { // функция сложения матриц
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			MatrixRes[i][j] = Matrix1[i][j] + Matrix2[i][j];
			countAdd++;
		}
	return;
}

void matrixSubstraction(int** Matrix1, int** Matrix2, int** MatrixRes, int size) { // функция разности матриц
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			MatrixRes[i][j] = Matrix1[i][j] - Matrix2[i][j];
			countAdd++;
		}
	return;
}

void shtrassenAlgorithm(int** Matrix1, int** Matrix2, int** MatrixRes, int newsize,int k) {
	int i, j, size;
	
	int** A11, ** A12, ** A21, ** A22;
	int** B11, ** B12, ** B21, ** B22;
	int** C11, ** C12, ** C21, ** C22;
	int** M1, ** M11, ** M12, ** M2, ** M21, ** M3, ** M31, ** M4, ** M41, ** M5, ** M51, ** M6, ** M61, ** M62, ** M7, ** M71, ** M72;
	size = newsize / 2;
	
	M1 = (int**)malloc(size * sizeof(int*));
	M11 = (int**)malloc(size * sizeof(int*));
	M12 = (int**)malloc(size * sizeof(int*));
	M2 = (int**)malloc(size * sizeof(int*));
	M21 = (int**)malloc(size * sizeof(int*));
	M3 = (int**)malloc(size * sizeof(int*));
	M31 = (int**)malloc(size * sizeof(int*));
	M4 = (int**)malloc(size * sizeof(int*));
	M41 = (int**)malloc(size * sizeof(int*));
	M5 = (int**)malloc(size * sizeof(int*));
	M51 = (int**)malloc(size * sizeof(int*));
	M6 = (int**)malloc(size * sizeof(int*));
	M61 = (int**)malloc(size * sizeof(int*));
	M62 = (int**)malloc(size * sizeof(int*));
	M7 = (int**)malloc(size * sizeof(int*));
	M71 = (int**)malloc(size * sizeof(int*));
	M72 = (int**)malloc(size * sizeof(int*));

	A11 = (int**)malloc(size * sizeof(int*));
	A12 = (int**)malloc(size * sizeof(int*));
	A21 = (int**)malloc(size * sizeof(int*));
	A22 = (int**)malloc(size * sizeof(int*));

	B11 = (int**)malloc(size * sizeof(int*));
	B12 = (int**)malloc(size * sizeof(int*));
	B21 = (int**)malloc(size * sizeof(int*));
	B22 = (int**)malloc(size * sizeof(int*));

	C11 = (int**)malloc(size * sizeof(int*));
	C12 = (int**)malloc(size * sizeof(int*));
	C21 = (int**)malloc(size * sizeof(int*));
	C22 = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++) {
		M1[i] = (int*)malloc(size * sizeof(int));
		M11[i] = (int*)malloc(size * sizeof(int));
		M12[i] = (int*)malloc(size * sizeof(int));
		M2[i] = (int*)malloc(size * sizeof(int));
		M21[i] = (int*)malloc(size * sizeof(int));
		M3[i] = (int*)malloc(size * sizeof(int));
		M31[i] = (int*)malloc(size * sizeof(int));
		M4[i] = (int*)malloc(size * sizeof(int));
		M41[i] = (int*)malloc(size * sizeof(int));
		M5[i] = (int*)malloc(size * sizeof(int));
		M51[i] = (int*)malloc(size * sizeof(int));
		M6[i] = (int*)malloc(size * sizeof(int));
		M61[i] = (int*)malloc(size * sizeof(int));
		M62[i] = (int*)malloc(size * sizeof(int));
		M7[i] = (int*)malloc(size * sizeof(int));
		M71[i] = (int*)malloc(size * sizeof(int));
		M72[i] = (int*)malloc(size * sizeof(int));

		A11[i] = (int*)malloc(size * sizeof(int));
		A12[i] = (int*)malloc(size * sizeof(int));
		A21[i] = (int*)malloc(size * sizeof(int));
		A22[i] = (int*)malloc(size * sizeof(int));

		B11[i] = (int*)malloc(size * sizeof(int));
		B12[i] = (int*)malloc(size * sizeof(int));
		B21[i] = (int*)malloc(size * sizeof(int));
		B22[i] = (int*)malloc(size * sizeof(int));

		C11[i] = (int*)malloc(size * sizeof(int));
		C12[i] = (int*)malloc(size * sizeof(int));
		C21[i] = (int*)malloc(size * sizeof(int));
		C22[i] = (int*)malloc(size * sizeof(int));
	}
	
	if (newsize > 2 && newsize % 2 == 0) {
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				A11[i][j] = Matrix1[i][j];
				B11[i][j] = Matrix2[i][j];
			}
			for (j = size; j < size*2; j++) {
				A12[i][j - size] = Matrix1[i][j];
				B12[i][j - size] = Matrix2[i][j];
			}
		}
		for (i = size; i < size*2; i++) {
			for (j = 0; j < size; j++) {
				A21[i-size][j] = Matrix1[i][j];
				B21[i-size][j] = Matrix2[i][j];
			}
			for (j = size; j < size*2; j++) {
				A22[i-size][j - size] = Matrix1[i][j];
				B22[i-size][j - size] = Matrix2[i][j];
			}
		}
	}
	else {
		matrixMultiplication(Matrix1, Matrix2, MatrixRes, newsize, newsize, newsize);
		return;															
	
	//M1
	matrixAddition(A11, A22, M11,size);
	matrixAddition(B11, B22, M12, size);
	shtrassenAlgorithm(M11, M12, M1, size,k);
	//M7
	matrixSubstraction(A12, A22, M71, size);
	matrixAddition(B21, B22, M72, size);
	shtrassenAlgorithm(M71, M72, M7, size,k);
	//M6
	matrixSubstraction(A21, A11, M61, size);
	matrixAddition(B11, B12, M62, size);
	shtrassenAlgorithm(M61, M62, M6, size,k);
	//M5
	matrixAddition(A11, A12, M51, size);
	shtrassenAlgorithm(M51, B22, M5, size,k);
	//M2
	matrixAddition(A21, A22, M21, size);
	shtrassenAlgorithm(M21, B11, M2, size,k);
	//M4
	matrixSubstraction(B21, B11, M41, size);
	shtrassenAlgorithm(A22, M41, M4, size,k);
	//M3
	matrixSubstraction(B12, B22, M31, size);
	shtrassenAlgorithm(A11, M31, M3, size,k);
	//C11
	matrixAddition(M1, M4, C11, size);
	matrixAddition(C11, M7, C11, size);
	matrixSubstraction(C11, M5, C11, size);
	//C12
	matrixAddition(M3, M5, C12, size);
	//C21
	matrixAddition(M2, M4, C21, size);
	//C22
	matrixSubstraction(M1, M2, C22, size);
	matrixAddition(C22, M3, C22, size);
	matrixAddition(C22, M6, C22, size);

	//получение конечных данных
	if (size == k) {
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++)
				MatrixRes[i][j] = C11[i][j];
			for (j = size; j < size * 2; j++)
				MatrixRes[i][j] = C12[i][j - size];
		}
		for (i = size; i < size * 2; i++) {
			for (j = 0; j < size; j++)
				MatrixRes[i][j] = C21[i - size][j];
			for (j = size; j < size * 2; j++)
				MatrixRes[i][j] = C22[i - size][j - size];
		}
	}
	return;
}

int main() {
	int m, n, p, k, i, newsize;
	int** A;
	int** B;
	int** C;
	printf("Enter size of  matrix A (m x n): ");
	if (scanf("%d%d", &m, &n) == NULL) {
		printf("Error: Value is not int");
		return 1;
	}
	printf("\nEnter size of  matrix B (n x p): ");
	if (scanf("%d%d", &n, &p) == NULL) {
		printf("Error: Value is not int");
		return 1;
	}
	printf("\nEnter paremeter k: ");
	if (scanf("%d", &k) == NULL) {
		printf("Error: Value is not int");
		return 1;
	}

	if (m >= n)
		newsize = m;
	else
		newsize = n;

	if (newsize > k) {
		while (newsize / k < 2)
			if (newsize % k != 0) {
				newsize++;
			}
		if (newsize / k > 2) {
			while (newsize % 2 != 0) 
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

	srand(time(NULL)); //определение генератора

	matrixGenerator(A, m, n);

	matrixGenerator(B, n, p); //сама генерация

	if (m <= 30 && n <= 30) {		//вывод матриц
		printf("\nMatrix A:\n");
		matrixOutput(A, m, n);
		printf("\nMatrix A:\n");
		matrixOutput(B, n, p);
	}
	
	matrixMultiplication(A, B, C, m, p, n); // умножение по определению

	if (m <= 30 && n <= 30) {
		printf("\nMatrix C (A*B by defenition):\n"); //вывод
		matrixOutput(C, m, p);
	}

	printf("\nCounters (multiplication by definition):\n");
	printf("\nNumber of additions: %d\nNumber of multiplications: %d\n", countAdd, countMult);  //счетчики

	countAdd = 0;
	countMult = 0;
	
	matrixExtension(A, m, n, newsize); 

	matrixExtension(B, n, p, newsize); 

	shtrassenAlgorithm(A, B, C, newsize,k);

	printf("\nCounters (Strassen algorithm):\n");
	printf("\nNumber of additions: %d\nNumber of multiplications: %d\n", countAdd, countMult);  
																						
										
	if (m <= 30 && n <= 30) {
		printf("\nMatrix C (A*B with Strassen algorithm):\n");
		matrixOutput(C, m, p);
	}
	return 0;
}						