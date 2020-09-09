// Una forma un poco rústica sería

int maint(){
	
	int pid, status;
	
	for(int i = 0;i<5;i++){
	
		pid = fork();
	
		if(pid==0){
			cout << "Proceso" << i << endl;
			exit(0);
		}
	}
	
	if(pid > 0){
		wait(&status);
		wait(&status);
		wait(&status);
		wait(&status);
		wait(&status);
		cout << "Terminaron todos " << endl;
		exit(0);
	}
}

// Pero como me da asco propongo el siguiente cambio

int main(){
	
	int pid;
	
	for(int i = 0;i<5;i++){
	
		pid = fork();
	
		if(pid==0){
			cout << "Proceso" << i << endl;
			exit(0);
		}

		wait(NULL);
	}
	
	if(pid > 0){
		cout << "Terminaron todos " << endl;
		return 0;
	}
}

/*
Con este código, siempre el output sería
Proceso0
Proceso1
Proceso2
Proceso3
Proceso4
Terminaron Todos

Pero sería inútil usar concurrencia
*/