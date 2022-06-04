#pragma once 
#define _CRT_SECURE_NO_WARNINGS  //Директивы для корректной работы программы
///
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
Matrix summatrix(Matrix* x, Matrix* y);
Matrix subtraction(Matrix* x, Matrix* y);
Matrix multiplication(Matrix* x, Matrix* y);             
Matrix transp(Matrix* a);
void mulnum(Matrix* a, double k);
Matrix gauss(Matrix* a);
void input(Matrix* x);
void getmemory(Matrix* x, int N, int M);
void output(Matrix* x);
void removemem(Matrix* a);
void inversion(Matrix* a);
int subsum(Matrix* x, Matrix* y);
int multi(Matrix* a, Matrix* b);
double det(Matrix* matrix);
void equating(Matrix* a, Matrix* b);
void saveFile(Matrix* a,char *filename);
void outerror(int typeError, const char* errStr);
void loadFile(Matrix* a,char *filename);
//