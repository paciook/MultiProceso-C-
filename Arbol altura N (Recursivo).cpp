#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void arbol_altura(int n){
	int pid;
	if (n == 0)
		return;

	for(int x = 0; x < 2; x++){
		pid = fork();
		wait(NULL);
		if (pid == 0){
			arbol_altura(n - 1);
			wait(NULL);
			break;
		}
	}

	printf("[%d] El pid de mi padre es %d\n",getpid(), getppid());
	exit(0);
}

int main(int argc, char *argv[]){
/*	
	printf("¿Qué altura uso para el árbol?\n");
	
	int n;
	cin >> n;  
*/

    arbol_altura(atoi(argv[1]));
}