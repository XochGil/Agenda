#include <stdio.h>
#include <string.h>
#include <locale.h>  
#include "Agenda.h"

struct Contacto agenda[MAX_CONTACTOS];
int numContactos = 0;

void configurarLocalizacion() {
    setlocale(LC_ALL, "");
}

void agregarContacto() {
    if (numContactos >= MAX_CONTACTOS) {
        printf("Agenda llena.\n");
        return;
    }

    printf("Nombre: ");
    scanf(" %[^\n]", agenda[numContactos].nombre);

    printf("Apellido: ");
    scanf(" %[^\n]", agenda[numContactos].apellido);

    printf("Teléfono: ");
    scanf(" %[^\n]", agenda[numContactos].telefono);

    printf("Tipo de número (1=Celular, 2=Casa, 3=Trabajo): ");
    scanf("%d", &agenda[numContactos].tipoNumero);

    printf("Correo: ");
    scanf(" %[^\n]", agenda[numContactos].correo);

    printf("Referencia: ");
    scanf(" %[^\n]", agenda[numContactos].Referencia);

    numContactos++;
    printf("Contacto agregado.\n");
}

void listarContactos() {
    if (numContactos == 0) {
        printf("No hay contactos.\n");
        return;
    }

    printf("\nLista de contactos:\n");
    for (int i = 0; i < numContactos; i++) {
        char* tipoNumeroStr;
        switch(agenda[i].tipoNumero) {
            case 1: tipoNumeroStr = "Celular"; break;
            case 2: tipoNumeroStr = "Casa"; break;
            case 3: tipoNumeroStr = "Trabajo"; break;
            default: tipoNumeroStr = "Desconocido"; break;
        }
        printf("%d. %s %s - %s %s %s (%s)\n", i + 1, agenda[i].nombre, agenda[i].apellido, 
       agenda[i].telefono, agenda[i].correo, agenda[i].Referencia, tipoNumeroStr);

    }
}

void buscarContacto() {
    char nombre[50];
    printf("Buscar nombre o apellido: ");
    scanf(" %[^\n]", nombre);

    int encontrados = 0;
    for (int i = 0; i < numContactos; i++) {
        if (strstr(agenda[i].nombre, nombre) || strstr(agenda[i].apellido, nombre)) {
            char* tipoNumeroStr;
            switch(agenda[i].tipoNumero) {
                case 1: tipoNumeroStr = "Celular"; break;
                case 2: tipoNumeroStr = "Casa"; break;
                case 3: tipoNumeroStr = "Trabajo"; break;
                default: tipoNumeroStr = "Desconocido"; break;
            }
            printf("%d. %s %s - %s (%s)\n", i + 1, agenda[i].nombre, agenda[i].apellido, 
                   agenda[i].telefono, tipoNumeroStr);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No se encontraron contactos.\n");
    }
}

void eliminarContacto() {
    int id;
    listarContactos();
    printf("ID del contacto a eliminar: ");
    scanf("%d", &id);

    if (id < 1 || id > numContactos) {
        printf("ID inválido.\n");
        return;
    }

    for (int i = id - 1; i < numContactos - 1; i++) {
        agenda[i] = agenda[i + 1];
    }

    numContactos--;
    printf("Contacto eliminado.\n");
}