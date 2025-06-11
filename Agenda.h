#ifndef AGENDA_H
#define AGENDA_H

#define MAX_CONTACTOS 100

struct Contacto {
    char nombre[50];
    char apellido[50];
    char telefono[15];
    char correo[100];
    int tipoNumero; // 1=Celular, 2=Casa, 3=Trabajo
    // Referencia adicional para almacenar información extra    
    char Referencia[200];
};

// Variables y funciones
extern struct Contacto agenda[MAX_CONTACTOS];
extern int numContactos;

void configurarLocalizacion(void);
void agregarContacto();
void listarContactos();
void buscarContacto();
void eliminarContacto();

#endif