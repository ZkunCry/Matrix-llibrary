#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "..\StaticLib\matrix.h"


int main()
{
	Matrix x, y,temp;
	int n=2, m=2,n2=2,m2=2;
	scanf("%d %d %d %d", &n, &m, &n2, &m2);
	getmemory(&x, n, m);
	getmemory(&y, n2, m2);
	input(&x);
	input(&y);
	temp = summatrix(&x, &y);
	output(&temp);
	output(&x);
	removemem(&temp);
	removemem(&x);
	removemem(&y);
	return 0;
}
