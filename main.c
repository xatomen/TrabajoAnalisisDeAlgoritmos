#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//AÑADIR LIBRERIA TIME

/*Funciones*/

/*generar listado de números de uno en uno ordenados ascendentemente y guardar en archivo*/
void generar_listado_asc(int length, int min){
    FILE *archivo;
    char nombre_archivo[50] = "listado_asc_length_";
    char str[20];

    sprintf(str,"%d",length);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,"_min_");
    sprintf(str,"%d",min);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,".txt");
    archivo = fopen(nombre_archivo, "w");
    char cadena[10];

    for(int i=0+min; i<=length+min; i++){
        sprintf(cadena,"%d",i);
        fputs(cadena,archivo);
        fputs("\n",archivo);
    }
    fclose(archivo);
    printf("Operacion completada\n");

}
/*generar listado de números de uno en uno ordenados descendentemente y guardar en archivo*/
void generar_listado_desc(int length, int min){
    FILE *archivo;
    char nombre_archivo[50] = "listado_desc_length_";
    char str[20];

    sprintf(str,"%d",length);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,"_min_");
    sprintf(str,"%d",min);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,".txt");
    archivo = fopen(nombre_archivo, "w");
    char cadena[10];

    for(int i=0; i+min<=length+min; i++){
        sprintf(cadena,"%d",i);
        fputs(cadena,archivo);
        fputs("\n",archivo);
    }
    fclose(archivo);
    printf("Operacion completada");

}

/*generar listado de números de uno en uno ordenados descendentemente y guardar en archivo*/
void generar_listado_aleatorio(int length, int min){
    FILE *archivo;
    char nombre_archivo[50] = "listado_alteatorio_length_";
    char str[20];

    sprintf(str,"%d",length);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,"_min_");
    sprintf(str,"%d",min);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,".txt");
    archivo = fopen(nombre_archivo, "w");
    char cadena[10];

    for(int i=0; i+min<=length+min; i++){
        /*HACER EL RANDOM PARA COMPLETAR EL LISTADO*/
        sprintf(cadena,"%d",i);
        fputs(cadena,archivo);
        fputs("\n",archivo);
    }
    fclose(archivo);
    printf("Operacion completada");

}

int cargar_listado_en_arreglo(int array[]){

    //LEER ARCHIVO Y GUARDAR EN ARREGLO

    return array;
}


/*Programa principal*/
int main(){
    int opcion=1, length=0, min=0;
    while(opcion!=0){
        printf("Menu:\n");
        printf("1. Generar listado numerico ordenado ascendente\n");
        printf("2. Generar listado numerico ordenado descendente\n");
        printf("3. Generar listado numerico aleatorio\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: \n");
        scanf("%d",&opcion);
        switch(opcion){
            case 0:

            break;

            case 1:
                /*Completamos los datos para ingresarlos como parámetros*/
                printf("Ingrese el largo del arreglo");
                scanf("%d",&length);
                printf("Ingrese el valor mínimo");
                scanf("%d",&min);
                /*Invocamos la función*/
                generar_listado_asc(length, min);
            break;

            case 2:
                /*Completamos los datos para ingresarlos como parámetros*/
                printf("Ingrese el largo del arreglo");
                scanf("%d",&length);
                printf("Ingrese el valor mínimo");
                scanf("%d",&min);
                /*Invocamos la función*/
                generar_listado_desc(length, min);
            break;

            case 3:
            break;
        }
    }
    return 0;
}