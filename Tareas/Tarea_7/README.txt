######### TAREA 7       DANIEL VALLEJO ALDANA ###########

#### Programación Avanzada #########################

->Problema 1:

La solución al problema 1 se hizo con ciclos de potencias y con base en eso se pudo determinar 
el último dígito de un número p elevado a la q

->Problema 2:

 La idea es construir la matriz de nxn con el espiral de Ulam y
después de eso hacer una matriz binaria en donde 1 representa que el número es
primo y 0 representa que dicho número no es primo, al final sacar la proporción de la
suma de la diagonal entre la suma total (las dos son en O(N^2)) y aumentar N hasta que 
obtengamos que la proporción es menor al 10% o 0.1

->Problema 3:

Sabemos que el m tal que sus divisores sumen n es a lo más n-1 por lo que hacemos un ciclo de
n-1 a 1 para ver si los divisores de algunos de estos números suman n, para calcular la suma 
de los divisores de m hay que hacer un ciclo de 1 hasta m y ver si m %k == 0, como el límite para 
n es 1000 esto si entra en tiempo.

->Problema 4:

En este problema la idea es hacer un precálculo de la suma GCD extreme para esto hay que mantener dos
arreglos, suma y aux, al final podemos responder en tiempo O(1) solo accediendo a la posición n 
del arreglo suma

->Problema 5:

Para encontrar todos los inversos multiplicativos de a modulo m en el intervalo l u, debemos de saber
que este inverso existe solo su gcd(a,m)=1, por lo que es lo que debemos de checar, luego con las ecuaciones
de Bezout obtenemos el valor del  x tal que ax=1 mod m, ahora, x es único mod m por lo que todos los demás 
inversos son de la forma (x+km) por lo anterior hay que encontrar los valores de k tal que (x+km) in [l,u]
de esta forma obtenemos todos los inversos multiplicativos modulo m de a en el intervalo [l,u]
