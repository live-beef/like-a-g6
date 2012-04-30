/* Autor: Victor Gabriel
 * Data: 29/04/2012
 *
 * Definição das funções para serializar (e desserializar) 1, 2 e 4 bytes.
 * Esses tamanhos correspondem aos campos que devem ser enviados nas
 * mensagens de comunicação do algoritmo de Berkeley.
 */

#ifndef SERIALIZATION_H
#define SERIALIZATION_H

#include <stdint.h>
#include <inttypes.h>
#include <stdarg.h>

/* pack_*: obtém o dado em Little-Endian e o armazena em buf
 * sob a representação Big-endian (similar à hton).
 *
 * unpack_*: obtém o dado a partir de uma representação em Big-Endian
 * para uma em Litte-Endian.
 *
 * É importante tratar a diferença entre arquiteturas de 32 e 64 bits
 * (x86 e x64, respectivamente). Na primeira, o tipo long é armazenado em
 * 32 bits, enquanto que na segunda ele é em 64.
 */

void pack_char(unsigned char *buf, unsigned char num);
void pack_short(unsigned char *buf, unsigned short num);
void pack_long(unsigned char *buf, unsigned long num);

unsigned char unpack_char(unsigned char *buf);
unsigned short unpack_short(unsigned char *buf);
unsigned long  unpack_long(unsigned char *buf);

/* pack: serializa todos os campos de um pacote para envio de acordo com o
 * buffer de string armazenado em memória:
 * c - 1 byte
 * s - 2 bytes
 * l - 8 bytes
 *
 * É importante ressaltar que o tipo "long" foi definido como sendo de 8 bytes,
 * apesar da arquitetura de 32 bits definí-lo como 4 bytes, para tornar a
 * serialização transparente para o usuário. Por isso nas funções pack_long
 * e unpack_long adicionou-se ou removeu-se, respectivamente, 0's da parte
 mais significativa.
 */
int32_t pack(unsigned char *buf, char *format, ...);

#endif
