#include <bits/stdc++.h>
typedef long long LL;

using namespace std;

int main(){
    int cases;
    cin>> cases;
    double n,k;
    while(cases--){
        cin>>n>>k;
        long double arriba=(LL)k*1000000000000000;
        long double abajo=(1<<(LL)n)-2*n-2;
        printf("%.15Lf\n", arriba/(abajo*1));
    }
}
