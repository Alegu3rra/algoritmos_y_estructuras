#include <iostream>
#include <queue>
using namespace std;

struct point{
	int x,y;
	point(int a, int b): x(a),y(b){}
	point(){x=y=0;}
};
int main(){
	int n;
	cin>> n;
	queue<point>ale;
	while(n--){
		point aux;
		cin>> aux.x>>aux.y;
		ale.push(aux);
	}
	while(!ale.empty()){
		point aux = ale.front();
		cout<< aux.x<<','<<aux.y<<endl;
		ale.pop();
		
	}
}