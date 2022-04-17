/******************************************************************************************/
/*                                      TPO2 DPOO                                         */
/*  ALUMNO: Damian del Campo                                                              */
/*  LU: 1027477                                                                           */
/*  CARRERA: Ingenieria en Telecomunicaciones                                             */
/*  FECHA: 28/11/2015                                                                     */
/*  ARCHIVO: ClasePGM.cpp                                                                 */
/*                                                                                        */
/******************************************************************************************/
#include "ClaseImagen.h"

//Constructor por defecto
IMG_PGM::IMG_PGM()
{
	imageWidth = 4;
	imageHeight = 4;
	intensidadPixel = 255;
	char temp[128] = "out.pgm";
	copiaNombre(temp, name);
	resolucion.re_ = 640;
	resolucion.im_ = 480;
	centro.re_ = 0;
	centro.im_ = 0;
	pixel.re_ = 0;
	pixel.im_ = 0;
	cantDig = 3;
	tamCache = 0;
	semilla.re_ = -0.7;		//JuliaSet
	semilla.im_ = 0.29015;	//JuliaSet
}

//Constructor por paso de parametros 
IMG_PGM::IMG_PGM(complejo r, complejo c, float w, float h, char temp[128], int p, int Dig, int Cache, complejo s)
{
	intensidadPixel = p;
	pixel.re_ = 0;
	pixel.im_ = 0;
	imageWidth = w;
	imageHeight = h;
	resolucion = r;
	centro = c;
	copiaNombre(temp, name);
	cantDig = Dig;
	tamCache = Cache;
	semilla = s;
}
//Destructor 
IMG_PGM::~IMG_PGM() {}

//Metodo casero para copiar cadenas de caracteres (origen, destino)
void IMG_PGM::copiaNombre(char src[128], char dest[128])
{
	int i = 0;
	while (src[i] != 0) {
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0x00;
}

//Funcion que arma la imagen en formato PGM escala de grises
void IMG_PGM::Set_Imagen(void)
{
	cout << "Nombre Archivo: " << name << endl;
	cout << "Resolucion: " << resolucion << endl;
	cout << "Pos. Centro: " << centro << endl;
	cout << "Intensidad del Pixel: " << intensidadPixel << endl;
	cout << "Ancho: " << imageWidth << endl;
	cout << "Alto: " << imageHeight << endl;
	cout << "Cant digitos: " << cantDig << endl;
	cout << "Tamano Cache: " << tamCache << endl;
	cout << "Semilla: " << semilla << endl;
	cout << "Aplicando configuracion, por favor espere..." << endl;

	ofstream fout(name);
	fout << "P2" << endl;
	fout << resolucion.re_ << " " << resolucion.im_ << endl;
	fout << "# Imagen Mandelbrot en centro: " << centro << ", con ancho de: " << imageWidth << " y alto de " << imageHeight << endl;
	fout << intensidadPixel << endl;
	
	lista Cache; //Armo el Cache y se le setea el tama�o maximo
	Cache.SetListaMaxTam(tamCache);
	for (int y = 0; y < resolucion.im_; y++)
	{
		for (int x = 0; x < resolucion.re_; x++)
		{
			pixel.re_ = 1.5 * (x - resolucion.re_ / 2) / (0.5 * imageWidth * resolucion.re_) + centro.re_;
			pixel.im_ = (y - resolucion.im_ / 2) / (0.5 * imageHeight * resolucion.im_) + centro.im_;
			int p = 0;
			if (Cache.ExisteDato(pixel, cantDig)) {
				p = Cache.p_;
			}
			else {
				complejo aux = pixel;
				int n = findMandelbrot();
				p = n;
				if (!Cache.Llena()) Cache.AltaPpio(aux, n);
				else {
					Cache.BajaFin();
					Cache.AltaPpio(aux, n);
				}
			}
			fout << p << "\t";
		}
		fout << endl;
	}
	Cache.PrintLista(); //IMPRIMI LISTA PARA TEST
	fout.close();
}

//Funcion de Iteracion de Mandelbrot, recibe la semilla pixel (type complejo)
int IMG_PGM::findMandelbrot(void)
{
	int i = 0;
	while (i < intensidadPixel - 1 && pixel.m2() < 4)
	{
		pixel = pixel*pixel + semilla;
		i++;
	}
	return i;
}