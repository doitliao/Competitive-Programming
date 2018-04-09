#include <bits/stdc++.h>

using namespace std;


map<unsigned, int> chain;
int chainLength(unsigned long long n){
  if(n == 1)return 1;
  if(chain[n] != 0)return chain[n];
  
  int cnt = 1;
  if(n&1){
    cnt += chainLength(3*n + 1);
  }else{
    cnt += chainLength(n / 2);
  }

  chain[n] = cnt;
  cout<<n<<" chain = "<<chain[n]<<endl;

  return chain[n];
}

int main() {
  unsigned long long n;
  cin>>n;
  //cout<<chainLength(n)<<endl;
  //return 0;
  int m = 0;
  int mi = 0;
  for(int i = 1; i <= n; i++){
    int x = chainLength(i);
    if (x > m){
      m = x;
      mi = i;
      cout<<"new max: "<<i<<" "<<m<<endl;
    }
  }
  cout<<mi<<" "<<m<<endl;
}
