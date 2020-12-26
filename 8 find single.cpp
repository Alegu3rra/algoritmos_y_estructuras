#include <iostream>
#include <vector>
using namespace std;
vector<int> arr {7,3,5,5,4,3,4,8,8};

int main(){
	int i=0;
	int res = 0;
	for(int i=0; i<arr.size(); i++){
		res ^= arr[i];
	}
	cout<<res<<endl;
}