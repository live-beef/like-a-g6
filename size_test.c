#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	char ch;

	ch = 255;

	printf("Size of char:\t\t%lu\n", sizeof (char));
	printf("Size of short:\t\t%lu\n", sizeof (short));
	printf("Size of long:\t\t%lu\n", sizeof (long));
	printf("Size of unsigned long:\t\t%lu\n", sizeof (unsigned long));
	printf("Size of int8_t:\t\t%lu\n", sizeof (int8_t));
	printf("Size of uint8_t:\t%lu\n", sizeof (uint8_t));
	printf("Size of int16_t:\t%lu\n", sizeof (int16_t));
	printf("Size of uint8_t:\t%lu\n", sizeof (uint16_t));
	printf("Size of int32_t:\t%lu\n", sizeof (int32_t));
	printf("Size of uint32_t:\t%lu\n", sizeof (uint32_t));
	printf("Testando o char %c\n:", ch);

	return 0;
}
