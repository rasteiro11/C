#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

int main() {
    char server_message[256] = "You have reached the server";
    int s = -1;
    struct sockaddr_in server;


    #if defined(_WIN32) || defined(_WIN64)    
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) {
        printf("\nError: Windows socket subsytsem could not be initialized. Error Code: %d. Exiting..\n", WSAGetLastError());
        exit(1);
    }
    #endif
    //creating a socket
    //int network_socket = -1;
    //Create a socket
    if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0)    {
        printf("Error: Could not create socket: %s. Exiting..\n", strerror(errno));
        exit(1);
    }
    //define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //bind the socket to our specified IP and port
    bind(s, (struct sockaddr*) (&server), sizeof(server));

    listen(s, 5);

    int client_socket;
    client_socket = accept(s, NULL, NULL);

    //send the message
    send(client_socket, server_message, sizeof(server_message), 0);

       
    #if defined(_WIN32) || defined(_WIN64)  
        closesocket(s);
        WSACleanup();
    #else
        close(s);
    #endif
        
    
    exit(0);
}