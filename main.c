


/*Librerias a utilizar*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*Prototipo de funciones*/
void generar_listado_asc(int length, int min);
void generar_listado_desc(int length, int min);
void generar_listado_aleatorio(int length, int min);
void cargar_listado_en_arreglo(int *arreglo, char *name);
int get_length(char *name);
int busqueda_binaria(int *arreglo,int i, int n, int k);
int jump_search(int *array, int n, int x);
void swap(int *arreglo, int i, int j);
int particion(int *arreglo, int l, int h);
void quicksort(int *arreglo, int l, int h);
void guardar_arreglo(int *arreglo, char *name, char *name_sort, int length);

/*Programa principal*/
int main(){
    int opcion_menu=1;
    int opcion_menu_generar=1, opcion_menu_buscar=1, opcion_menu_ordenar=1, length=0, min=0;
    char name[50];
    int* array = (int *)malloc((30000000)*sizeof(int));
    int valor;
    clock_t tiempo_inicio, tiempo_final;
    double segundos;

    //ARREGLAR LOS ARCHIVOS PORQUE SON 1001 DATOS!!!!!!!!!!!!!!

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
                cargar_listado_en_arreglo(array,name);
                /*Verificación (se puede comentar)*/
                // for(int i=1; i<=length; i++){
                //     printf("array indice: %d - dato: %d\n",i,array[i]);
                // }
                printf("Operacion completada...\n");
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
                        valor = busqueda_binaria(array,0,length,k);
                        /*Imprimimos el índice que tiene el elemento en el array*/
                        printf("Indice: %d\n",valor);
                    break;

                    case 2:
                        /*Ingresamos el valor a buscar*/
                        int x;
                        printf("Ingrese el valor a buscar:\n");
                        scanf("%d",&x);
                        /*Invocamos la función, guardando el retorno en la variable "valor"*/
                        valor = jump_search(array,length,x);
                        /*Imprimimos el índice que tiene el elemento en el array*/
                        printf("Indice: %d\n",valor);
                    break;

                    case 3:
                    break;
                }
            break;

            case 4:
                /*Imprimimos el submenú*/
                printf("Menu ordenar arreglo:\n");
                printf("1. QuickSort\n");
                printf("2. MergeSort\n");
                printf("0. Salir\n");
                printf("Ingrese una opcion: \n");
                scanf("%d",&opcion_menu_ordenar);
                switch(opcion_menu_ordenar){
                    case 1:
                        /*Invocamos la función y calculamos el tiempo de ejecución*/
                        tiempo_inicio = clock();
                        quicksort(array,1,length);
                        tiempo_final = clock();
                        segundos = (double)(tiempo_final-tiempo_inicio)/CLOCKS_PER_SEC;

                        printf("Operacion completada en %.20lf segundos...\n",segundos);

                        /*Guardamos el arreglo en un archivo de texto*/
                        guardar_arreglo(array,name,"quicksort",length);
                        /*Traza*/
                        // for(int i=1; i<=length+1; i++){
                        //     printf("indice: %d - valor: %d\n",i,array[i]);
                        //     system("pause");
                        // }
                        // printf("Operacion completada...\n");
                    break;

                    case 2:

                    break;

                    case 3:
                    break;
                }
            break;

            case 5:
                free(array);
            break;
        }
    }
    return 0;
}



/*Funciones*/

/*Generar listado de números de uno en uno ordenados ascendentemente y guardar en archivo*/
void generar_listado_asc(int length, int min){
    /*Declaraciones*/
    FILE *archivo;
    char nombre_archivo[50] = "listado_asc_length_";
    char str[20];
    /*Vamos generando el nombre del archivo*/
    sprintf(str,"%d",length);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,"_min_");
    sprintf(str,"%d",min);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,".txt");

    /*Creamos el archivo*/
    archivo = fopen(nombre_archivo, "w");
    /*Declaramos una "cadena" que poseerá el número generado*/
    char cadena[50];

    /*Ciclo for para llenar el archivo con números consecutivos de manera ascendente*/
    /*Se suma "min" para indicar desde que número queremos comenzar*/
    for(int i=min; i<=length+min-1; i++){
        /*Transformamos el "int" a "char" para poder almacenarlo en el archivo*/
        sprintf(cadena,"%d",i);
        /*Ingresamos el número en el archivo*/
        fputs(cadena,archivo);
        /*Pasamos a la siguiente línea*/
        fputs("\n",archivo);
    }
    /*"Cerramos" el archivo*/
    fclose(archivo);
    printf("Operacion completada\n");
}

/*generar listado de números de uno en uno ordenados descendentemente y guardar en archivo*/
void generar_listado_desc(int length, int min){
    /*Declaraciones*/
    FILE *archivo;
    char nombre_archivo[50] = "listado_desc_length_";
    char str[20];

    /*Vamos generando el nombre del archivo*/
    sprintf(str,"%d",length);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,"_min_");
    sprintf(str,"%d",min);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,".txt");
    archivo = fopen(nombre_archivo, "w");
    char cadena[10];

    /*Ciclo for para llenar el archivo con números consecutivos de manera descendente*/
    /*Se suma "min" para indicar desde que número queremos comenzar*/
    for(int i=length+min-1; i>=min; i--){
        /*Transformamos el "int" a "char" para poder almacenarlo en el archivo*/
        sprintf(cadena,"%d",i);
        /*Ingresamos el número en el archivo*/
        fputs(cadena,archivo);
        /*Pasamos a la siguiente línea*/
        fputs("\n",archivo);
    }
    /*"Cerramos" el archivo*/
    fclose(archivo);
    printf("Operacion completada");

}

/*generar listado de números de uno en uno ordenados descendentemente y guardar en archivo*/
void generar_listado_aleatorio(int length, int min){
    /*Declaraciones*/
    FILE *archivo;
    char nombre_archivo[50] = "listado_aleatorio_length_";
    char str[20];
    int value;

    /*La semilla del "random" dependerá del tiempo de nuestro computador*/
    srand(time(NULL));

    /*Vamos generando el nombre del archivo*/
    sprintf(str,"%d",length);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,"_min_");
    sprintf(str,"%d",min);
    strcat(nombre_archivo,str);
    strcat(nombre_archivo,".txt");
    archivo = fopen(nombre_archivo, "w");
    char cadena[10];

    /*Ciclo for para llenar el archivo con números consecutivos de manera "aleatoria"*/
    for(int i=min; i<=length+min-1; i++){
        value = rand() % length + min;
        sprintf(cadena,"%d",value);
        fputs(cadena,archivo);
        fputs("\n",archivo);
    }
    /*"Cerramos" el archivo*/
    fclose(archivo);
    printf("Operacion completada");

}

void cargar_listado_en_arreglo(int *arreglo, char *name) {
    /*Declaraciones*/
    int i=1;
    FILE *archivo;
    /*Preparamos el archivo para leer*/
    archivo = fopen(name,"r");

    /*"buffer" contendrá el texto de cada línea del archivo*/
    char buffer[100];
    int number;
    /*Ciclo while para poner ir obteniendo cada "número" de cada línea de texto mientras*/
    /*se cumpla la condición de que haya una línea de texto para "leer"*/
    /*Dentro de la condición de este while, obtenemos el "número" y lo guardamos en "buffer"*/
    while(fgets(buffer,100,archivo)){
        /*Saltamos a la siguiente línea*/
        strtok(buffer,"\n");
        /*Transformamos el "número" de char a int*/
        number = atoi(buffer);
        /*Ingresamos el número en el arreglo en la posición correspondiente*/
        arreglo[i]=number;
        /*Incrementamos i para avanzar a la siguiente posición del arreglo*/
        i++;
    }
    /*"Cerramos" el archivo de texto*/
    fclose(archivo);

}

/*Función que obtiene el largo del array a partir del nombre del archivo*/
int get_length(char *name){
    /*str: variable que guardará la subcadena*/
    char str[20];
    /*Ciclo for para iterar sobre nombre del archivo*/
    for(int i=0; i<=50; i++){
        /*Cuando encontremos las "h" significa que estámos en ...length...*/
        if(name[i]=='h'){
            /*Ejecutamos otro ciclo for para iterar sobre la subcadena restante*/
            /*j es i+2, debido a que i contiene el índice de la letra "h", i+1 posee el caracter "_",*/
            /*por lo tanto, i+2 posee el inicio del número que indica el largo del array*/
            for(int j=i+2; j<=50; j++){
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

int jump_search(int *array, int n, int x){
    int i=1, ini, fin;
    fin = sqrt(n);
    while(array[fin]<x && ini<=n){
        ini = fin;
        fin += sqrt(n);
        if(fin>n){
            fin = n;
        }
    }

    i = ini;
    while(i<=fin && array[i]!=x){
        i++;
    }
    if(i>fin){
        return -1;
    }
    else{
        return i;
    }
}

void swap(int *arreglo, int i, int j){
    int aux;
    aux = arreglo[i];
    arreglo[i] = arreglo[j];
    arreglo[j] = aux;
}

int particion(int *arreglo, int l, int h){
    int i, pivote;
    pivote = arreglo[h];
    i = l-1;
    for(int j=l;j<=h-1; j++){
        if(arreglo[j]<=pivote){
            i++;
            swap(arreglo,i,j);
        }
    }
    swap(arreglo,i+1,h);
    return i+1;
}

void quicksort(int *arreglo, int l, int h){
    int pi;
    if(l<h){
        pi = particion(arreglo,l,h);
        quicksort(arreglo,l,pi-1);
        quicksort(arreglo,pi+1,h);
    }
}

void guardar_arreglo(int *arreglo, char *name, char *name_sort, int length){

    // char new_file[] ;
    // char name_without_txt[100];

    // strcat(name_without_txt,name);
    // printf("name: %s\n",name_without_txt);
    // int i=0;
    // while(name[i]!='.'){
    //     new_file[100] = name[i];
    //     i++;
    // }
    // strcat(new_file,name_without_txt);
    // strcat(new_file,"_");
    char number[100];
    // strcat(new_file,name_sort);
    // strcat(new_file,".txt");

    // strcat(new_file,name_sort);
    // strcat(new_file,".txt");

    // new_file = "quicksort.txt";

    // printf("Nombre: %s",new_file);

    FILE *archivo;
    archivo = fopen("quicksort.txt","w");

    for(int i=1; i<=length; i++){
        sprintf(number,"%d",arreglo[i]);
        fputs(number,archivo);
        fputs("\n",archivo);
    }
    fclose(archivo);
}