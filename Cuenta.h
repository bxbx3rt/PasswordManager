#ifndef CUENTA_H
#define CUENTA_H

#include <string>
#include <vector>

class Cuenta {
public:
    Cuenta(const std::string& claveCifrado);

    void agregarCuenta();
    void listarServicios();
    void mostrarContrasena();

private:
    std::string clave; // clave para cifrado
    std::string toLower(const std::string& str);

    std::string cifrarDescifrar(const std::string& texto);
    std::vector<std::string> split(const std::string& s, char delim);
};

#endif
