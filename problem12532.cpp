#include <bits/stdc++.h>
#define MAX_N 1000000//normalmente sera 10^6
typedef long long ll;//solo los arreglos seran ll

using namespace std;
ll arr[MAX_N];
ll tree[6*MAX_N];

int normaliza(ll a){
    if(a>0)
        return 1;
    if (a<0)
        return -1;
    return 0;
}
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
    tree[p]=tree[2*p]*tree[2*p+1];
}
int query(int p, int i, int j, int a, int b){//search valor acumulado
    //existen 3 casos
    if(j<a or i>b){//cuando no me sirve
        return 1;//neutro es de 1 por op multiplicacion
    }
    if(a<=i and j<=b){//cuando me sirve todo
        return tree[p];
    }
    int mid=i+(j-i)/2;//cuando me sirve un cacho
    int hijol =query(2*p,i,mid,a,b);
    int hijor =query(2*p+1,mid+1,j,a,b);
    return hijol*hijor;
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
    tree[p]=tree[2*p]*tree[2*p+1];//actualizo papa, asi hasta ser toda la rama
}
int main(){
    int n,k,temp;
    while(cin>>n>>k){
        for(int i=0;i<n;i++){
            ll temp;
            cin>>temp;
            arr[i]=normaliza(temp);
        }
        build(1,0,n-1);//siempre en uno, inicio del interv, fin del interv
        //cout<<query(1, 0,n-1,0, n-1);
        while(k--){
            char temp;
            int a,b;
            cin>>temp>>a>>b;
            if(temp=='P'){
                int temp=query(1, 0,n-1,a-1,b-1);
                if(temp>0)
                    cout<<'+';
                if(temp<0)
                    cout<<'-';
                if(temp==0)
                    cout<<0;
            }
            else{
                update(1, 0,n-1, a-1, normaliza(b));
            }
        }
        cout<<endl;
    }
}
