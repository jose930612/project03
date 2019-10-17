__Compilacion del problema__
=============================
Primero entramos a la carpeta raiz del proyecto:

       $cd proyecto3
        
En este directorio encontraremos las soluciones al problema divididas en cuatro directorios serial/ y held-karp-serial/ para los algoritmos de forma serial y para los algoritmos de forma paralela/ held-karp-paralelo/ se compilan de la siguiente manera 


__Compilacion en serial__:

       $ cd serial
       
En este directorio se encontraran los archivos de correspondientes para la compilacion y se compila con el siguiente comando:

       $ g++ main.cpp  leer.cpp 

al realizar el anterior comando de compilacion se generara un ejecutable a.out en el mismo directorio el cual complilaremos
de la siguiente forma :

       $ ./a.out

Al compilar este ejecutable nos retornara el numero de nodos evaluados y el tiempo que tardo en analizar dicho numero de nodos
dependiendo del numero de nodos que se esten analizando la ejecución podra tardar segundos o horas.

__held-karp-serial/ :__ 
       
       $cd held-karp-serial/
       
En este directorio se encontraran los archivos de correspondientes para la compilacion y se compila con el siguiente comando que solo funciona en c++ v11 :

     $ g++ -std=c++11 leer.cpp main.cpp


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

__Compilación held-karp-paralelo:__

    $cd held-karp-paralelo:/
       
En este directorio se encontraran los archivos de correspondientes para la compilacion y se compila con el siguiente comando que solo funciona en c++ v11 :

     $ g++ -std=c++11 leer.cpp main.cpp


al realizar el anterior comando de compilacion se generara un ejecutable a.out en el mismo directorio el cual complilaremos
de la siguiente forma :

       $ ./a.out
       
Al compilar este ejecutable nos retornara el numero de nodos evaluados y el tiempo que tardo en analizar dicho numero de nodos
dependiendo del numero de nodos que se esten analizando la ejecución podra tardar segundos o horas.



       



       
       
       
       

