#include "request.h"

Request::Request() {
    server_sock_path_ = SERVER_SOCK_PATH;
    memset(&server_sockaddr, 0, sizeof(struct sockaddr_un));
    memset(buf, 0, BUFF_SIZE);
    server_sockaddr.sun_family = AF_UNIX;
    strcpy(server_sockaddr.sun_path, SERVER_SOCK_PATH);

    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("socket error : %s\n", strerror(errno));
        throw 1;
    } else {
        printf("server socket fh : %d\n", sock);
    }
}

std::string Request::Call(const std::string& data) {
    int rc = connect(sock, (struct sockaddr *)&server_sockaddr, sizeof(server_sockaddr));
    if (rc < 0) {
        printf("\nConnection Failed \n");
        throw 1;
    }
    send(sock, data.c_str(), strlen(data.c_str()), 0);
    read(sock, buf, BUFF_SIZE);
    printf("received: %s\n", buf);
    return std::string(buf);
}

