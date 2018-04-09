#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int N, x;
    scanf("%d", &N);
    vector<int> train;
    for(int i = 0; i < N; i++){
      scanf("%d", &x);
      train.push_back(x); 
    }
    
    int g_cnt = 0;
    for(int i = 0; i < train.size(); i++){
      for(int j = i + 1; j < train.size(); j++) {
        if(train[i] > train[j]) g_cnt ++;
      }
    }

    printf("Optimal train swapping takes %d swaps.\n", g_cnt);
  }
}
