#include <iostream>  
#include <string>  
#include <vector>  
using namespace std;  

class Alumno {  
private:  
    string nombre;  
    double nota1;  
    double nota2;  
    double nota3;  
    int edad;  
    string estado;  

    void actualizarEstado() {  
        double promedio = calcularPromedio();  
        estado = (promedio >= 7) ? "Aprobado" : "Desaprobado";  
    }  

public:  
    Alumno(string nombre, double nota1, double nota2, double nota3, int edad)  
    : nombre(nombre), nota1(nota1), nota2(nota2), nota3(nota3), edad(edad) {  
        actualizarEstado();  
    }  
    string getNombre() const { return nombre; }  
    double getNota1() const { return nota1; }  
    double getNota2() const { return nota2; }  
    double getNota3() const { return nota3; }  
    int getEdad() const { return edad; }  
    string getEstado() const { return estado; }  
    double calcularPromedio() const { return (nota1 + nota2 + nota3) / 3; }  
};  
int main() {  
    vector<Alumno> alumnos;  
    string nombre;  
    double nota1, nota2, nota3;  
    int edad, numAlumnos;  

    cout << "Ingrese el número de alumnos: ";  
    cin >> numAlumnos;  

    for (int i = 0; i < numAlumnos; i++) {  
        cout << "Ingrese el nombre del alumno: ";  
        cin >> nombre;  
        cout << "Ingrese la nota 1 del alumno: ";  
        cin >> nota1;  
        cout << "Ingrese la nota 2 del alumno: ";  
        cin >> nota2;  
        cout << "Ingrese la nota 3 del alumno: ";  
        cin >> nota3;  
        cout << "Ingrese la edad del alumno: ";  
        cin >> edad;  
        alumnos.push_back(Alumno(nombre, nota1, nota2, nota3, edad));  
    }  
    cout << "Ingrese el nombre del alumno a buscar: ";  
    string nombreBuscado;  
    cin >> nombreBuscado;  
    bool encontrado = false;  

    for (const auto& alumno : alumnos) {  
        if (alumno.getNombre() == nombreBuscado) {  
            encontrado = true;  
            cout << "Alumno encontrado: " << alumno.getNombre() << endl;  
            cout << "Edad: " << alumno.getEdad() << endl;  
            cout << "Notas: " << alumno.getNota1() << ", " << alumno.getNota2() << ", " << alumno.getNota3() << endl;  
            cout << "Promedio: " << alumno.calcularPromedio() << endl;  
            cout << "Estado: " << alumno.getEstado() << endl;  
            break;  
        }  
    }  
    if (!encontrado) {  
        cout << "Alumno no encontrado." << endl;  
    }  
    return 0;  
}
