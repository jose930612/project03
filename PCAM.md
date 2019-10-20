__*Universidad Eafit*__
===================

Curso ST0263 Tópicos Especiales en Telemática, 2019-2

Proyecto3 HPC/ Problema del viajero 


__Integrantes__:

Jose alberto mejia 
Edward damian londoño
Jhoany londoño toro

__Indice:__

    1.Introducción
    2.Analisis del algoritmo 
    3.Metodologia de desarrollo 
      3.1 Modelo Pcam
    4.Esquema de algoritmo paralelo 
    
1.Introducción:
=============
Este proyecto usara el problema del agente viajero usando el algoritmo de fuerza bruta (ya que es el mas ineficiente)                   este estara en un inicio de forma serial , se analizara el algoritmo serial utilizando la metodologia pecam  y se tomara el tiempo de operacion para calcular 11 nodos y cual es la ruta mas eficiente para recorrer la totalidad de los nodos.

Luego se diseñará e implemetará este algoritmo en paralelo(OPENMP) se tomara el tiempo de respuesta para calcular la mejor ruta para 11 nodos  y se comparara con el algoritmo serial buscando optimizar la mayor cantidad de hilos.  

2.Análisis de algoritmo:
========================
El algoritmo de fuerza bruta para encontrar el mejor camino en un grafo  es uno de los algoritmos mas ineficientes ya que consume mucha memoria y su tiempo de respuesta es muy costoso ya que este algoritmo es de orden O(n!) aun asi teniendo en cuenta esto vamos a analizar las diferentes caracteristicas.

para este problema usamos dos algoritmos , ambos usando fuerza ,pero uno con recursividad de cola (serial 1) y otro sin recursividad usando netamente ciclos (serial2) se tomaron los tiempos de respuesta de ambos algoritmos como se ve a continuación:


|      | Serial-1 |      |
| ---- | -------- | ---- |
| nodos | hilos | tiempo |
| 1   |  | 0s   |
| 2   |  | 0s   |
| 3   |  | 0s   |
| 4   |  | 0s   |
| 5   |  | 0s   |
| 6   |  | 0.04s |
| 7   |  | 0.04s |
| 8   |  | 4.27s |
| 9   |  | 47.51s |
| 10  |  | 589.1s |


3.Metodologia de desarrollo 
===========================
   3.1 Metodologia Pcam:
   
   __Problema__: Tenemos un grafo conexo con peso en los vertices y deseamos saber cual es la mejor forma de recorrer todos los nodos pero el crecimiento del problema aumenta con cada nodo que se agrega al problema de forma  O(n!) esto si usamos fuerza bruta evaluando cada posible solucion y comparando. (ver figura 1)
   
   ![cat](https://github.com/jose930612/project03/blob/master/img/Problema.png)  
   
                                  figura(1)
   
   __particionado__: Se particiono el problema en n subgrafos pertenecientes al grafo del problema incial de esta manera poder visualizar de manera mas simple el problema (divide y venceras(ver figura 2))
   
   ![cat](https://github.com/jose930612/project03/blob/master/img/Particionado.png)
   
                                  figura(2)
   __Comunicacion__ : 
   ![alt tag](https://github.com/jose930612/project03/blob/master/img/Comunicacion.png)
   
                                  figura(3)
   __Mapeado__: haciendo las pruebas correspondientes llegamos a la conclusión que el optimo numero de hilos que se podian usar para lograr la mayor eficiencia es igual a la cantidad de nodos que tiene el grafo,  por los asignamos n-1 de ellos a realizar los subgrafos y el hilo sobrante  a realizar el analisis del grafo principal y comparar los resultados dados por los grafos anteriores. por fines de rendimiento se decidio solo paralelizar hasta el segundo nivel de grafos para evitar dependencia de cola . (ver figura 4)
   ![alt tag](https://github.com/jose930612/project03/blob/master/img/Mapeado.png)
   
                                  figura(4)
   
   
 
 
    
    

