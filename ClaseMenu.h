/******************************************************************************************/
/*                                      TPO2 DPOO                                         */
/*  ALUMNO: Damian del Campo                                                              */
/*  LU: 1027477                                                                           */
/*  CARRERA: Ingenieria en Telecomunicaciones                                             */
/*  FECHA: 28/11/2015                                                                     */
/*  ARCHIVO: ClaseMenu.h                                                                  */
/*                                                                                        */
/******************************************************************************************/
#ifndef _CLASEMENU_H_INCLUDED_
#define _CLASEMENU_H_INCLUDED_
#include "ClaseImagen.h"

class  Menu {
private:
	//Atributos Privados

public:
	//Metodos y Atributos Publicos
	int op_r, op_c, op_w, op_h, op_o, op_s, op_D, op_C, op_m;
	complejo resolucion, centro, semilla;
	float imageWidth, imageHeight;
	char name[128];
	int intensidadPixel, tamCache, cantDig;

	int menuPpal(void);
	int FunctionR(void);
	int Function_c(void);
	int FunctionH(void);
	int FunctionW(void);
	int FunctionO(void);
	int FunctionS(void);
	int FunctionD(void);
	int FunctionC(void);
	int FunctionM(void);
	void SeteoValDefault(void);
	bool PaseArgumentosMain(int, char *[]);
};
#endif