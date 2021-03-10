#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>

#if defined(_WIN32) || defined(_WIN64)
    #include <winsock2.h>
#else
    #include <sys/socket.h>
    #include <arpa/inet.h>
#endif

#define MSG_SIZE 1024
#define REPLY_SIZE 65536

int main(int argc, char *argv[])
{
    int s = -1;
    struct sockaddr_in server;
    char message[MSG_SIZE] = {0}, server_reply[REPLY_SIZE] = {0};
    int recv_size = 0;

#if defined(_WIN32) || defined(_WIN64)    
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) {
        printf("\nError: Windows socket subsytsem could not be initialized. Error Code: %d. Exiting..\n", WSAGetLastError());
        exit(1);
    }
#endif
    
    //Create a socket
    if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)    {
        printf("Error: Could not create socket: %s. Exiting..\n", strerror(errno));
        exit(1);
    }

    // Fill in server's address
    memset(&server, 0, sizeof(server));
    server.sin_addr.s_addr = inet_addr("172.217.160.238"); // google.com
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    // Connect to server
    if (connect(s, (struct sockaddr *)(&server), sizeof(server)) < 0) {
        printf("Error: Could not connect to server: %s. Exiting..\n", strerror(errno));
        exit(1);
    }
    
    // Send HTTP request
    strcpy(message, "GET / HTTP/1.1\r\n\r\n");
    if(send(s, message, strlen(message), 0) < 0) {
        printf("Error: Could not send http request to server: %s. Exiting..\n", strerror(errno));
        exit(1);
    }
    
    // Receive a reply from the server
    printf("\nWaiting for server reply..\n");
    if((recv_size = recv(s, server_reply, REPLY_SIZE, 0)) < 0) {
        printf("Error: Something wrong happened while getting reply from server: %s. Exiting..\n", strerror(errno));
        exit(1);
    }

    server_reply[REPLY_SIZE - 1] = 0;

    printf("\nServer Reply:\n\n");
    printf("%s\n", server_reply);

    // Close the socket
#if defined(_WIN32) || defined(_WIN64)  
    closesocket(s);
    WSACleanup();
#else
    close(s);
#endif

    exit(0);
} 