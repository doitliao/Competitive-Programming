#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  int t, a, max_a;
  cin>>n;
  for(int i = 1; i <= n; i++){
    scanf("%d", &t);
    max_a = 0;
    while(t--){
      scanf("%d", &a);
      if(a > max_a){
        max_a = a;
      }
    }

    printf("Case %d: %d\n", i, max_a);
  }
}
