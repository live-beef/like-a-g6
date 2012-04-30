#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "common_interest.h"

/* Flag de debug que todos os outros arquivos referenciam. */
int debug = 0;

extern int sockfd;

void set_debug(int *argc, char *argv[])
{
	if (*argc > 1) {
		int i;

		for (i = 1; i < *argc; ++i) {
			/* "-d" sinaliza que deve entrar em modo de debug. */
			if (strncmp(argv[i], "-d", 2) == 0) {
				debug = 1;
				break;
			}
		}

		if (debug) {
			/* Remoção do argumento "-d" passado pela linha de comando. */
			for (; i < (*argc) - 1; ++i)
				argv[i] = argv[i + 1];

			--(*argc);
		}
	}
}

int create_udp_socket()
{
	int sockfd;

	if ((sockfd = socket(PF_INET, SOCK_DGRAM, 0)) == -1) {
		printe("Erro na criacao do socket.");
		exit(-1);
	}

	printa("Socket %d criado com sucesso.\n", sockfd);
	return sockfd;
}

void close_socket(int sockfd)
{
	if (sockfd == -1)
		return;
	else if (close(sockfd) == -1) {
		printe("Nao foi possivel encerrar o socket.");
		exit(-1);
	}

	printa("Socket %d encerrado com sucesso.", sockfd);
}

void sigint_handler()
{
	printe("Recebeu SIGINT, encerrando processo...\n");
	close_socket(sockfd);
	exit(0);
}
