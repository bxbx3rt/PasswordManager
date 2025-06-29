#ifndef GESTOR_H
#define GESTOR_H
#include <string>
class Gestor{
private: 
std::string user;
std::string psswd;

public: 
Gestor(){
    // Constructor can initialize member variables if needed
    user = "";
    psswd = "";
}
Gestor(const std::string& usuario, const std::string& contrasena) {
    user = usuario;
    psswd = contrasena;
}
void configuracionInicial(std::string, std::string);
bool loginUsuario(std::string& hashSalida);

};
#endif

