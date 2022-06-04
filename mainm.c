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
	scanf("%d %d", &n, &m);
	getmemory(&x, n, m);
	input(&x);
	mulnum(&x,2);
	output(&x);
	return 0;
}
