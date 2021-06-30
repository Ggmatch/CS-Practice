#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    // 检查启动命令是否正确
    if (argc < 2)
    {
        printf("用法：%s ip_address port_number\n", basename(argv[0]));
        return 1;
    }

    const char *ip = argv[1]; //ip地址
    int port = atoi(argv[2]); //端口

    struct sockaddr_in address;  //套接字地址
    memset(&address, 0, sizeof(address));
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);
    address.sin_family = AF_INET;

    int sock = socket(PF_INET, SOCK_STREAM, 0);  //创建监听套接字
    assert(sock >= 0);

    int ret = bind(sock, (struct sockaddr *)&address, sizeof(address));  //绑定地址
    assert(ret != -1);

    ret = listen(sock, 5);  //开始监听
    assert(ret != -1);
    // sleep(20);  //可以用于抓包测试等

    struct sockaddr_in client;  //发起连接的客户端套接字地址
    socklen_t client_addrlength = sizeof(client);

    int connfd = accept(sock, (struct sockaddr *)&client, &client_addrlength);  //接受客户端发送的消息，并建立通话套接字
    if (connfd < 0)
    {
        printf("error");
    }
    else
    {
        char buffer[BUF_SIZE];

        memset(buffer, '\0', BUF_SIZE);
        ret = recv(connfd, buffer, BUF_SIZE - 1, 0);
        printf("got %d bytes of normal data '%s'\n", ret, buffer);

        memset(buffer, '\0', BUF_SIZE);
        ret = recv(connfd, buffer, BUF_SIZE - 1, MSG_OOB);  //接受紧急数据
        printf("got %d bytes of obb data '%s'\n", ret, buffer);

        memset(buffer, '\0', BUF_SIZE);
        ret = recv(connfd, buffer, BUF_SIZE - 1, 0);
        printf("got %d bytes of normal data '%s'\n", ret, buffer);

        close(connfd);  //关闭通话
    }

    close(sock);  //关闭监听
    return 0;
}