##### Este es el readme de la tarea 4 #### 

Implementación de la descomposición HL
###En esta tarea no se cumplió el objetivo de implementar la descomposición Heavy Light para
el problema de DTPSUM, los posibles errores del código son 
1-. Alguna de las descomposiciones DFSCSZ ó DFSHLD, están incorrectas, ya sea porque estamos asignando 
mal algún valor o algo parecido
2-. La actualización de tipo lazy que fue implementada al realizarse sobre actualizaciones de rango pero no
era necesario hacer eso. Sin emgargo esta implementación no es muy complicada en el código por lo que no debería de
generr algun problema para la actualización.


VECTORES UTILIZADOS

-> El vector madj corresponde al vector de vectores para representar las adyacencias entre los nodos,
se construye a partir de los datos de entrada de la matriz.

->El vector parent representa los padres de cada uno de los nodos, -1 significa que ese nodo es papá de si mismo 
y un entero i, con 0<=i<=numnodos es el padre del nodo en los demás arreglos.

->El vector depth representa la profundidad de cada uno de los nodos
->chain da la cadena del camino formado por las aristas pesadas
->lazy y segment tree: Son los utilizados para hacer las actualizaciones, el st es para todos los caminos pesados
->csz: chain size es el tamaño de la cadena

FUNCIONES UTILIZADAS:

// Descomposiciones //
DFSCZ: Funcion para construir las cadenas y los tamaños de las cadenas dada las adyacencias
DFSHLD: Función para hacer la descomposicion HL dada las adyacencias

//OTRAS FUNCIONES//
LCA: Funcíon para calcular el ancestro mínimo común, para hacer consultas del tipo (A,LCA(A,B)), (LCA(A,B),B)
add_node y query: Usan propagación retardada que igual no es necesaria pero ya se había implementado para este problema en 
caso de querer aumentar a actualizaciones de rango, en este caso solo hay que actualizar en un rango (a,a) y listo
queyr_path: Hace la consulta de la suma entre dos nodos. Aqupi puede también estar el problema aunque no se está contando dos 
veces al LCA por el valor de tipo bool (ignore_lca).
