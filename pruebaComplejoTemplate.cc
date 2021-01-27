/*
 * pruebaComplejoTemplate.cc
 *
 *  Created on: 19/04/2019
 *      Author: Matías López
 */
#include "ComplejoTemplate.h"
#include <list>
using namespace std;

template <class T>
void pruebaComplejoTemplate()
{
	//Constructores
	Complejo<T> c1(4.0); //se genera el complejo. Paso Parte real y la imag toma cero por defecto.
	Complejo<T> c2(c1); //se genera un nuevo complejo, copia del c1.
	Complejo<T> c3(-1.0, 2.7);//se genera el complejo con parte real e imaginaria.
	cout << "Generacion de complejos:\nc1= " << c1 << endl << "c2= " << c2 << endl << "c3= " << c3 << endl;

	//Sobrecarga del operador >>
	cout << "\nSobrecarga del operador >>:\n";
	Complejo<T> c6;
	cout <<"Ingresar Valores del nuevo complejo:" << endl;
	cin >> c6;// se le asigna el valor por teclado. Sobrecarga de operador >>
	cout << "c6= " << c6 << endl;

	//Conjugado
	cout << "\nConjugado:\n" << "El Conjugado de c6= " << c6.Conjugado() << endl;

	// Sobrecarga de operadores aritmeticos.
	T f(2.5);
	Complejo<T> c4 = c1 + c2 + c3;// sobrecarga del operador suma con un complejo.
	Complejo<T> c5 = c3 + f;// sobrecarga del operador suma con un doble.
	Complejo<T> c7 = c1 - c2;// sobrecarga del operador resta con un complejo.
	Complejo<T> c8 = c1 - f;// sobrecarga del operador resta con un doble.
	Complejo<T> c9 = c1 * c6;// sobrecarga del operador multiplicacion con un complejo.
	Complejo<T> c10 = c1 * f;// sobrecarga del operador multiplicacion con un double.
	Complejo<T> c11 = c9 / c1;// sobrecarga del operador division con un complejo.
	Complejo<T> c12 = c9 / f;// sobrecarga del operador division con un double.
	cout << "\nSobrecarga de operadores aritmeticos:\n" << "c4 = c1 + c2 + c3 = " << c4 << endl << "c5 = c3 + f = "
	<< c5 << endl << "c7 = c1 - c2 = " << c7 << endl << "c8 = c1 - f = " << c8 << endl << "c9 = c1 * c6 = " << c9 << endl
	<< "c10 = c1 * f = " << c10 << endl << "c11 = c9 / c1 = " << c11 << endl << "c12 = c9 / f = " << c12 << endl ;

	// Sobrecarga de operadores aritmeticos y asignacion.
	c6 += c2;// sobrecarga del operador suma con un complejo.
	c7 += f;// sobrecarga del operador suma con un doble.
	c8 -= c5;// sobrecarga del operador resta con un complejo.
	c9 -= f;// sobrecarga del operador resta con un doble.
	c10 *= c6;// sobrecarga del operador multiplicacion con un complejo.
	c11 *= f;// sobrecarga del operador multiplicacion con un double.
	c12 /= c11;// sobrecarga del operador division con un complejo.
	Complejo<T> c13(1.0,-1.0);
	c13 /= f;// sobrecarga del operador division con un double.
	cout << "\nSobrecarga de operadores aritmeticos y asignacion:\n" << "c6 += c2 => " << c6 << endl
	<< "c7 += f => " << c7 << endl << "c8 -= c5 => " << c8 << endl << "c9 -= f => " << c9 << endl << "c10 *= c6 => " << c10 << endl
	<< "c11 *= f => " << c11 << endl << "c12 /= c11 => " << c12 << endl << "c13 /= f => " << c13 << endl ;

	//Sobrecarga del operador asignacion
	Complejo<T> c14;
	c14 = c6;
	Complejo<T> c15;
	c15 = f;
	cout << "\nSobrecarga de operadores de asignacion:\n" << "c14 = c6 => "<< c14 << endl << "c15 = f => " << c15 << endl;

	// Sobrecarga de operadores de comparacion
	cout << "\nSobrecarga de operadores de comparacion:\n";
	if(c2 == c1)
	{
		cout << "c1 y c2 son iguales" << endl;
	}
	if(c1 != c5)
	{
		cout <<  "c1 y c5 son distintos" << endl;
	}
	if(c1 < c4)
	{
		cout <<  "c1 es menor que c4" << endl;
	}
	if(c1 <= c2)
	{
		cout <<  "c1 es menor o igual a c2" << endl;
	}
	if(c1 > c3)
	{
		cout <<  "c1 es mayor que c3" << endl;
	}
	if(c1 >= c2)
	{
		cout <<  "c1 es mayor o igual que c2" << endl;
	}

	//Prueba de los Sets.
	cout << "\nPrueba de los sets:\n" ;
	c8.SetData(1.6,1.6);
	cout << "c8= " << c8 << endl;
	c8.SetData(c3);
	cout << "c8= " << c8 << endl;
	c8.SetReal(4.0);
	cout << "c8= " << c8 << endl;
	c8.SetImag(4.0);
	cout << "c8= " << c8 << endl;
	c8.SetModuloFase(4.0,15);
	cout << "c8= " << c8 << endl;
	c8.SetModulo(2);
	cout << "c8= " << c8 << endl;
	c8.SetFase(45);
	cout << "c8= " << c8 << endl;

	//Manejo Archivos
	cout << "\nArchivos:";
	ifstream ifs("Archivo.txt");
	if( !ifs )
	{
		throw( int(ERROR_ARCHIVO_ENTRADA));
	}
	Complejo<T> c16;
	ifs >> c16;
	cout << "\nComplejo recibido desde el archivo c16= " << c16;
	ofstream ofs("archModif.txt");
	if( !ofs )
	{
		throw( int(ERROR_ARCHIVO_SALIDA));
	}
	ofs << c6;
}

int main( int argc, char **argv )
{
	try
	{
		pruebaComplejoTemplate<double>();
	}
	catch(int e)
	{
		switch (e)
		{
		case (int(ERROR_DIVISION_CERO)):
		cout << "Error en la division. El divisor vale cero.";
		break;
		case (int(ERROR_ARCHIVO_ENTRADA)):
		cout << "Error al abrir archivo de entrada";
		break;
		case (int(ERROR_ARCHIVO_SALIDA)):
		cout << "Error al abrir archivo de salida";
		break;
		case (int(ERROR_FORMATO)):
		cout << "Error en el formato del complejo";
		break;
		}
	}
return 0;
}


