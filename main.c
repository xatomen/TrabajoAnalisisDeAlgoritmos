#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
    char nombre_archivo[50] = "listado_aleatorio_length_";
    char str[20];
    int value;

    srand(time(NULL));

    sprintf(str,"%d",length);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,"_min_");
    sprintf(str,"%d",min);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,".txt");
    archivo = fopen(nombre_archivo, "w");
    char cadena[10];

    for(int i=0; i<=length; i++){
        value = rand() % length + min;
        sprintf(cadena,"%d",value);
        fputs(cadena,archivo);
        fputs("\n",archivo);
    }
    fclose(archivo);
    printf("Operacion completada");

}

void cargar_listado_en_arreglo(int *arreglo, char *name) {
    // char name[50];
    // printf("Ingrese el nombre del archivo:\n");
    // scanf("%49s", name);

    /*Obtenemos el largo del array*/
    // char str[20];
    // for(int i=0; i<=50; i++){
    //     if(name[i]=='h'){
    //         printf("h encontrado\n");
    //         for(int j=i+2; j<=50; j++){
    //             printf("iteracion...\n");
    //             if(name[j]=='_'){
    //                 break;
    //             }
    //             else{
    //                 str[j-i-2]=name[j];
    //             }
    //         }
    //     }
    // }
    // printf("Largo obtenido...\n");
    // int length = atoi(str);

    /*Declaramos el array con el tamaño correspondiente*/
    int i=0;
    FILE *archivo;
    archivo = fopen(name,"r");
    char buffer[100];
    int number;
    printf("Iniciamos while get...\n");
    while(fgets(buffer,100,archivo)){
        printf("Iteracion...\n");
        strtok(buffer,"\n");
        number = atoi(buffer);
        arreglo[i]=number;
        i++;
    }
    printf("Terminamos while...\n");
    fclose(archivo);

    // for(int i=0; i<=length; i++){
    //     printf("for indice: %d - dato: %d\n",i,arreglo[i]);
    // }

}

int busqueda_binaria(int *arreglo,int i, int n, int k){
    int l = i;
    int h = n;
    int medio;
    while(l<=h){
        medio = (h+l)/2;
        if(arreglo[medio]==k){
            return medio;
        }
        if(arreglo[medio]<k){
            l = medio+1;
        }
        else{
            h = medio-1;
        }
    }
    return -1;
}

/*Función que obtiene el largo del array a partir del nombre del archivo*/
int get_length(char *name){
    /*str -> variable que guardará la subcadena*/
    char str[20];
    /*Ciclo for para iterar sobre nombre del archivo*/
    for(int i=0; i<=50; i++){
        /*Cuando encontremos las "h" significa que estámos en ...length...*/
        if(name[i]=='h'){
            // printf("h encontrado\n");
            /*Ejecutamos otro ciclo for para iterar sobre la subcadena restante*/
            /*j es i+2, debido a que i contiene el índice de la letra "h", i+1 posee el caracter "_",*/
            /*por lo tanto, i+2 posee el inicio del número que indica el largo del array*/
            for(int j=i+2; j<=50; j++){
                // printf("iteracion...\n");
                /*Cuando encontremos el siguiente "_", salimos del ciclo debido a que ya terminamos*/
                /*de iterar sobre la subcadena que poseía el número*/
                if(name[j]=='_'){
                    break;
                }
                /*Si aún no encontramos el final del número, seguimos "almacenando" los números*/
                else{
                    /*Vamos generando una cadena que va incluyendo cada número de la subcadena*/
                    str[j-i-2]=name[j];
                }
            }
        }
    }
    /*Transformamos el número a int para poder retornarlo y obtener el largo del array*/
    int length = atoi(str);
    return length;
}

/*Programa principal*/
int main(){
    int opcion_menu=1;
    int opcion_menu_generar=1, opcion_menu_buscar=1, opcion_menu_ordenar=1, length=0, min=0;
    char name[50];
    int* array = (int *)malloc((1050001)*sizeof(int));

    while(opcion_menu!=0){
        /*Imprimimos menú principal*/
        printf("Menu:\n");
        printf("1. Generar listado\n");
        printf("2. Cargar listado en array\n");
        printf("3. Buscar en array\n");
        printf("4. Ordenar array\n");
        printf("5. Vaciar array\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: \n");
        scanf("%d",&opcion_menu);
        
        switch(opcion_menu){
            /*Caso de salida*/
            case 0:
            break;

            /*Submenú para generar listados*/
            case 1:
                /*Imprimimos submenu de generar listados*/
                printf("Menu generar listado:\n");
                printf("1. Generar listado numerico ordenado ascendente\n");
                printf("2. Generar listado numerico ordenado descendente\n");
                printf("3. Generar listado numerico aleatorio\n");
                printf("0. Salir\n");
                printf("Ingrese una opcion: \n");
                scanf("%d",&opcion_menu_generar);

                switch(opcion_menu_generar){

                    /*Salir*/
                    case 0:
                    break;

                    case 1:
                        /*Completamos los datos para ingresarlos como parámetros*/
                        printf("Ingrese el largo del arreglo\n");
                        scanf("%d",&length);
                        printf("Ingrese el valor minimo\n");
                        scanf("%d",&min);
                        /*Invocamos la función*/
                        generar_listado_asc(length, min);
                    break;

                    case 2:
                        /*Completamos los datos para ingresarlos como parámetros*/
                        printf("Ingrese el largo del arreglo\n");
                        scanf("%d",&length);
                        printf("Ingrese el valor minimo\n");
                        scanf("%d",&min);
                        /*Invocamos la función*/
                        generar_listado_desc(length, min);
                    break;

                    case 3:
                        /*Completamos los datos para ingresarlos como parámetros*/
                        printf("Ingrese el largo del arreglo\n");
                        scanf("%d",&length);
                        printf("Ingrese el valor minimo\n");
                        scanf("%d",&min);
                        /*Invocamos la función*/
                        generar_listado_aleatorio(length, min);
                    break;
            }
            break;

            /*Cargar listado en array*/
            case 2:

                // printf("antes...\n");
                /*Ingresamos el nombre del archivo*/
                printf("Ingrese el nombre del archivo:\n");
                scanf("%49s", name);
                /*Obtenemos el largo*/
                length = get_length(name);
                /*Cargamos el listado en el array*/
                cargar_listado_en_arreglo(array,name); /*REVISAR ESTO!! Y CAMBIAR NOMBRE TXT LISTADO ALEATORIO*/
                
                // printf("despues...\n");
                // printf("%d",length);

                /*Verificación*/
                for(int i=1; i<=length; i++){
                    printf("array indice: %d - dato: %d\n",i,array[i]);
                }
            break;

            /*Submenú para buscar elemento en arreglo*/
            case 3:
                /*Imprimimos el submenú*/
                printf("Menu buscar elemento en arreglo:\n");
                printf("1. Busqueda binaria\n");
                printf("2. Busqueda lineal por saltos\n");
                printf("0. Salir\n");
                printf("Ingrese una opcion: \n");
                scanf("%d",&opcion_menu_buscar);
                switch(opcion_menu_buscar){
                    case 1:
                        /*Ingresamos el valor a buscar*/
                        int k;
                        printf("Ingrese el valor a buscar:\n");
                        scanf("%d",&k);
                        /*Invocamos la función, guardando el retorno en la variable "valor"*/
                        int valor = busqueda_binaria(array,0,length,k);
                        /*Imprimimos el índice que tiene el elemento en el array*/
                        printf("Indice: %d\n",valor);
                    break;

                    case 2:

                    break;

                    case 3:
                    break;
                }
            break;

            case 4:
            break;

            case 5:
                free(array);
            break;
        }
    }
    return 0;
}