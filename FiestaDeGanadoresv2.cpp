#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
    ll T=0;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        vector<pair<ll,char>> arr;
        while(n--){
            ll x, y;
            cin>>x>>y;
            arr.push_back({x,'E'});
            arr.push_back({y,'S'});
        }
        sort(arr.begin(), arr.end());
        ll max_num=0,res=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i].second=='E')
                res+=1;
            if(arr[i].second=='S')
                res-=1;
            max_num=max(max_num,res);
        }
        cout<<max_num<<endl;
        arr.clear();
    }

}

