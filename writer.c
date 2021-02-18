#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int t;
	char *tuberia = "/tmp/tuberia";

	/*crea un nuevo archivo fifo especial,
	incluye una ruta y un parametro con una
	mascara de permisos.
	*/
	mkfifo(tuberia,0666);

	/*
	abrimos una nueva tuberia
	O_RDONLY - Abrir para solo lectura
	O_WRONLY - Abrir para solo escritura
	O_RDWR - Abrir para lectura / escritura
	O_APPEND - Agrega al final del Archivo
	...
	*/
	t = open(tuberia,O_WRONLY);
	//escribimos el mensaje que compartiremos
	write(t,"Mensaje entre Procesos",sizeof("Mensaje entre Procesos"));
	//cerramos la tuberia
	close(t);

	//borramos
	unlink(tuberia);

	return 0;
}