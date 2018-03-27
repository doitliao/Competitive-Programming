#include <bits/stdc++.h>

using namespace std;

int main(){
  int n,m,c, seq;
  seq = 0;
  while(true){
    seq++;
    scanf("%d%d%d", &n, &m, &c);
    if(n == 0 && m == 0 && c == 0)break;
    vector<std::tuple<int, bool> > C;
    int ci;
    bool on = false;
    for(int i = 0; i < n; i++){
       cin>>ci;
       C.push_back(std::tie(ci, on)); 
    }
    
    int cons = 0;
    int k;
    int max_c = 0;
    for(int i = 0; i < m; i++){
      cin>>k;
      k --;
      std::tie(ci, on) = C[k];
      if(on){
        cons -= ci;
      } else{
        cons += ci;
        if(cons > max_c)max_c = cons;
      }
      on = ! on;
      C[k] = std::tie(ci, on);
    }

    printf("Sequence %d\n", seq);
    if(max_c > c){
      printf("Fuse was blown.\n\n");
    }else{
      printf("Fuse was not blown.\n");
      printf("Maximal power consumption was %d amperes.\n\n", max_c);
    }
  }
}
