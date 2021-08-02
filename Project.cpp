#include<bits/stdc++.h>
#include <fstream>
using namespace std;



void BasisFuns(int i, double u, int p, double *U, double *N)
{

	double *left = NULL, *right = NULL, saved, temp;

	int j, r;

	if(!(left = (double*)calloc(p+1, sizeof(double)))) return;

    if(!(right=(double*)calloc(p+1, sizeof(double))))	{ free(left); return; }

	N[0] = 1.0;

	for(j = 1; j <= p; j++) {

		left[j] = u - U[i+1-j];

		right[j] = U[i+j] - u;

		saved = 0.0f;

		for(r = 0; r < j; r++){

			temp = N[r] / (right[r+1] + left[j-r]);

			N[r] = saved + right[r+1] * temp;

			saved = left[j-r] * temp;

		}

	N[j] = saved;

	}

	free(left);

	free(right);

	return;

}	




int FindSpan(int n, int p, double u, double *U) {

	int low, mid, high;

	if(u >= U[n]) return n;

	if(u <= U[p]) return p;

	low = 0; /* low = p; */

	high = n+1; mid = (low+high)/2;

	while(u < U[mid] || u >= U[mid+1]){

		if(u < U[mid])	high = mid;

		else low = mid;	

		mid = (low + high)/2;

    } 

return(mid);

} 




 
int CurvePoint3D(int n, int p, double *U, double *P, double u, double *C)
{

	int span, j, k;

	double *N = NULL;

	if(!(N = (double*)calloc(p+1, sizeof(double)))) return 1;

	span = FindSpan(n, p, u, U);

	BasisFuns(span, u, p, U, N);

	C[0] = 0.0; C[1] = 0.0; C[2] = 0.0;

	for(j = 0; j <= p; j++){

		k = (span-p+j)*3;

		C[0] = C[0] + N[j]*P[k];

		C[1] = C[1] + N[j]*P[k+1];

		C[2] = C[2] + N[j]*P[k+2];

	}

	free(N);

	return 0;

}



int main(){
	std::ifstream fileInput("C:/Users/Admin/Desktop/ProjectEx(u=1).txt");//Duong dan den file vi du duoc neu trong bao cao

	int n,p; 	double u;

	double *U=new double[n+p+2];

	double *P=new double[(n+1)*3];

	double C[3];

	if (fileInput.fail())

	{

		std::cout << "Failed to open this file!" << std::endl;

		return 1;

	}

	cout<<"tham so nho nhat trong tap diem: ";

	cin>>u;

	while (!fileInput.eof())

	{

		fileInput >> n >> p;

		P=(double*)calloc(n+1, sizeof(double));

		U=(double*)calloc(n+p+2, sizeof(double));
		
		cout<<"Bac :"<<p<<endl;
		
		for(int i=1;i<=n+1;i++){

			int k=i*3;

			fileInput>>P[k]>>P[k+1]>>P[k+2];
			
			cout<<"P["<<i-1<<"]:("<<P[k]<<", "<<P[k+1]<<", "<<P[k+2]<<")"<<endl;
		}
		
		cout<<endl;
		
		for(int i=1;i<=(n+p+2);i++){

			fileInput>>U[i];
	
			cout<<"U["<<i<<"]:"<<U[i]<<"; ";
	
		}
		cout<<endl;
	}
	cout<<endl;
	
	fileInput.close();

//	u=0;

	do{

	CurvePoint3D(n, p, U, P, u, C);


	cout<<"C("<<u<<")="<<"("<<C[0]<<","<<C[1]<<","<<C[2]<<")"<<endl;

	u=u+0.05;

	}while (u<=1.05);

	return 0;

}
