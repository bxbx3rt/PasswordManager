#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "sha256.h"
#include "Gestor.h"
#include <string>

using namespace std;
void Gestor::configuracionInicial(string a, string b) {
	
    string hash = sha256(b);

    system("mkdir data");
    
    ofstream archivo("data/user_data.txt");
    if (archivo.is_open()){
        archivo << "Usuario: " << a << "\n";
        archivo << "Hash: " << hash << "\n";

        archivo.close();
        cout << "Registro exitoso. \n";
    }else
    cout << "Error al crear el archivo.";
}

bool Gestor::loginUsuario(std::string& hashSalida) {
    std::ifstream archivo("data/user_data.txt");
    if (!archivo.is_open()) {
        std::cout << "No hay usuario registrado. Regístrate primero.\n";
        return false;
    }

    std::string linea, usuarioGuardado, hashGuardado;

    if (std::getline(archivo, linea)) {
        if (linea.substr(0, 7) == "Usuario")
            usuarioGuardado = linea.substr(7);
    }

    if (std::getline(archivo, linea)) {
        if (linea.substr(0, 4) == "Hash")
            hashGuardado = linea.substr(4);
    }

    archivo.close();

    std::string usuarioInput, contrasenaInput;
    std::cout << "Usuario: ";
    std::cin >> usuarioInput;
    std::cout << "Contraseña: ";
    std::cin.ignore();
    std::getline(std::cin, contrasenaInput);

    std::string hashInput = sha256(contrasenaInput);

    if (usuarioInput == usuarioGuardado && hashInput == hashGuardado) {
        std::cout << "Login correcto.\n";
        hashSalida = hashInput;
        return true;
    } else {
        std::cout << "Usuario o contraseña incorrectos.\n";
        return false;
    }
}



