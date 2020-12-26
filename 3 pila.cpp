#include <iostream>
#include <stack>
using namespace std;

int main(){
	int n;
	stack<int> ale;
	cin>>n;
	while(n--){
		int val;
		cin >> val;
		ale.push(val);
	}
	while(!ale.empty()){
		cout<<ale.top()<<endl;
		ale.pop();
	}
	
}