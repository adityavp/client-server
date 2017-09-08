#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char const *argv[])
{
    int soc;
    int response[1];
    struct sockaddr_in addr;

    soc = socket(PF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(7891);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    /*  keep trying until connection is esatablished with server */
    while(connect(soc, (struct sockaddr *) &addr, sizeof(addr))) ;
    printf("\nClient is connected to Server");

    printf("\nRecieved response\n\n");
    recv(soc, response, sizeof(response), 0);
    printf("%d\n\n", response[0]);

    return 0;
}