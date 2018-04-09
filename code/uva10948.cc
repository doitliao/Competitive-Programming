#include <bits/stdc++.h>

using namespace std;

int main(){
  const int N = 1000009;
  vector<bool> p(N, false);
  set<int> primes;
  for(int i = 2; i < N; i++){
    if(p[i] == true)continue;
    for(int x = 2*i; x < N; x+=i){
      p[x] = true;
    }
    primes.insert(i);
  }

  while(true){
    int x;
    scanf("%d", &x);
    if(x == 0)break;

    printf("%d:\n", x);
    for(int i: primes){
      if((i + i) > x){
        printf("NO WAY!\n");
        break;
      }else if(p[x-i] == false){
        printf("%d+%d\n", i, x - i);
        break;
      }
    }
  }

}
