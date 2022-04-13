#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
using namespace std;

int main(int argc, char* argv[]) {
    int sockfd, portNumber, n;
    struct sockaddr_in serverAddress;
    struct hostent *server;

    //localhost
    char buffer[255];

    portNumber = atoi(argv[1]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
        cout << "Error: opening socket." << endl;

    server = gethostbyname("127.0.0.1");
    bzero((char*) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;

    bcopy((char*) server->h_addr, (char*) &serverAddress.sin_addr.s_addr, server->h_length);

    serverAddress.sin_port = htons(portNumber);

    if (connect(sockfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0)
        cout << "Error: Connection failed." << endl;

    bzero(buffer, 255);

    n = write(sockfd, "<Valentina>:<04959393>", strlen("<Valentina>:<04959393>"));

    if (n < 0)
        cout << "Error: Writing failed." << endl;

    bzero(buffer, 255);

    n = read(sockfd, buffer, 255);

    if (n < 0)
        cout << "Error: Reading failed." << endl;

    cout << buffer << endl;

    close(sockfd);
    return 0;
}
