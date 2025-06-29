#include <fstream>
#include <iostream>
#include "Gestor.h"
#include "Cuenta.h"
#include <string>

using namespace std;
bool existeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    return archivo.good();
}

void mostrarMenu() {
    
    std::cout << "\n----- Gestor de Contraseñas -----\n";
    std::cout << "1. Añadir contraseña\n";
    std::cout << "2. Ver servicios guardados\n";
    std::cout << "3. Mostrar contraseña de un servicio\n";
    std::cout << "4. Limpiar pantalla\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    string user, psswd;
    Gestor g;

    if (!existeArchivo("data/user_data.txt")) {
        cout << "¡Hola! Parece que eres nuevo... Introduce tu usuario y contraseña deseados: " << endl;
        cout << "Usuario: ";
        cin >> user;
        cout << "Contraseña: ";
        cin.ignore();
        getline(std::cin, psswd);
        g.configuracionInicial(user, psswd);
    }

    std::string hashClave;
    if (g.loginUsuario(hashClave)) {
        Cuenta gestor(hashClave);
        bool salir = false;
        while (!salir) {
            mostrarMenu();
            int opcion;
            std::cin >> opcion;

            switch (opcion) {
                case 1:
                    gestor.agregarCuenta();
                    break;
                case 2:
                    gestor.listarServicios();
                    break;
                case 3:
                    gestor.mostrarContrasena();
                    break;
                case 4:
                    system("cls");
                break;
                case 5:
                  std::cout << "Saliendo...\n";
                  system("cls");
                    salir = true;
                    break;
                default:
                    std::cout << "Opción no válida.\n";
                    break;
            }
        }
    }

    return 0;
}
