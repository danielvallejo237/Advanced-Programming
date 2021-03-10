#### REPORTE DE LA TAREA 2 Problema pelotas robadas ######

Descripción general:

En la presente tarea se resolvieron satisfactoriamente los ejercicios 0,1 y 2. Para la parte 3
no se logró completar la implementación sin embargo se intentó implementar una estructura de vector 
de treaps para la construcción de los muros con un map de entero entero donde se guarda la posición
en la que comienza un treap y la que se encuentra en el vector. Sin embargo las funciones de inserción 
y borrado son las que no fue posible implementar debido a que la idea no se logró concretar


Archivos generados:

->Treap_simple.h: Contiene solamente la estructura treap para resolver los problemas 0,1,2
->pelotas_robadas.cpp: Resuelve el problema 0,1,2
->full_pelotas_robadas.cpp: Es una mezcla de los dos anteriores y es el que se subió a Omega Up
->treap_w_walls.h: Librería donde se implementa la creación de muros, esta librería no fue probada

FUNCIONES GENERADAS:

Estructura _Node y Node: Corresponde a la estructura del nodo del treap, tiene una prioridad, un valor x y un valor máximo
así como un valor cnt que cuenta el número de nodos hijos en el subarbol
Así mismo las funciones recalc() y getMax() son para calcular el número de nodos en el subarbol
y el número máximo en el subarbol.

Estructura Treap: Inicializada con el nodo root consta de las siguientes funciones importantes
print(): Imprime el árbol en orden desde el nodo de la raíz 
size(): Regresa el tamaño del treap a partir de un nodo n, si ese tamaño es 0
se considera al nodo como NULL
getNodeInPos(): Recibe un nodo n inicial y p la posición que se busca, regresa el 
nodo que se encuentra en dicha posición o NULL si no existe, esta funcione es una recursividad
getValueInPos(): Recibe los mismos argumentos que la función anterior, regresa un entero 
que corresponde al valor en dicha posición si se encuentra si no regresa -1
SplitByPos(): Función split del treap, separa la raiz del treap en varias partes.
InsertBP(): Hace una inserción por posición en el treap, si no es una posición alcanzable válida no se 
hace nada. 
eraseByPos(): Dada una posición borra el nodo que se encuentra en dicha posición, si esa posición no es
válida no se hace nada
moveItems(): Solución al problema 2, mueve los items de posiciones
getMaxbyPos(): Saca el máximo dada una posición, se hace un split en las posiciones p1 a p2, 
del treap restante se obtiene la raíz que contiene el máximo en el subarbol.

Estructura BorderTreap:
Consiste de un vector<Treap> y de un map<long long int, long long int>, cada posición
del vector representa un muro y el map es originalmente para guardar las posiciones
que abarca cada uno de los treaps del vector así como en que posicion del vector
se encuentra.
Esta es la estructura problemática que no fue posible completar.
  
