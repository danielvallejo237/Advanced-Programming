#######################################
#   TAREA 5: DCCOMP                   #
#    Daniel Vallejo Aldana            #
#######################################


</--- Descripción general de la tarea -->

En la presente tarea se resolvió el problema DCCOMP en el que se busca encontrar el numero de componentes conexos
en un grafo en un intervalo de la forma [L,R], para esto se usó una técnica de solución offline (Sabemos primero
las preguntas, preprocesamos esas preguntas y al final las resolvemos de forma eficiente). Dicha técnica es el 
algoritmo de MO en el cual dividimos las preguntas en bloques de sqrt(N), donde en este caso N es el numero de 
nodos que estamos considerando.
Así mismo recibimos el valor M el cual corresponde a las M aristas y Q que es el valor de cuántas preguntas vamos a contestar.

    <// Estructuras de datos utilizadas //>

1-Estructura Query: Esta estructura representa una consulta, consta del valor l (left), r(right), idx que nos sirve
                    para poder imprimir las soluciones en orden, y block que nos dice en que bloque corresponde cada 
                    consulta, en este caso block=l/sqrt(N). Finalmente se define el operador < para poder ordenar las consultas
                    por bloque y luego por el valor de r.
2-Edge: Simplemente representa una arista y tiene los valores u y v 

3-Namespace UFDS: Para hacer conexiones entre nodos usamos en este caso la estructura de datos Union Find Disjoint Set (UFDS),
                para el caso de este problema lo representamos como un Namespace, con funciones unionSet y findSet modificadas 
                con un valor booleano en donde agregamos una tupla que guarda el elemento hijo, su padre y su rango, esto ya que 
                por la naturaleza del problema debemos de mantener control de estados pasados. Para hacer cálculos eficientes 

 <//Algoritmo principal//>

 </--- Idea general -->

 La idea general del algoritmo es dividir las preguntas en bloques, la asignación de bloque se hace de acuerdo a lo descrito en 
 las lineas anteriores, para cada batch o bloque vamos contestando esas preguntas pero como la l es variable (no es ni decreciente
 ni creciente) hay que mantener control de los estados pasados. Cada que cambiamos de bloque hay que hacer un tipo reset del UFDS.
 Consideramos dos casos importantes, cuando toda la pregunta completa (es decir l y r) se encuentran en el mismo bloque,
 y cuando no, dependiendo de los Union que vayamos haciendo se va disminuyendo el numero de componentes conexos que incialmente se
 inicializa como N (El numero de nodos).

 </--- Complejidad del Algoritmo -->

 Desglozando un poco la complejidad vemos lo siguiente 

 -Cada cambio de bloque tenemos un reset lineal o sea es de orden O(N*sqrt(N)) a lo mas
 -El ultimo for para las Q preguntas es mas o menos O(sqrt(N)*Q)
 
 De acuerdo al cáclulo pasado la complejidad algorítmica es de orden O(N*sqrt(N) + Q*sqrt(N))