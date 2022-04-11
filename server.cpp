//
// Created by vcs04 on 4/11/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
using namespace std;

int main(int argc, char* argv[]) {
    int sockfd, newsockfd, portNumber, n;
    char buffer[255];
    struct sockaddr_in serverAddress, clientAddress;

    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        cout << "Error: opening socket" << endl;

    bzero((char*) &serverAddress, sizeof(serverAddress));

    portNumber = atoi(argv[1]);

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(portNumber);

    if (bind(sockfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        cout << "Error: Binding failed." << endl;
        return 0;
    }

    listen(sockfd, 5);
    clilen = sizeof(clientAddress);

    newsockfd = accept(sockfd, (struct sockaddr *) &clientAddress, &clilen);

    if (newsockfd < 0) {
        cout << "Error: Accept failed." << endl;
    }

    //bzero(buffer, 255);
    //n = read(newsockfd, buffer, 255);
    //n = write(newsockfd, buffer, 255);

    cout << "<Valentina>:<04959393>" << endl;

    if (n < 0)
        cout << "Error: Reading failed." << endl;


    bzero(buffer, 255);
    //fgets(buffer, 255, stdin);

    n = write(newsockfd, "Welcome to the server running on REPTILIAN", 43);

    if (n < 0)
        cout << "Error: Writing failed." << endl;

    close(newsockfd);
    close(sockfd);
}