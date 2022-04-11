#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
    int sockfd, portNumber, n;
    struct sockaddr_in serverAddress;
    struct hostent *server;

    char buffer[255];

    portNumber = atoi(argv[1]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        cout << "Error: opening socket." << endl;

    bzero((char*) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;

    bcopy((char*) server->h_addr, (char*) &serverAddress.sin_addr.s_addr, server->h_length);

    serverAddress.sin_port = htons(portNumber);

    if (connect(sockfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0)
        cout << "Error: Connection failed." << endl;

    while (1) {
        bzero(buffer, 255);
        fgets(buffer,255,stdin);
        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0)
            cout << "Error: Writing failed." << endl;

        bzero(buffer, 255);

        n = read(sockfd, buffer, strlen(buffer));

        if (n < 0)
            cout << "Error: Reading failed." << endl;

        cout << "Server: " << buffer << endl;

        int i = strcmp("Bye", buffer, 3);

        if (i == 0)
            break;
    }

    close(sockfd);
    return 0;
}
