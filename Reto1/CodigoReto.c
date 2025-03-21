#include <stdio.h>

int main(int argc, char const *argv[])
{
    int opciones;
    double valor1, valor2, suma, resta, multiplicacion, division;
    char continuar;

    do {
        // parrafo inicial
        printf("Ingresa el primer número: ");
        
        printf("Ingresa el segundo número: ");
        

        // Mostrar el menú de opciones
        printf("1. suma\n2. resta\n3. multiplicacion\n4. division\n");
        printf("Elija una opcion: ");
        scanf("%d", &opciones);

        // Realizar la operación seleccionada
        switch (opciones)
        {
            case 1:
                suma = valor1 + valor2;
                printf("La suma es: %lf\n", suma);
                break;
            case 2:
                resta = valor1 - valor2;
                printf("La resta es: %lf\n", resta);
                break;
            case 3:
                multiplicacion = valor1 * valor2;
                printf("La multiplicacion es: %lf\n", multiplicacion);
                break;
            case 4:
                if (valor2 != 0) {
                    division = valor1 / valor2;
                    printf("La division es: %lf\n", division);
                } else {
                    printf("Error: No se puede dividir por cero.\n");
                }
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }

        // Preguntar al usuario si desea continuar
        printf("¿Desea realizar otra operación? (Ingrese '?' para salir, cualquier otro carácter para continuar): ");
        scanf(" %c", &continuar); // El espacio antes de %c ignora el salto de línea anterior

    } while (continuar != '?'); // Repetir hasta que el usuario ingrese '?'

    printf("¡Gracias por usar la calculadora! Hasta luego.\n");
    return 0;
}