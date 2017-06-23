/*
Programação Dinâmica - Dieta
Maximizar a massa consumida em funnçãoo do limite de calorias diárias*/

#include <iostream>
using namespace std;

int mat[100][100];

void dieta(int *c, int *w, int W, int n){ 
	for(int i=0;i<=n;i++)
		mat[i][0]=0;
	for(int j=1;j<=W;j++)
		mat[0][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			mat[i][j]=mat[i-1][j];
			if(w[i-1]<=j&&c[i-1]+mat[i-1][j-w[i-1]]>mat[i-1][j])
				mat[i][j]=c[i-1]+mat[i-1][j-w[i-1]];
		}
	}
	//Solu��o �tima
	cout<<"\nResposta: "<<mat[n][W]<<" gramas"<<endl;
}

void alimentosDaDieta(string *nome, int *c, int *w, int n, int W){ //Quais alimentos ser�o ingeridos
	bool x[n];
	int aux=mat[n][W];
	
	for(int i=0;i<n;i++)
		x[i]=false;
	
	if(aux==c[n-1]+mat[n-1][W-w[n-1]]){
		x[n-1]=true;
		aux-=c[n-1];
	}
	
	for(int i=n-2;i>=0;i--){
		if(aux-c[i]==0){
			x[i]=true;
			break;
		}
		if(aux-c[i]>0){
			if(aux==c[i]+mat[i][W-w[i]]){
				x[i]=true;
				aux-=c[i];
			}
		}
	}	
	
	cout<<"\nAlimento(s): ";
	for(int i=0;i<n;i++){
		if(x[i])
			cout<<nome[i]<<" ";
	}
}

int main(){
	int limite,alimentos;
	cout<<"Numero de alimentos disponiveis: ";
	cin>>alimentos;
	int massa[alimentos],calorias[alimentos];
	string nome[alimentos];
	
	for(int i=0;i<alimentos;i++){
		cout<<"\n\tAlimento "<<i+1;
		cout<<"\nNome: ";
		cin>>nome[i];
		cout<<"Massa: ";
		cin>>massa[i];
		cout<<"Calorias: ";
		cin>>calorias[i];
	}
	
	cout<<"\nCalorias diarias: ";
	cin>>limite;
	
	dieta(massa,calorias,limite,alimentos);
	alimentosDaDieta(nome,massa,calorias,alimentos,limite);
}
