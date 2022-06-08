#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "..\StaticLib\matrix.h"
//
int main()
{
	system("chcp 1251 >null");
	Matrix x, y,temp;
	int n, m,n2,m2;
	char* namefile = "matrix.txt";
	getmemory(&x, 2, 2);
	getmemory(&y, 2, 2);
	input(&x);
	input(&y);
	temp = summatrix(&x, &y);
	output(&temp);
	return 0;
}
