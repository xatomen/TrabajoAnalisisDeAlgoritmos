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
    char nombre_archivo[50] = "listado_alteatorio_length_";
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
        /*HACER EL RANDOM PARA COMPLETAR EL LISTADO*/
        value = rand() % length + min;
        sprintf(cadena,"%d",value);
        fputs(cadena,archivo);
        fputs("\n",archivo);
    }
    fclose(archivo);
    printf("Operacion completada");

}

// int cargar_listado_en_arreglo(int array[]){
//     char name[50];
//     printf("Ingrese el nombre del archivo\n");
//     scanf("%49s",name);

//     //LEER ARCHIVO Y GUARDAR EN ARREGLO

//     // FILE *archivo;
    

//     /*Leemos el tamaño del arreglo a partir del nombre del archivo*/
//     char str[]="h_";
//     // char sub_str[3]="";
//     char length[21];
//     // char character;
//     for(int i=0;i<=20;i++){
//         // character = name[i];
//         // strcat(sub_str,character);
//         // character = name[i+1];
//         // strcat(sub_str,character);
//         char sub_str[3] = name[i] + name[i+1];
//         if(strcmp(sub_str,str)==1){
//             for(int j=i+2;j<=20;j++){
//             //    strcat(length,name[j]);
//                 length[21] = length + name[j];
//                 if(name[j+1]=='_'){
//                 break;
//                }
//             }
//             break;
//         }
//     }
//     printf("%s",length);
//     return 0;
// }

// int cargar_listado_en_arreglo(int array[]) {
//     char name[50];
//     printf("Ingrese el nombre del archivo:\n");
//     scanf("%49s", name); // Limitamos la entrada a 49 caracteres para evitar desbordamientos de búfer

//     // Leer archivo y guardar en arreglo

//     char str[] = "h_";
//     char sub_str[3] = ""; // Se reserva espacio para dos caracteres más el carácter nulo
//     char length[21] = ""; // Se reserva espacio para 20 caracteres más el carácter nulo
    
//     for (int i = 0; i <= 20; i++) {
//         strncat(sub_str, &name[i], 1);
        
//         if (strcmp(sub_str, str) == 0) {
//             for (int j = i + 2; j <= 20; j++) {
//                 strncat(length, &name[j], 1);
//                 if (name[j + 1] == '_') {
//                     break;
//                 }
//             }
//             break;
//         }
//     }
    
//     printf("%s\n", length);
//     printf("hola");
    
//     return 0;
// }

// int* cargar_listado_en_arreglo() {
//     char name[50];
//     printf("Ingrese el nombre del archivo:\n");
//     scanf("%49s", name);

//     /*Obtenemos el largo del array*/
//     char str[20];
//     for(int i=0; i<=50; i++){
//         if(name[i]=='h'){
//             printf("h encontrado\n");
//             for(int j=i+2; j<=50; j++){
//                 printf("iteracion...\n");
//                 if(name[j]=='_'){
//                     break;
//                 }
//                 else{
//                     str[j-i-2]=name[j];
//                 }
//             }
//         }
//     }
//     int length = atoi(str);

//     /*Declaramos el array con el tamaño correspondiente*/
//     int arreglo[length+1];
//     int i=0;
//     FILE *archivo;
//     archivo = fopen(name,"r");
//     char buffer[100];
//     int* number;
//     while(fgets(buffer,100,archivo)){
//         strtok(buffer,"\n");
//         number = atoi(buffer);
//         arreglo[i]=number;
//         // printf("number: %d",number);
//         // printf("buffer: -%s-",buffer);
//         i++;
//     }
//     fclose(archivo);

//     for(int i=0; i<=length; i++){
//         printf("for indice: %d - dato: %d\n",i,arreglo[i]);
//     }

//     return arreglo;
// }

void cargar_listado_en_arreglo(int *arreglo) {
    char name[50];
    printf("Ingrese el nombre del archivo:\n");
    scanf("%49s", name);

    /*Obtenemos el largo del array*/
    char str[20];
    for(int i=0; i<=50; i++){
        if(name[i]=='h'){
            printf("h encontrado\n");
            for(int j=i+2; j<=50; j++){
                printf("iteracion...\n");
                if(name[j]=='_'){
                    break;
                }
                else{
                    str[j-i-2]=name[j];
                }
            }
        }
    }
    int length = atoi(str);

    /*Declaramos el array con el tamaño correspondiente*/
    // int arreglo[length+1];
    int i=0;
    FILE *archivo;
    archivo = fopen(name,"r");
    char buffer[100];
    int number;
    while(fgets(buffer,100,archivo)){
        strtok(buffer,"\n");
        number = atoi(buffer);
        arreglo[i]=number;
        // printf("number: %d",number);
        // printf("buffer: -%s-",buffer);
        i++;
    }
    fclose(archivo);

    for(int i=0; i<=length; i++){
        printf("for indice: %d - dato: %d\n",i,arreglo[i]);
    }

}

/*Programa principal*/
int main(){
    printf("hola");
    int opcion_menu=1;
    int opcion_menu_generar=1, opcion_menu_buscar=1, opcion_menu_ordenar=1, length=0, min=0;
    int* array = (int *)malloc((1001)*sizeof(int));
    printf("hola");
    // char name[50];
    while(opcion_menu!=0){
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
            case 0:
            break;

            /*Submenú para generar listados*/
            case 1:
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

            case 2:
                printf("antes...\n");
                cargar_listado_en_arreglo(array); /*REVISAR ESTO!! Y CAMBIAR NOMBRE TXT LISTADO ALEATORIO*/
                printf("despues...\n");
                // printf("%d",&array[1]);
                for(int i=1; i<=1001; i++){
                    printf("array indice: %d - dato: %d\n",i,array[i]);
                }
            break;

            case 3:
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