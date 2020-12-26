#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(){
	int num=0;
	while(cin>>num, num){
		priority_queue<int, vector<int>, greater<int>>colita;
		while(num--){
			int dato;
			cin>>dato;
			colita.push(dato);
		}
		int res=0;
		int costo=0;
		while(colita.size() > 1){
			res=colita.top();
			colita.pop();
			res+=colita.top();
			colita.pop();
			colita.push(res);
			costo+=res;
		}
		cout<<costo<<endl;
	}

}