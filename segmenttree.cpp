#include <bits/stdc++.h>
#define MAX_N 1000000//normalmente sera 10^6
typedef long long ll;//solo los arreglos seran ll

using namespace std;
ll arr[MAX_N];
ll tree[6*MAX_N];
/*p l mid y r son enteros por ser iteradores*/
void build(int p, int l, int r){//ordena tree con posicion en tree,left y right
    if(l==r){//cuando es hoja
        tree[p]=arr[r];//asigno uno de los numeros del arreglo
        return;
    }
    int mid= l+(r-l)/2;//declaro un numero que este ne
    build(2*p,l,mid);//checo derecho de rama
    build(2*p+1,mid+1,r);//checo izquierdo de rama
    /*aqui asignamos el valor acumulado en el nodo,
    donde ya sabe cuanto valen sus hijos y se coloca
    el valor del nodo en el que estamos parados*/
    tree[p]=tree[2*p]+tree[2*p+1];
}
int query(int p, int a, int b, int i, int j){//search valor acumulado
    //existen 3 casos
    if(j<a or i>b){//cuando no me sirve
        return 0;
    }
    if(a<=i and j<=b){//cuando me sirve todo
        return tree[p];
    }
    int mid=i+(j-i)/2;//cuando me sirve un cacho
    int hijol =query(2*p,a,b,i,mid);
    int hijor =query(2*p+1,a,b,mid+1,j);
    return hijol+hijor;
}
void update(int p, int i,int j,int pos, int val){
    if(pos<i or j<pos)//caundo no me sirve
        return;
    if(i==j and i==pos){//cuando encontre el valor
        tree[p] = val;//asigno el nuevo
        return;
    }
    int mid=i+(j-i)/2;//sigo buscando
    update(2*p, i ,mid, pos, val);//lado der
    update(2*p+1, mid+1, j,pos,val);//lado izq
    tree[p]=tree[2*p]+tree[2*p+1];//actualizo papa, asi hasta ser toda la rama
}
int main(){
    int n,k,temp;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    build(1,0,n-1);//siempre en uno, inicio del interv, fin del interv
    cin>>k;
    while(k--){
        char temp;
        int a,b;
        cin>>temp>>a>>b;
        if(temp=='q'){
            cout<<query(1, a-1,b-1,0,n-1)<<endl;
        }
        else{
            update(1, 0,n-1, a-1, b);
        }
    }

}
