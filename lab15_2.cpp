#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}
void inputMatrix(double A[][N]){
    double x;
    
    for (int i = 0; i < N; i++)
    {
        cout << "Row "<< i+1<<": ";
        for(int j= 0;j <N; j++){
        cin >> x ;
        A[i][j]=x;
        }
    }
}
void findLocalMax(const double P[][N], bool B[][N]){
    for (int k = 0; k < N; k++)
    {
        for (int l = 0; l < N; l++)
        {			//ซ้าย				ขวา  					บน						ล่าง
            if (P[k][l]>=P[k][l-1] && P[k][l]>=P[k][l+1] && P[k][l]>=P[k-1][l] && P[k][l]>=P[k+1][l])
            {
                B[k][l] =true;
            }else B[k][l]=false;
            
        }
        
    }
    for (int i = 0; i<N; i++){
        B[0][i] =0;
        B[N-1][i] =0;
    }
    for (int j = 0; j < N-2; j++){
        B[j+1][0]=0;
        B[j+1][N-1]=0;
    }
    
}
void showMatrix(const bool b[][N]){
     for (int j = 0; j < N; j++)
    {   for (int k = 0; k < N; k++)
        {   if(b[j][k]==true){
                cout << "1 ";
            }else cout << "0 ";
        }
     cout << endl;
    }
 }