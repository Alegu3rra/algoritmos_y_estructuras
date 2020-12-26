#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector< int > vec;
	int n;
	cin>> n;
	
	for(int i = 0;  i<n; i++)
	{
		int tmp;
		cin>> tmp;
		vec.push_back(tmp);//complejidad amortizada
	}
	
	for(int i=0; i<n ; i++)
	{
			cout<< vec[i] << endl;
	}
}