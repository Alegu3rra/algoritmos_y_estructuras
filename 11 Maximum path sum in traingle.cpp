#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> triangulo[15];
int DP[15][15];


int DFS_suma(int fila, int column){
	if(fila==14)
		return triangulo[14][column];
	if(DP[fila][column]!=-1)
		return DP[fila][column];		
	return  DP[fila][column] = (max(DFS_suma(fila+1, column), DFS_suma(fila+1, column+1)))+triangulo[fila][column];
}

int main(){
	memset(DP,-1,sizeof(DP));
	for(int i=0; i<15; i++){
		for(int j=0; j<i+1; j++){
			int num;
			cin>>num;
			triangulo[i].push_back(num);
		}
	}
	cout<<DFS_suma(0, 0);	
	
	
}