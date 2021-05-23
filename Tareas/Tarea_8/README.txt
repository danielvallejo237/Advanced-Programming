###########################################################
#                                                         #
#                                                         #
#          TAREA 8                                        #
#                                                         #
###########################################################

@Author Daniel Vallejo Aldana
Licenciatura en Computación


DESCRIPCIÓN GENERAL DE LOS PROBLEMAS	

Problema 1:

El problema 1 resuelve el problema de encontrar el número de sub cadenas distintas para esto
usa un arreglo de sufijos y el algoritmo de KMP extendido para poder calcular dicho número.
La complejidad del algoritmo sale de recorrer n veces cada caracter por lo que dicha complejudad del
algoritmo es de orden O(n^2)

Problema 2:

El problema 2 resuelve el problema de calcular la máxima ganancia de matcheo de caracteres, para esto se usa una
variación del algoritmo de Needelman-Wunsh enfocada a calcular el número de espacios y de máximos caracteres matcheados
en las cadenas para esto la complejidad de dicho algoritmo es de O(m*n) donde m<n y m,n son las longitudes de las cadenas matcheadas

Problema 3:
El problema 3 usa el algoritmo de la Liebre y la Tortuga para determinar el elemento repetido en el arreglo, dado un arreglo arr
de números la actualización de la tortuga es de la forma tortuga=arr[i]  mientras que la de la liebre es de la forma liebre=arr[arr[i]] de esta forma se convierte el problema en el de detección de ciclos.

Problema 4:

El problema 4 es similar al problema 2, la complejidad es la misma y el problema se reduce a calcular el número de espacios que hay que 
poner para que se haga el máximo matcheo de las dos cadenas que contienen las pilas de HotCakes 
