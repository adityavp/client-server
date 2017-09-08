#include <stdio.h>
#include <arpa/inet.h>
#include <time.h>

int getEpochTime()
{
	time_t now;
	return now = time(0);
}

int main(int argc, char const *argv[])
{
	int ser_soc, cli_soc;
	int time[1];
    struct sockaddr_in addr;

    ser_soc = socket(PF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(7891);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(ser_soc, (struct sockaddr *) &addr, sizeof(addr));

    printf("\nServer is Online\n\n");
    /*  listen for connections from the socket */
    listen(ser_soc, 1);
    /*  accept a connection */
    cli_soc = accept(ser_soc, NULL, NULL);

    time[0] = getEpochTime();
    printf("Current epoch time is: %d\n", time[0]);
    send(cli_soc, time, sizeof(time), 0);

    printf("\nRequest sent\n");

	return 0;
}