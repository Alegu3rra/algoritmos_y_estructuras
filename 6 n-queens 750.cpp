#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
int const tab_tam = 15;

int row[tab_tam], TC, a, b, lineCounter;

bool place(int r, int c){
	for(int prev = 0; prev < c; prev++)
		if(row[prev]==r or (abs(row[prev]-r)==abs(prev - c)))
			return false;
		return true;
}
void backtrack(int c){
	if(c == tab_tam){
		printf("%2d     %d", ++lineCounter, row[0]+1);
		for(int j=1;j<tab_tam;j++)
			printf(" %d", row[j]+1);
		printf("\n");
	}
	for(int r = 0; r<tab_tam;r++){
		if(place(r,c)){
			row[c]= r; 
			backtrack(c+1);
		}
	}
}

int main(){
	memset(row, 0, sizeof row);
	lineCounter = 0;
	printf("SOLN     COLUMN\n");
	printf("#      1 2 3 4 5 6 7 8\n\n");
	backtrack(0);
}
