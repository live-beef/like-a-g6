/*
 * Data de criação: 28/04/2012
 * Autor: Victor Gabriel P. Lacôrte e Silva
 *
 * Definição dos tipos de mensagens a serem utilizadas no algoritmo de
 * Berkeley, assim como funcionalidades para debug da aplicação.
 */

#ifndef COMMON_INTEREST_H
#define COMMON_INTEREST_H

/* Prints utilizados no modo de debug */
#define ENABLE_DEBUG() extern int ebug;

/* printp: printf phrase */
#define printp(x) if (debug) { printf(x); fflush(stdout); }

/* printfa: print argument */
#define printa(x, a) if (debug) { printf(x, a); fflush(stdout); }

/* Prints a serem utilizados caso contrário */
/* printe: print error */
#define printe(x) printf(x); fflush(stdout);

/* Número de retransmissões enquanto não recebe um ACK */
#define RETRY 10

/* 
 * Através dos argumentos fornecidos pela linha de comando, verifica se
 * deve ou não setar a flag de debug. Em caso afirmativo, remove o
 * argumento correspondente da lista fornecida pelo usuário (isto é,
 * faz um "shift" dos outros argumentos.
 */
void set_debug(int *argc, char *argv[]);

/*  Criação de um socket UDP e retorno do file descriptor associado. */
int create_udp_socket();

/* Encerra um socket caso esteja aberto. */
void close_socket(int sockfd);

/* Handler para o SIGINT */
void sigint_handler();

#endif
