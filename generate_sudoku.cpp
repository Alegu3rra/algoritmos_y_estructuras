#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Sudoku {
public:
	vector< vector< char>> mat;//declaración de la matriz
	Sudoku(){//constructor
		vector<char> seed1= {'1','2','3','4','5','6','7','8','9'};//declaración de seed1(rellena semilla)
		vector<char> seed;//declaración de seed(la semilla)
		
		/*algoritmo Fisher-Yates*/
		//crea una semilla, genera una inicialización en la matriz para el algoritmo DFS 
		while (seed1.size()){//mientras el vector tenga elementos
			int k = seed1.size();//asigna el tamaño de seed1 en k
			int temp = (rand()%k);//asigna un entero random de cero a k en temp
			swap(seed1[temp],seed1[k-1]);//intecambia el elemen indice temp con el elem indice k-1(final vector) dentro de seed
			seed.push_back(seed1[k-1]);//ingresa en el vector el elemento indice k-1 (ultimo elemento)
			seed1.pop_back();//saca del vector de seed1
		}
		/*algoritmo Fisher-Yates*/
		//crea una matriz de puntos
		for(int i = 0; i < 9; i++){//por cada i menor a 9 
			vector<char>line;//declara un vector llamado line
			for(int j = 0; j < 9; j++){//por cada j menor a 9
				char c='.';//declara c valuado en '.'
				line.push_back(c);//ingresa el caractér '.' en line
			}
			mat.push_back(line);//ingresa el vector en la matriz mat(como fila)
		}
		//se asignará de forma random en fila o en columna el vector seed(la semilla)
		int pos_in_mat = rand() % 9;//ingresa un numero random para determinar lugar de colocación de la semilla
		if( !(rand() % 2) ){//si random es par entra
			for(int i = 0; i < 9; i++){//por cada i menor a 9
				mat[pos_in_mat][i] = seed[i];//ingresa la semilla en la posición pos_in_mat de los renglones
			}
		}
		else{//si no
			for(int i = 0; i < 9; i++){//por cada i menor a 9
				mat[i][pos_in_mat] = seed[i];//ingresa la semilla en la posición pos_in_mat de las columnas
			}
		}
	}	
	
    void ResSudoku() {//declaración de la fucnión que llena mat y muestra la resolución del sudoku
        for (int r = 0; r < 9; ++ r) {//por cada r menor a 9
            for (int c = 0; c < 9; ++ c) {//por cada c menor a 9
                if (mat[r][c] != '.') {//si mat en pocisión r,c es diferente de '.'
                    int x = mat[r][c] - '0';//parceo del numero como string(mat en r,c) a numero como entero(x)
					/*en estas lineas se rellena sets que me ayudaran a checar las posiciones para evitar repetir
					en columnas, renglones y cuadrados*/
					cols[c].insert(x);//inserta en la columna la pocisión c a x
                    rows[r].insert(x);// inserta en el renglon la pocisión r a x 
                    box[r/3][c/3].insert(x);// inserta en el box(cuadrado correspond) a x
                }
            }
        }
        dfs(mat, 0, 0);//mando a llamar a la dfs
		//vaciar el sudoku completo
    }
    
private:
	
    unordered_set<int> cols[9];//declaración del set de las columnas
    unordered_set<int> rows[9];//declaración del set de los renglones
    unordered_set<int> box[3][3];//declaración del set de los cuadrados
	
	/*DFS*/
    bool dfs(vector< vector< char>>& mat, int r, int c) {//dfs recibe mat y el indice de renglones y columnas
        if (c == 9) {//si es igual a 9(terminó de recorrer columna)
            r ++;//avanza renglon (continua a la siguiente columna)
            c = 0;//regresa a cero a c (empieza la sig columna)
        }
        if (r == 9) {//si es igual a 9(terminó de recorrer todas las columnas)
            return true;//retorna true
        }       
        if (mat[r][c] != '.') {//si matriz en r,c es diferente de '.'
            return dfs(mat, r, c + 1);//llama a la dfs de mat en r,c+1
        }
        for (int i = 1; i <= 9; ++ i) {//para cada i menor o igual a 9
            if (check(i, r, c)) {//llama check(si puede colocar el numero de 1 a 9) de i en r,c
                mat[r][c] = (char)(48 + i);//parceo del numero como entero(i) a numero como string, asignando a la matriz en r,c
                cols[c].insert(i);//inserta en la columna la pocisión c a i
                rows[r].insert(i);//inserta en el renglón la pocisión c a i
                box[r/3][c/3].insert(i);// inserta en el box(cuadrado correspond) a i
                /*bracktraking*/
				if (dfs(mat, r, c + 1)) { //si dfs de r, c+1                 
                    return true;//retorna true
                }
                mat[r][c] = '.';//inserta dentro de mat en r,c '.'
                cols[c].erase(i);//en la columna en c, borra el elem en i 
                rows[r].erase(i); //en el renglon en c, borra el elem en i      
                box[r/3][c/3].erase(i);//en el box(cuadrado correspond) en c, borra el elem a i
				/*backtracking*/
            }
        }
        return false;//retorna false
    }
	/*DFS*/
	
    //checa si es posible ingresar un numero en una posición r,c
    bool check(int x, int r, int c) {//funcion check recibe numero a ingresar en r,c
        return (cols[c].count(x) == 0) //retorna true si en columna en c, x no existe
			and (rows[r].count(x) == 0) //y si en renglones en r , x no existe
			and (box[r/3][c/3].count(x) == 0);//y si en el box(cuadrado correspond), x no existe
			//.count(x) cuenta cuantos x hay en el set
    }
	
	
};





int main(){
	srand(time(NULL));//Instrucción que inicializa el generador de números aleatorios
    Sudoku sudo; //declaras un objeto sudoku llamado sudo
    sudo.ResSudoku();//resuelve mat con semilla usando backtracking
    for(int i = 0; i < 9; i++){//para cada i menor a 9
        for(int j = 0; j < 9; j++)//para cada j menor a 9
            cout << " "<<sudo.mat[i][j];//imprime mat en i,j
        cout << endl;//imprime salto de linea
    }
}
