__Compilacion del problema__
=============================
Primero entramos a la carpeta raiz del proyecto:

       $cd proyecto3
        
En este directorio encontraremos las soluciones al problema divididas en dos directorios serial/ y paralelo /


__Compilacion en serial__:

       $ cd serial
       
En este directorio se encontraran los archivos de correspondientes para la compilacion y se compila con el siguiente comando:

       $ g++ main.cpp  leer.cpp 

al realizar el anterior comando de compilacion se generara un ejecutable a.out en el mismo directorio el cual complilaremos
de la siguiente forma :

       $ ./a.out

Al compilar este ejecutable nos retornara el numero de nodos evaluados y el tiempo que tardo en analizar dicho numero de nodos
dependiendo del numero de nodos que se esten analizando la ejecución podra tardar segundos o horas.



__Compilacion en Paralelo__

 $ cd paralelo
       
En este directorio se encontraran los archivos de correspondientes para la compilacion y se compila con el siguiente comando:

       $ g++ main.cpp  leer.cpp -fopenmp

al realizar el anterior comando de compilacion se generara un ejecutable a.out en el mismo directorio el cual complilaremos
de la siguiente forma :

       $ ./a.out
       
Al compilar este ejecutable nos retornara el numero de nodos evaluados y el tiempo que tardo en analizar dicho numero de nodos
dependiendo del numero de nodos que se esten analizando la ejecución podra tardar segundos o horas.

       



       
       
       
       

