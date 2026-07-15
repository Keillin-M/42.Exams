#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

int sockfd, maxfd, next_id;
fd_set afd, rfd;
int ids[1024];
char *bufs[1024], rbuf[200001], wbuf[200001];

int extract_message(char **buf, char **msg)
{
	char *newbuf;
	int i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char *newbuf;
	int len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void fatal(void) {
    write(2, "Fatal error\n", 12);
    exit(1);
}

void broadcast(int skip) {
    for(int fd = 0; fd <= maxfd; fd++) {
        if (FD_ISSET(fd, &afd) && fd != skip && fd != sockfd)
            send(fd, wbuf, strlen(wbuf), 0);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        write(2,  "Wrong number of arguments\n", 26);
        exit(1);
    }
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(0x7F000001); // 127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        fatal();
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
        fatal();
    if (listen(sockfd, 10) != 0)
        fatal();
    FD_ZERO(&afd);
    FD_SET(sockfd, &afd);
    maxfd = sockfd;
    while (1) {
        rfd = afd;
        if (select(maxfd + 1, &rfd, NULL, NULL, NULL) < 0)
            continue;
        for (int fd = 0; fd <= maxfd; fd++) {
            if (!FD_ISSET(fd, &rfd))
                continue;
            if (fd == sockfd) {
                int connfd = accept(sockfd, NULL, NULL);
                if (connfd < 0)
                    continue;
                FD_SET(connfd, &afd);
                if (connfd > maxfd)
                    maxfd = connfd;
                ids[connfd] = next_id++;
                bufs[connfd] = NULL;
                sprintf(wbuf,  "server: cliet %d just arrived\n", ids[connfd]);
                broadcast(connfd);
            }
            else {
                int n = recv(fd, rbuf, 200000, 0);
                if (n <= 0) {
                    sprintf(wbuf, "server: client %d just left\n", ids[fd]);
                    broadcast(fd);
                    free(bufs[fd]);
                    bufs[fd] = NULL;
                    FD_CLR(fd, &afd);
                    close(fd);
                }
                else {
                    rbuf[n] = 0;
                    bufs[fd] = str_join(bufs[fd], rbuf);
                    if (!bufs[fd])
                        fatal();
                    char *line;
                    int ret;
                    while ((ret = extract_message(&bufs[fd], &line)) > 0) {
                        sprintf(wbuf, "client %d: %s", ids[fd], line);
                        broadcast(fd);
                        free(line);
                    }
                    if (ret == -1)
                        fatal();
                }
            }
        }
    }

}
