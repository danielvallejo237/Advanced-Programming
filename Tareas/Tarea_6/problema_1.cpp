//Implementación de la clase BigInteger 

#include "BigInt.h"

using namespace std;

int main()
{
    BigInt entero1,entero2;
    cin>>entero1>>entero2;
    cout<<"Enteros grandes dados: "<<entero1<<" , "<<entero2<<endl;
    cout<<"Operacion Suma: "<<(entero1+entero2)<<endl;
    cout<<"Operacion Resta: "<<entero1-entero2<<endl;
    cout<<"Operacion Multiplicación: "<<entero1*entero2<<endl;
    cout<<"Operacion División: "<<entero1/entero2<<endl;
    cout<<"Operacion potencia: "<<(entero1^entero2)<<endl;
    return 0;
}
