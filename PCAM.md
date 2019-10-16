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

2. Análisis de algoritmo


3.Metodologia de desarrollo 
===========================
   3.1 Metodologia Pcam:
   
   __Problema__:
   
   ![alt tag](https://github.com/jose930612/project03/blob/master/img/Problema.png)
   
   __particionado__:
   
   ![alt tag](https://github.com/jose930612/project03/blob/master/img/Particionado.png)
   
   __Comunicacion__ :
   ![alt tag](https://github.com/jose930612/project03/blob/master/img/Comunicacion.png)
   
   __Mapeado__:
   ![alt tag](https://github.com/jose930612/project03/blob/master/img/Mapeado.png)
   
   
    


4.Esquema de algoritmo paralelo
============================
 
 
 
    
    

