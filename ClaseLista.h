/******************************************************************************************/
/*                                      TPO2 DPOO                                         */
/*  ALUMNO: Damian del Campo                                                              */
/*  LU: 1027477                                                                           */
/*  CARRERA: Ingenieria en Telecomunicaciones                                             */
/*  FECHA: 28/11/2015                                                                     */
/*  ARCHIVO: ClaseLista.h                                                                 */
/*                                                                                        */
/******************************************************************************************/
#ifndef _CLASELISTA_H_INCLUDED_
#define _CLASELISTA_H_INCLUDED_
#include "ClaseNodo.h"
#include  <cmath>   

//Declaracion de Lista Doblemente enlazada
class lista {
public:
	lista();
	~lista();
	void AltaPpio(const complejo&, const int); //por referencia
	void AltaFin(const complejo&, const int);
	void BajaPpio();
	void BajaFin();
	void PrintLista();
	void EliminoNodo();
	void SetListaMaxTam(int);
	bool Vacia()const;
	bool Llena()const;
	bool ExisteDato(const complejo&, const int); //existe este dato?? (es lo que se pregunta la funcion)
	bool cmp(complejo, complejo, int); //Comparo complejo vs complejo con precision cant d digitos decimales
	int CuentaNodos()const; //que me mantenga constante lo que va a procesar
							//void Emitir()const; //NO se para que era este metodo
	//int getIntNodo();
	int p_; //intensidad del pixel
private:
	nodo *Ppio; //Puntero al primer nodo de la lista
	nodo *Fin; //Puntero al ultimo nodo de la lista
	int tam_lista;
	int max_tam_lista; //Tamaño maximo de la lista
};
#endif