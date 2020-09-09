#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main()
{
	int pid;
	string name;

	cout << "Hola soy " << name << endl;

	pid = fork();

	if (pid == 0)
	{
		// Lo que hace el Homero
		name = "Homero";

		cout << "Hola soy " << name << endl;

		pid = fork();

		if (pid == 0)
		{
			// Lo que hace Bart
			name = "Bart";
			cout << "Hola soy " << name << endl;
		}
		else
		{
		    wait(NULL);
			// Lo que hace Homero
			pid = fork();
			if (pid == 0)
			{
				// Lo que hace Lisa
				name = "Lisa";
				cout << "Hola soy " << name << endl;
			}
			else
			{
			    wait(NULL);
			}
			
		}
	}
	else
	{
		// Lo que hace el Abraham
		wait(NULL);
		name = "Abraham";
	}
    exit(pid);
}
