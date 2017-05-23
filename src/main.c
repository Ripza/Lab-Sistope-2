#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#define SYS_hola_mundo_64 326
#define SYS_hola_mundo_32 377
#define sys_procinfo_32 388
#define sys_procinfo_64 327

//388	i386	procinfo		sys_procinfo
//389	i386	procsinfo		sys_procs_info
//327	64		procinfo		sys_procinfo
//328	64		procsinfo		sys_procs_info


int main(){
	int opcion, arg = 0, salida;

	// Establece el modo de ejecución del programa para hacerlo compatible con el sistema
	do{
		printf(" 1. − MAQUINA 32 BITS\n 2.−MAQUINA 64 BITS");
		scanf("%d", &opcion);
	} while (opcion != 1 && opcion!=2);

	// Se ingresa el estado de los procesos que se deseen listar en el archivo de salida
	do{
		printf("Ingresá la opcion de state \n");
		scanf("%d", &arg);
	} while (opcion != 1 && opcion!=2);
	if(opcion == 1){
		salida = syscall( sys_procinfo_32 , arg);
	}
	else {
		salida = syscall( sys_procinfo_64 , arg);
	}
	printf( "salida %d" , salida);
	return 0;
}
