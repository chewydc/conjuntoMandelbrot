/******************************************************************************************/
/*                                      TPO2 DPOO                                         */
/*  ALUMNO: Damian del Campo                                                              */
/*  LU: 1027477                                                                           */
/*  CARRERA: Ingenieria en Telecomunicaciones                                             */
/*  FECHA: 28/11/2015                                                                     */
/*  ARCHIVO: ClaseComplejo.h                                                              */
/*                                                                                        */
/******************************************************************************************/
#ifndef _CLASECOMPLEJO_H_INCLUDED_
#define _CLASECOMPLEJO_H_INCLUDED_

#include <iostream>
using namespace std;

class  complejo {
private:
	//Atributos Privados

public:
	//Metodos y Atributos Publicos
	float re_, im_;
	complejo();
	complejo(float, float);
	complejo(const complejo&);
	~complejo();
	float m2() const;
	float Re() const;
	float Im() const;
	complejo const &conjugar();
	complejo const conjugado() const;
	complejo const &operator=(complejo const &);
	bool    complejo::operator ==(const complejo &);
	friend complejo const operator+(const complejo &, const complejo &);
	friend complejo const operator-(const complejo &, const complejo &);
	friend complejo const operator*(const complejo &, const complejo &);
	friend complejo const operator/(const complejo &, const complejo &);
	friend complejo const operator/(const complejo &, float const &);

	friend std::ostream &operator<<(std::ostream &, const complejo &);
	friend std::istream &operator>>(std::istream &, complejo &);
};
#endif