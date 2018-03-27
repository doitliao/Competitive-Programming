#include <bits/stdc++.h>

using namespace std;

int main(){
  int N,B,H,W;
  while(EOF != scanf("%d%d%d%d", &N, &B, &H, &W)){
    double budget = B * 1.0 / N;
    int price;
    unsigned min_price = -1;
    for(int i = 0; i < H; i++){
      bool sat = false;
      int ava = 0;
      scanf("%d", &price);
      for(int j = 0; j < W; j++){
        scanf("%d", &ava);
        if(ava >= N && price <= budget){
          sat = true;
        }
      } 
      
      if(sat && min_price > price){
        min_price = price;
      }
    }

    if(min_price == -1){
      printf("stay home\n");
    }else{
      printf("%d\n", min_price * N);
    }
  }

}
