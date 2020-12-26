#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	map<string, int>trees;
	int cases=0;
	cin>>cases;
	getchar();
	string aux = "";
	float n = 0;
	while(cases>=0){
		getline(cin,aux);
		if(aux==""){
			cases--;
			if(!trees.empty()){
				for(auto &it: trees){
					cout<<it.first;
					printf(" %.4f\n",(it.second*100)/n);
				}
				if(cases>=0)
					cout<<endl;
			}
			n=0;
			trees.clear();
		}
		else{	
			trees[aux]++;
			n++;
		}
	}

	
}
