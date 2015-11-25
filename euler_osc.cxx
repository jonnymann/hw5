#include <iostream>
#include <fstream>

using namespace std;

int main(){
    const int N=2000;
    const double Max=20*3.1415;
    const double Min=0;
    double step = (Max-Min)/N;
    double* arr = new double[2*N];
    arr[0]=1;
    arr[N]=0;
    
    //forward
    for(int i=1; i<N;i++){
        arr[i]=arr[i-1]+step*arr[N+i-1];
        arr[N+i]=arr[N+i-1]-step*arr[i-1];
    }
    ofstream out("euler_for.txt");
    for(int i=0; i<N;i++)
        out << i*step << "\t" << arr[i] << endl;
    out.close();
    
    //backward
    for(int i=1; i<N;i++){
        arr[i]=1/(1+step*step)*(arr[i-1]-step*arr[N+i-1]);
        arr[N+i]=1/(1+step*step)*(step*arr[i-1]+arr[N+i-1]);
    }
    ofstream out2("euler_back.txt");
    for(int i=0; i<N;i++)
        out2 << i*step << "\t" << arr[i] << endl;
    out2.close();

    delete[] arr;
    return 0;
}