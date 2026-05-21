#ifndef PROGRA_III_PERSONA_H
#define PROGRA_III_PERSONA_H
#include <iostream>
using namespace std;

class Persona {
    public:
        //
        // Tipos de constructores
        //

        Persona() = default; //Constructor por default
        Persona(const string& name, const string& apellido); // Constructor por parametros
        Persona(const Persona& persona); // constructor copia (Semantica de Copia)
        Persona(Persona&& persona) noexcept; // Constroctur move
        Persona& operator=(const Persona& persona); //Operador asignacion
        Persona& operator=(Persona&& persona) noexcept; //Operador asignacion move

        ~Persona(); //Destructor
        string getName() const;
        string getApellido() const;

    private:
        string name;
        string apellido;
    };


#endif //PROGRA_III_PERSONA_H