#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n=0;
	long long m=0;

	while(cin>>n>>m and n and m){
		long long res=0;
		queue<long long>Jack;
		queue<long long>Jill;
		while(n--){
			long long dato=0;
			cin>>dato;
			Jack.push(dato);
		}
		while(m--){
			long long dato=0;
			cin>>dato;
			Jill.push(dato);
		}
		while(!Jack.empty() and !Jill.empty()){
			if(Jack.front()==Jill.front()){
				res++;
				Jack.pop();
				Jill.pop();
			}
			else if(Jack.front()<Jill.front()){
				Jack.pop();
			}
			else if(Jack.front()>Jill.front()){
				Jill.pop();
			}
		}
		cout<<res<<endl;
	}	
}