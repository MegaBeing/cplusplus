#include <iostream>
#include <omp.h>

// Function to multiply two matrices
void matrix_multiply(int **A, int **B, int **C, int m, int n, int p) {
    #pragma omp parallel for
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to print a matrix
void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int m = 3; // Number of rows in matrix A
    const int n = 2; // Number of columns in matrix A (and rows in matrix B)
    const int p = 3; // Number of columns in matrix B

    // Initialize matrices A, B, and C
    int **A = new int*[m];
    int **B = new int*[n];
    int **C = new int*[m];
    for (int i = 0; i < m; ++i) {
        A[i] = new int[n];
        C[i] = new int[p];
    }
    for (int i = 0; i < n; ++i) {
        B[i] = new int[p];
    }

    // Populate matrices A and B (you can modify this part according to your needs)
    // For simplicity, I'm filling them with sequential numbers
    int count = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            A[i][j] = count++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            B[i][j] = count++;
        }
    }

    // Perform matrix multiplication
    matrix_multiply(A, B, C, m, n, p);

    // Print matrices
    std::cout << "Matrix A:" << std::endl;
    print_matrix(A, m, n);

    std::cout << "Matrix B:" << std::endl;
    print_matrix(B, n, p);

    std::cout << "Matrix C (result of A * B):" << std::endl;
    print_matrix(C, m, p);

    // Free memory
    for (int i = 0; i < m; ++i) {
        delete[] A[i];
        delete[] C[i];
    }
    for (int i = 0; i < n; ++i) {
        delete[] B[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}

