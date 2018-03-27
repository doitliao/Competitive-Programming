#include <bits/stdc++.h>

using namespace std;

class Mapmaker{
  public:
    Mapmaker(){}
    Mapmaker(string name, int base, int element_size, int D);
    void addBound(int L, int U);
    void init();
    void print();

    int physical(vector<int> &ref);

    string name;
    int base;
    int element_size;
    int D;
    vector<int> C;
    vector< tuple<int, int> > bounds;
};

Mapmaker::Mapmaker(string n, int b, int e, int d):name(n), base(b), element_size(e), D(d), C(d + 1){
  addBound(0, 0);
}

void Mapmaker::init(){
 C[D] = element_size;

 C[0] = base;
 int U , L;
 for(int i = D - 1; i >= 1; i --){
   tie(L, U) = bounds[i+1];
   C[i] = C[i+1] * (U - L + 1);
   C[0] -= C[i+1] * L;
 }
 tie(L, U) = bounds[1];
 C[0] -= C[1] * L;

}

void Mapmaker::print(){
  printf("bounds:\n");
  for(auto i =0; i < bounds.size(); i++){
    int L, U;
    tie(L, U) = bounds[i];
    printf("\tBound[%d] = [%d %d] \n", i, L, U);
  }
   printf("C:\n");
   for(auto i = 0; i < C.size(); i++){
    printf("\tC[%d] = %d\n", i, C[i]);
   }
}

void Mapmaker::addBound(int L, int U){
  bounds.push_back(std::tie(L, U));
}

int Mapmaker::physical(vector<int>& ref){
  int address = 0;
  for(size_t i = 0; i <= D; i++){
    address += C[i] * ref[i];
  } 
  return address;
}

int main()
{
  int N, R;
  scanf("%d%d", &N, &R);

  string name;
  int b,e,d, L, U;

  map<string, Mapmaker> pool;

  for(int i = 0; i < N; i++){
    cin>>name;
    scanf("%d%d%d", &b, &e, &d);
    
    pool.insert(std::pair<string, Mapmaker>(name, Mapmaker(name, b, e, d)));

    while(d--){
      scanf("%d%d", &L, &U);
      pool[name].addBound(L, U);
    }
    pool[name].init();
  }

  while(R--){
    cin>>name;
    d = pool[name].D;

    ostringstream ss;
    ss.clear();
    ss<<name<<"[";

    vector<int> ref(d);
    int t;
    ref[0] = 1;

    for(int i = 1; i <= d; i++){
      scanf("%d", &t);
      ref[i] = t;
      if(i!=1){
        ss<<", ";
      }
      ss<<t;
    }
    ss<<"]";

    int addr = pool[name].physical(ref);    
    //pool[name].print();
    cout<<ss.str()<<" = "<<addr<<endl;
  }
}
