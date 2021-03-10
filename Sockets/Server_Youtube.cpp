#include <iostream>
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")
#pragma comment (lib, "ws2_32.lib")

using namespace std;

void main() {
    //initialize winsock
    WSADATA wsData;
    WORD ver = MAKEWORD(2, 2);

    int wsOk = WSAStartup(ver, &wsData);
    if(wsOk != 0){
        cerr << "Can't initialize winsock! Quitting" << endl;
        return; 
    }

    //create a socket
    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == INVALID_SOCKET)
    {
        cerr << "Can't create a socket! Quitting" << endl;
        return;
    }
    //bind the ip address and port to a socket 
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    hint.sin_addr.S_un.S_addr = INADDR_ANY;

    bind(listening, (sockaddr *)&hint, sizeof(hint));

    //tell winsock the socket is for listening
    listen(listening, SOMAXCONN);

    //wait for connection
    sockaddr_in client;
    int clientSize = sizeof(client);

    SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
    
    char host[NI_MAXHOST]; // clients remote name
    char service[NI_MAXSERV]; // Service (i.e port) the client is connected on

    ZeroMemory(host, NI_MAXHOST); //same as memset(host, 0, NI_MAXHOST)
    ZeroMemory(service, NI_MAXSERV);//same as memset(host, 0, NI_MAXHOST)

    if(getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0){
        cout << host << " connected on port " << service << endl;
    }else {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }
    //close listening socket
    closesocket(listening);

    //While loop: accept echo message back to client
    char buf[4096];
    while (true) {
        ZeroMemory(buf, 4096);
        //wait for client to send data
        int bytesReceived = recv(clientSocket, buf, 4096, 0);
        if(bytesReceived == SOCKET_ERROR){
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }
        if (bytesReceived == 0)
        {
            cout << "client disconnected " << endl;
            break;
        }
        //echo message back to client
        send(clientSocket, buf, bytesReceived + 1, 0); 
    }
    //close the socket
    closesocket(clientSocket);

    //cleanup winsock
    WSACleanup();

}