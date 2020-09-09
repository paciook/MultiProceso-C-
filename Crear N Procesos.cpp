#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int crear_n_procesos(int n){
	int pid;
	string color = "Negro";

	for (int i = 1; i < n; i++)
	{
		pid = fork();
		if (pid == 0)
		{
    		if (i % 2 == 0){
    		    color = "Negro";
    		}
    		else
    		{
    			color = "Rojo";
    		}
		}
		if (pid > 0)
			break;
	}
	wait(NULL);

    printf("Soy %s\n", color.c_str());
	
	exit(0);

}


int main(){
	crear_n_procesos(5);  // Es un ejemplo

	return 0;
}