#pragma once 
#define _CRT_SECURE_NO_WARNINGS  //Директивы для корректной работы программы
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

enum MatrixError
{
    MATRIX_ERROR_INPUT, 
    MARTIX_ERROR_PRINT,
    MATRIX_ERROR_MEM,
    MATRIX_ERROR_DELETE,
    MATRIX_ERROR_SUM,
    MATRIX_ERROR_SUB,
    MATRIX_ERROR_TRANSP,
    MATRIX_ERROR_MUL,
    MATRIX_ERROR_GAUS,
    MATRIX_ERROR_INV,
    MATRIX_ERROR_MULN
};

typedef struct Matrix
{
    int m, n;
    double countSwaps;
    double** arr;
}Matrix;

Matrix division(Matrix* a, Matrix* b);
//@return sum matrix N x M
Matrix summatrix(Matrix* x, Matrix* y);
//@return sub matrix N x M
Matrix subtraction(Matrix* x, Matrix* y);
//@return mul matrix N x M
Matrix multiplication(Matrix* x, Matrix* y);
/*@returnreturns a matrix M x N instead N x M
*/                   
Matrix transp(Matrix* a);
//@return matrix mul number
Matrix mulnum(Matrix* a, double k);
//@return triangle matrix
Matrix gauss(Matrix* a);
//@return input matrix
void input(Matrix* x);
//@return gives memory to a dynamic two-dimensional array
void getmemory(Matrix* x, int N, int M);
//@return prints a matrix on the display
void output(Matrix* x);
//@removes allocated memory
void removemem(Matrix* a);
//@finds the inverse matrix
void inversion(Matrix* a);
//@checks the condition for finding the sum and difference of matrices
int subsum(Matrix* x, Matrix* y);
//@return checks the condition for finding the multiplication
int multi(Matrix* a, Matrix* b);
//@return determinant
double det(Matrix* matrix);
//@Matrix division.
void equating(Matrix* a, Matrix* b);
//@Save your matrix to file.
void saveFile(Matrix* a,char *filename);
//@displays the type of error when a function is running
void outerror(int typeError, const char* errStr);
void loadFile(Matrix* a,char *filename);
//