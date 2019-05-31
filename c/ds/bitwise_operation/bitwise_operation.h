#include <stdbool.h>

int set_bit(int x, int pos)
{
	int mask = 1 << pos;
	return x | mask;
}

int clear_bit(int x, int pos)
{
	int mask = 1 << pos;
	return x & ~mask;
}

int flip_bit(int x, int pos)
{
	int mask = 1 << pos;
	return x ^ mask;
}

bool is_bit_set(int x, int pos)
{
	return x >> pos & 1;
}

bool is_even(int x)
{
	return ~x & 1;
}

bool is_power_of_two(int x)
{
	return (x & x-1) == false;
}

int modify_bit(int x, int pos, int state)
{
	int mask = 1 << pos;
	return (x & ~mask) | (state << pos);
}
