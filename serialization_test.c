#include <stdio.h>

#include "serialization.h"

int main()
{
	unsigned char buf[20];
	int32_t packetsize;
	int8_t unpack_char;
	int16_t unpack_short;
	int64_t unpack_long;
	int i;

	for (i = 0; i < 20; ++i)
		buf[i] = 0;

	packetsize = pack(buf, "lcs", (int64_t)1, (int8_t)2, (int16_t)3);

	printf("Packet is %" PRId32 " bytes\n", packetsize);

	unpack(buf, "lcs", &unpack_long, &unpack_char, &unpack_short);

	printf("%" PRId64 " %d %" PRId16 "\n", unpack_long, unpack_char, unpack_short);

	for (i = 0; i < 20; ++i)
		printf("%d", (unsigned int)buf[i]);

	printf("\n\n");

	return 0;
}
