#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main(){
	int t;
	char *tuberia = "/tmp/tuberia";
	char msj[MAX_BUF];

	//abre la tuberia
	t = open(tuberia,O_RDONLY);
	//lee el mensaje desde la tuberia y lo almacena
	read(t,msj,MAX_BUF);
	//imprime el valor que comparte el otro proceso
	printf("Recibido: %sn",msj);
	//cerramos el tubo
	close(t);

	return 0;
}