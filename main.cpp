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
			int conteito = 0;
			int a = 0;
			string pot;
			ostringstream ss;
			cout << "Ingrese el grado mas alto del polinomio: " <<endl;
			cin >> grado;
			cont = grado;
			cont2 = grado+1;
			conteito = grado;
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
			int conteo = 0;
			int conteoarray = 0;
			if(tablero[0][0][0] == 0){
			     for(int m=0;m<grado+1;m++){
				for(int i=0;i<grado+1;i++){
					
					tablero[m][0][i] = array[i];
					tablero[m][1][i] = arreglo[i];
					if(i==0){
						tablero[m][2][i] = array[i]; 
					}else{
						tablero[m][2][i] = 0;
					}
					
				}
			     }
				
				conteoarray++;
				conteo++;
			}

			while(conteoarray < grado+1){
				if(tablero[0][0][0] != 0){
					for(int i =0;i<3;i++){
					    for(int j=0;j<grado+1;j++){
						tablero[conteoarray][i][j] = tablero[conteoarray-1][i][j];
					   }
					
					}
					for(int j=0;j<grado;j++){
						
						int a = tablero[conteoarray][2][conteo-1];
						int b = tablero[conteoarray][0][conteo];
						tablero[conteoarray][1][conteo] = a;
						tablero[conteoarray][2][conteo] = a+b;
						conteoarray++;
						conteo++;
						
						for(int i =0;i<3;i++){
					    		for(int j=0;j<grado+1;j++){
							if(conteoarray < grado+1 ){
							tablero[conteoarray][i][j] = tablero[conteoarray-1][i][j];
					   		}else{
								break;
							}
							}
						}
					}
					for(int m=0;m<grado+1;m++){
						for(int i =0;i<3;i++){
							for(int j=0;j<grado+1;j++){
								cout << tablero[m][i][j] << "  ";
							}
							cout << "" << endl;
						}
						cout << "" << endl;
					}
				}
				cout << "El residuo es:" << tablero[grado][2][grado] << endl;
				cout << "El cociente es: ";
				for(int m=grado;m<grado+1;m++){
					for(int i =2;i<3;i++){
						for(int j=0;j<grado;j++){
							if(tablero[m][i][j] > 0){
								conteito--;
								if(conteito > 0){
								cout << tablero[m][i][j] << "x^" <<conteito<< "+";
								}else{
									cout << tablero[m][i][j];
								}
							}
						}
					}
							cout << "" << endl;
				}
						cout << "" << endl;
				}
					
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
