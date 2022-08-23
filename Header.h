#define _CRT_SECURE_NO_WARNINGS
const double E = 1e-6;
const int INF_ROOTS = -1;
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

struct Roots {
	int nRoots = 0;
	double* roots;
};

Roots Init(int nRoots) {
	Roots r;
	r.nRoots = nRoots;
	if(nRoots > 0)
		r.roots = (double*)malloc(sizeof(double)*nRoots);
	return r;
}

void clean_buffer() {
	while ((getchar()) != '\n');
}

void get_rand_coef(double* a, double* b, double* c)
{
	*a = rand();
	double k = rand();
	if (k == 0)
		k = ((int)k % 10) + 1;
	*a = (*a) / k;

	*b = rand();
	k = rand();
	if (k == 0)
		k = ((int)k % 10) + 1;
	*b = (*b) / k;

	*c = rand();
	k = rand();
	if (k == 0)
		k = ((int)k % 10) + 1;
	*c = (*c) / k;

	printf("%lg %lg %lg\n", *a, *b, *c);
}

void get_coef(double* a, double* b, double* c)
{
	printf("Enter the coefficient for x squared\n");
	while (!scanf("%lg", a))
	{
		clean_buffer();
		printf("Wrong format. Try again\n");
	}

	clean_buffer();
	printf("Enter the coefficient for x\n");
	while (!scanf("%lg", b))
	{
		clean_buffer();
		printf("Wrong format. Try again\n");
	}

	clean_buffer();
	printf("Enter the free coefficient\n");
	while (!scanf("%lg", c))
	{
		clean_buffer();
		printf("Wrong format. Try again\n");
	}
}

double D(double a, double b, double c)
{
	return b * b - 4 * a * c;
}

Roots solve_1eq(double b, double c) 
{
	Roots r;
	if (-E < b && b < E)
	{
		if (-E < c && c < E)
		{
			r = Init(INF_ROOTS);
			return r;
		}
		else
		{
			r = Init(0);
			return r;
		}
	}
	else
	{
		r = Init(1);
		r.roots[0] = -c / b;
		return r;
	}
}

Roots solve_2eq(double a, double b, double c)
{
	Roots r;
	if (-E < a && a < E)
	{
		return solve_1eq(b, c);
	}

	double d = D(a, b, c);

	if (- E < d && d < E)
	{
		r = Init(1);
		r.roots[0] = -b / (2 * a);
		return r;
	}

	if (d < 0)
	{
		r = Init(0);
		return r;
	}

	d = sqrt(d);
	r = Init(2);
	r.roots[0] = (-b + d) / (2 * a);
	r.roots[1] = (-b - d) / (2 * a);
	return r;
}

void Output(Roots anses) {

	if (anses.nRoots == INF_ROOTS)
	{
		printf("Infinity number of roots\n");
	}
	if (anses.nRoots == 0)
	{
		printf("No roots\n");
	}

	if (anses.nRoots > 0) {
		for (int i = 0; i < anses.nRoots; i++) {
			printf("%lg ", anses.roots[i]);
		}
		printf("\n");
	}
}