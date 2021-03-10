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

int main() {

    //create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // specify an address for  the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    //check for error with connection
    if(connection_status == -1){
        printf("There was an error making a connection to th remote socket\n\n");
    }
    //recieve data from the server
    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);

    //print the server's response
    printf("The server sent the data %s\n", server_response);

    closesocket(network_socket);
    return 0;
}