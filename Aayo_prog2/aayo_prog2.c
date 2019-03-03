//
//	EE 4374 Assignment # 2 Shell (Test Function)
//	Author: Anthony Ayo
//

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "aayo_argtok.h"
#include "aayo_exec.h"

int main()
{
    int i;
	int inputSize;
	char buff[128];		// Character buffer
	char **args;

    write(1, "Welcome to the Student Shell (type 'x' to exit)\n", 48);
	while(1)
	{
		// Request a line of input
		write(1, "\nshell -> ", 10);
		// Read the line
		inputSize = read(0, buff, 128);
		// Strip off carriage return
		buff[inputSize - 1] = '\0';

		if(buff[0] == '\0')
			continue;

		if((buff[0] == 'x') && (buff[1] == '\0'))
		{
			exit(0);
		}
	       	// make the argument vector
		args = argtok(buff); //MAIN CODE//
		//TEST CODE//
		/*
		printf("%s\n", buff);
	       	int c = string_length(buff);
		printf("The length of the token is %d\n", c);
		int startPos = find_word_start(buff,0);

		printf("Test 2\n");

		int endPos = find_word_end(buff,startPos);

		printf("Test 3\n");

		int wordCount = count_words(buff);

		printf("Test 4\n");
		printf("The start of the next word is located in position : %d\n", startPos);

		printf("The end of the next word is located in position : %d\n", endPos);

		printf("the number of words in the statement is : %d\n" , wordCount);
		print_tokens(args);
		*/
		// execute the command
		executeCmd(args);

	}

	return 0;

}
