/******************************************************************************************/
/*                                      TPO2 DPOO                                         */
/*  ALUMNO: Damian del Campo                                                              */
/*  LU: 1027477                                                                           */
/*  CARRERA: Ingenieria en Telecomunicaciones                                             */
/*  FECHA: 28/11/2015                                                                     */
/*  ARCHIVO: Main.cpp                                                                     */
/*                                                                                        */
/******************************************************************************************/

#include "ClaseMenu.h"
#include "ClaseLista.h"
#include "ClaseImagen.h"


int main(int argc, char *argv[])
{
	Menu I;
	if (I.PaseArgumentosMain(argc, argv)) I.menuPpal();
	IMG_PGM imagen(I.resolucion, I.centro, I.imageWidth, I.imageHeight, I.name, I.intensidadPixel, I.cantDig, I.tamCache, I.semilla);
	imagen.Set_Imagen();
	
	system("PAUSE");
	return 0;
}
