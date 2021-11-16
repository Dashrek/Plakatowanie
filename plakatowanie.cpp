#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#define FOR(i,n) for(int i=0;i<n; i++)
#define FOR1(i,n) for(int i=n-2; i>=0; i-- )
using namespace std;
class lista{
    public:
    int actual_iterator_position;
    int rozmiar;
    list<int>::iterator poz;
    list<int> k;
    lista(){
        int actual_iterator_position=0;
        int rozmiar=0;
        poz=k.begin();
    }
    void wstaw(int a){
        int start=0;
        int stop=rozmiar;
        actual_iterator_position=0;
        poz=k.begin();
        while(start<stop){
            int med=(start+stop)/2;
            advance(poz,med-actual_iterator_position);
            actual_iterator_position=med;
            if (*poz<a){
                start=med+1;
            }else{
                stop=med;
            }
        }
       if(start==0){
            k.push_front(a);
        }else if(start==rozmiar){
            k.push_back(a);
        }else{
            advance(poz,start-actual_iterator_position);
            k.insert(poz,a);
            rozmiar++;
        }}
    int wyszukaj_lewy(int c){
        int start=0;
        int stop=rozmiar;
        actual_iterator_position=0;
        poz=k.begin();
        while(start<stop){
            int med=(start+stop)/2;
            advance(poz,med-actual_iterator_position);
            actual_iterator_position=med;
            if (*poz<c){
                start=med+1;
            }else{
                stop=med;
            }
        }
        advance(poz,start-actual_iterator_position);
        return start;
        }
    
};
vector <int> load_input(){
    /* Funkcja wczytujaca dane ze strumienia, zamienia je w tablice danych*/
    int a,n;
    vector <int> dane;
    cin >> n;
    dane.reserve(n);
    dane.resize(n,0);
    FOR(i,n){
        cin >>a;
        cin >>dane[i];
    }
    return dane;
}
int min1(int a, int b){
    if (a==-1 && b>0){
        return b;
    }else if (a>0 && b==-1){
        return a;
    }else if(a>b) {return b;}
    else if (a<=b) {return a;}
    return 0;
}
void wypiszv(vector <int> d){
    FOR(i,d.size()){
        cout << d[i]<<"\n";
    }
    
}
void wypiszl(list <int> darek){
    for(list<int>::iterator i=darek.begin();i!=darek.end();i++){
        cout << *i << "\n";
    }
}
class tree{
    
    public:
    int k,n,n1;
    int ilosc_tapet;
    vector<int> d;
    lista kolejnosci;
    list<int> kolejnosci_do_wstawienia;
    list<int> monotonicznosci;
    tree(vector <int> d1){
        ilosc_tapet=0;
        k=d1.size();
        n=powf(2.0,(float)ceilf(log2((float)k)));
        n1=2*n-1;
        d.reserve(n1);
        d.resize(n1,-1);
        FOR(i,k){
            d[i+n-1]=d1[i];
        }
        FOR1(i,n){
            d[i]=min1(d[i*2+1],d[i*2+2]);
        }
        kolejnosci.wstaw(-1);
        kolejnosci.wstaw(k);
    }
    void zejscie(int c){
        
        if(c<n-1){
            if(d[c]==d[2*c+1]) zejscie(c*2+1);
            if(d[c]==d[2*c+2]) zejscie(c*2+2);
            d[c]=min1(d[c*2+1],d[c*2+2]);
        }else{
            kolejnosci_do_wstawienia.push_back(c-n+1);
            monotonicznosci.push_back(kolejnosci.wyszukaj_lewy(c-n+1));
            d[c]=-1;
        }
    }
    void wyrownaj(){
        list<int>::iterator i=kolejnosci.k.begin();
        list<int>::iterator k1=monotonicznosci.begin();
        int licznik=0;
        int zmiany_mono=1;
        int poprzedni=0;
        int k2=*k1;
        for(list<int>::iterator j=kolejnosci_do_wstawienia.begin();j!=kolejnosci_do_wstawienia.end();++j){
            advance(i,*k1-poprzedni+licznik);
            kolejnosci.k.insert(i,*j);
            kolejnosci.rozmiar++;
            poprzedni=*k1+licznik;
            licznik++;
            if (k2!=*k1){
                zmiany_mono++;
            }
            k2=*k1;
            advance(k1,1);
        }
        ilosc_tapet+=zmiany_mono;
        monotonicznosci.clear();
        kolejnosci_do_wstawienia.clear();
    }
    
};

int main() {

    vector <int> dane=load_input();
    tree drzewo=tree(dane);
    
    while(drzewo.d[0]!=-1){
        drzewo.zejscie(0);
        drzewo.wyrownaj();
    }
    cout<<drzewo.ilosc_tapet;
}
