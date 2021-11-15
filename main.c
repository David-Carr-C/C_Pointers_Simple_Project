#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variables globales
short uno = 0, dos = 0, tres = 0, cuatro = 0, cinco = 0, seis = 0;//Next //Boolean
//Variable para saber si fue tomada la opcion o no

int fecha = 0;

void filtroaceite(float* costo, float* totalpagar) {
    char select = 'n';
    printf("El costo de la reparacion es de: 750$\n");
    printf("Desea pagar por Cambios de filtro y aceite?: (s/n)\n");
    scanf("%c",&select);
    if (select=='s') {
        printf("Añadido a su carrito!\n");
        *costo = *costo + 750;
        uno = 1;
    } else {
        printf("Compra no hecha, por favor siga eligiendo\n");
    }
}

void revisionfrenos(float* costo,float* totalpagar) {
    char select = 'n';
    printf("El costo de la reparacion es de: 1100$\n");
    printf("Desea pagar por Revision de frenos?: (s/n)\n");
    scanf("%c",&select);
    if (select=='s') {
        printf("Añadido a su carrito!\n");
        *costo = *costo + 1100;
        dos = 1;
    } else {
        printf("Compra no hecha, por favor siga eligiendo\n");
    }
}

void cambioneumaticos(float* costo,float* totalpagar) {
    char select = 'n';
    printf("El costo de la reparacion es de: 777$\n");
    printf("Desea pagar por Cambio de neumaticos?: (s/n)\n");
    scanf("%c",&select);
    if (select=='s') {
        printf("Añadido a su carrito!\n");
        *costo = *costo + 777;
        tres = 1;
    } else {
        printf("Compra no hecha, por favor siga eligiendo\n");
    }
}

void amortiguadores(float* costo,float* totalpagar) {
    char select = 'n';
    printf("El costo de la reparacion es de: 1550$\n");
    printf("Desea pagar por Revision de amortiguadores?: (s/n)\n");
    scanf("%c",&select);
    if (select=='s') {
        printf("Añadido a su carrito!\n");
        *costo = *costo + 1550;
        cuatro = 1;
    } else {
        printf("Compra no hecha, por favor siga eligiendo\n");
    }
}

void luces(float* costo,float* totalpagar) {
    char select = 'n';
    printf("El costo de la reparacion es de: 1090$\n");
    printf("Desea pagar por Revision de las luces?: (s/n)\n");
    scanf("%c",&select);
    if (select=='s') {
        printf("Añadido a su carrito!\n");
        *costo = *costo + 1090;
        cinco = 1;
    } else {
        printf("Compra no hecha, por favor siga eligiendo\n");
    }
}

void bateria(float* costo,float* totalpagar) {
    char select = 'n';
    printf("El costo de la reparacion es de: 3050$\n");
    printf("Desea pagar por Cambio de bateria?: (s/n)\n");
    scanf("%c",&select);
    if (select=='s') {
        printf("Añadido a su carrito!\n");
        *costo = *costo + 3050;
        seis = 1;
    } else {
        printf("Compra no hecha, por favor siga eligiendo\n");
    }
}

void comprar(float* costo,float* totalpagar, int* avanzo) {
    char select = 'n';
    printf("El monto total es: %f\n",*costo);
    printf("Desea proceder con el trabajo o salir?: (s/n): ");
    scanf("%c",&select);
    if (select=='s') {
        if (*costo==0) {
            printf("Usted no ha seleccionado ninguna opcion\n");
            *avanzo = 0;
        }else {//Salta este else si es true el if
            *avanzo = 1;
        }//Salta tambien este else de abajo
    } else {
        *avanzo = 0;
    }
}
//////////////////////////////////////////////////////////
void reparacionesElegidas(float* costo) {
    //Crear un archivo de recibo:
    FILE *recibo = fopen("Recibos.txt","a+");
    if (uno==1) {
        printf("Usted eligio Cambios de filtro y aceite\n");
        printf("Costo: %.2f\n",750.00);
    } //No es else if, porque eso es para que solo tome una opcion de todas,
        //Es solo if para ir checando caso por caso si lo eligio
    if (dos==1) {
        printf("Usted eligio Revision de frenos\n");
        printf("Costo: %.2f\n",1100.00);
    }
    if (tres==1) {
        printf("Usted eligio Cambio de neumaticos\n");
        printf("Costo: %.2f\n",777.00);
    }
    if (cuatro==1) {
        printf("Usted eligio Revision de amortiguadores\n");
        printf("Costo: %.2f\n",1550.00);
    }
    if (cinco==1) {
        printf("Usted eligio Revision de las luces\n");
        printf("Costo: %.2f2\n",1090.00);
    }
    if (seis==1) {
        printf("Usted eligio Cambio de bateria\n");
        printf("Costo: %.2f2\n",3050.00);
    }
    fprintf(recibo,"%c %d %c %d %c %d %c %d %c %d %c %d\n",'a',uno,'b',dos,'c',tres,'d',cuatro,'e',cinco,'f',seis);
    //Se leen los datos, primero a b c d e f que simboliza que repacacion es, y si es 1 o 0 para saber si la eligio
    printf("Monto total: %.2f\n\n",*costo);
    fclose(recibo);
}

void logdespues() {
    char usuario[50], password[50];
    printf("No ocupe espacios\n");
    gets(usuario);
    printf("Por favor cree una contraseña:\n");
    printf("No ocupe espacios\n");
    gets(password);

    FILE *save = fopen("Log.txt","a+");
    fprintf(save,"%s ",usuario);
    fprintf(save,"%s ",password);
    fprintf(save, "%d\n",fecha);
    printf("Guardado!\n");
    fclose(save);
}

void creandoRecibo(float* costo){
    fecha = rand()%31;//Se agrega el +1 para que el dia no caiga en 0
    printf("Fecha de entrega: Diciembre %d\n",fecha);//El numero aletoria saldra entre 0 y 31, que son los dias del mes de diciembre
    printf("Resultado de trabajo y costos:\n"); //Guardar... file
    reparacionesElegidas(costo); //Para volver a pasar por parametro se tiene que poner la variable sin "&"
    printf("Por favor cree un nombre de usuario:\n"); //guardar...
    logdespues();
}

/////////////////////////////////////////////////////////
void bienvenido(int* ffecha){
    float totalapagar = 0;
    FILE *recibo = fopen("Recibos.txt","r");
    printf("Su compra llegara el %d de Diciembre\n",*ffecha);//Se me estaba olvidando el *
    printf("Su recibo es: \n");
    char eleccion1,eleccion2,eleccion3,eleccion4,eleccion5,eleccion6;
    int elec1,elec2,elec3,elec4,elec5,elec6;
    fscanf(recibo,"%c %d %c %d %c %d %c %d %c %d %c %d\n",&eleccion1,&elec1,&eleccion2,&elec2,&eleccion3,&elec3,&eleccion4,&elec4,&eleccion5,&elec5,&eleccion6,&elec6);
    if (elec1==1) {
        printf("Usted eligio Cambios de filtro y aceite\n");
        printf("Costo: %.2f\n",750.00);
        totalapagar =  totalapagar+750.00;
    }
    if (elec2==1) {
        printf("Usted eligio Revision de frenos\n");
        printf("Costo: %.2f\n",1100.00);
        totalapagar =  totalapagar+1100.00;
    }
    if (elec3==1) {
        printf("Usted eligio Cambio de neumaticos\n");
        printf("Costo: %.2f\n",777.00);
        totalapagar =  totalapagar+777.00;
    }
    if (elec4==1) {
        printf("Usted eligio Revision de amortiguadores\n");
        printf("Costo: %.2f\n",1550.00);
        totalapagar =  totalapagar+1550.00;
    }
    if (elec5==1) {
        printf("Usted eligio Revision de las luces\n");
        printf("Costo: %.2f\n",1090.00);
        totalapagar =  totalapagar+1090.00;
    }
    if (elec6==1) {
        printf("Usted eligio Cambio de bateria\n");
        printf("Costo: %.2f\n",3050.00);
        totalapagar =  totalapagar+3050.00;
    }
    printf("Total a pagar: %.2f",totalapagar);
    printf("---------------------\n");
    fclose(recibo);
}
        //tener 'int *exit' es lo mismo que tener 'int* exit'
void logantes(int* exit) {
    int autenticacion = 1;

    printf("Inserte su usuario: ");
    char nombredeusuario[50], contrasenia[50];
    gets(nombredeusuario);

    FILE *log;
    log = fopen("Log.txt","a+");
    rewind(log);//Pasa el puntero al inicio del archivo
    char fileusuario[50];
    fscanf(log,"%s",fileusuario);
    //Recaba del archivo el usuario y lo compara con el que recabo del input del programa
    autenticacion = strcmp(nombredeusuario,fileusuario);

    if (autenticacion==0) {
        char fcontraseña[50];

        char ffecha[2]; //Este es fecha de string
        int fffecha = 0; //Este sera la variable para pasarla de string a entero

        fscanf(log,"%s",fcontraseña);
        while ( strcmp(contrasenia,fcontraseña)!=0 ) {
            printf("Inserte su contraseña: ");
            gets(contrasenia);
            *exit = 1;
        }
        fscanf(log, " %s",ffecha); //Se forzara a cargar el numero pero como string
        fffecha = atoi(ffecha); //Una vez obtenido el numero como string se pasa a entero/integer
        fclose(log);//Todo archivo FILE que se abra se tiene que cerrar
        bienvenido(&fffecha);
    } else {
        printf("Usuario no encontrado\n");
        printf("Por favor proceda con el registro\n");
        fclose(log);
    }
}

int main() {
    printf("Taller Mecanico\n");
    int exit = 0;
    logantes(&exit); //&variable <- 0x123123, variable
    if (exit==1) {
        return 0;
    }
    printf("Nombre completo: ");
    char nombre[50];
    gets(nombre);
    printf("Direccion y numero de calle: ");
    char direccion[50];
    gets(direccion);
    printf("Placa del auto: ");
    char placa[50];
    gets(placa);
    printf("Año: ");
    char fecha[50];
    gets(fecha);
    printf("Marca: ");
    char marca[50];
    gets(marca);
    printf("Modelo: ");
    char modelo[50];
    gets(modelo);
    //printf("Comprobacion de datos %s %s %s %s %s %s",nombre,direccion,placa,fecha,marca,modelo);
    char seleccion = 'a'; //que mantenimiento de auto escogera
    float costo = 0, totalpagar = 0;
    int avanzo = 0; //Saber si se procede con la compra
    while (seleccion != 'x') {
        printf("Matenimientos del auto:\n");
        printf("1) Cambios de filtro y aceite\n");
        printf("2) Revision de frenos\n");
        printf("3) Cambio de neumaticos\n");
        printf("4) Revision de amortiguadores\n");
        printf("5) Revision de las luces\n");
        printf("6) Cambio de bateria\n");
        printf("7) Proceder\n");
        printf("-> ");
        scanf("%c",&seleccion);
        switch (seleccion) {
            case '1':
                getchar();
                filtroaceite(&costo,&totalpagar);
                getchar();
                break;
            case '2':
                getchar();
                revisionfrenos(&costo,&totalpagar);
                getchar();
                break;
            case '3':
                getchar();
                cambioneumaticos(&costo,&totalpagar);
                getchar();
                break;
            case '4':
                getchar();
                amortiguadores(&costo,&totalpagar);
                getchar();
                break;
            case '5':
                getchar();
                luces(&costo,&totalpagar);
                getchar();
                break;
            case '6':
                getchar();
                bateria(&costo,&totalpagar);
                getchar();
                break;
            case '7':
                getchar();
                comprar(&costo,&totalpagar,&avanzo);
                getchar();
                seleccion = 'x';
                break;
            default:
                printf("Elija una opcion valida\n");
        }

    }

    if (avanzo==1) {
        creandoRecibo(&costo);
        printf("Vuelva pronto!\n");
    }

    return 0;
}
