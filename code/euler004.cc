#include <bits/stdc++.h>

using namespace std;

bool isPalindromic(unsigned n) {
  vector<unsigned> x;
  while (n > 0) {
    x.push_back(n % 10);
    n /= 10;
  }

  int i = 0, j = x.size() - 1;
  while (i < j) {
    if(x[i] != x[j])return false;
    i++;
    j--;
  }

  return true;
}

int main() {
  unsigned n;
  //cin>>n;
  //cout<<isPalindromic(n)<<endl;
  
  for (int i = 999; i >= 100; i--) {
    for(int j = 999; j >= 100; j--) {
      if(isPalindromic(i * j)){
        cout<<i<<" x "<<j<<" = "<<i*j<<endl;
      }
    }
  }
}
