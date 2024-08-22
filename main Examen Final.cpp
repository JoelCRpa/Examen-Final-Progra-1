#include <iostream>
#include <string>
#include <windows.h> // Necesario para la función gotoxy en Windows

using namespace std;

// Constante para el número máximo de viajeros
const int MAX_VIAJEROS = 100;

// Estructuras para manejar la información
struct Viajero {
    int id;             // Identificador único del viajero
    string nombre;      // Nombre completo del viajero
    string direccion;   // Dirección del viajero
};

struct Ingreso {
    int idViajero;          // ID del viajero que ingresa
    string fechaEntrada;   // Fecha de entrada del viajero
    string lugarIngreso;   // Lugar de ingreso
};

struct Salida {
    int idViajero;         // ID del viajero que sale
    string fechaSalida;   // Fecha de salida del viajero
    string lugarSalida;   // Lugar de salida
};

struct Visa {
    int idViajero;            // ID del viajero
    string tipoVisa;         // Tipo de visa (ej. turista, de trabajo)
    string fechaExpiracion;  // Fecha de expiración de la visa
};

struct Pasaporte {
    int idViajero;        // ID del viajero
    string numeroPasaporte; // Número de pasaporte
    string paisEmision;  // País que emitió el pasaporte
};

// Arreglos para almacenar los datos de los viajeros y sus registros
Viajero viajeros[MAX_VIAJEROS];
Ingreso ingresos[MAX_VIAJEROS];
Salida salidas[MAX_VIAJEROS];
Visa visas[MAX_VIAJEROS];
Pasaporte pasaportes[MAX_VIAJEROS];

// Contadores para los registros almacenados
int numViajeros = 0;
int numIngresos = 0;
int numSalidas = 0;
int numVisas = 0;
int numPasaportes = 0;

// Función para mover el cursor a una posición específica en la consola
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para limpiar la pantalla
void limpiarPantalla() {
    system("cls"); // Limpia la pantalla en Windows
}

// Función para agregar un nuevo viajero
void agregarViajero() {
    limpiarPantalla();
    if (numViajeros < MAX_VIAJEROS) {
        Viajero v;
        gotoxy(20, 2);
        cout << "--- Agregar Nuevo Viajero ---";
        gotoxy(10, 4);
        cout << "Ingrese ID del viajero: ";
        cin >> v.id;
        gotoxy(10, 6);
        cout << "Ingrese nombre del viajero: ";
        cin.ignore();
        getline(cin, v.nombre);
        gotoxy(10, 8);
        cout << "Ingrese direccion del viajero: ";
        getline(cin, v.direccion);

        // Almacena el nuevo viajero en el arreglo
        viajeros[numViajeros] = v;
        numViajeros++;

        gotoxy(20, 10);
        cout << "Viajero agregado exitosamente.";
    } else {
        gotoxy(20, 2);
        cout << "No se pueden agregar mas viajeros.";
    }
}

// Función para registrar el ingreso de un viajero
void registrarIngreso() {
    limpiarPantalla();
    if (numIngresos < MAX_VIAJEROS) {
        Ingreso ing;
        gotoxy(20, 2);
        cout << "--- Registrar Ingreso ---";
        gotoxy(10, 4);
        cout << "Ingrese ID del viajero: ";
        cin >> ing.idViajero;
        gotoxy(10, 6);
        cout << "Ingrese fecha de entrada (dd/mm/aaaa): ";
        cin >> ing.fechaEntrada;
        gotoxy(10, 8);
        cout << "Ingrese lugar de ingreso: ";
        cin.ignore();
        getline(cin, ing.lugarIngreso);

        // Almacena el nuevo registro de ingreso
        ingresos[numIngresos] = ing;
        numIngresos++;

        gotoxy(20, 10);
        cout << "Ingreso registrado exitosamente.";
    } else {
        gotoxy(20, 2);
        cout << "No se pueden registrar mas ingresos.";
    }
}

// Función para registrar la salida de un viajero
void registrarSalida() {
    limpiarPantalla();
    if (numSalidas < MAX_VIAJEROS) {
        Salida sal;
        gotoxy(20, 2);
        cout << "--- Registrar Salida ---";
        gotoxy(10, 4);
        cout << "Ingrese ID del viajero: ";
        cin >> sal.idViajero;
        gotoxy(10, 6);
        cout << "Ingrese fecha de salida (dd/mm/aaaa): ";
        cin >> sal.fechaSalida;
        gotoxy(10, 8);
        cout << "Ingrese lugar de salida: ";
        cin.ignore();
        getline(cin, sal.lugarSalida);

        // Almacena el nuevo registro de salida
        salidas[numSalidas] = sal;
        numSalidas++;

        gotoxy(20, 10);
        cout << "Salida registrada exitosamente.";
    } else {
        gotoxy(20, 2);
        cout << "No se pueden registrar mas salidas.";
    }
}

// Función para registrar una visa para un viajero
void registrarVisa() {
    limpiarPantalla();
    if (numVisas < MAX_VIAJEROS) {
        Visa v;
        gotoxy(20, 2);
        cout << "--- Registrar Visa ---";
        gotoxy(10, 4);
        cout << "Ingrese ID del viajero: ";
        cin >> v.idViajero;
        gotoxy(10, 6);
        cout << "Ingrese tipo de visa: ";
        cin.ignore();
        getline(cin, v.tipoVisa);
        gotoxy(10, 8);
        cout << "Ingrese fecha de expiracion (dd/mm/aaaa): ";
        cin >> v.fechaExpiracion;

        // Almacena el nuevo registro de visa
        visas[numVisas] = v;
        numVisas++;

        gotoxy(20, 10);
        cout << "Visa registrada exitosamente.";
    } else {
        gotoxy(20, 2);
        cout << "No se pueden registrar mas visas.";
    }
}

// Función para registrar un pasaporte para un viajero
void registrarPasaporte() {
    limpiarPantalla();
    if (numPasaportes < MAX_VIAJEROS) {
        Pasaporte p;
        gotoxy(20, 2);
        cout << "--- Registrar Pasaporte ---";
        gotoxy(10, 4);
        cout << "Ingrese ID del viajero: ";
        cin >> p.idViajero;
        gotoxy(10, 6);
        cout << "Ingrese numero de pasaporte: ";
        cin.ignore();
        getline(cin, p.numeroPasaporte);
        gotoxy(10, 8);
        cout << "Ingrese pais de emision: ";
        getline(cin, p.paisEmision);

        // Almacena el nuevo registro de pasaporte
        pasaportes[numPasaportes] = p;
        numPasaportes++;

        gotoxy(20, 10);
        cout << "Pasaporte registrado exitosamente.";
    } else {
        gotoxy(20, 2);
        cout << "No se pueden registrar más pasaportes.";
    }
}

// Función para borrar el registro de un viajero
void borrarRegistro() {
    limpiarPantalla();
    int id;
    gotoxy(20, 2);
    cout << "--- Borrar Registro de Viajero ---";
    gotoxy(10, 4);
    cout << "Ingrese ID del viajero a eliminar: ";
    cin >> id;

    bool encontrado = false;
    for (int i = 0; i < numViajeros; i++) {
        if (viajeros[i].id == id) {
            // Limpia el registro del viajero encontrado
            viajeros[i].id = 0;
            viajeros[i].nombre = "";
            viajeros[i].direccion = "";
            encontrado = true;
            gotoxy(20, 6);
            cout << "Registro eliminado exitosamente.";
            break;
        }
    }

    if (!encontrado) {
        gotoxy(20, 6);
        cout << "Viajero no encontrado.";
    }
}

// Función para consultar la información de un viajero
void consultarViajero() {
    limpiarPantalla();
    int id;
    gotoxy(20, 2);
    cout << "--- Consultar Informacion de Viajero ---";
    gotoxy(10, 4);
    cout << "Ingrese ID del viajero a consultar: ";
    cin >> id;

    for (int i = 0; i < numViajeros; i++) {
        if (viajeros[i].id == id) {
            // Muestra la información del viajero encontrado
            gotoxy(10, 6);
            cout << "ID: " << viajeros[i].id;
            gotoxy(10, 8);
            cout << "Nombre: " << viajeros[i].nombre;
            gotoxy(10, 10);
            cout << "Direccion: " << viajeros[i].direccion;
            return;
        }
    }

    gotoxy(10, 6);
    cout << "Viajero no encontrado.";
}

// Función para generar reportes de los registros
void generarReportes() {
    limpiarPantalla();
    gotoxy(20, 2);
    cout << "--- Generar Reportes ---";
    
    // Muestra todos los viajeros
    gotoxy(10, 4);
    cout << "Registros de viajeros:";
    for (int i = 0; i < numViajeros; i++) {
        gotoxy(10, 6 + i);
        cout << "ID: " << viajeros[i].id << ", Nombre: " << viajeros[i].nombre << ", Direccion: " << viajeros[i].direccion;
    }

    // Muestra todos los registros de ingresos
    gotoxy(10, 8 + numViajeros);
    cout << "\nRegistros de ingresos:";
    for (int i = 0; i < numIngresos; i++) {
        gotoxy(10, 10 + numViajeros + i);
        cout << "ID Viajero: " << ingresos[i].idViajero << ", Fecha de entrada: " << ingresos[i].fechaEntrada << ", Lugar de ingreso: " << ingresos[i].lugarIngreso;
    }

    // Muestra todos los registros de salidas
    gotoxy(10, 12 + numViajeros + numIngresos);
    cout << "\nRegistros de salidas:";
    for (int i = 0; i < numSalidas; i++) {
        gotoxy(10, 14 + numViajeros + numIngresos + i);
        cout << "ID Viajero: " << salidas[i].idViajero << ", Fecha de salida: " << salidas[i].fechaSalida << ", Lugar de salida: " << salidas[i].lugarSalida;
    }

    // Muestra todos los registros de visas
    gotoxy(10, 16 + numViajeros + numIngresos + numSalidas);
    cout << "\nRegistros de visas:";
    for (int i = 0; i < numVisas; i++) {
        gotoxy(10, 18 + numViajeros + numIngresos + numSalidas + i);
        cout << "ID Viajero: " << visas[i].idViajero << ", Tipo de visa: " << visas[i].tipoVisa << ", Fecha de expiracion: " << visas[i].fechaExpiracion;
    }

    // Muestra todos los registros de pasaportes
    gotoxy(10, 20 + numViajeros + numIngresos + numSalidas + numVisas);
    cout << "\nRegistros de pasaportes:";
    for (int i = 0; i < numPasaportes; i++) {
        gotoxy(10, 22 + numViajeros + numIngresos + numSalidas + numVisas + i);
        cout << "ID Viajero: " << pasaportes[i].idViajero << ", Numero de pasaporte: " << pasaportes[i].numeroPasaporte << ", Pais de emision: " << pasaportes[i].paisEmision;
    }
}

// Función para mostrar el menú principal y manejar las opciones del usuario
void mostrarMenu() {
    int opcion;
    do {
        limpiarPantalla();
        gotoxy(20, 2);
        cout << "===== SISTEMA DE CONTROL DE VIAJEROS =====";
        gotoxy(10, 4);
        cout << "1. Agregar nuevo viajero";
        gotoxy(10, 5);
        cout << "2. Registrar ingreso";
        gotoxy(10, 6);
        cout << "3. Registrar salida";
        gotoxy(10, 7);
        cout << "4. Registrar visa";
        gotoxy(10, 8);
        cout << "5. Registrar pasaporte";
        gotoxy(10, 9);
        cout << "6. Borrar registro de viajero";
        gotoxy(10, 10);
        cout << "7. Consultar viajero";
        gotoxy(10, 11);
        cout << "8. Generar reportes";
        gotoxy(10, 12);
        cout << "9. Salir";
        gotoxy(10, 14);
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Maneja la opción seleccionada por el usuario
        switch (opcion) {
            case 1:
                agregarViajero();
                break;
            case 2:
                registrarIngreso();
                break;
            case 3:
                registrarSalida();
                break;
            case 4:
                registrarVisa();
                break;
            case 5:
                registrarPasaporte();
                break;
            case 6:
                borrarRegistro();
                break;
            case 7:
                consultarViajero();
                break;
            case 8:
                generarReportes();
                break;
            case 9:
                gotoxy(20, 16);
                cout << "Saliendo del sistema...\n";
                break;
            default:
                gotoxy(20, 16);
                cout << "Opcion no valida. Intente de nuevo.\n";
        }
        // Espera a que el usuario presione Enter para continuar
        if (opcion != 9) {
            gotoxy(20, 18);
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 9); // Repite hasta que el usuario elija salir
}

// Función principal del programa
int main() {
    mostrarMenu(); // Llama a la función para mostrar el menú
    return 0;
}

