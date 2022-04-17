# Conjunto de Mandelbrot en c++
Proyecto para la materia  Programacion Orientada a Objetos (año 2015) - Ing Telecomunicaciones

<p align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Mandelbrot.jpg">
</p>

***
## Contenido
1. [Resumen](#Resumen)
2. [Contenido del Programa](#Contenido-del-Programa)
3. [Diagrama General del Programa](#Diagrama-General-del-Programa) 
4. [Memoria Cache](#Memoria-Cache)
5. [Comparación de números complejos](#comparacion-complejos)
6. [Valores por defecto](#Valores-por-defecto)
7. [Ejecución del programa vía método Asistido (Menú)](#ejecucion-asistido)
8. [Ejecución del programa vía método Desatendido o Silencioso](#ejecucion-desatendido)
9. [Simulacion](#Simulacion)
10. [Conclusion](#Conclusion)


***
<a name="Resumen"></a>
### Resumen

El propósito del programa es generar un archivo imagen en formato PGM (escala de grises) del conjunto de Mandelbrot. Para ello el algoritmo espera una serie de parámetros de entrada.
Existen dos alternativas para el ingreso de dichos parámetros:
- Asistida, mediante un menú en pantalla que indicará la opción de cada parámetro. En dicho menú se seleccionara la opción que se desea y de finalizar faltando opciones por ingresar, las mismas serán completadas por los valores por defecto (para más información consultar la sección Valores por Defecto).
- Desatendida o Silenciosa, vía este método se podrá, al momento de ejecutar el programa, enviar los parámetros de configuración necesarios directamente por línea de comandos. Es importante señalar que este método solo funcionara correctamente si se ingresan todos los parámetros esperados, de lo contrario se solicitara el ingreso vía Menú. 
A su vez, se incorporó un cache de números complejos utilizando listas enlazadas. El formato de cada nodo de la lista es una variable tipo complejo denominada pixel en conjunto con una variable del tipo entera denominada ‘cantIter’.

***
<a name="Contenido-del-Programa"></a>
### Contenido del Programa

Para la nueva versión del programa, se añadieron 2 clases (señaladas en verde) a las existentes. El conjunto total de archivos seria el siguiente:
<p align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura1.JPG">
</p>

***
<a name="Diagrama-General-del-Programa"></a>
### Diagrama General del Programa

<p align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura2.JPG">
</p>

***
<a name="Memoria-Cache"></a>
### Memoria Cache

Para la nueva versión del programa, se agregó la opción para el manejo de una memoria Cache del tipo LRU que guarde en la misma los valores complejos que no se haya iterados previamente. Antes de iterar para obtener la intensidad del pixel, se chequea que dicho valor se encuentre en la memoria, si esta se extrae sus datos asociados, de lo contrario se procede a calcular los mismos y se los guardara en la memoria. La lógica se la puede resumir en el siguiente esquema:

<p align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura3.JPG">
</p>

La memoria Cache como se puede observar, es una lista enlazada (se utilizó una lista doblemente enlazada para la reutilización de librerías, pero una lista simplemente enlazada hubiese bastado para la finalidad del programa) donde en la cabecera de la lista se irá guardando el ultimo complejo utilizado, mientras que los nodos del final se irán eliminando a medida que sea necesario agregar valores y que el tamaño del Cache sea el máximo configurado.
Es posible configurar la cantidad de nodos que conforman la lista (tamaño cache) via la opción –C del menú.

***
<a name="comparacion-complejos"></a>
### Comparación de números complejos

En cada iteración se compara el valor complejo del pixel vs las variables complejas guardadas en la memoria. Dicha comparación se realiza con un ajuste de precisión en la cantidad de cifras significativas, dicha precisión es modificable bajo la opción –D del menú.
Para realizar dicha comparación se generó el siguiente método:
```
//Función que compara dos números complejos con una tolerancia de n cant de dígitos siguiente:

bool lista::cmp(complejo a, complejo b, int n) {
       float epsilon = pow(10, -n);
       if (fabs(a.re_ - b.re_) <= epsilon && fabs(a.im_ - b.im_) <= epsilon) return true;
       return false;
}
```
Donde los argumentos de entrada a y b serán los complejos a comparar y el entero “n” es la precisión de dicha comparación, a mayor “n” mayor cantidad de dígitos significativos tomados en cuenta en la comparación.


***
<a name="Valores-por-defecto"></a>
### Valores por defecto

El programa tiene predefinido los siguientes valores por defecto en caso de no ingresarse la opción correspondiente:

- Nombre del Archivo: “out.pgm”
- Resolución: 640x480
- Posición del centro: 0 +0i
- Intensidad del Pixel: 256
- Ancho: 4
- Alto: 4
- Cantidad de dígitos significativos: 3
- Tamaño de Cache: 0 
- Semilla: -0.7 + 0.29015i

***
<a name="ejecucion-asistido"></a>
### Ejecución del programa vía método Asistido (Menú)

Si al ejecutar el programa, el mismo detecta que no se pasaron la totalidad de argumentos o ninguno de ellos, se presentara en pantalla un menú como el que se muestra en la figura (2).

<p align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura4.JPG"> 
     <p align="center"> Fig. 2 Menú Principal </p>
</p>
Aquí se espera el ingreso de alguna de las opciones presentadas, no marcar opción implicara el seteo de los valores por defecto.
Para ingresar en algunas de las opciones, el menú admite que se marque la opción numérica o la letra en minúscula o mayúscula correspondiente (la única excepción es la opción c donde se discrimina la mayúscula de la minúscula). Para finalizar además puede ingresarse ‘q’ o ‘Q’.
Ejemplo:
Si se desea modificar la resolución de la imagen, puede ingresarse en la opción ‘R’ e ingresar el valor deseado. Figura (3)

<p align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura5.JPG"> 
     <p align="center"> Fig. (3) A. Seteo de resolución vía Menú </p>
</p>

<p align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura6.JPG"> 
     <p align="center"> Fig. (3) B. Seteo de resolución vía Menú </p>
</p>

<p align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura7.JPG"> 
     <p align="center"> Fig. (3) C. Seteo de resolución vía Menú </p>
</p>

Como puede detallarse en la Fig. (3) C., al ingresar en la opción R, se pre-visualiza el valor ingresado, lo que permite modificarlo si se detecta un error. Dichos valores pueden cambiarse cuantas veces se desee hasta que no se ingrese la opción de finalizar.
De ingresar en la opción finalizar se mostrará en pantalla los valores con los que se armara la imagen. Para el ejemplo de la imagen 3 será:

<p align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura8.JPG"> 
     <p align="center"> Fig. (4) Armado de Imagen </p>
</p>

El archivo resultante tendrá la siguiente apariencia.

<p align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura9.JPG"> 
     <p align="center"> Fig. (5) Imagen de Ejemplo </p>
</p>


***
<a name="ejecucion-desatendido"></a>
### Ejecución del programa vía método Desatendido o Silencioso

Para ejecutar el programa en este modo, es necesario ejecutar el mismo con alguno de los siguientes argumentos o parámetros de entrada:
- [-o]  Nombre del Archivo
- [-r]  Resolución
- [-c]  Posición del centro
- [-m]  Intensidad del Pixel
- [-h]  Ancho
- [-w]  Alto
- [-D]  Cantidad de dígitos significativos
- [-C]  Tamaño de Cache
- [-s]  Semilla

Por ejemplo: 

<p align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura10.JPG"> 
     <p align="center">Fig. (6) Seteo de parámetros vía modo desatendido</p>
</p>
El nombre del programa en este ejemplo es “TPO_DPOO_2.exe” y se modificó el nombre del archivo (-o), la cantidad de dígitos significativos (-D), el tamaño del Cache (-C), la resolución (-r), la semilla (-s) y el alto (-h) y ancho (-w). Obteniéndose:


