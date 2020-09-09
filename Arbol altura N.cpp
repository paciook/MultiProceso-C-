#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int crear_arbol_altura(int n){
	int pid = 0;
	cout << getpid() << endl;
	for (int x = 0; x < n; x++){
		if(pid == 0){
			pid = fork();
			wait(NULL);
			if (pid > 0){
				pid = fork();
				wait(NULL);
				if (pid > 0)
				    break;
			}		
		}
	}
	printf("[%d] Mi padre tiene el pid %d\n",getpid(), getppid());
	exit(0);
}

int main(int argc, char *argv[]){
    crear_arbol_altura(atoi(argv[1]));
}