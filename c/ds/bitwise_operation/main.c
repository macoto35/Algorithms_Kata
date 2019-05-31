#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "bitwise_operation.h"

int main(int argc, char* argv[])
{
	int x1 = 22;
	int pos1 = 5;
	assert(set_bit(x1, pos1) == 54);

	int x2 = 54;
	int pos2 = 5;
	assert(clear_bit(x2, pos2) == 22);

	int x3 = 97;
	int pos3 = 5;
	assert(flip_bit(x3, pos3) == 65);
	assert(is_bit_set(x3, pos3) == true);
	assert(is_bit_set(x3, 1) == false);
	assert(is_bit_set(x3, 0) == true);

	assert(is_even(2) == true);
	assert(is_even(3) == false);

	for (int i = 0; i < 8; i++)
		assert(is_power_of_two(pow(2, i)) == true);
	assert(is_power_of_two(3) == false);
	assert(is_power_of_two(5) == false);

	assert(modify_bit(77, 4, 0) == 77);
	assert(modify_bit(80, 7, 1) == 208);

	return EXIT_SUCCESS;
}
