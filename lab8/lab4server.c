#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define SORT_PORT 1719
#define LINESIZE 80
#define NUMWORDS 100

void sort(char *str[],int n);

int main(){
    char bugger[LINESIZE];
    char *words[NUMWORDS];
    int count=0;
    int sockfd;
    int sd;
    struct sockaddr_in server, client;
    if ((sockfd=socket(AF_INET,SOCK_STREAM,0)) <0){
	perror("creating stream socket error!\n");
	exit(1);
    }
    memset(&server,0,sizeof(server));
    server.sin_family=AF_INET;
    server.sin_port=htons(SORT_PORT);
    server.sin_addr.s_addr=htonl(INADDR_ANY);
    if (bind(sockfd,(struct sockaddr *)&server,sizeof(server))<0){
	perror("error in binding!\n");
	exit(1);
    }
    size_t bytes_read;
    socklen_t addr_len=sizeof(client);
    printf("Server: Waiting for connection\n");
    if ((sd=accept(sockfd,(struct sockaddr*)&client,&addr_len))<0){
	perror("error in accepting!\n");
	exit(1);
    }
    printf("Server: Connected\n");
    while(1){
	bytes_read=read(sd,buffer,LINESIZE);
	buffer[bytes_read]='\0';
	printf("Server: Received %s\n",buffer);
	if (buffer[0]=='0'){
	    printf("Server: End received.\n");
	    break;
	}
	char *str=malloc(sizeof(buffer));
	strcpy(str, buffer);
	words[count]=str;
	count++;
	if (count>=NUMWORDS){
	    printf("Server: Max words received\n");
	    break;
	}
    }
    printf("Server: Sorting words received.\n");
    sort(words, count);
    printf("Server: Sending sorted words.\n");
    for (int i=0;i<count;i++){
	printf("Sending word %s\n",words[i]);
	write{sd, words[i],strlen(words[1]));
    }
    close(sd);
    return 0;
}

void sort(char *str[],int n){
    int i,j;
    char temp[20];
    for (i=n;i>=0;i--){
	for (j-0;j<i-1;j++){
	    if(strcmp(str[j],str[j+1]);
	    strcpy(str[j],str[j+1]);
	    strcopy(str[j+1],temp);
	}
    }
}
}
