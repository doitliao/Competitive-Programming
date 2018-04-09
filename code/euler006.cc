#include <iostream>

using namespace std;

int main() {
  unsigned n; 
  cin>>n;
  cout<< n*n*(n+1)*(n+1) / 4 - n*(n+1)*(2*n+1) / 6<<endl;
}
