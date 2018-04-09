#include <bits/stdc++.h>

using namespace std;

class Factor{
  public:
    Factor(unsigned n):N(n), p(n), d(n){
      for(int i = 2; i < n; i++){
          if (!p[i]) {
            for (int x = i; x < n; x += i) {
              d[x].push_back(i);
              p[x] = true;
            }
          }
      }
    }
   
    vector<unsigned> get(int x){
      return d[x];
    } 
    const unsigned N;
    vector<bool> p; // is not prime number.
    vector<vector<unsigned> > d;
};

class Coprime {
public:
  Coprime(unsigned n):N(n), factor(n) {
    for(int i = 2; i < n; i++){
      cp.insert(i);
    }
  }

  void add(int a){
    for(auto x : factor.get(a)) {
      for (int i = x; i < N; i += x) {
	cp.erase(i);
      }
    }
  }

  unsigned get(unsigned low){
    return * cp.lower_bound(low);
  }
  const unsigned N;	
  Factor factor;
  std::set<unsigned> cp;
};

int main() {
  Factor ft(200005);
  for(int x:ft.get(30030)){
    cout<<x<<" ";
  }
  cout<<endl;

  Coprime c(200005);
  c.add(210);
  cout<<c.get(0)<<endl;
}
