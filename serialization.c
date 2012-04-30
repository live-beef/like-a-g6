#include "serialization.h"

void pack_char(unsigned char *buf, unsigned char num)
{
	*buf = num;
}


void pack_short(unsigned char *buf, unsigned short num)
{
	*buf++ = num >> 8;
	*buf = num;
}

void pack_long(unsigned char *buf, unsigned long num)
{
#ifndef _LP64
	/* x86_32: long armazenado em 32 bits (4 bytes). */
	/* Completar as posições mais significativas com 0. */
	/* TODO: completar */

	int i;

	for (i = 0; i < 4; ++i)
		*buf++ = 0x00;

#endif

	*buf++ = num >> 56;
	*buf++ = num >> 48;
	*buf++ = num >> 40;
	*buf++ = num >> 32;
	*buf++ = num >> 24;
	*buf++ = num >> 16;
	*buf++ = num >> 8;
	*buf = num;
}

unsigned char unpack_char(unsigned char *buf)
{
	return buf[0];
}

unsigned short unpack_short(unsigned char *buf)
{
	return (buf[0] << 8) | buf[1];
}

unsigned long unpack_long(unsigned char *buf)
{
#ifndef _LP64
	/* x86_32: long armazenado em 32 bits (4 bytes). */
	/* Descartar as posições mais significativas (possuem 0). */
	/* TODO: completar */

	int i;

	for (i = 0; i < 4; ++i)
		*buf++;
#endif

	return ((unsigned long) buf[0] << 56)
			| ((unsigned long) buf[1] << 48)
			| ((unsigned long) buf[2] << 40)
			| ((unsigned long) buf[3] << 32)
			| ((unsigned long) buf[4] << 24)
			| ((unsigned long) buf[5] << 16)
			| ((unsigned long) buf[6] << 8)
			| buf[7];
}


int32_t pack(unsigned char *buf, char *format, ...)
{
	va_list ap;
	int8_t c;
	int16_t s;
	int64_t l;
	int32_t size = 0;

	va_start(ap, format);

	for (; *format != '\0'; ++format) {
		switch (*format) {
			case 'c': /* 1 byte */
				size += 1;
				c = (int8_t) va_arg(ap, int);
				pack_char(buf, c);
				++buf;
				break;
			case 's': /* 2 bytes */
				size += 2;
				s = (int16_t) va_arg(ap, int);
				pack_short(buf, s);
				buf += 2;
				break;
			case 'l':
				size += 8;
				l = (int64_t) va_arg(ap, int64_t);
				pack_long(buf, l);
				buf += 8;
				break;
		}
	}

	va_end(ap);

	return size;
}

void unpack(unsigned char *buf, char *format, ...)
{
	va_list ap;
	int8_t *c;
	int16_t *s;
	int64_t *l;

	va_start(ap, format);

	for (; *format != '\0'; ++format) {
		switch (*format) {
			case 'c':
				c = va_arg(ap, int8_t *);
				*c = unpack_char(buf);
				++buf;
				break;
			case 's':
				s = va_arg(ap, int16_t *);
				*s = unpack_short(buf);
				buf += 2;
				break;
			case 'l':
				l = va_arg(ap, int64_t *);
				*l = unpack_long(buf);
				buf += 8;
				break;
		}
	}
}
