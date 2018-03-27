#include <bits/stdc++.h>

using namespace std;

int main(){
  char c;
  vector<char> word;
  while((c = getchar()) != EOF){
    if(c == ' ' || c == '\n'){
      for(int i = word.size() - 1; i >= 0; i--){
        putchar(word[i]);
      }
      putchar(c);
      word.resize(0);
    }else{
      word.push_back(c);
    }
  }
  
  for(int i = word.size() - 1; i >= 0; i--){
    putchar(word[i]);
  }
}
