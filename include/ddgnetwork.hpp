#ifndef DDG_NETWORK
#define DDG_NETOWRK

#include "includes.hpp"

#define SOCKET_BUFFER_SIZE 8224

// ============== Connection section ================

void startConnection() {
    WORD winsock_version = 0x202;
    WSADATA winsock_data;

    if(WSAStartup(winsock_version, &winsock_data)) {
        std::cout << "WSAStartup failed: " << WSAGetLastError();
        return;
    }

    int address_family = AF_INET;
    int type = SOCK_DGRAM;
    int protocol = IPPROTO_UDP;
    SOCKET sock = socket(address_family, type, protocol);

    if(sock == INVALID_SOCKET) {
        std::cout << "Socket failed: " << WSAGetLastError();
        return;
    }

    SOCKADDR_IN local_address;
    local_address.sin_family = AF_INET;
    local_address.sin_port = htons(9999);
    local_address.sin_addr.s_addr = INADDR_ANY;
    if(bind(sock, (SOCKADDR*)&local_address, sizeof(local_address)) == SOCKET_ERROR) {
        std::cout << "Binding has failed: " << WSAGetLastError();
        return;
    }

    char buffer[SOCKET_BUFFER_SIZE];
    bool is_running = true;
    int flags = 0;

    while(is_running) {
        
        SOCKADDR_IN from;
        int from_size = sizeof(from);
        int bytes_received = recvfrom(sock, buffer, SOCKET_BUFFER_SIZE, flags, (SOCKADDR*)&from, &from_size);
    
        if(bytes_received == SOCKET_ERROR) {
            std::cout << "Recvfrom returned socket error, " << WSAGetLastError();
        }
        else {
            // buffer[bytes_received] = 0;
            
            // std::cout << from.sin_addr.S_un.S_un_b.s_b1 <<  "." <<
            //             from.sin_addr.S_un.S_un_b.s_b2 << "." << from.sin_addr.S_un.S_un_b.s_b3 << "." <<
            //             from.sin_addr.S_un.S_un_b.s_b4 << ":" << ntohs(from.sin_port) << " - " <<
            //             buffer;
            char client_input = buffer[0];
            switch(client_input) {
                case 'q':
                    is_running = 0;
                break;
            }
        }
    }



    SOCKADDR_IN server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons( 9999 );
    server_address.sin_addr.S_un.S_addr = inet_addr( "127.0.0.1" );

    char message[SOCKET_BUFFER_SIZE];
    gets_s( message, SOCKET_BUFFER_SIZE );

    flags = 0;
    if( sendto( sock, message, strlen( message ), flags, (SOCKADDR*)&server_address, sizeof( server_address ) ) == SOCKET_ERROR )
    {
        printf( "sendto failed: %d", WSAGetLastError() );
        return;
    }
}

#endif