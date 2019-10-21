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


|      | Serial   |        |  Paralelo |       |SpeedUP|Eficiencia|
| ---- | -------- | ----   |  -------  |-----  |-------| ---------|
| nodos  | Hilos  | Tiempo |   Hilos   |Tiempo | ||
| 24     |   1    |54.4 seg |   24      |   11.8 seg    |||
| 25     |   1    |112.66 seg|   24      | 22.82 seg      |||
| 26     |   1    |255.6 seg|   24      | 46.871 seg      |||
| 27     |   1    |570.26 seg|   24      | 83.4 seg      |||
| 28     |   1    |4216.28 seg|   24      | 430.4 seg      |||



3.Metodologia de desarrollo 
===========================
   3.1 Metodologia Pcam:
   
   __Problema__: Tenemos un grafo conexo con peso en los vertices y deseamos saber cual es la menor distancia con la cual se pueden recorrer todos los nodos pero el crecimiento del problema aumenta con cada nodo que se agrega al problema de forma  O(n!) esto si usamos fuerza bruta evaluando cada posible solucion y comparando. (ver figura 1)
   
   ![cat](https://github.com/jose930612/project03/blob/master/img/Problema.png)  
   
                                  figura(1)
   
   __particionado__: Se particiono el problema en n subgrafos pertenecientes al grafo del problema incial de esta manera poder visualizar de manera mas simple el problema (divide y venceras(ver figura 2)), en la figura 3 podemos ver como estas definidas las tareas, primera tarea consiste en separar el nodo inicial del subconjunto compuesto por los demas nodos, la segunda tarea consiste en a su vez dividir esos subconjuntos en subconjuntos mas pequeños, la tercera tarea consiste en evaluar distancias cuando solo quedan 2 nodos en esos subconjuntos y guardar la mas pequeña, estas tareas se pueden ver en la figura 3.
   
Ya de cara al algoritmo podemos ver como hay 3 ciclos anidados y cada tarea corresponde a unos de esos ciclos (ver figura 4), ya que la tarea T2 divide el problema en N-1 subproblemas, decidimos paralelizar esta tarea, al ser la que menos va crecer con respecto a la cantidad de nodos, ya que las demas crecen con una velocidad de 2^n-1, siendo n la cnatidad de nodos del grafo, por lo que incluso paralelizandolas, no se notaria una mejoria, almenos no con una buena eficiencia
   
   ![cat](https://github.com/jose930612/project03/blob/master/img/Particionado.png)
   
                                  figura(2)
                                  
   ![cat](https://github.com/jose930612/project03/blob/master/img/tareasnew1.png)
   
                                  figura(3)
       
   ![cat](https://github.com/jose930612/project03/blob/master/img/tareasAlgor.png)
   
                                 figura(4)
  __Comunicacion__ : 
   ![alt tag](https://github.com/jose930612/project03/blob/master/img/Comunicacion.png)
   
                                  figura(5)
   __Mapeado__: haciendo las pruebas correspondientes llegamos a la conclusión que el optimo numero de hilos que se podian usar para lograr la mayor eficiencia es igual a la cantidad de nodos que tiene el grafo,  por los asignamos n-1 de ellos a realizar los subgrafos y el hilo sobrante  a realizar el analisis del grafo principal y comparar los resultados dados por los grafos anteriores. por fines de rendimiento se decidio solo paralelizar hasta el segundo nivel de grafos para evitar dependencia de cola . (ver figura 6)
   ![alt tag](https://github.com/jose930612/project03/blob/master/img/Mapeado.png)
   
                                  figura(6)
   4.Analisis de rendimiento 
===========================
[Presentación de analisis de rendimiento](https://github.com/jose930612/project03/blob/master/Speed%20up%20-%20Efficiency.pptx)

   __Conclusiones__: Se cumplio el objetivo de bajar el tiempo e incrementar la eficiencia del algoritmo implementando el paralelismo, aunque el algoritmo serial tiene un rendimiento aceptable hasta con 20-25 nodos, el algoritmo serial comienza a presentar problemas de desempleño a medida que incrementa el número de nodos. Al haber implementado el paralelismo, el programa deja de presentar problemas por la cantidad de nodos(n) n > 25 lo que representa un incremento en la eficiencia de al menos un 87%.
   Según los datos tomados con 10 hilos y 22 hilos, el cuello de botella que se ve evidenciado en el algoritmo serial con 28 nodos podemos ver como se baja el tiempo de respuesta de 48 minutos a 5 minutos (10 hilos) y 4 minutos (22 hilos). El algoritmo paralelo tiene un valor real cuando la cantidad de nodos es mayor a 25 y acorde a los datos recolectados, entre más hilos se tengan disponibles es más fácil para el algoritmo repartir la carga y encontrar una ruta más optima.
   Por último, una de las conclusiones que es necesario resaltar es que la relación de hilos vs nodos esta ligada a que cuando hay una cantidad de nodos menos a la cantidad de hilos, el incremento del performance no es tan significativo ya que la cantidad de subconjuntos que se generan no son suficientes para utilizar todos los hilos de forma optima y completa, por eso es que la eficiencia y el speedup se nota más cuando el número de nodos es igual o mayor a el número de hilos.
