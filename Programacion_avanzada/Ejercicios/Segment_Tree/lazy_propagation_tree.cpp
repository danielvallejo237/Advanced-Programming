
/*Implementación de un arbol de propagación lazy para el cálculo del
elemento mínimo usando actualizaciones */

#include<bits/stdc++.h>

using namespace std;
#define N 50005

vector<int> lazy(N); //Asignamos el valor de 0
vector<int> arr(N);
vector<int> st(4*N); //Este es el segment tree, solo debemos de guardar un valor así que
//no es necesario hacer un vector de vectores
lazy.assign(N,0); //un vector de 0
