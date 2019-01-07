#include <stdio.h>

void add(n1, d1, n2, d2);
void mul(n1, d1, n2, d2);
int gcd(int a, int b);

void main()
{
	/*
	n1    n2
	--    -- 
	d1    d2
	*/
	int n1, d1, n2, d2;

	printf("enter four numbers (numerator1, denominator1, numerator2, denominator2) : ");
	scanf("%d %d %d %d", &n1, &d1, &n2, &d2);

	add(n1, d1, n2, d2);
	mul(n1, d1, n2, d2);
}

void add(n1, d1, n2, d2)
{
	int rn =  (n1 * d2) + (n2 * d1);
	int rd = d1 * d2;
	int g = rn > rd? gcd(rn, rd) : gcd(rd, rn);

	printf("result = %d / %d\n", rn/g, rd/g);
}

void mul(n1, d1, n2, d2)
{
	int rn = n1 * n2;
	int rd = d1 * d2;
	int g = rn > rd? gcd(rn, rd) : gcd(rd, rn);

	printf("result = %d / %d\n", rn/g, rd/g);
}

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}
