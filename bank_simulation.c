#include<stdio.h>
#include<stdlib.h>
#include"TDA_queue.h"

void simulacion_fila(){
    printf("====SIMULACION FILA DE BANCO=====");
    Queue*fila=createQueue();
    
    int clientesAtendidos=0;
    int clienteID=1;
    int cliente_actual=0;   

    printf("===LLEGADA DE CLIENTES ===");

    printf("Cliente numero %d llega al banco",clienteID);
    enqueue(fila,clienteID++);

    printf("Cliente numero %d llega al banco",clienteID);
    eneque(fila,clienteID++);

    printf("Cliente numero %d llega al banco",clienteID);
    enqueue(fila,clienteID++);

    printf("Fila actual");
    printQueue(fila);

    while (!=isEmpty(fila))
    {
        cliente_actual=dequeue(fila);
        clientesAtendidos++;
    }
    

    printf("resumen de la simulacion \n ");
    printf("clientes atendidos %d \n",clientesAtendidos);

    printf("Fila final: ");
    printQueue(fila);
}