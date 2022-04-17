/******************************************************************************************/
/*                                      TPO2 DPOO                                         */
/*  ALUMNO: Damian del Campo                                                              */
/*  LU: 1027477                                                                           */
/*  CARRERA: Ingenieria en Telecomunicaciones                                             */
/*  FECHA: 28/11/2015                                                                     */
/*  ARCHIVO: ClaseNodo.h                                                                  */
/*                                                                                        */
/******************************************************************************************/
#ifndef _CLASENODO_H_INCLUDED_
#define _CLASENODO_H_INCLUDED_
#include <iostream>
#include "ClaseComplejo.h"
using namespace std;

class nodo {
private:
public:
	nodo();
	nodo(const complejo &, bool, bool,int);
	nodo(const nodo &);
	~nodo();
	void PrintNodo();
	complejo pixel;
	nodo *next;
	nodo *prev;
	bool Break;
	bool Hit;
	int cantIter; //Cantidad de Iteraciones
};
#endif