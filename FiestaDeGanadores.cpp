#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
     ll T=0;
     map<ll,ll> arr;
     cin>>T;
     while(T--){
        ll n;
        cin>>n;
        while(n--){
            ll x,y;
            cin>>x>>y;
            arr[x] += 1;
            arr[y] += -1;
        }

        int max_num=0,res=0;
        for(auto a:arr){
            res+=a.second;
            if(res>max_num)
                max_num=res;
        }
        cout<<max_num<<endl;
        arr.clear();
     }
}
