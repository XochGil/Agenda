#include <stdio.h>
#include "Agenda.h"

int main() {
    configurarLocalizacion();
    int opcion;

    do {
        printf("\n--- MENÚ AGENDA ---\n");
        printf("1. Agregar contacto\n");
        printf("2. Listar contactos\n");
        printf("3. Buscar contacto\n");
        printf("4. Eliminar contacto\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                agregarContacto();
                break;
            case 2:
                listarContactos();
                break;
            case 3:
                buscarContacto();
                break;
            case 4:
                eliminarContacto();
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while(opcion != 5);

    return 0;
}