#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define MAXBUF 1024
#include <errno.h>

void isValidSocket(int sockfd)
{
    int error = 0;
    socklen_t len = sizeof (error);
    //int retval = getsockopt (sockfd, SOL_SOCKET, SO_ACCEPTCONN, &error, &len);

    //if( ( -1 == getsockopt(sockfd, SOL_SOCKET, SO_ACCEPTCONN, &error, &len) ) &&
    //        (errno == ENOTSOCK))
    //    printf("fail: not valid socket\n\n");
    //else
    //    printf("ok: valid socket\n\n");
    
    int retval = getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &len);
    if (retval != 0) {
        /* there was a problem getting the error code */
        fprintf(stderr, "error getting socket error code: %s\n\n", strerror(retval));
        return;
    }

    else if (error != 0) {
        /* socket has a non zero error status */
        fprintf(stderr, "socket error: %s\n\n", strerror(error));
    }
    else
        printf("ok valid socket\n\n");
    
    
}

int main(int argc, char **argv)
{
    int server_sockfd, client_sockfd;
    int client_len, n;
    char buf[MAXBUF];
    struct sockaddr_in clientaddr, serveraddr;

    client_len = sizeof(clientaddr);

    printf("before socket\n");
    isValidSocket(server_sockfd);
    if((server_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1 )
    {
        perror("socket error:");
        exit(0);
    }
    printf("after socket\n");
    isValidSocket(server_sockfd);
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddr.sin_port = htons(atoi(argv[1]));

    bind(server_sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
    printf("after bind\n");
    isValidSocket(server_sockfd);

    listen(server_sockfd, 5);
    printf("after listen\n");
    isValidSocket(server_sockfd);

    while(1)
    {
        printf("before accept\n");
        isValidSocket(client_sockfd);
        memset(buf, 0x00, MAXBUF);
        client_sockfd = accept( server_sockfd,
                (struct sockaddr*)&clientaddr, (socklen_t*)&client_len);
        printf("New Client Connect: %s\n",
                inet_ntoa(clientaddr.sin_addr));
        printf("after accept\n");
        isValidSocket(client_sockfd);
        if((n=read(client_sockfd, buf, MAXBUF))<=0)
        {
            close(client_sockfd);
            continue;
        }
        if(write(client_sockfd, buf, MAXBUF)<=0)
        {
            perror("write error:");
            close(client_sockfd);
        }
        close(client_sockfd);
    }
    close(server_sockfd);
    return 0;
}


