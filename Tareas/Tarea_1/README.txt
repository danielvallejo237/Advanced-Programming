Heap Actualizable- Informe final 

Daniel Vallejo Aldana Licenciatura en Computación UG

################ Descripción general ##############

Para la presente tarea se usaron dos estructuras de datos para la
creación del Heap actualizable, la primera se refiere a un vector
el cual es el Heap conformado de parejas (Prioridad, Llave) y un map
de (llave, posición), lo anterior para poder acceder en tiempo
logarítmico a los elementos del vector así como para encontrar 
si existen elementos en el heap en tiempo log(N)
El principal problema al momento de realizar el Heap Actualizable
fue el encontrar la estructura de datos que ayudara a optimizar tiempo
de búsqueda. Así mismo la eliminación de los nodos hoja que se
encuentran al final del heap ya que en ese caso no era necesario 
hacer heapify.

################## Funciones del problema ##################

>>>> Funciones privadas:
-fixUp: Se encarga de arreglar el heap de los hijos al padre o nodo
raíz
-fixDown: Arregla el heap del padre hasta los hijos, es una función de 
tipo void
-insert: Función que se encarga de insertar elementos en el heap, haciendo fuxUp
-Maxheapify: Combinación de fixDown y fixUp

>>>>Funciones Públicas:
-print: Imprime el Heap 
-delByKey: Elimina el elemento del heap que posea una cierta llave 
-pop: Elimina el elemento del mayor valor del heap
-top: Regresa la pareja con la mayor prioridad en el heap
-IoU: Función insert or Update, inserta un elemento en el heap si éste no 
se encuentra ahí o lo actualiza (lo elimina y luego vuelve a insertarlo)
-isInserted: Función de tipo bool que regresa si un elemento se encuentra ahí o no
-size: Regresa el tamaño del heap
-getPos: Regresa la posición en la que se encuentra el elemento
con base en el valor de su llave, si no se encuentra regresa -1
-empty: Función de tipo bool que regresa si el heap se encuentra
vacío o no.

#### NOTA ####
Notemos que para que podamos hacer comparaciones con el operador 
<, se necesita que tanto la clase Tpr (prioridad) y la clase (Tkey)
tengan definido este operador, de otra forma no va a ser posible realizar
comparación alguna entre las parejas de dichas clases.
