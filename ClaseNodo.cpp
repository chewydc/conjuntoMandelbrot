/******************************************************************************************/
/*                                      TPO2 DPOO                                         */
/*  ALUMNO: Damian del Campo                                                              */
/*  LU: 1027477                                                                           */
/*  CARRERA: Ingenieria en Telecomunicaciones                                             */
/*  FECHA: 28/11/2015                                                                     */
/*  ARCHIVO: ClaseNodo.cpp                                                                */
/*                                                                                        */
/******************************************************************************************/
#include "ClaseNodo.h"

//Constructor por defecto
nodo::nodo() {
	pixel.re_ = NULL;
	pixel.im_ = NULL;
	next = NULL;
	prev = NULL;
	Break = false;
	Hit = false;
	cantIter = 0;
}
//Constructor por pase de arg
nodo::nodo(const complejo &dato, bool b, bool h,int f) {
	pixel = dato;
	next = NULL;
	prev = NULL;
	Break= b;
	Hit = h;
	cantIter = f;
}
//Constructor por copia
nodo::nodo(const nodo &n) {
	pixel = n.pixel;
	next = n.next;
	prev = n.prev;
	Break = n.Break;
	Hit = n.Hit;
	cantIter = n.cantIter;
}
nodo::~nodo() {}
// Imprimir un Nodo
void nodo::PrintNodo()
{
	cout << "Nodo-> " << "Dato: " << pixel << " Direcion: " << this << " Prev: " << prev << " Next: " << next << endl;
}