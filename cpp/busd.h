/*
reference
https://www.ibm.com/support/knowledgecenter/en/SSB23S_1.1.0.14/gtpc1/unixsock.html
*/

#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCK_PATH "/tmp/busd.sock"
#define DATA "Hello from the server"
#define BUFF_SIZE 256

class BUSD {
public:
    BUSD();
    void RegisterFunction();
    void Start();

private:
    // variables
    int server_sock, client_sock, rc;
    socklen_t len;
    int bytes_rec = 0;
    struct sockaddr_un server_sockaddr;
    struct sockaddr_un client_sockaddr;
    char buf[BUFF_SIZE];
    int backlog = 10;
};

