# Laboratorio 03: KD-Tree

El presente trabajo corresponde al laboratorio 03 del cirso de Estructura de datos avanzados de la carrera de Ciencia de la computación en la Universidad Nacional de San Agustín de Arequipa.

## Integrantes

| # |Estudiante | Código  |
| :---:   | :-: | :-: |
|1 |PERCA QUISPE, Joel Cristian | 20190744 |
|2 |VILCHEZ MOLINA, Misael Svante | 2019XXXX |
|3 |ESPINOZA PEÑALOZA, Edgar Alfonso | 2019XXXX |


## Objetivos:

Utilizar dos versiones del algoritmos de búsqueda de vecinos más próximos (k-nearest neighbors (KNN) ) (i)
fuerza bruta (ii) usando un kd-tree, en el lenguaje de programación de su preferencia, con las funciones de
construcción/inserción y búsqueda, para realizar sus respectivos análisis comparativos:


## Actividades

1. Analizar y comparar el **tiempo de ejecución** de la función de inserción tanto en **fuerza bruta** y con **kd-tree**.

2. Analizar y comparar el **tiempo de ejecución** de la función de búsqueda tanto en **fuerza bruta** y con **kd-tree**.

3. Analizar y comparar el **tiempo de ejecución** de la función de **búsqueda de  k-vecinos más cercanos** tanto en **fuerza bruta** y con **kd-tree**.  

## Requisitos

* ANN: A Library for
Approximate Nearest Neighbor Searching
David M. Mount and Sunil Arya
Version 1.1.2
Release Date: Jan 27, 2010


* Fast C++ CSV Parser: This is a small, easy-to-use and fast header-only library for reading comma separated value (CSV) files.

* G++ compiler 9.3

* Visual Studio Code

* SO: Linux Lite 5.6

## Desarrollo

1. Se descargó los códigos fuente de la libreria ANN, se incluyó en el entorno de desarrollo.

2. Se implementó las estructuras KD-Tree y Fuerza bruta para el análisis de los métodos de Inserción y Búsqueda.

3. Se automatizó los procesos de captura de tiempo de ejecución.

4. Se guardó los datos en un registro adicional.

5. Se usó los datos para generar una tabla así como las gráficas comparativas.

## Resultados

1. Inserción **Fuerza bruta VS KD-Tree**.

    ![Image1](docs/image1.png)

1. Búsqueda **Fuerza bruta VS KD-Tree**.

    ![Image1](docs/image1.png)

1. k-Nearest Neighbor **Fuerza bruta VS KD-Tree**.

    ![Image1](docs/image1.png)