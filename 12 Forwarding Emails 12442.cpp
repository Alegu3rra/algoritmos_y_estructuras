#include <iostream>
#include <vector>
#include <cstring>
#define MAX_N 50500

using namespace std;

int sum[MAX_N];
bool visit[MAX_N];
int emails[MAX_N];


int DFS(int nodo){
	visit[nodo]=true;
	int suma_nodos=0;
	if(visit[emails[nodo]]==false and emails[nodo]!=-1)
		suma_nodos+= 1+ DFS(emails[nodo]);
	visit[nodo]=false;
	return sum[nodo]=suma_nodos;
	//for(int &n: emails[nodo])
	//	if(!vist[n])
	//		DFS(n);
}

int main(){
	int cases;
	cin>> cases;
	int martians;
	for(int c=0; c<cases; c++){
		cin>>martians;
		memset(emails, -1, sizeof(emails));
		for(int i=0; i<martians; i++){
			int temp1, temp2;
			cin>>temp1>>temp2;
			emails[temp1-1]=temp2-1;
		}
		memset(sum, -1, sizeof(sum));
		memset(visit, false, sizeof(visit));
		
		int max_comp = 0;
		int comp=0;
		for(int i=0; i<martians; i++){
			if(sum[i]== -1){
				DFS(i);
			}
			if(max_comp<sum[i]){
				max_comp=sum[i];
				comp=i;
			}
			
		}
		cout<<"Case "<<c+1<<": "<<comp+1<<endl;
	}
		
}