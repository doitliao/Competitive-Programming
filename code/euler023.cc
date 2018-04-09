#include <bits/stdc++.h>

using namespace std;

unsigned long long d(unsigned long long n) {
  unsigned long long sum = 1;
  if(n == 2)return sum;
  unsigned long long i;
  for (i = 2; i * i < n; i++) {
    if ((n%i) == 0) {
      sum += i + (n / i);
    }
  }

  if(i*i == n) {
    sum += i;
  }
  return sum;
}

int main() {
  set<unsigned> abundant;
  for(int i = 1; i < 28123; i++) {
    if(d(i) > i){
      abundant.insert(i);
    }
  }

  unsigned long long sum= 28123 * 28122 / 2;
  set<unsigned> xs;
  for(auto i = abundant.begin(); i != abundant.end(); i++) {
    for (auto j = abundant.begin(); j != abundant.end(); j++){
      unsigned x = *i + *j;
      if(x < 28123){
        //cout<<*i<<" "<<*j<<" = "<<x<<endl;
        xs.insert(x);
      }
    }
  }

  for (auto it = xs.begin(); it != xs.end(); it++) {
    sum -= *it;
  }
  cout<<sum<<endl;
}
