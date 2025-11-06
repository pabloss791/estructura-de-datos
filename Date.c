#include<stdio.h>

typedef struct Date{
    int dia;
    int mes;
    int año;
}Date;




 Date*create_Date(int dia, int mes,int año){
 Date*fecha=malloc(sizeof(Date));
 fecha->dia=dia;
 fecha->mes=mes;
 fecha->año=año;
}

void Date_destroy(Date*d){
free(d);

}

int Date_getDia(){
    return dia;
}

int Date_getMes(){
    return mes;
}

int Date_getAño(){
    return año;
}

void Date_setDia(Date*d,int dia){
    d->dia=dia;
}

void Date_setMes(Date*d,int mes){
    d->mes=mes;
}

void Date_setAño(Date*d,int año){
    d->año=año;
}


