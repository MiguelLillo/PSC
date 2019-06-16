/*
 * colaPrioridad.c
 *
 *  Created on: 15 jun. 2019
 *      Author: miguel
 */
#include <stdio.h>
#include <stdlib.h>
#include "colaPrioridad.h"

void crear(TColaPrio cp){
	int i;
	for (i=0;i<L;i++){
		cp[i]=NULL;
	}
}

/**
 * Dada una prioridad y un identificador de proceso,
 * lo a�ade AL FINAL de la lista que le corresponde.
 */
void nuevoProceso (TColaPrio cp,int p, int id){
	printf("What\n");
	Lista proc=(Lista)malloc(sizeof(struct TNodo));
	printf("What2\n");
	(proc)->id=id;
	(proc)->sig=NULL;
	printf("antes del if\n");
	fflush(stdout);
	if(cp[p]==NULL){
		printf("Dentro del if\n");
		cp[p]=proc;
	}else{
		Lista aux=cp[p];
		while(aux->sig!=NULL){
			printf("Que cojones pasa aqui");
			aux=aux->sig;
		}
		(aux)->sig=proc;
	}
	printf("después del if\n");


}

/**
 * Elimina de la lista el proceso m�s prioritario que le corresponde ejecutarse.
 * Se devuelve 0 si se ha podido ejecutar el proceso, y -1, en caso contrario.
 */

//void ejecutarProceso(TColaPrio cp);
int ejecutaProceso(TColaPrio cp){
	int i=0;
	while(i<L && cp[i]==NULL){
		i++;
	}
	if(i==L){
		printf("No se ha encontrado ningún proceso.\n");
		return -1; //hay que poner los returns bien
	}else{//hay alguna posicion de la cola ocupada
		Lista aux=cp[i];
		int idEliminado=cp[i]->id;
		cp[i]=cp[i]->sig;
		printf("Se ha ejecutado el proceso %d con prioridad %d\n",idEliminado,i);
		free(aux);

		return 0;
	}

}

/**
 * Dado un identificador de proceso devuelve la prioridad de �ste.
 * Si el id del proceso no existe se devolver� -1.
 */
int buscar(TColaPrio cp, int id);

/*
 * Recorre la estructura para mostrar los procesos existentes
 * que est�n disponibles para ejecuci�n ordenados por prioridad.
 *
 */
void mostrar(TColaPrio cp){
	int i;
	for(i=0;i<L;i++){
		printf("Posición %d:\n",i);
		fflush(stdout);
		if (cp[i] != NULL) {
			Lista aux = cp[i];
			printf("\t %d\n",(aux)->id);
			while ((aux)->sig != NULL) {
				aux = (aux)->sig;
				printf("\t %d\n",(aux)->id);
			}


		}//si es null pasamos al siguiente indice
		printf("\n");

	}


}

/*
 * Se eliminan todos los procesos de la cola de prioridad
 */
void destruir (TColaPrio cp);


