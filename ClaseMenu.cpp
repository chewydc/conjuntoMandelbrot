/******************************************************************************************/
/*                                      TPO2 DPOO                                         */
/*  ALUMNO: Damian del Campo                                                              */
/*  LU: 1027477                                                                           */
/*  CARRERA: Ingenieria en Telecomunicaciones                                             */
/*  FECHA: 28/11/2015                                                                     */
/*  ARCHIVO: ClaseMenu.cpp                                                                */
/*                                                                                        */
/******************************************************************************************/

#include "ClaseMenu.h"

int Menu::menuPpal(void)
{
	imageWidth = 0;
	imageHeight = 0;
	char myChoice = NULL;
	int opcion = 0;
	op_r = 1, op_c = 1, op_w = 1, op_h = 1, op_o = 1, op_s = 1, op_D = 1, op_C = 1, op_m = 1;
	while (!opcion) {
		cout << "************** Menu Principal **************" << endl;
		if (!op_r)cout << "1.Opcion(r): Resolucion= " << resolucion << endl;
		else cout << "1.Opcion(r): Seteo de Resolucion" << endl;
		if (!op_c)cout << "2.Opcion(c): Centro= " << centro << endl;
		else cout << "2.Opcion(c): Seteo de Centro" << endl;
		if (!op_w)cout << "3.Opcion(w): Ancho= " << imageWidth << endl;
		else cout << "3.Opcion(w): Seteo del Ancho" << endl;
		if (!op_h)cout << "4.Opcion(h): Alto= " << imageHeight << endl;
		else cout << "4.Opcion(h): Seteo del Alto" << endl;
		if (!op_o)cout << "5.Opcion(o): Nombre del Archivo= " << name << endl;
		else cout << "5.Opcion(o): Seteo del Nombre del Archivo" << endl;
		if (!op_s)cout << "6.Opcion(s): Semilla= " << semilla << endl;
		else cout << "6.Opcion(s): Seteo del valor de Semilla" << endl;
		if (!op_D)cout << "7.Opcion(D): Cant Dig Significativos= " << cantDig << endl;
		else cout << "7.Opcion(D): Seteo Cant Dig Significativos" << endl;
		if (!op_C)cout << "8.Opcion(C): Tamaño Cache= " << tamCache << endl;
		else cout << "8.Opcion(C): Seteo del tamano Cache" << endl;
		if (!op_m)cout << "9.Opcion(m): Intensidad de pixel= " << intensidadPixel << endl;
		else cout << "9.Opcion(m): Seteo intensidad de pixel" << endl;

		cout << "0.Opcion(F): Finalizar" << endl;
		cin >> myChoice;
		switch (myChoice)
		{
		case '1':case 'r':case 'R':
			op_r = FunctionR();
			system("cls");
			break;
		case '2':case 'c':
			op_c = Function_c();
			system("cls");
			break;
		case '3':case 'w':case 'W':
			op_w = FunctionW();
			system("cls");
			break;
		case '4':case 'h':case 'H':
			op_h = FunctionH();
			system("cls");
			break;
		case '5':case 'o':case 'O':
			op_o = FunctionO();
			system("cls");
			break;
		case '6':case 's':case 'S':
			op_s = FunctionS();
			system("cls");
			break;
		case '7':case 'd':case 'D':
			op_D = FunctionD();
			system("cls");
			break;
		case '8':case 'C':
			op_C = FunctionC();
			system("cls");
			break;
		case '9':case 'm':case 'M':
			op_m = FunctionM();
			system("cls");
			break;
		case '0': case 'q':case 'Q':case 'F':case 'f':
			system("cls");
			opcion = 1;
			SeteoValDefault(); 	//Seteo de valores por defecto para opciones no ingresadas
			break;
		default:
			system("cls");
			cout << "ERROR! Opcion incorrecta, vuelva a intentarlo." << endl;
			break;
		}
	}
	return 0;
}

int Menu::FunctionR(void) {
	float x, y;
	system("cls");
	cout << "Opcion(r) :" << endl << "Ingrese el ancho: ";
	cin >> x;
	cout << "Ingrese el alto: ";
	cin >> y;
	resolucion.re_ = x;
	resolucion.im_ = y;
	return 0;
}

int Menu::Function_c(void) {
	float x, y;
	system("cls");
	cout << "Opcion(c) :" << endl << "Ingrese coordenada x: ";
	cin >> x;
	cout << "Ingrese coordenada y: ";
	cin >> y;
	centro.re_ = x;
	centro.im_ = y;
	return 0;
}

int Menu::FunctionW(void) {
	system("cls");
	cout << "Opcion(w) :" << endl << "Ingrese el ancho deseado: ";
	cin >> imageWidth;
	return 0;
}

int Menu::FunctionH(void) {
	system("cls");
	cout << "Opcion(h) :" << endl << "Ingrese el alto deseado: ";
	cin >> imageHeight;
	return 0;
}

int Menu::FunctionO(void) {
	system("cls");
	cout << "Opcion(o) :" << endl << "Ingrese el nombre del archivo deseado con su extension: ";
	cin.ignore(numeric_limits<int>::max(), '\n');
	cin.getline(name, 128, '\n');  //lectura incluyendo espacios
	return 0;
}

int Menu::FunctionS(void) {
	float x, y;
	system("cls");
	cout << "Opcion(s) :" << endl << "Ingrese coordenada x: ";
	cin >> x;
	cout << "Ingrese coordenada y: ";
	cin >> y;
	semilla.re_ = x;
	semilla.im_ = y;
	return 0;
}

int Menu::FunctionD(void) {
	system("cls");
	cout << "Opcion(D) :" << endl << "Ingrese la cantidad de Digitos Significativos: ";
	cin >> cantDig;
	return 0;
}

int Menu::FunctionC(void) {
	system("cls");
	cout << "Opcion(C) :" << endl << "Ingrese el tamaño del Cache: ";
	cin >> tamCache;
	return 0;
}

int Menu::FunctionM(void) {
	system("cls");
	cout << "Opcion(m) :" << endl << "Ingrese la intensidad de pixel deseada: ";
	cin >> intensidadPixel;
	return 0;
}

void Menu::SeteoValDefault(void) {
	if (op_w) imageWidth = 4;
	if (op_h) imageHeight = 4;
	if (op_r) {
		resolucion.re_ = 640;
		resolucion.im_ = 480;
	}
	if (op_c) {
		centro.re_ = 0;
		centro.im_ = 0;
	}
	if (op_o) {
		char temp[128] = "out.pgm";
		IMG_PGM copy;
		copy.copiaNombre(temp, name);
	}
	if (op_s) {
		semilla.re_ = -0.7;		//Semilla para JuliaSet
		semilla.im_ = 0.29015;	//Semilla para JuliaSet
	}
	if (op_D) cantDig = 3;
	if (op_C) tamCache = 0;
	if (op_m) intensidadPixel = 256;
}


/*Argumentos:
[-r]: Modifica la resolucion de la imagen
[-c]: Modifica el centro de la imagen
[-h]: Modifica el Alto
[-w]: Modifica el Ancho
[-o]: Modifica el nombre del archivo
[-s]: Permite controlar el valor complejo de la semilla
[-D]: Digitos significativos de las claves complejas usadas en cache
[-C]: Cant max de num complejos que puede alojar el cache
[-m]: Cant max de iteraciones por pixel */
bool Menu::PaseArgumentosMain(int argc, char* argv[]) {
	op_r = 1, op_c = 1, op_w = 1, op_h = 1, op_o = 1, op_s = 1, op_D = 1, op_C = 1, op_m = 1;
	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			if (strcmp(argv[i], "-r") == 0) {
				resolucion.re_ = atof(argv[i + 1]);
				resolucion.im_ = atof(argv[i + 2]);
				op_r = 0;
			}
			if (strcmp(argv[i], "-c") == 0) {
				centro.re_ = atof(argv[i + 1]);
				centro.im_ = atof(argv[i + 2]);
				op_c = 0;
			}
			if (strcmp(argv[i], "-w") == 0) {
				imageWidth = atof(argv[i + 1]);
				op_w = 0;
			}
			if (strcmp(argv[i], "-h") == 0) {
				imageHeight = atof(argv[i + 1]);
				op_h = 0;
			}
			if (strcmp(argv[i], "-o") == 0) {
				IMG_PGM copy;
				copy.copiaNombre(argv[i + 1], name);
				op_o = 0;
			}
			if (strcmp(argv[i], "-s") == 0) {
				semilla.re_ = atof(argv[i + 1]);
				semilla.im_ = atof(argv[i + 2]);
				op_s = 0;
			}
			if (strcmp(argv[i], "-D") == 0) {
				cantDig = atoi(argv[i + 1]);
				op_D = 0;
			}
			if (strcmp(argv[i], "-C") == 0) {
				tamCache = atoi(argv[i + 1]);
				op_C = 0;
			}
			if (strcmp(argv[i], "-m") == 0) {
				intensidadPixel = atoi(argv[i + 1]);
				op_m = 0;
			}
		}
	}
	else return true;
	//Seteo de valores por defecto para opciones no ingresadas via la linea de comando
	SeteoValDefault();
	return false;
}