#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int fd[2];
	pipe(fd);
	pid_t pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);

		execl("../ls", "../ls", NULL);
		
	}
	else
	{
		dup2(fd[0], 0);
		wait(NULL);
		close(fd[1]);

		char buf[4096] = {0};
		// printf("lmao");
		fgets(buf, 100, stdin);
		int length = strlen(buf);
		int counter = 0;
		char** files = (char**) calloc(10, sizeof(char*));
		for (int i = 0; i < length; i++)
		{
			if(i == 0)
			{
				files[0] = &buf[0];
				counter++;
			}
			// printf("%d", buf[7]);
			if (buf[i] == 32)
			{
				files[counter] = &buf[i + 1];
				buf[i] = '\0';
				counter++;
			}
		}
		// int k = strlen(files[1]);
		// printf("%d\n", k);
		for (int i = 0; i < counter; i++)
		{
			FILE* fp = fopen(files[i], "r");
			struct stat buffer;
			
			fstat(fileno(fp), &buffer);

			int nsymb = buffer.st_size;

			char *files = (char *)calloc(nsymb + 1, sizeof(char));
			fread(files, sizeof(char), nsymb, fp);
			fwrite(files, sizeof(char), nsymb, stdout);

		}
		
	}
	return 0;
}
