#include <stdio.h>
#include <math.h>
// Prototipos de funciones
void MenuPrincipal();
void LeyDeOhm();
void FactorDePotencia();  
void ResistenciaConductor();  
void ResistenciaLED();  
//Funcion main
int main()
{
    int opcion;
   
    printf("Bienvenido a la Calculadora de Ingeniería\n");
   
    do {
        MenuPrincipal();
        printf("Ingresa el número de la opción deseada: ");
        scanf("%d", &opcion);
       
        switch(opcion)
        {
            case 1:
                LeyDeOhm();
                break;
            case 2:
                FactorDePotencia();
                break;
            case 3:
                ResistenciaConductor();
                break;
            case 4:
                ResistenciaLED();
                break;
            case 5:
                printf("Saliendo del programa\n");
                break;
            default:
                printf("Opción no válida. Por favor, intenta de nuevo.\n");
        }
    } while(opcion != 5);
   
    return 0;
}

void MenuPrincipal()
{
    printf("Por favor, selecciona una opción:\n");
    printf("1. Calcular Ley de Ohm\n");
    printf("2. Calcular Factor de Potencia\n");
    printf("3. Calcular Resistencia de un Conductor\n");
    printf("4. Calcular Valor de la Resistencia para un LED\n");
    printf("5. Salir\n");
}

void LeyDeOhm()
{
    int opcion;
    float v, i, r;
   
    do {
        printf("\nHas seleccionado calcular la Ley de Ohm.\n");
        printf("¿Qué parámetro deseas calcular?\n");
        printf("1. Calcular Tensión (Voltaje)\n");
        printf("2. Calcular Corriente\n");
        printf("3. Calcular Resistencia\n");
        printf("4. Volver al menú principal\n");
        printf("Ingresa el número de la opción deseada: ");
        scanf("%d", &opcion);
       
        if(opcion == 4) return;
       
        switch(opcion)
        {
            case 1:
                printf("Ingresa el valor de la corriente en amperios: ");
                scanf("%f", &i);
                printf("Ingresa el valor de la resistencia en ohmios: ");
                scanf("%f", &r);
                v = i * r;
                printf("Tensión = %.2f V\n", v);
                break;
            case 2:
                printf("Ingresa el valor del voltaje en voltios: ");
                scanf("%f", &v);
                printf("Ingresa el valor de la resistencia en ohmios: ");
                scanf("%f", &r);
                i = v / r;
                printf("Corriente = %.2f A\n", i);
                break;
            case 3:
                printf("Ingresa el valor del voltaje en voltios: ");
                scanf("%f", &v);
                printf("Ingresa el valor de la corriente en amperios: ");
                scanf("%f", &i);
                r = v / i;
                printf("Resistencia = %.2f ohms\n", r);
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while(opcion != 4);  // Se repetirá hasta que el usuario elija la opción 4
}
void FactorDePotencia()
{
    int opcion;
    float P, Q, S, FP, V, I, cos_phi;

    do {
        printf("\n--- Cálculo de Factor de Potencia ---\n");
        printf("1. Calcular Potencia Activa (P)\n");
        printf("2. Calcular Potencia Aparente (S)\n");
        printf("3. Calcular Factor de Potencia (FP)\n");
        printf("4. Volver al menú principal\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        if (opcion == 4) return;

        switch (opcion) {
            case 1: // Calcular P 
                printf("\nIngrese la Potencia Aparente (S) en VA: ");
                scanf("%f", &S);
                printf("Ingrese el Factor de Potencia (cosφ): ");
                scanf("%f", &cos_phi);
                P = S * cos_phi;
                Q = sqrt(S * S - P * P);
                printf("\nResultados:\n");
                printf("-> Potencia Activa (P) = %.2f W\n", P);
                printf("-> Potencia Reactiva (Q) = %.2f VAR\n", Q);
                printf("-> Coseno phi (cosφ) = %.2f\n", cos_phi);
                break;

            case 2: // Calcular S 
                printf("\nIngrese el Voltaje (V) en voltios: ");
                scanf("%f", &V);
                printf("Ingrese la Corriente (I) en amperios: ");
                scanf("%f", &I);
                S = V * I;
                printf("\nResultados:\n");
                printf("-> Potencia Aparente (S) = %.2f VA\n", S);
                printf("(Nota: Para calcular P y Q, use la opción 1)\n");
                break;

            case 3: // Calcular FP 
                printf("\nIngrese la Potencia Activa (P) en W: ");
                scanf("%f", &P);
                printf("Ingrese la Potencia Aparente (S) en VA: ");
                scanf("%f", &S);
                if (S == 0) {
                    printf("Error: S no puede ser cero.\n");
                    break;
                }
                FP = P / S;
                Q = sqrt(S * S - P * P);
                printf("\nResultados:\n");
                printf("-> Factor de Potencia (FP) = %.2f\n", FP);
                printf("-> Potencia Reactiva (Q) = %.2f VAR\n", Q);
                printf("-> Coseno phi (cosφ) = %.2f\n", FP);
                break;

            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 4);
}
void ResistenciaConductor() {
    int opcion;
    float resistividad, coef_temperatura, area_mm2, temperatura;
    float resistividad_mm2m, resistencia_por_metro;
    
    do {
        printf("\n--- Calculo de Resistencia de un Conductor ---\n");
        printf("Seleccione el material del conductor:\n");
        printf("1. Oro\n");
        printf("2. Aluminio\n");
        printf("3. Cobre\n");
        printf("4. Otro material\n");
        printf("5. Volver al menú principal\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        if (opcion == 5) return;

        // Valores predefinidos para materiales comunes
        switch(opcion) {
            case 1: // Oro
                resistividad = 2.44e-8;      // Ω·m a 20°C
                coef_temperatura = 0.0034;    // Coeficiente de temperatura
                break;
            case 2: // Aluminio
                resistividad = 2.82e-8;
                coef_temperatura = 0.0039;
                break;
            case 3: // Cobre
                resistividad = 1.68e-8;
                coef_temperatura = 0.00386;
                break;
            case 4: // Otro material
                printf("Ingrese la resistividad del material a 20°C (en Ω·m): ");
                scanf("%f", &resistividad);
                printf("Ingrese el coeficiente de temperatura del material: ");
                scanf("%f", &coef_temperatura);
                break;
            default:
                printf("Opción no valida.\n");
                continue;
        }

        // Solicitar datos comunes a todos los materiales
        printf("Ingrese la sección transversal del conductor (en mm²): ");
        scanf("%f", &area_mm2);
        printf("Ingrese la temperatura actual del conductor (en °C): ");
        scanf("%f", &temperatura);

        // Calcular resistividad en Ω·mm²/m
        resistividad_mm2m = resistividad * 1e6;
        
        // Calcular resistencia por metro (Ω/m)
        float resistencia_20_por_metro = resistividad / (area_mm2 * 1e-6);
        resistencia_por_metro = resistencia_20_por_metro * (1 + coef_temperatura * (temperatura - 20));

        // Mostrar resultados
        printf("\n--- Resultados a %.1f°C ---\n", temperatura);
        printf("-> Resistividad: %.6f Ω·mm²/m\n", resistividad_mm2m);
        printf("-> Resistencia por metro: %.6f Ω/m\n", resistencia_por_metro);
        
    } while (opcion != 5);
}
void ResistenciaLED()
{
    float V_fuente, V_led, I_led_mA, I_led_A, R, PR, PTotal, ITotal;
    int num_leds;
    char conexion;
    
    printf("\n--- Cálculo de Resistencia para un LED ---\n");
    
    // Solicitar datos al usuario
    printf("Ingrese la tensión de la fuente en voltios (V): ");
    scanf("%f", &V_fuente);
    printf("Ingrese el número de LEDs que se conectarán: ");
    scanf("%d", &num_leds);
    printf("¿Conexión en serie (S) o paralelo (P)?: ");
    scanf(" %c", &conexion);
    printf("Ingrese la tensión nominal del LED en voltios (V_f): ");
    scanf("%f", &V_led);
    printf("Ingrese la corriente nominal del LED en miliamperios (I_f en mA): ");
    scanf("%f", &I_led_mA);
    
    // Validaciones de tensión
    if(conexion == 'S' || conexion == 's') {
        // Validación para conexión en serie
        if(V_fuente <= (num_leds * V_led)) {
            printf("\n¡ADVERTENCIA! La tensión de alimentación (%.2f V) debe ser mayor que ", V_fuente);
            printf("la suma de las tensiones de los LEDs (%.2f V).\n", num_leds * V_led);
            printf("No es posible calcular la resistencia con estos valores.\n");
            return;
        }
    } else if(conexion == 'P' || conexion == 'p') {
        // Validación para conexión en paralelo
        if(V_fuente <= V_led) {
            printf("\n¡ADVERTENCIA! La tensión de alimentación (%.2f V) debe ser mayor ", V_fuente);
            printf("que la tensión del LED (%.2f V).\n", V_led);
            printf("No es posible calcular la resistencia con estos valores.\n");
            return;
        }
    } else {
        printf("Opción de conexión no válida.\n");
        return;
    }
    
    // Convertir mA a A (1 mA = 0.001 A)
    I_led_A = I_led_mA / 1000.0;
    
    // Realizar calculos según el tipo de conexión
    if(conexion == 'S' || conexion == 's') {
        // Conexión en serie
        R = (V_fuente - (num_leds * V_led)) / I_led_A;
        ITotal = I_led_A;
    } else {
        // Conexion en paralelo
        R = (V_fuente - V_led) / (num_leds * I_led_A);
        ITotal = num_leds * I_led_A;
    }
    
    // Validar que la resistencia no sea negativa (por si acaso)
    if(R <= 0) {
        printf("\n¡Error en los cálculos! La resistencia resultó con valor negativo.\n");
        printf("Revise los valores ingresados.\n");
        return;
    }
    
    // Calcular potencia de la resistencia y potencia total
    PR = pow(ITotal, 2) * R;
    PTotal = V_fuente * ITotal;
    
    // Mostrar resultados
    printf("\n--- Resultados ---\n");
    printf("-> Valor de la resistencia (R): %.2f ohms\n", R);
    printf("-> Potencia de la resistencia (PR): %.4f W\n", PR); 
    printf("-> Potencia total del circuito (PTotal): %.4f W\n", PTotal);
    printf("-> Corriente total suministrada por la fuente (ITotal): %.3f A (%.1f mA)\n\n", ITotal, ITotal*1000);
}