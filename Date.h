#include<stdio.h>

typedef struct Date{
    int dia;
    int mes;
    int año;
}Date;




 Date*create_Date(int dia, int mes,int año);
 
    
void Date_destroy(Date*d);


int Date_getDia();
    


int Date_getMes();

int Date_getAño();


void Date_setDia(Date*d,int dia);


void Date_setMes(Date*d,int mes);

void Date_setAño(Date*d,int año);









