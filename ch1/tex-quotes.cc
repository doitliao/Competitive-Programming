#include <bits/stdc++.h>

using namespace std;

int main(){
  char c;
  bool left = true;
  while((c = getchar()) != EOF){
    if(c != '"'){
      printf("%c", c);
      continue;
    }

    if(left){
      printf("``");
    }else{
      printf("''");
    }

    left = ! left;
  }
}
