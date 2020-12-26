#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	string s;
	cin>> n;
	getchar();//para limpiar el buffer
	getline(cin,s);//problemas con el \n
	cout << s<<" "<< n<<endl;
	
}