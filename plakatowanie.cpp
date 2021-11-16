#include <iostream>
#include <vector>
#include <cmath>
#define FOR(i,n) for(int i=0;i<n; i++)
#define FOR1(i,n) for(int i=n-2; i>=0; i-- )
using namespace std;
int min(int a, int b){
    if (a==-1 && b>=0) return b;
    else if ( a>=0 && b==-1) return a;
    else if(a>b) return b;
    else if(a<=b) return a;
    return 0;
}
class moja_lista{
    
    public:
    int k,n,n1;
    vector<int> d;
    void create_tree(vector <int> d1){
        k=d1.size();
        n=powf(2.0,(float)ceilf(log2((float)k)));
        n1=2*n-1;
        d.reserve(n1);
        d.resize(n1,-1);
        FOR(i,k){
            d[i+n-1]=d1[i];
        }
        FOR1(i,n){
            d[i]=min(d[i*2+1],d[i*2+2]);
        }
    }
    vector <int> zejscie(int c){
        
        if(c<n-1){
            if(d[c]==d[2*c+1])
        }
    }
    
};
int main() {
    vector<int> d;
    d.resize(5,0);
    d[0]=2;d[1]=3;d[2]=2;d[3]=5;d[4]=4;
    moja_lista x;
    x.create_tree(d);
    FOR(i,x.n1){
        cout << x.d[i] <<"\n";
    }
}
