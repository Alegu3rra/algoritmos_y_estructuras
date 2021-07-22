#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> tree;

int LSOne(int n){
    return n & (-n);
}
void update(int pos, int val){
    while(pos<=tree.size()){
        tree[pos]+=val;
        pos+=LSOne(pos);
    }

int query(int pos){
    int res=0;//neutro
    while(pos>0){
        res+= tree[pos];
        pos-= LSOne(pos);
    }
    return res;
}
int main(){
    int n,k;
    cin>>n>>k;
    tree.assign(n+1,0);
    for(int i=0; i<n;i++){
        int aux;
        cin>>aux;
        update(i+1, aux);//prohibido empezar en 0 ft i+1
    }
    /*for(auto x: tree)
        cout<<x<<endl;
    */
    for(int i=0; i<k;i+)
        //char op;
        int a,b;
        cin>>a>>b;
        //if(op=='P')
            cout<<query(b)-query(a-1)<<endl;
        //if(op=='C')
           //update(a, b);
    }
}
