#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define alumnos 3
#define progresos 4

float promedios_estudiantes[alumnos] = {0};
char archivo[] = "DatosEstudiantes.csv";

void promedio_individual(float calificaciones[alumnos][progresos])
{
    float promedio_individual;

    for (int i = 0; i < alumnos; i++)
    {
        float sumTotal = 0;

        for (int j = 0; j < progresos; j++)
        {
            sumTotal += calificaciones[i][j];
        }
        promedios_estudiantes[i] = sumTotal/3;
    }
}

float promedio_general()
{
    float sumTotal_individual[alumnos] = {0};
    float promedio_individual[alumnos] = {0};
    float promedio;
    float sumTotal_global;


    for (int i = 0; i < alumnos; i++)
    {
        sumTotal_individual[i] = promedios_estudiantes[i];
        promedio_individual[i] = sumTotal_individual[i]/3;
        sumTotal_global += promedio_individual[i];
    }
    
    promedio = sumTotal_global/alumnos;

    return promedio;
}

void requerimiento_Mayor_Calificacion(float calificaciones[alumnos][progresos])
{
    float mayorPromedio = 0;
    int alumno = 0;

    for (int i = 0; i < alumnos; i++)
    {
        if(calificaciones[i][3] > mayorPromedio)
        {
            mayorPromedio = calificaciones[i][3];
            alumno = i;
        }      
    }
    printf("\nEL ESTUDIANTE %d, TIENE EL MAYOR PROMEDIO = %.1f\n", alumno+1, mayorPromedio);
}

int main()
{
    int vflag = 1;
    float calificaciones[alumnos][progresos] = {0};
    float promedio;

    FILE *archivoLectura;
    if((archivoLectura = fopen(archivo,"rt"))==NULL) printf("\nLo sentimos, existe un error al abrir el archivo %s",archivo);

    FILE *archivoEscritura;
    if((archivoEscritura = fopen(archivo,"rt"))==NULL) printf("\nLo sentimos, existe un error al abrir el archivo %s",archivo);

    while (vflag!=0)
    {
        printf("Menu\nOPCIONES\n1.Ingresar promedios.\n2. Conocer promedio general.\n3. Salir\n");
        /*Asignación de valores al arreglo calificaciones*/
        for (int i = 0; i < alumnos; i++)
        {      
            printf("Asigne la calificacion para el ESTUDIANTE %d:\n ", i);

            for (int j = 0; j < 3; j++)
            {
                printf("PROGRESO %d: ", j+1);
                scanf("%f", &calificaciones[i][j]);
            }
        }

        promedio_individual(calificaciones);


        printf("\n\nESTUDIANTE\tNOTA1\tNOTA2\tNOTA3\tPROMEDIO\n");
        for (int i = 0; i < alumnos; i++)
        {
            printf("Estudiante %d:", i+1);
            
            for (int j = 0; j < progresos; j++){

                if (j == 3)
                {
                    calificaciones[i][j] = promedios_estudiantes[i];
                }
                
                if(calificaciones[i][j] < 10) printf("\t  %.1f ", calificaciones[i][j]);
                else{
                    printf("\t  %.0f", calificaciones[i][j]);
                }
            }
            printf("\n");
        }
        
        
        promedio = promedio_general(calificaciones);
        printf("\n\nPROMEDIO GENERAL: %.2f", promedio);

        requerimiento_Mayor_Calificacion(calificaciones);
        }

    return 0;
}
