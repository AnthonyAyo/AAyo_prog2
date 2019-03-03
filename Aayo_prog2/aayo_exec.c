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
  
  first_Pid = fork();
  int ampersand = execBackground(args);
  if( ampersand == 0){
    if(first_Pid < 0){
      fprintf(stderr,"Error forking a process");
    return -1;
    }
  } else if (first_Pid == 0 ){
    printf("This is the child process %d\n", (int)getpid());
    if(-1 ==  execvp(args[0],args)){
      fprintf(stderr, "Error with execvp");
      return -1;
    }
  } else if (ampersand == 0){
    if( -1 == execvp (args[0], args)){
      fprintf(stderr, "Error with execvp");
      return -1;
    }
    else {
      waitpid(first_Pid, Null, 0);  
  }
  return 0;
}
