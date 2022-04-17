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
9. [Imagen generada](#Imagen-generada)
10. [Test del programa](#Test-del-programa)
11. [Conclusiones del Test](#conclusiones)
12. [Algunos ejemplos de salida](#Algunos-ejemplos-de-salida)
 


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

- Nombre del Archivo: **“out.pgm”**
- Resolución: **640x480**
- Posición del centro: **0 +0i**
- Intensidad del Pixel: **256**
- Ancho: **4**
- Alto: **4**
- Cantidad de dígitos significativos: **3**
- Tamaño de Cache: **0**
- Semilla: **-0.7 + 0.29015i**

***
<a name="ejecucion-asistido"></a>
### Ejecución del programa vía método Asistido (Menú)

Si al ejecutar el programa, el mismo detecta que no se pasaron la totalidad de argumentos o ninguno de ellos, se presentara en pantalla un menú como el que se muestra en la figura (2).

<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura4.JPG">
     <div>Fig. 2 Menú Principal</div>
</div>

Aquí se espera el ingreso de alguna de las opciones presentadas, no marcar opción implicara el seteo de los valores por defecto.
Para ingresar en algunas de las opciones, el menú admite que se marque la opción numérica o la letra en minúscula o mayúscula correspondiente (la única excepción es la opción c donde se discrimina la mayúscula de la minúscula). Para finalizar además puede ingresarse ‘q’ o ‘Q’.

Ejemplo:

Si se desea modificar la resolución de la imagen, puede ingresarse en la opción ‘R’ e ingresar el valor deseado. Figura (3)


<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura5.JPG">
     <div>Fig. (3) A. Seteo de resolución vía Menú</div>
</div>     


<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura6.JPG">
     <div>Fig. (3) B. Seteo de resolución vía Menú</div>
</div>


<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura7.JPG">
     <div>Fig. (3) C. Seteo de resolución vía Menú</div>
</div>

Como puede detallarse en la Fig. (3) C., al ingresar en la opción R, se pre-visualiza el valor ingresado, lo que permite modificarlo si se detecta un error. Dichos valores pueden cambiarse cuantas veces se desee hasta que no se ingrese la opción de finalizar.
De ingresar en la opción finalizar se mostrará en pantalla los valores con los que se armara la imagen. Para el ejemplo de la imagen 3 será:

<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura8.JPG"> 
     <div> Fig. (4) Armado de Imagen </div>
</div>

El archivo resultante tendrá la siguiente apariencia.

<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura9.JPG"> 
     <div> Fig. (5) Imagen de Ejemplo </div>
</div>



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

<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/438543af1046d15403a99fc9905ff69390ced2fc/img/Figura10.JPG"> 
     <div>Fig. (6) Seteo de parámetros vía modo desatendido</div>
</div>

El nombre del programa en este ejemplo es “TPO_DPOO_2.exe” y se modificó el nombre del archivo (-o), la cantidad de dígitos significativos (-D), el tamaño del Cache (-C), la resolución (-r), la semilla (-s) y el alto (-h) y ancho (-w). Obteniéndose:

<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/f4923905ace61eff5a18595e206dda5ac46bc93c/img/Figura11.JPG"> 
     <div>Fig. (7) Resumen de valores ingresados</div>
</div>



<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/f4923905ace61eff5a18595e206dda5ac46bc93c/img/Figura12.JPG"> 
     <div>Fig. (7 b) Imagen generada de valores ingresados por línea de comando.</div>
</div>



***
<a name="Imagen-generada"></a>
### Imagen generada

El formato de la imagen generada es PGM en escala de grises. Tiene seteado el valor por defecto de 255 y puede modificarse via la opción [–m] vista previamente.
En el encabezado de la imagen se agregó la posición del centro y el ancho/alto de la imagen generada a modo de comentario. Puede resultar útil dicha información para generar nuevas imágenes a partir de un archivo ya conformado.

Ejemplo de header o encabezado de archivo imagen:


<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/f4923905ace61eff5a18595e206dda5ac46bc93c/img/Figura13.JPG"> 
     <div>Fig. (8) Encabezado del archivo imagen generado.</div>
</div>


***
<a name="Test-del-programa"></a>
### Test del programa

En la siguiente tabla se volcaron los resultados de las distintas corridas de prueba realizadas y el tiempo medido en segundos de cada prueba. Los resultados son aproximados y no se contempló el error humano en la toma de las mediciones.



<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/f4923905ace61eff5a18595e206dda5ac46bc93c/img/Figura14.JPG"> 
</div>



<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/f4923905ace61eff5a18595e206dda5ac46bc93c/img/Figura15.JPG"> 
     <div>Fig. (9) Archivos generados en las corridas de pruebas.</div>
</div>



<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/f4923905ace61eff5a18595e206dda5ac46bc93c/img/Figura16.JPG"> 
     <div>Fig. (10) Archivos generados en las corridas de pruebas test#21 y test#5</div>
</div>



<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/f4923905ace61eff5a18595e206dda5ac46bc93c/img/Figura17.JPG"> 
     <div>Fig. (11) Archivos generados en las corridas de pruebas test#5 y test#7</div>
</div>



<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/f4923905ace61eff5a18595e206dda5ac46bc93c/img/Figura18.JPG"> 
     <div >Fig. (12) Archivos generados en las corridas de pruebas test#5 y test#7</div>
</div>



***
<a name="conclusiones"></a>
### Conclusiones del Test

Como puede apreciarse en la imagen (9), a medida que se disminuye la cantidad de dígitos significativos utilizados en la comparación de valores complejos la calidad de la imagen disminuye considerablemente pero el tiempo de ejecución se mejora sustancialmente.
Otra conclusión que podemos obtener de los test  realizados, es que en la corrida sin cache (variable [–C]=’0’) donde cada pixel es resultado de la iteración sin intervención de la comparación de valores complejos, la imagen generada es exactamente igual a la generada vía cache y dígitos significativos en valores [-D]=’4’ y [-C]=’10’. Esta conclusión se obtiene de la figura (10), donde se comparan línea a línea los archivos imagen de los test #5 vs test #21.
Ahora si analizamos los resultados línea a línea entre archivo del test #5 vs el test #7 donde los dígitos significativos se disminuyeron a [-D]=’3’, en ese caso si encontramos diferencia en sus líneas (imagen 11) aunque abriendo la imagen y comparando visualmente la diferencia es insignificante para el ojo humano (imagen 12).
Finalmente y pese a lo rudimentario de las pruebas, podemos concluir en que la inserción de la memoria cache al programa es beneficioso en determinadas situaciones, si necesitamos una imagen de mayor resolución (superando los 1024x720) ya comienza a ser beneficioso. Si disminuimos la cantidad de dígitos significativos menor a 3 la calidad de la imagen no es buena y se presenta diferencias perceptibles al ojo humano. Por debajo de la resolución 640x480 (test #1 al #4), nos encontramos que la performance disminuye y resulta conveniente realizar la iteración completa de cada pixel en lugar de recurrir al uso de la memoria Cache.

***
<a name="Algunos-ejemplos-de-salida"></a>
### Algunos ejemplos de salida

<div align="center">
     <img src="https://github.com/chewydc/conjuntoMandelbrot/blob/f4923905ace61eff5a18595e206dda5ac46bc93c/img/Figura19.JPG"> 
</div>
