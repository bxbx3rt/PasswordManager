#include "Cuenta.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm> // para transform()
#include <cctype>    // para tolower()

// Constructor que guarda la clave para cifrado
Cuenta::Cuenta(const std::string& claveCifrado) {
    clave = claveCifrado;
}

std::string Cuenta::cifrarDescifrar(const std::string& texto) {
    std::string resultado = texto;
    for (size_t i = 0; i < texto.size(); ++i) {
        resultado[i] = texto[i] ^ clave[i % clave.size()];
    }
    return resultado;
}

std::vector<std::string> Cuenta::split(const std::string& s, char delim) {
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

// Convierte una cadena a minúsculas para comparación insensible a mayúsculas
std::string Cuenta::toLower(const std::string& str) {
    std::string resultado = str;
    for (char& c : resultado) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return resultado;
}


void Cuenta::agregarCuenta() {
    std::string servicio, usuario, contrasena;
    std::cout << "Servicio: ";
    std::cin.ignore(); // limpiar buffer
    std::getline(std::cin, servicio);
    std::cout << "Usuario: ";
    std::getline(std::cin, usuario);
    std::cout << "Contraseña: ";
    std::getline(std::cin, contrasena);

    std::string servicioC = cifrarDescifrar(servicio);
    std::string usuarioC = cifrarDescifrar(usuario);
    std::string contrasenaC = cifrarDescifrar(contrasena);

    std::ofstream archivo("data/passwords.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << servicioC << "|" << usuarioC << "|" << contrasenaC << "\n";
        archivo.close();
        std::cout << "Cuenta guardada con éxito.\n";
    } else {
        std::cout << "Error al abrir el archivo.\n";
    }
}

void Cuenta::listarServicios() {
    std::ifstream archivo("data/passwords.txt");
    if (!archivo.is_open()) {
        std::cout << "No hay cuentas guardadas.\n";
        return;
    }

    std::string linea;
    int contador = 0;
    while (std::getline(archivo, linea)) {
        auto partes = split(linea, '|');
        if (partes.size() == 3) {
            std::string servicio = cifrarDescifrar(partes[0]);
            std::cout << ++contador << ". " << servicio << "\n";
        }
    }

    if (contador == 0) {
        std::cout << "No hay cuentas guardadas.\n";
    }

    archivo.close();
}

void Cuenta::mostrarContrasena() {
    std::string servicioBuscado;
    std::cout << "Introduce el nombre del servicio para mostrar la contraseña: ";
    std::cin.ignore();
    std::getline(std::cin, servicioBuscado);
    servicioBuscado = toLower(servicioBuscado);

    std::ifstream archivo("data/passwords.txt");
    if (!archivo.is_open()) {
        std::cout << "No hay cuentas guardadas.\n";
        return;
    }

    std::string linea;
    bool encontrado = false;
    while (std::getline(archivo, linea)) {
        auto partes = split(linea, '|');
        if (partes.size() == 3) {
            std::string servicio = cifrarDescifrar(partes[0]);
            std::string servicioLower = toLower(servicio);

            // DEBUG para verificar coincidencias
            std::cout << "[DEBUG] Comparando con: " << servicio << std::endl;

            if (servicioLower == servicioBuscado) {
                std::string usuario = cifrarDescifrar(partes[1]);
                std::string contrasena = cifrarDescifrar(partes[2]);
                std::cout << "\n--- Detalles del servicio ---\n";
                std::cout << "Servicio: " << servicio << "\n";
                std::cout << "Usuario: " << usuario << "\n";
                std::cout << "Contraseña: " << contrasena << "\n";
                encontrado = true;
                break;
            }
        }
    }

    if (!encontrado) {
        std::cout << "Servicio no encontrado.\n";
    }

    archivo.close();
}
