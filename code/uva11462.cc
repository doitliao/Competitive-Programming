#include <bits/stdc++.h>

using namespace std;

int main() {
  while(true) {
    int n; 
    scanf("%d", &n);
    if(n == 0)break;

    map<int, unsigned> cnt;
    int age;
    for(int i = 0; i < n; i++){
      scanf("%d", &age);
      cnt[age]++;
    }

    bool first = true;
    for(auto it = cnt.begin(); it != cnt.end(); it++){
      for(int j = 0; j < it->second; j++){
        if(first){
          first = false;
        }else{
          printf(" ");
        }
        printf("%d", it->first);
      }
    }
    printf("\n");
  }
}
