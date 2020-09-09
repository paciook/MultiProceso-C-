#include <iostream>
#include <string>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
	int pid = fork();

	if (pid == 0)
	{
		// Lo que hace el hijo
		execvp(argv[1], &argv[1]);
	}

	wait(NULL);
	printf("Comando terminado\n");
	return 0;
}