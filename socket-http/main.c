#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
int main(){
    char *url = "www.example.com";
    char address[30];
    struct hostent *server = gethostbyname(url);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
    }else {
        printf("%s\n\n", server->h_name);

        struct in_addr **addr_list = (struct in_addr **) server->h_addr_list;
        for(int i = 0; addr_list[i] != NULL; i++) {
            strcpy(address, inet_ntoa(*addr_list[i]) );
            printf("i is %d, IP ADDRESS->%s\n", i+1, address);
        }
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(address);
    serv_addr.sin_port = htons(80);
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("connect err");
        return 0;
    }

    /* char *request_header = "\ */
/* GET / HTTP/1.1\r\n\ */
/* HOST: %s\r\n\ */
/* Cache-Control: no-cache\r\n\r\n"; */
    char request_header[200];
    strcat(request_header, "GET ");
	strcat(request_header, "/");
	strcat(request_header, " HTTP/1.1\r\n");
	strcat(request_header, "HOST: ");
	strcat(request_header, url);
	strcat(request_header, "\r\n");
	strcat(request_header,"Cache-Control: no-cache\r\n\r\n");
	printf("-> HTTP请求报文如下\n--------HTTP Request--------\n%s\n", request_header);

    /* send the request */
    int total = strlen(request_header);
    int sent = 0;
    do {
        printf("total is %d \n", total);
        int bytes = write(sock, request_header + sent, total - sent);
        if (bytes < 0)
            printf("ERROR writing message to socket");
        if (bytes == 0)
            break;
        printf("wrote bytes %d \n", bytes);
        sent += bytes;
    } while (sent < total);

    char response[10*1024];
    memset(response, 0, sizeof(response));
    total = sizeof(response)-1;
    int received = 0;
    do {
        int bytes = recv(sock,  response+received, total-received, 0);
        printf("received bytes %d \n", bytes);
        /* int bytes = read(sock, response+received, total-received); */
        if (bytes < 0)
            printf("ERROR reading response from socket");
        if (bytes == 0) {
            printf("received bytes 0, break\n");
            break;
        }
        printf("received bytes %d \n", bytes);
        received += bytes;
    } while (received < total);

    if (received == total)
        printf("ERROR storing complete response from socket");

    close(sock);
    printf("Response:\n%s\n",response);
    return 0;
}
