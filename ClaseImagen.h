/******************************************************************************************/
/*                                      TPO2 DPOO                                         */
/*  ALUMNO: Damian del Campo                                                              */
/*  LU: 1027477                                                                           */
/*  CARRERA: Ingenieria en Telecomunicaciones                                             */
/*  FECHA: 28/11/2015                                                                     */
/*  ARCHIVO: ClaseImagen.h                                                                */
/*                                                                                        */
/******************************************************************************************/
#ifndef _CLASEIMAGEN_H_INCLUDED_
#define _CLASEIMAGEN_H_INCLUDED_

#include "ClaseComplejo.h"
#include "ClaseLista.h"
#include <fstream>
#include <iostream>
#include <cstring>
#pragma warning(disable:4996)
#pragma warning(disable:4244)
using namespace std;

class  IMG_PGM {
private:
	//Atributos Privados

public:
	//Metodos y Atributos Publicos
	float imageWidth, imageHeight;
	complejo pixel;
	complejo resolucion, centro, semilla;
	int intensidadPixel, tamCache, cantDig;
	char name[128];

	IMG_PGM();
	IMG_PGM(complejo, complejo, float, float, char[128], int, int, int, complejo);
	~IMG_PGM();
	void Set_Imagen(void);
	int findMandelbrot(void);
	void copiaNombre(char[128], char[128]);
//	bool cmp(complejo,complejo,int);

};
#endif