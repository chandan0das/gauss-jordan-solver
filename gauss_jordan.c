/*
 * Author: Chandan Das
 * Purpose: Solve system of linear equations using matrix (Gauss-Jordan elimination)
 * Copyright: 2024 ; seems it expired as I'm posting it on git-hub in 2026
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10
#define EPS 1e-12

// Function prototypes. could put then in a header
void printHeader();
void showHelp();
void inputMatrix(double a[MAX][MAX], int* r, int* c);
void gaussJordan(double a[MAX][MAX], int r, int c);
void printMatrix(double a[MAX][MAX], int r, int c);
int rankMatrix(double a[MAX][MAX], int r, int c);
void solveSystem(double a[MAX][MAX], int r, int c);

int main() {
	int choice;
	double a[MAX][MAX];
	int r, c;

	printHeader();

	while (1) {
		printf("\n\n1. Help\n2. Calculate equations\n3. Quit\n\nEnter your choice: ");
		scanf("%d", &choice);
		#ifdef _WIN32
		if (system("cls")) { perror("system"); exit(1); }
		#else
			system("clear");
		#endif
		//fflush(stdin);

		switch (choice) {
		case 1:
			showHelp();
			break;
		case 2:
			inputMatrix(a, &r, &c);
			gaussJordan(a, r, c);
			printf("\nRow reduced form:\n");
			printMatrix(a, r, c);
			solveSystem(a, r, c);
			break;
		case 3:
			return 0;
		default:
			printf("Wrong choice, try again.\n");
		}
	}
	return 0;
}

/* ---------------- Utility Functions ---------------- */

void printHeader() {
	printf(" * Author: Chandan Das\n * Purpose: Solve system of equations by matrix\n * Copyright: 2024\n");
}

void showHelp() {
	printf("\nExample:\nSolve equations:\n  5x + 4y = 28\n  7x + 2y = 39\n\n");
	printf("Enter row and col of augmented matrix (limit <=10):\n2 3\n");
	printf("Enter matrix elements:\n5 4 28\n7 2 39\n");
	printf("Row reduced form:\n  1  0  5.556\n  0  1  0.05556\n");
	printf("Rank of augmented matrix: 2\nRank of coefficient matrix: 2\n");
	printf("System is consistent, unique solution:\n(x=5.556, y=0.05556)\n");
}

void inputMatrix(double a[MAX][MAX], int* r, int* c) {
	printf("Enter row and col of augmented matrix (limit <=10): ");
	scanf("%d%d", r, c);

	printf("Enter matrix elements:\n");
	for (int i = 0; i < *r; i++) {
		for (int j = 0; j < *c; j++) {
			scanf("%lf", &a[i][j]);
		}
	}
}

void gaussJordan(double a[MAX][MAX], int r, int c) {
	for (int i = 0; i < r; i++) {
		// Pivoting
		if (fabs(a[i][i]) < EPS) {
			for (int k = i + 1; k < r; k++) {
				if (fabs(a[k][i]) > EPS) {
					for (int j = 0; j < c; j++) {
						double temp = a[i][j];
						a[i][j] = a[k][j];
						a[k][j] = temp;
					}
					break;
				}
			}
		}

		// Normalize pivot row
		double pivot = a[i][i];
		if (fabs(pivot) > EPS) {
			for (int j = 0; j < c; j++) {
				a[i][j] /= pivot;
			}
		}

		// Eliminate other rows
		for (int k = 0; k < r; k++) {
			if (k != i) {
				double factor = a[k][i];
				for (int j = 0; j < c; j++) {
					a[k][j] -= factor * a[i][j];
				}
			}
		}
	}
}

void printMatrix(double a[MAX][MAX], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (fabs(a[i][j]) < EPS) a[i][j] = 0;
			printf("%10.4lf", a[i][j]);
		}
		printf("\n");
	}
}

int rankMatrix(double a[MAX][MAX], int r, int c) {
	int rank = r;
	for (int i = 0; i < r; i++) {
		int zeroRow = 1;
		for (int j = 0; j < c; j++) {
			if (fabs(a[i][j]) > EPS) {
				zeroRow = 0;
				break;
			}
		}
		if (zeroRow) {
			rank--;
		}
	}
	return rank;
}

void solveSystem(double a[MAX][MAX], int r, int c) {
	int rankAug = rankMatrix(a, r, c);
	int rankCoef = rankMatrix(a, r, c - 1);

	printf("\nRank of augmented matrix: %d", rankAug);
	printf("\nRank of coefficient matrix: %d", rankCoef);

	if (rankAug == rankCoef) {
		printf("\nSystem is consistent.");
		if (rankCoef == c - 1) {
			printf("\nUnique solution:\n(");
			for (int i = 0; i < c - 1; i++) {
				printf(" %.4lf ", a[i][c - 1]);
			}
			printf(")\n");
		} else {
			printf("\nInfinite solutions (parametric form).\n");
			// Extension: implement parametric solution printing
		}
	} else {
		printf("\nSystem is inconsistent (no solution).\n");
	}
}
