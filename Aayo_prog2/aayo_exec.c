//
//	EE 4374 Assignment # 2 Command Executer
//	Author: Anthony Ayo
//

#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int execBackground(char **args)
{
    int i;
    // check for the ampersand at the end of the set of tokens
    i = 0;
    while(args[i] != 0){
         i++;
    }                       // traverse to the end of the tokens
    if(args[i-1][0] == '&') // check the last token
    {
        free(args[i-1]);
        args[i-1] = NULL;  // remove the ampersand
        return 1;
    } else {
        return 0;
    }
}

int executeCmd(char **args){
  pid_t first_Pid, second_Pid;
  int ampersand = execBackground(args);
  first_Pid = fork();
  if((first_Pid = fork()) == 0){
    printf("ERROR: Forking child process has failed \n");
    exit(1);
  } else if (first_Pid == 0 ){
      if(execvp(*args,args) < 0){
	printf("ERROR: Exec failed \n");
	exit(1);
      }
      
  }






  
}
