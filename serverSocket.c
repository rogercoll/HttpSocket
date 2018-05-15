#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "socketMng.h"

#define WEB_ROOT "/WEB"

void doService(int fd) {
		int i = 0;
		char buff[80];
		char buff2[80];
		int ret;
		int socket_fd = (int) fd;
		char *filename = "/baidu.html";
		char path[128] = {'\0'};
		sprintf(path,"%s%s",WEB_ROOT,filename);
		FILE *fp = fopen(path,"r");
		if(fp == NULL){
			char errmsg[32] = {"<h1>404 Not Found</h1>"};
			write(fd,errmsg,strlen(errmsg));
			return;
		}
		else{
			while(1){
				char buf[1024] = {'\0'};
				int read_size = fread(buf,1,sizeof(buf),fp);
				if(read_size <= 0) break;
				write(fd,buf,read_size);
			}		
		}
	return;
}

void doServiceFork(int fd){
	int pid = fork();
	if(pid == 0) doService(fd);	
	deleteSocket(fd);
}
	
	
	
void main (int argc, char *argv[])
{
  int socketFD;
  int connectionFD;
  char buffer[80];
  int ret;
  int port;


  if (argc != 2)
    {
      strcpy (buffer, "Usage: ServerSocket PortNumber\n");
      write (2, buffer, strlen (buffer));
      exit (1);
    }

  port = atoi(argv[1]);
  socketFD = createServerSocket (port);
  if (socketFD < 0)
    {
      perror ("Error creating socket\n");
      exit (1);
    }

  while (1) {
	  connectionFD = acceptNewConnections (socketFD);
	  if (connectionFD < 0)
	  {
		  perror ("Error establishing connection \n");
		  deleteSocket(socketFD);
		  exit (1);
	  }

	  doServiceFork(connectionFD);
  }

}
