#include <stdio.h>
int main () 
{
    double notas,promedio,cantidad;
    do 
    {
       cantidad=cantidad+1; // ordené esta linea de codigo
       printf("ingrese la calificacion %lf:",cantidad); //le quité el ampersand que no iba
       scanf("%.2lf",&notas);
      
       if (notas>5 && notas<0)    // agrego este if
       {
        printf("calificacion invalida\n");
       }
    }
    while(notas != -1);
    
    promedio=notas/cantidad;
    
    for(int i=1;i>=cantidad;i++)
    {
        printf("se ingresaron %lf calificaciones",cantidad);//le quité el ampersand que no iba
        printf("promedio final: %lf", promedio);//le quité el ampersand que no iba
    }
    return 0;
}