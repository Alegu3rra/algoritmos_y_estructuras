#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    LL num;
    cin>>num;
    while(num--)
    {
        LL n,k;
        cin>>n>>k;
        LL b1, b2;
        LL pb1=1,pb2;
        while(pb1*(pb1+1)/2<k)
            pb1++;
        pb2=k-(pb1*(pb1-1)/2)-1;
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

