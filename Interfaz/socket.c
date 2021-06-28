#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <io.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <time.h>

#pragma comment(lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

char SendBuff[512],RecvBuff[512];
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
/**
 * Eschucha en un puerto
 * @param puerto
 * @param ip
 * @return
 */
char* escuchar(int puerto,char* ip){
    WSADATA wsaData;
    SOCKET conn_socket,comm_socket;
    SOCKET comunicacion;
    struct sockaddr_in server;
    struct sockaddr_in client;
    struct hostent *hp;
    int resp,stsize;
    char * respuesta;

    //Inicializamos la DLL de sockets
    resp=WSAStartup(MAKEWORD(1,0),&wsaData);
    if(resp){
        printf("Error al inicializar socket\n");
        return resp;
    }

    //Obtenemos la IP que usará nuestro servidor...
    // en este caso localhost indica nuestra propia máquina...
    hp=(struct hostent *)gethostbyname(ip);

    if(!hp){
        printf("No se ha encontrado servidor...\n");
        WSACleanup();return WSAGetLastError();
    }

    // Creamos el socket...
    conn_socket=socket(AF_INET,SOCK_STREAM, 0);
    if(conn_socket==INVALID_SOCKET) {
        printf("Error al crear socket\n");
        WSACleanup();return WSAGetLastError();
    }

    memset(&server, 0, sizeof(server)) ;
    memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
    server.sin_family = hp->h_addrtype;
    server.sin_port = htons(puerto);

    // Asociamos ip y puerto al socket
    resp=bind(conn_socket, (struct sockaddr *)&server, sizeof(server));
    if(resp==SOCKET_ERROR){
        printf("Error al asociar puerto e ip al socket\n");
        closesocket(conn_socket);WSACleanup();
        return WSAGetLastError();
    }

    if(listen(conn_socket, 1)==SOCKET_ERROR){
        printf("Error al habilitar conexiones entrantes\n");
        closesocket(conn_socket);WSACleanup();
        return WSAGetLastError();
    }

    // Aceptamos conexiones entrantes
    printf("Esperando conexiones entrantes... \n");
    stsize=sizeof(struct sockaddr);
    comm_socket=accept(conn_socket,(struct sockaddr *)&client,&stsize);
    if(comm_socket==INVALID_SOCKET){
        printf("Error al aceptar conexión entrante\n");
        closesocket(conn_socket);WSACleanup();
        return WSAGetLastError();
    }
    printf("Conexión entrante desde: %s\n", inet_ntoa(client.sin_addr));

    // Como no vamos a aceptar más conexiones cerramos el socket escucha
    closesocket(conn_socket);

    strcpy(SendBuff,"Hola Cliente... .P");
    //Enviamos y recibimos datos...
//    printf("Enviando Mensaje... \n");
//    send (comm_socket, SendBuff, sizeof(SendBuff), 0);
//    printf("Datos enviados: %s \n", SendBuff);

    printf("Recibiendo Mensaje... \n");
    recv (comm_socket, RecvBuff, sizeof(RecvBuff), 0);
    printf("Datos recibidos: %s \n", RecvBuff);


    //getchar();

    // Cerramos el socket de la comunicacion
    closesocket(comm_socket);

    // Cerramos liberia winsock
    WSACleanup();
    return RecvBuff;
}

/**
 * Envia en un puerto
 * @param ip
 * @param puerto
 * @param mensaje
 * @return
 */
int enviar(char *ip, int puerto, char* message){
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;

    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }

    printf("Initialised.\n");

    //Create a socket
    if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }

    printf("Socket created.\n");


    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_family = AF_INET;
    server.sin_port = htons( puerto );

    //Connect to remote server
    if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }

    puts("Connected");

    //Send some data
    if( send(s , message , strlen(message) , 0) < 0)
    {
        puts("Send failed");
        return 1;
    }
    puts("Data Send\n");

    closesocket(s);
    WSACleanup();
    return 0;
}