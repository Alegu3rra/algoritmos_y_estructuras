#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll fast_pow(ll base, ll pot, ll mod){
    ll res=1;//inicializamos en 1 por ser neutro multiplicativo
    while(pot>0){//mientras la potencia sea mayor a 0
        /*(manejando bits) checaremos los bits, y haremos 
        operaci[on unaria con 1, encontrando si el digito
        que corresponde a 2^0 esta encendido*/
        if(pot&1)
            /*si esta encendido, res se mutiplicara
            por la base y se le hara el modulo,(siempre modulo aqui
            para no topar el limite, asi maximo estara a la mod-1,
            dentro de la vecindad del modulo)*/
            res=res*base%mod;
        base=base*base%mod;//para tener el proximo numero elevado al cuadrado
        pot>>=1;/*se recorre un bit para checar el siguiente
        si esta encendido o no(asi se reducira la potencia en potencias
        de 2, una manera particular de hacer division entera del numero)*/
    }
    return res;
}

int main(){
    ll base, pot, mod;//recibimos a, la potencia b, modulo
    cin>>base>>pot>>mod;
    cout<<fast_pow(base, pot, mod)<<endl;//imprime res
}//pyhton ya cuenta con su propio fast_pow
