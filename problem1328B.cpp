#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
LL gauss(LL num){
    return num*(num+1)/2;
}

//LL binary(LL k, LL left, LL right){
    
//}



int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL num;
    cin>>num;
    vector <LL> g;
    //guarda todos los gauss
    for(int j=0;j<100000;j++){
        g.push_back(gauss(j));
    }

    while(num--)
    {
        LL n,k;
        cin>>n>>k;
        LL b1, b2;
        LL pb1=1,pb2;
        pb1 = upper_bound(g.begin(),g.end(),k) - g.begin();
        if ( gauss(pb1 -1) == k)
            pb1--;
        pb2=k-(gauss(pb1-1))-1;
        //cout << n <<" " << k <<endl;
        //cout<<pb1<<" "<< g[pb1] <<"..."<<pb2<<" " << g[pb2]<<endl;
        for(int i=n-1;i>=0;i--)
        {
            if(i==pb1 or i==pb2)
                cout<<"b";
            else
                cout<<"a";
        }
        cout<<endl;
    } 
    
}

