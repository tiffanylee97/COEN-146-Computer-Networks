#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define SORT_PORT 1719
#define LINESIZE 80

int main(ing argc, char *argv[]){
    struct addrinfo *server, *result, hints={0};
    int sock=0;
    int s=0;
    int count=0;
    char inlin[LINESIZE]={0};
    char outline[LINESIZE]={0};
    char *server_name;

    server_name=(argc>1)?argv[1]:"localhost";
    if (server_name == NULL){
	fprint(stderr, "%s: unknown host: %s\n", argv[0], server_name);
	exit(1);
    }
    hints.ai_family=AF_INET;
    hints.ai_socktype=SOCK_STREAM;
    hints.ai_protocol=IPPROTO_TCP;
    char port[16];
    snprintf(port, sizeof(port),"%d",SORT_PORT);
    s=getaddrinfo(server_name, port, &hints, &result);
    if (s!=0){
	perror("creating stream socket\n");
	exit(2);
    }
    for (server=result; server!=NULL; server=server->ai_next){
	sock=socket(server->ai_family, server->ai_socktype, server->ai_protocol);
        if (sock==-1){
	    continue;
        }
        if(connect(sock,server->ai_addr,server->ai_addrlen)==0){
	    break;
        }
    }
    if (server==NULL){
	fprintf(stderr,"could not bind\n");
    }
    freeaddrinfo(result);
    int index=0;
    printf("\nClient: connect to server %s\n",server_name);
    printf("Client: Write word %d to sort at server:\n", ++index);
    while ((count=read(0,outline,LINESIZE))>0{
	outlint[count]='\0';
	if(write(sock,outline,count)<0)
	    printf("writing to server failed\n");
	if(outline[0]=='0')
	    break;
    printf("Client: sending word to server: %s",outline);
    printf("\nClient: Write word %d to sort at server:\n",++index);
    }
    printf("Client: results are:\n");
    while((count=read(sock, inlin, LINESIZE))>0){
	write(1,inlin,count);
	printf("\n");
    }
    close(sock);
    return 0;
}
