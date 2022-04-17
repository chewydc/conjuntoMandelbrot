/******************************************************************************************/
/*                                      TPO2 DPOO                                         */
/*  ALUMNO: Damian del Campo                                                              */
/*  LU: 1027477                                                                           */
/*  CARRERA: Ingenieria en Telecomunicaciones                                             */
/*  FECHA: 28/11/2015                                                                     */
/*  ARCHIVO: ClaseLista.cpp                                                               */
/*                                                                                        */
/******************************************************************************************/
#include "ClaseLista.h"

lista::lista() {
	Ppio = NULL;
	Fin = NULL;
	tam_lista = 0;
	max_tam_lista = 4;
}
lista::~lista() {}

void lista::AltaPpio(const complejo&dato, const int n) {
	if (!Llena()) {
		nodo *aux;
		aux = new nodo;
		aux->pixel = dato;
		aux->cantIter = n;
		aux->next = Ppio;
		aux->prev = NULL;
		if (Ppio) Ppio->prev = aux;
		Ppio = aux;
		tam_lista++;
	}
}

void lista::AltaFin(const complejo &dato, const int n) {
	if (!Llena()) {
		nodo *aux, *navegador;
		aux = new nodo;
		aux->pixel = dato;
		aux->cantIter = n;
		aux->next = NULL;
		if (Vacia()) {
			Ppio = aux;
			Ppio->prev = NULL;
		}
		else {
			navegador = Ppio;
			while ((navegador->next) != NULL)
				navegador = navegador->next;
			navegador->next = aux;
			aux->prev = navegador;
			tam_lista++;
		}
	}
}

void lista::BajaPpio()
{
	if (!Vacia()) {
		nodo *temp = Ppio;
		Ppio = Ppio->next;
		if (Ppio) Ppio->prev = NULL;
		tam_lista--;
	}
}
void lista::BajaFin() {

	if (!Vacia()) {						// Si la lista no esta vacia:
		nodo *aux = Ppio;				// Copio la referncia del nodo inial
		if (!Ppio->next) {				// Si la lista tiene un solo elemento:
			delete Ppio;				// lo borro
			Ppio = 0;					// y pongo el puntero inicial en cero
		}
		else {
			while ((aux->next) && (aux->next->next))	// mientras el nodo sgte y su consecutivo no
				aux = aux->next;						// sean cero , recorro la lista hasta el fin-1
			delete aux->next; 							// borro el nodo sgte al final-1
			aux->next = 0;								// se anula el puntero al siguiente.
		}
		tam_lista--;
	}
}

bool lista::ExisteDato(const complejo & data_,int presicion_) {
	nodo *temp = Ppio;
	if (Vacia()) return 0;
	else
	{
		while (temp)
		{
			if (cmp(temp->pixel, data_, presicion_)) {	//Si existe el dato, 
				p_=temp->cantIter;						//obtenfo el dato
				EliminoNodo();							//elimino el nodo 
				AltaPpio(temp->pixel, temp->cantIter);	//Guardo el nodo al inicio de la lista Cache
				return true;
			}
			temp = temp->next;
		}
		return false;
	}
}
bool lista::Vacia() const
{
	return (tam_lista == 0);
}
bool lista::Llena() const
{
	return (tam_lista == max_tam_lista);
}
int lista::CuentaNodos() const
{
	return tam_lista;
}

void lista::PrintLista()
{
	nodo *temp = Ppio;
	if (Vacia()) cout << "La Lista esta vacia " << endl;
	else {
		while (temp) {
			temp->PrintNodo();
			if (!temp->next) cout << "NULL ";
			temp = temp->next;
		}
	}
	cout << endl;
}

void lista::EliminoNodo() {
	if (Vacia() == true)return;
	if (Ppio->prev == 0)return;
	nodo * aux1, *aux2;
	aux1 = Ppio->prev;
	aux2 = Ppio->next;
	Ppio->next = 0;
	Ppio->prev = 0;
	if (aux1 == 0)return;
	aux1->next = aux2;
	if (aux2 == 0)return;
	aux2->prev = aux1;
	delete(Ppio);
	tam_lista--;
}
void lista::SetListaMaxTam(int max_size) {
	max_tam_lista = max_size;
}
//Funcion que compara dos numeros complejos con una tolerancia de n cant de digitos sig.
bool lista::cmp(complejo a, complejo b, int n) {
	float epsilon = pow(10, -n);
	if (fabs(a.re_ - b.re_) <= epsilon && fabs(a.im_ - b.im_) <= epsilon) return true;
	return false;
}