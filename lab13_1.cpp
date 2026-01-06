#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}
void stat (const double x[], int y, double z[]){
    double sum = 0, summ = 0, mul = 1, sumR = 0, Max = 0,Min = x[0];
    for(int i = 0;i < y; i++){
        sum += x[i];
    }
    z[0] = sum/y;

    for (int i = 0;i < y;i++){
        summ += pow((x[i] - z[0]),2);
    }
    z[1] = sqrt((summ/y));
    
    for (int i = 0;i < y;i++){
        mul *= x[i];
    }
    z[2] = pow(mul, 1.0/y);
    
    for(int i = 0; i<y; i++){
        sumR += 1/x[i];
    }
    z[3] = y/sumR;

    for(int i = 0; i<y; i++){
        if (x[i] > Max){Max = x[i];}
        if (x[i] < Min){Min = x[i];}
    }
    z[4] = Max;
    z[5] = Min;
}