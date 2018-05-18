#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string convert(int);
int*** crear(int);


int main(){
	int opcion = 0;
	cout << "MENU" << endl;
	cout << "Ingrese Opcion" << endl;
	cout << "1) Calendario"<< endl;
	cout << "2) Calculadora" << endl;
	cout << "3) Cifrado" << endl;
	cin >> opcion;
	switch(opcion){
		case 1:{
			
			break;
		}
		case 2:{
			int grado = 0;
			int cont = 0;
			int cont2 = 0;
			int a = 0;
			string pot;
			ostringstream ss;
			cout << "Ingrese el grado mas alto del polinomio: " <<endl;
			cin >> grado;
			cont = grado;
			cont2 = grado+1;
			int* array = new int[grado+1];
			string* array2 = NULL;
			int* arreglo = new int[grado+1];
			for(int i=0;i<grado+1;i++){
				arreglo[i] = 0;
			}
				
			array2 = new string[grado+1];
			
			for(int i=0;i<=grado;i++){
				cout << "Ingrese el polinomio x^" << cont << endl;
				cin >> array[i];
				if(i == grado){
					array2[i] = "";
				}else{
				array2[i] = "x^"+ convert(cont);
				}
				cont--;	
			}

			cout<< "Ingrese valor de a: " << endl;
			cin>>a;
			cout<< "Division de: (";
			for(int i =0;i<=grado;i++){
				if(array[i] > 0){
					cout <<"+" <<array[i] << array2[i];
				}else if(array[i] < 0){
					cout << array[i] << array2[i];
				}
			}
			cout << ")" << "/ (x" << (a*-1) << ")" << endl;
			
			
			int*** tablero = crear(grado+1);
			/*for(int i =0;i<grado+1;i++){
				for(int j =0;j<3;j++){
					for(int k = 0;k<grado+1;k++){
						tablero[i][j][k] = arreglo[k];
						cout<<tablero[i][j][k]<<"-";
					}
				}
				cout << "" << endl;
			}*/			

			if(tablero[0][0][0] == 0){
				cout << "entro m" << endl;
				for(int i=0; i<cont2; i++){
				cout << i << endl;	
					tablero[0][0][i] = array[i];
					tablero[0][1][i] = arreglo[i];
					if(i=0){
						tablero[0][2][i] = array[i]; 
					}else{
						tablero[0][2][i] = 0;
					}
					cout << "fin" << endl;
				}
				cout << "escribio" << endl;
				for(int i =0;i<3;i++){
					for(int j=0;j<grado+1;j++){
						cout << tablero[0][i][j];
					}
					cout << "" << endl;
				}
				cout << "imprimio" << endl;
				
			}

			//int matriz = new Matriz[];
			break;
		}
		case 3:{

			break;
		}
		default:{
			break;	
		}
	}
}


string convert(int num){
	ostringstream ss;
	ss << num;
	return ss.str();
}

int*** crear(int n){
	int*** tablero = new int**[n];
	for(int i=0;i<n;i++){
		tablero[i] = new int*[3];
	}
	for(int i =0;i<n;i++){
		for(int j =0;j<3;j++){
			tablero[i][j] = new int[n];
		}
	}	
	return tablero;
}
