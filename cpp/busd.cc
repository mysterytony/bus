#include "busd.h"

BUSD::BUSD() {
    memset(&server_sockaddr, 0, sizeof(struct sockaddr_un));
    memset(&client_sockaddr, 0, sizeof(struct sockaddr_un));
    memset(buf, 0, BUFF_SIZE);

    // create a unix domain stream socket
    server_sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_sock < 0) {
        printf("socket error : %s\n", strerror(errno));
        throw 1;
    } else {
        printf("server socket fh : %d\n", server_sock);
    }

    server_sockaddr.sun_family = AF_UNIX;
    strcpy(server_sockaddr.sun_path, SOCK_PATH);
    len = sizeof(server_sockaddr);

    unlink(SOCK_PATH);
    rc = bind(server_sock, (struct sockaddr *)&server_sockaddr, len);
    if (rc != 0) {
        printf("bind error : %s\n", strerror(errno));
        close(server_sock);
        throw 1;
    }
}

void BUSD::Start() {
    // ignores the SIGPIPE the broken pipe signal
    // if we are sending to a tcp socket that's closed by peers
    // send() will crash the program instead of return an error code
    // so we ignore SIGPIPE and handle the error returned by send()
    signal(SIGPIPE, SIG_IGN);

    // listen
    rc = listen(server_sock, backlog);
    if (rc != 0) {
        printf("listen error : %s\n", strerror(errno));
        close(server_sock);
        throw 1;
    }

    while (1) {
        client_sock =
            accept(server_sock, (struct sockaddr *)&client_sockaddr, &len);
        if (client_sock < 0) {
            printf("accept error : %s\n", strerror(errno));
            close(server_sock);
            close(client_sock);
            throw 1;
        } else {
            printf("client socket fh: %d\n", client_sock);
        }

        len = sizeof(client_sockaddr);
        rc = getpeername(client_sock, (struct sockaddr *)&client_sockaddr, &len);
        if (rc != 0) {
            printf("getpeername error: %s\n", strerror(errno));
            close(server_sock);
            close(client_sock);
            exit(1);
        } else {
            printf("client socket filepath: %s.\n", client_sockaddr.sun_path);
        }

        // read
        memset(buf, 0, BUFF_SIZE);
        bytes_rec = recv(client_sock, buf, sizeof(buf), 0);
        if (bytes_rec < 0) {
            printf("recv error: %s\n", strerror(errno));
            close(server_sock);
            close(client_sock);
            exit(1);
        } else {
            printf("received data %s\n", buf);
        }

        // send data
        memset(buf, 0, BUFF_SIZE);
        strcpy(buf, DATA);
        rc = send(client_sock, buf, strlen(buf), 0);
        if (errno == EPIPE) {
            close(client_sock);
        } else if (rc < 0) {
            printf("send error: %s", strerror(errno));
            close(server_sock);
            close(client_sock);
            exit(1);
        }

        close(client_sock);
    }

    close(server_sock);
    close(client_sock);
}
