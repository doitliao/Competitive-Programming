#include <bits/stdc++.h>

using namespace std;

unsigned long long d(unsigned long long n) {
  unsigned long long sum = 1;
  if(n == 2)return sum;
  for (unsigned long long i = 2; i * i <= n; i++) {
    if ((n%i) == 0) {
      sum += i + (n / i);
    }
  }
  return sum;
}

int main() {
  set<unsigned> x;
  unsigned long long sum = 0;
  for(unsigned long long i = 2;  i < 10000; i++) {
    unsigned long long dx = d(i);
    if(i != dx && d(dx) == i) {
      cout<<i<<" "<<dx<<endl;
      x.insert(i);
      sum += i;
    }
  }

  cout<<sum<<endl;
  sum = 0;
  for(auto it = x.begin(); it != x.end(); it++) {
    sum += *it;
  }

  cout<<sum<<endl;
  return 0;
}
