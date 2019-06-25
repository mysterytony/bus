#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <sys/un.h>
#include <string>

#define SERVER_SOCK_PATH "/tmp/busd.sock"
#define BUFF_SIZE 256

class Request {
public:
    Request();

    std::string Call(const std::string& data);

private:
    int sock;
    struct sockaddr_un server_sockaddr;

    std::string server_sock_path_;
    char buf[BUFF_SIZE];
};

