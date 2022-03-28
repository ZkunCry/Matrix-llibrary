#include "..\StaticLib\matrix.h"

const double eps = 1e-9;

void removemem(Matrix* a)
{
    int i = 0, j = 0;
    if (a->line <= a->column)
    {
        for (i = 0; i < a->column; i++)
            free(a->arr[i]);
    }
    else
    {
        for (i = 0; i < a->line; i++)
            free(a->arr[i]);
    }
}
void input(Matrix* type)
{
    int i = 0, j = 0;
    for (i = 0; i < type->line; i++)
    {
        for (j = 0; j < type->column; j++)
            scanf("%lf", &type->arr[i][j]);
    }
}

void getmemory(Matrix* matrix, int N, int M)
{
    int i = 0, j = 0;
    matrix->line = N;
    matrix->column = M;
    matrix->arr = (double**)malloc(N * sizeof(double*));
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            matrix->arr[i] = (double*)malloc(M * sizeof(double));
            matrix->arr[i][j] = 0;

        }
    }
}

void output(Matrix* x)
{
    int i = 0, j = 0;
    for (i = 0; i < x->line; i++)
    {
        printf("| ");
        for (j = 0; j < x->column; j++)
        {
            printf("%11.5lf ", x->arr[i][j]);
        }
        printf("  |\n");
    }
    printf("\n\n");
}
Matrix error(Matrix* a)
{
    a->arr = 0;
    a->line = 0;
    a->column = 0;
    return *a;
}

Matrix summatrix(Matrix* x, Matrix* y)
{
    int i = 0, j = 0;
    Matrix temp;
    getmemory(&temp, x->line, x->column);
    if (subsum(x, y))
    {
        for (i = 0; i < x->line; i++)
        {
            for (j = 0; j < x->column; j++)
            {
                temp.arr[i][j] = x->arr[i][j] + y->arr[i][j];
            }
        }
        return temp;
    }
    else
        return temp = error(&temp);
}
int subsum(Matrix* x, Matrix* y)
{
    return (x->line == y->line && x->column == y->column);
}

Matrix multiplication(Matrix* x, Matrix* y)
{
    int i = 0, j = 0, k = 0;
    Matrix c;
    getmemory(&c, x->line, y->column);
    if (multi(x, y))
    {
        for (i = 0; i < x->line; i++)
        {
            for (j = 0; j < y->column; j++)
            {
                for (k = 0; k < x->column; k++)
                {
                    c.arr[i][j] += (x->arr[i][k] * y->arr[k][j]);
                }
            }
        }
        return c;
    }
    else
        return c = error(&c);
}

Matrix subtraction(Matrix* x, Matrix* y)
{
    int i = 0, j = 0;
    Matrix temp;
    getmemory(&temp, x->line, x->column);
    if (subsum(x, y))
    {
        for (i = 0; i < x->line; i++)
        {
            for (j = 0; j < x->column; j++)
            {
                temp.arr[i][j] = x->arr[i][j] - y->arr[i][j];
            }
        }
        return temp;
    }
    else
        return temp = error(&temp);
}


int det(Matrix* matrix)
{
    if (matrix->line == matrix->column)
    {

        int i = 0, j = 0, k = 0;
        double temp = 0;
        double determinant = 1,countSwaps=1;
        Matrix c = *matrix;
        for (i = 0; i < matrix->line; ++i)
        {
            int iMax = i;
            for (j = i + 1; j < matrix->line; ++j)
                if (fabs(c.arr[j][i]) > fabs(c.arr[iMax][i]))
                    iMax = j;
            if (fabs(c.arr[iMax][i]) < eps)
                continue;
            for (k = 0; k < matrix->column; ++k)
            {
                temp = c.arr[i][k];
                c.arr[i][k] = c.arr[iMax][k];
                c.arr[iMax][k] = temp;
            }
            countSwaps = -countSwaps * (i != iMax ? 1 : -1);

            for (j = i + 1; j < matrix->line; ++j)
            {
                double q = -c.arr[j][i] / c.arr[i][i];
                for (k = matrix->column - 1; k >= i; --k)
                    c.arr[j][k] += q * c.arr[i][k];
            }
        }
        for (i = 0; i < matrix->line; i++)
        {
            determinant *= c.arr[i][i];
        }
        return determinant * countSwaps;
    }
    else
        return -1;
}

void inversion(Matrix* a)
{
    int i = 0, j = 0, k = 0;
    if (a->line == a->column)
    {
        double temp;
        double** E = (double**)malloc(a->line * sizeof(double*)); 
        for (i = 0; i < a->line; i++)
            E[i] = (double*)malloc(a->line * sizeof(double));

        for (i = 0; i < a->line; i++)
            for (j = 0; j < a->line; j++)
            {
                E[i][j] = 0.0;

                if (i == j)
                    E[i][j] = 1.0;
            }

        for (k = 0; k < a->line; k++)
        {
            temp = a->arr[k][k];

            for (j = 0; j < a->line; j++)
            {
                a->arr[k][j] /= temp;
                E[k][j] /= temp;
            }

            for (i = k + 1; i < a->line; i++)
            {
                temp = a->arr[i][k];

                for (j = 0; j < a->line; j++)
                {
                    a->arr[i][j] -= a->arr[k][j] * temp;
                    E[i][j] -= E[k][j] * temp;
                }
            }
        }

        for (k = a->line - 1; k > 0; k--)
        {
            for (i = k - 1; i >= 0; i--)
            {
                temp = a->arr[i][k];

                for (j = 0; j < a->line; j++)
                {
                    a->arr[i][j] -= a->arr[k][j] * temp;
                    E[i][j] -= E[k][j] * temp;
                }
            }
        }

        for (i = 0; i < a->line; i++)
            for (j = 0; j < a->line; j++)
                a->arr[i][j] = E[i][j];

        for (i = 0; i < a->line; i++)
            free(E[i]);

        free(E);
    }
    else
        printf("The dimension of the matrix does not match!");
}

Matrix transp(Matrix* a)
{
    int i = 0, j = 0;
    Matrix temp;
    getmemory(&temp, a->column, a->line);
    for (i = 0; i < a->line; i++)
    {
        for (j = 0; j < a->column; j++)
            temp.arr[j][i] = a->arr[i][j];
    }
    return temp;
}

Matrix mulnum(Matrix* a, double k)
{
    int i = 0, j = 0;
    Matrix temp;
    getmemory(&temp, a->line, a->column);
    for (i = 0; i < a->line; ++i)
        for (j = 0; j < a->column; ++j)
            temp.arr[i][j] = a->arr[i][j] * k;
    return temp;
}

int multi(Matrix* a, Matrix* b)
{
    return (a->line == b->column && a->column == b->line ||
        a->line == b->line && a->column == b->column);
}
Matrix gauss(Matrix* a)
{
    int i = 0, j = 0, k;
    double temp = 0;
    double countSwaps = 1;
    Matrix c = *a;
    for (i = 0; i < a->line; ++i)
    {
       
        int iMax = i;
        for (j = i + 1; j < a->line; ++j)
            if (fabs(c.arr[j][i]) > fabs(c.arr[iMax][i]))
                iMax = j;
        if (fabs(c.arr[iMax][i]) < eps)
            continue;
        for (k = 0; k < a->column; ++k)
        {
            temp = c.arr[i][k];
            c.arr[i][k] = c.arr[iMax][k];
            c.arr[iMax][k] = temp;
        }
        countSwaps = -1 * countSwaps * (i != iMax ? 1 : -1); 

        
        for (j = i + 1; j < a->line; ++j)
        {
            double q = -c.arr[j][i] / c.arr[i][i];
            for (k = a->column - 1; k >= i; --k)
                c.arr[j][k] += q * c.arr[i][k];
        }
    }
    return c;
}