#include "Persona.h"


Persona::Persona(const string& name, const string& apellido):name(name),
apellido(apellido){}

Persona::Persona(const Persona &persona) {
    this->name = persona.name;
    this->apellido = persona.apellido;
}

Persona::Persona(Persona &&persona) noexcept {
    this->name = persona.name;
    this->apellido = persona.apellido;
}

Persona& Persona::operator=(const Persona &persona) {
    this->name = persona.name;
    this->apellido = persona.apellido;
    return *this;
}

Persona& Persona::operator=(Persona &&persona) noexcept {
    this->name = persona.name;
    this->apellido = persona.apellido;
    return *this;
}

Persona::~Persona() = default;

string Persona::getName() const {
    return this->name;
}
string Persona::getApellido() const{
    return this->apellido;
}