#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	// 检查启动命令是否正确
	if (argc < 2)
	{
		printf("用法：%s ip_address port_number\n", basename(argv[0]));
		return 1;
	}

	const char *ip = argv[1];
	int port = atoi(argv[2]);

	struct sockaddr_in server_address;  //服务器套接字地址
	memset(&server_address, 0, sizeof(server_address));
	inet_pton(AF_INET, ip, &server_address.sin_addr);
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);

	int sockfd = socket(PF_INET, SOCK_STREAM, 0);  //创建发送套接字
	assert(sockfd >= 0);
	// 发起连接
	if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
	{
		printf("connect failed\nerror: %d, msg: %s\n", errno, strerror(errno));
	}
	else
	{

		const char *oob_data = "abc";
		const char *normal_data = "123";
		send(sockfd, normal_data, strlen(normal_data), 0);  //发送消息
		send(sockfd, oob_data, strlen(oob_data), MSG_OOB);
		send(sockfd, normal_data, strlen(normal_data), 0);
	}

	close(sockfd);  //关闭发送
	return 0;
}