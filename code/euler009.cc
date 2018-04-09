#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c;
  for (a = 1; a < 1000 / 3; a++) {
    for (b = a+1; b < (1000 - a - b); b++) {
      c = 1000 - a - b;
      if(c <= b)break;
      if(c*c == ( b*b + a*a)){
        cout<<a<<"*"<<b<<"*"<<c<<" = "<<a*b*c<<endl;
      }
    }
  }  
}
