/*------------------------------------------------------
                    Trabajo grupal 1

    Integrantes:    -Luis Caro
                    -Jorge Gallardo
                    -Fernando Maldonado
                    -Felipe Vera
    Asignatura: Análisis de Algoritmos (INFB8071)
    Sección:    412
    Profesor:   Sergio Muñoz
------------------------------------------------------*/

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

void cargar_listado_csv(int *arreglo);

int get_length(char *name);

int busqueda_binaria(int *arreglo,int i, int n, int k);

int jump_search(int *array, int n, int x);

int partition(int left, int right, int pivot, int *numbers);
void quickSort(int left, int right, int *numbers);
void swap(int i, int j, int *arreglo);

void merge(int *arreglo, int l, int m, int r);
void mergesort(int *arreglo, int l, int r);

void guardar_arreglo(int *arreglo, char *name_sort, int length);
void ingresar_tiempo_datalog(char *operacion, double tiempo, int anio, int mes, int dia, char *name, int length);

/*Programa principal*/
int main(){
    int opcion_menu=1;
    int opcion_menu_generar=1, opcion_menu_buscar=1, opcion_menu_ordenar=1, length=0, min=0;
    char name[50];
    int* array = (int *)malloc((15000000)*sizeof(int));
    int valor;
    
    /*Para calcular tiempo e ingresar en datalog*/
    clock_t tiempo_inicio, tiempo_final;
    double segundos;

    time_t tiempoActual = time(NULL);
    struct tm *fechaHora = localtime(&tiempoActual);

    int anio = fechaHora->tm_year + 1900;
    int mes = fechaHora->tm_mon + 1;
    int dia = fechaHora->tm_mday;

    length=30000;

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
                /*Ingresamos el nombre del archivo*/
                // printf("Ingrese el nombre del archivo:\n");
                // scanf("%49s", name);
                /*Obtenemos el largo*/
                // length = get_length(name);
                printf("Ingrese el tamaño del arreglo:\n");
                scanf("%d",length);
                /*Cargamos el listado en el array*/
                // cargar_listado_en_arreglo(array,name);
                cargar_listado_csv(array);
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
                        int k = 121;
                        for(length=30000; length<=8250000; length+=30000){
                             /*Invocamos la función, guardando el retorno en la variable "valor"*/
                            tiempo_inicio = clock();
                            valor = busqueda_binaria(array,0,length,k);
                            tiempo_final = clock();
                            segundos = (double)(tiempo_final-tiempo_inicio)/CLOCKS_PER_SEC;
                            ingresar_tiempo_datalog("binaria",segundos,anio,mes,dia,name,length);
                            /*Imprimimos el índice que tiene el elemento en el array*/
                            printf("Indice: %d\n",valor);
                        }
                        // printf("Ingrese el valor a buscar:\n");
                        // scanf("%d",&k);

                        /*Invocamos la función, guardando el retorno en la variable "valor"*/
                        // valor = busqueda_binaria(array,0,length,k);
                        /*Imprimimos el índice que tiene el elemento en el array*/
                        // printf("Indice: %d\n",valor);
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
                        // quicksort(array,1,length);
                        quickSort(0,length,array); //REVISAR SI ES 0 O ES 1
                        tiempo_final = clock();
                        segundos = (double)(tiempo_final-tiempo_inicio)/CLOCKS_PER_SEC;
                        // ingresar_tiempo_datalog("quicksort",segundos,anio,mes,dia,name);
                        printf("Operacion completada en %.20lf segundos...\n",segundos);
                        /*Guardamos el arreglo en un archivo de texto*/
                        printf("Guardando arreglo en archivo de texto...");
                        guardar_arreglo(array,"quicksort.txt",length);
                        printf("Operacion completada...\n");
                    break;

                    case 2:
                        /*Invocamos la función y calculamos el tiempo de ejecución*/
                        tiempo_inicio = clock();
                        mergesort(array,1,length);
                        tiempo_final = clock();
                        segundos = (double)(tiempo_final-tiempo_inicio)/CLOCKS_PER_SEC;
                        // ingresar_tiempo_datalog("mergesort",segundos,anio,mes,dia,name);
                        printf("Operacion completada en %.20lf segundos...\n",segundos);
                        /*Guardamos el arreglo en un archivo de texto*/
                        // guardar_arreglo(array,"mergesort.txt",8926307);
                        printf("Guardando arreglo en archivo de texto...");
                        guardar_arreglo(array,"mergesort.txt",length);
                        printf("Operacion completada...\n");
                    break;

                    case 3:
                    break;
                }
            break;

            case 5:
                free(array);
            break;

            case 6:
                        for(length=30000; length<=8250000; length+=30000){
                            /*Cargamos el listado en el array*/
                            printf("length: %d",length);
                            cargar_listado_csv(array);
                            printf("Operacion completada...\n");

                            /*Invocamos la función y calculamos el tiempo de ejecución*/
                            tiempo_inicio = clock();
                            // quicksort(array,1,length);
                            quickSort(0,length,array); //REVISAR SI ES 0 O ES 1
                            tiempo_final = clock();
                            segundos = (double)(tiempo_final-tiempo_inicio)/CLOCKS_PER_SEC;
                            ingresar_tiempo_datalog("quicksort",segundos,anio,mes,dia,name,length);
                            printf("Operacion completada en %.20lf segundos...\n",segundos);
                            /*Guardamos el arreglo en un archivo de texto*/
                            printf("Guardando arreglo en archivo de texto...");
                            guardar_arreglo(array,"quicksort.txt",length);
                            printf("Operacion completada...\n");
                        }
                        
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

void swap(int i, int j, int *arreglo){
    int aux;
    aux = arreglo[i];
    arreglo[i] = arreglo[j];
    arreglo[j] = aux;
}

int partition(int left, int right, int pivot, int *numbers) {
   int leftPointer = left -1;
   int rightPointer = right;

   while (1) {
      while (numbers[++leftPointer] < pivot) {
         //do nothing
      }

      while (rightPointer > 0 && numbers[--rightPointer] > pivot) {
         //do nothing
      }

      if (leftPointer >= rightPointer) {
         break;
      } else {
         // printf(" item swapped :%d,%d\n", numbers[leftPointer],numbers[rightPointer]);
         swap(leftPointer,rightPointer, numbers);
      }
   }

   // printf(" pivot swapped :%d,%d\n", numbers[leftPointer],numbers[right]);
   swap(leftPointer, right, numbers);
   // printf("Updated Array: ");
   // display();
   return leftPointer;
}

void quickSort(int left, int right, int *numbers) {
   if(right - left <= 0) {
      return;
   } else {
      int pivot = numbers[right];
      int partitionPoint = partition(left, right, pivot, numbers);
      quickSort(left, partitionPoint-1, numbers);
      quickSort(partitionPoint+1, right, numbers);
   }
}

void merge(int *arreglo, int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    /*Utilizamos arreglos dinámicos para evitar que el programa finalice por problemas*/
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
 
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arreglo[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arreglo[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arreglo[k] = L[i];
            i++;
        }
        else {
            arreglo[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arreglo[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arreglo[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}
 
// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergesort(int *arreglo, int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergesort(arreglo, l, m);
        mergesort(arreglo, m + 1, r);
 
        merge(arreglo, l, m, r);
    }
}

void guardar_arreglo(int *arreglo, char *name_sort,int length){
    char number[100];

    FILE *archivo;
    archivo = fopen(name_sort,"w");

    for(int i=1; i<=length; i++){
        sprintf(number,"%d",arreglo[i]);
        fputs(number,archivo);
        fputs("\n",archivo);
    }
    fclose(archivo);
}

void ingresar_tiempo_datalog(char *operacion, double tiempo, int anio, int mes, int dia, char *name, int length){
    FILE *archivo;
    archivo = fopen("datalog.txt","a");
    fprintf(archivo,"operacion: %s fecha: %02d-%02d-%d tiempo:%0.20lf length: %d\n",operacion,dia,mes,anio,tiempo,length);
    fclose(archivo);
}

/*TERMINAR FUNCION!!!!!!!!*/
void cargar_listado_csv(int *arreglo){
    FILE* archivo;
    archivo = fopen("AtencionesUrgencia2022.csv","r");
    
    char buffer[500];
    char char_number[5];
    int flag=0;
    // int j;
    int number;
    int row = 0;
    fgets(buffer,500,archivo);
    strtok(buffer,"\n");
    while(fgets(buffer,500,archivo)){
        for(int i=0; i<500; i++){
            if(buffer[i]==';'){
                flag++;
            }
            if(flag==4){
                //BUSCAR NUM
                for(int j=0; j<=500;j++){
                    if(buffer[i+j+1]==';'){
                        flag++;
                        break;
                    }
                    else{
                        char_number[j]=buffer[i+j+1];
                    }
                }
            }
            if(flag==5){
                break;
            }
        }
        number = atoi(char_number);
        arreglo[row]=number;
        flag=0;
        row++;
        memset(char_number,0,5);
        strtok(buffer,"\n");
    }
    printf("Listado cargado en arreglo satisfactoriamente...");
}
