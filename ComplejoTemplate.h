/*
 * ComplejoTemplate.h
 *
 *  Created on: 19/04/2019
 *      Author: Matías López
 */

#ifndef COMPLEJOTEMPLATE_H_
#define COMPLEJOTEMPLATE_H_

#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;

enum{ERROR_DIVISION_CERO, ERROR_ARCHIVO_ENTRADA,ERROR_ARCHIVO_SALIDA,ERROR_FORMATO};

template <class T>
class Complejo
{
	private:
		T real;
		T imag;
	    T modulo;
		T faseGrados;
		// Representaciones
		void ModuloFase(Complejo<T>&);
		void RealImag(Complejo<T>&);
	public:
		// Constructores
		Complejo(void);
		Complejo(const T&, const T im=0.0);
		Complejo(const Complejo<T>&);
		// SetThings
		void SetData(const T re, const T im);
		void SetData(const Complejo<T> c);
		void SetReal(const T);
		void SetImag(const T);
		void SetModuloFase(const T, const T);
		void SetModulo(const T);
		void SetFase(const T);
		// GetThings
		T GetReal(void) const{return real;}
		T GetImag(void) const{return imag;}
		T GetModulo(void) const{return modulo;}
		T GetFaseGrados(void) const{return faseGrados;}
		// Sobrecarga de operadores aritmeticos
		Complejo<T> operator+ (const Complejo<T>&);
		Complejo<T> operator+ (const T&);
		Complejo<T> operator- (const Complejo<T>&);
		Complejo<T> operator- (const T&);
		Complejo<T> operator* (const Complejo<T>&);
		Complejo<T> operator* (const T&);
		Complejo<T> operator/ (const Complejo<T>&);
		Complejo<T> operator/ (const T&);
		// Sobrecarga del operador de asignacion
		void operator= (const Complejo<T>&);
		void operator= (const T&);
		// Sobrecarga de operadores aritmeticos-asignacion
		void operator+= (const Complejo<T>&);
		void operator+= (const T&);
		void operator-= (const Complejo<T>&);
		void operator-= (const T&);
		void operator*= (const Complejo<T>&);
		void operator*= (const T&);
		void operator/= (const Complejo<T>&);
		void operator/= (const T&);
		// Sobrecarga de operadores de comparacion
		bool operator== (const Complejo<T>&)const;
		bool operator!= (const Complejo<T>&)const;
		bool operator<  (const Complejo<T>&)const;
		bool operator<= (const Complejo<T>&)const;
		bool operator>  (const Complejo<T>&)const;
		bool operator>= (const Complejo<T>&)const;
		// Conjugado
		Complejo<T> Conjugado(void);
		// Sobrecarga del operador de insercion en el flujo de salida
		template <class Z>
		friend ofstream& operator<<(ofstream&,const Complejo<Z>&);
		template <class Z>
		friend ostream& operator<< (ostream&, const Complejo<Z>&);
		// Sobrecarga del operador de insercion en el flujo de entrada
		template <class Z>
		friend istream& operator>> (istream&, Complejo<Z>&);
		template <class Z>
		friend ifstream& operator>>(ifstream&, Complejo<Z>&);
};

// Constructores
template <class T>
Complejo<T>::Complejo(void)
{
	real = 0.0;
	imag = 0.0;
	modulo = 0.0;
	faseGrados = 0.0;
}
template <class T>
Complejo<T>::Complejo(const T& re, const T im)
{
	real = re;
	imag = im;
	ModuloFase(*this);
}
template <class T>
Complejo<T>::Complejo(const Complejo<T>& c)
{
	this->real = c.real;
	this->imag = c.imag;
	this->modulo=c.modulo;
	this->faseGrados=c.faseGrados;
}

// Representaciones
template <class T>
void Complejo<T>::ModuloFase(Complejo<T>& c)
{
	c.modulo = sqrt(pow(c.real,2) + pow(c.imag,2));
	c.faseGrados = ((atan2(c.imag,c.real))*180)/M_PI;
}
template <class T>
void Complejo<T>::RealImag(Complejo<T>& c)
{
	c.imag = c.modulo * sin((c.faseGrados*M_PI)/180);
	c.real = c.modulo * cos((c.faseGrados*M_PI)/180);
}

// SetThings
template <class T>
void Complejo<T>::SetData(const T re, const T im )
{
	real = re;
	imag = im;
	ModuloFase(*this);
}
template <class T>
void Complejo<T>::SetData(const Complejo<T> c)
{
	*this = c;
}
template <class T>
void Complejo<T>::SetReal(const T re)
{
	real = re;
	ModuloFase(*this);
}
template <class T>
void Complejo<T>::SetImag(const T im)
{
	imag = im;
	ModuloFase(*this);
}
template <class T>
void Complejo<T>::SetModuloFase(const T mod, const T fase)
{
	modulo = mod;
	faseGrados = fase;
	RealImag(*this);
}
template <class T>
void Complejo<T>::SetModulo(const T mod)
{
	modulo = mod;
	RealImag(*this);
}
template <class T>
void Complejo<T>::SetFase(const T fase)
{
	faseGrados= fase;
	RealImag(*this);
}

// Sobrecarga de operadores aritmeticos
template <class T>
Complejo<T> Complejo<T>::operator+ (const Complejo<T> &a)
{
	Complejo<T> suma;
	suma.real = real + a.real;
	suma.imag = imag + a.imag;
	ModuloFase(suma);
	return suma;
}
template <class T>
Complejo<T> Complejo<T>::operator+ (const T &re)
{
	Complejo<T> suma;
	suma.real = real + re;
	suma.imag = imag;
	ModuloFase(suma);
	return suma;
}
template <class T>
Complejo<T> Complejo<T>::operator- (const Complejo<T> &a)
{
	Complejo<T> resta;
	resta.real = real - a.real;
	resta.imag = imag - a.imag;
	ModuloFase(resta);
	return resta;
}
template <class T>
Complejo<T> Complejo<T>::operator- (const T &re)
{
	Complejo<T> resta;
	resta.real = real - re;
	resta.imag = imag;
	ModuloFase(resta);
	return resta;
}
template <class T>
Complejo<T> Complejo<T>::operator* (const Complejo<T> &c6)
{
	Complejo multiplicacion;
	multiplicacion.real = real * c6.real - imag * c6.imag;
	multiplicacion.imag = real * c6.imag + c6.real * imag;
	ModuloFase(multiplicacion);
	return multiplicacion;
}
template <class T>
Complejo<T> Complejo<T>::operator* (const T &re)
{
	Complejo<T> multiplicacion;
	multiplicacion.real = real * re;
	multiplicacion.imag = imag * re;
	ModuloFase(multiplicacion);
	return multiplicacion;
}
template <class T>
Complejo<T> Complejo<T>::operator/ (const Complejo<T> &c)
{
	if((pow(c.real,2) + pow(c.imag,2))==0)
	{
		throw(int(ERROR_DIVISION_CERO));
	}
	Complejo division;
	division.real = ((real * c.real) + (imag * c.imag)) / (pow(c.real,2) + pow(c.imag,2));
	division.imag = (( - real * c.imag) + (imag * c.real)) / (pow(c.real,2) + pow(c.imag,2));
	ModuloFase(division);
	return division;
}
template <class T>
Complejo<T> Complejo<T>::operator/ (const T &re)
{
	if(re==0)
	{
		throw(int(ERROR_DIVISION_CERO));
	}
	Complejo<T> division;
	division.real = real / re;
	division.imag = imag / re;
	ModuloFase(division);
	return division;
}

// Sobrecarga de operadores aritmeticos-asignacion
template <class T>
void Complejo<T>::operator+= (const Complejo<T> &c)
{
	real += c.real;
	imag += c.imag;
	ModuloFase(*this);
}
template <class T>
void Complejo<T>::operator+= (const T& re)
{
	real += re;
	ModuloFase(*this);
}
template <class T>
void Complejo<T>::operator-= (const Complejo<T> &c)
{
	real -= c.real;
	imag -= c.imag;
	ModuloFase(*this);
}
template <class T>
void Complejo<T>::operator-= (const T& re)
{
	real -= re;
	ModuloFase(*this);
}
template <class T>
void Complejo<T>::operator*= (const Complejo<T> &c)
{
	Complejo<T> multiplicacion;
	multiplicacion.real = real * c.real - imag * c.imag;
	multiplicacion.imag = real * c.imag + c.real * imag;
	ModuloFase(multiplicacion);
	*this = multiplicacion;
}
template <class T>
void Complejo<T>::operator*= (const T& re)
{
	real *= re;
	imag *= re;
	ModuloFase(*this);
}
template <class T>
void Complejo<T>::operator/= (const Complejo<T> &c)
{
	if((pow(c.real,2) + pow(c.imag,2))==0)
	{
		throw(int(ERROR_DIVISION_CERO));
	}
	Complejo<T> division;
	division.real = ((real * c.real) + (imag * c.imag)) / (pow(c.real,2) + pow(c.imag,2));
	division.imag = (( - real * c.imag) + (imag * c.real)) / (pow(c.real,2) + pow(c.imag,2));
	ModuloFase(division);
	*this = division;
}
template <class T>
void Complejo<T>::operator/= (const T& re)
{
	if(re==0)
	{
		throw(int(ERROR_DIVISION_CERO));
	}
	real /= re;
	imag /= re;
	ModuloFase(*this);
}

// Sobrecarga del operador de asignacion
template <class T>
void Complejo<T>::operator= (const Complejo<T>& a)
{
    real = a.real;
	imag = a.imag;
	ModuloFase(*this);
}
template <class T>
void Complejo<T>::operator= (const T& re)
{
    real = re;
	ModuloFase(*this);
}

// Sobrecarga de operadores de comparacion
template <class T>
bool Complejo<T>::operator== (const Complejo<T>& c2)const
{
	return((real == c2.real)&&(imag == c2.imag));
}
template <class T>
bool Complejo<T>::operator!= (const Complejo<T>& c2)const
{
	return((real != c2.real)||(imag != c2.imag));
}
template <class T>
bool Complejo<T>::operator< (const Complejo<T>& a2)const
{
	return(modulo < a2.modulo);
}
template <class T>
bool Complejo<T>::operator<= (const Complejo<T>& a2)const
{
	return(modulo <= a2.modulo);
}
template <class T>
bool Complejo<T>::operator> (const Complejo<T>& a2)const
{
	return(modulo > a2.modulo);
}
template <class T>
bool Complejo<T>::operator>= (const Complejo<T>& a2)const
{
	return(modulo >= a2.modulo);
}

//Conjugado
template <class T>
Complejo<T> Complejo<T>::Conjugado(void)
{
	imag = -imag;
	ModuloFase(*this);
	return *this;
}

// Sobrecarga del operador de insercion en el flujo de salida
template <class T>
ostream& operator<< (ostream& os, const Complejo<T>& c1)
{
	os << "(" <<  c1.real << ", " << c1.imag << ") -----> ";
	os << "Modulo= " <<  c1.modulo << " | Fase= " << c1.faseGrados << "°";
	return os;
}
template <class T>
ofstream& operator<<(ofstream& os,const Complejo<T>& c1)
{
	os << "(" << c1.real << "," << c1.imag << ") -----> ";
	os << "Modulo= " <<  c1.modulo << " | Fase= " << c1.faseGrados << "°";
	return os;
}

// Sobrecarga del operador de insercion en el flujo de entrada
template <class T>
istream& operator>> (istream& is, Complejo<T>& c1)
{
	char temp;
	is >> temp;
	if('(' != temp)
	{
		throw(int(ERROR_FORMATO));
	}
	is >> c1.real;
	is >> temp;
	if(',' != temp)
	{
		throw(int(ERROR_FORMATO));
	}
	is >> c1.imag;
	is >> temp;
	if(')' != temp)
	{
		throw(int(ERROR_FORMATO));
	}

	c1.ModuloFase(c1);
	return is;
}
template <class T>
ifstream& operator>>(ifstream& is, Complejo<T>& c1)
{
	char temp;
		is >> temp;
		if('(' != temp)
		{
			throw(int(ERROR_FORMATO));
		}
		is >> c1.real;
		is >> temp;
		if(',' != temp)
		{
			throw(int(ERROR_FORMATO));
		}
		is >> c1.imag;
		is >> temp;
		if(')' != temp)
		{
			throw(int(ERROR_FORMATO));
		}

		c1.ModuloFase(c1);
		return is;
}

#endif

// COMPLEJOTEMPLATE
