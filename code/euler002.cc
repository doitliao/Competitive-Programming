#include <bits/stdc++.h>

using namespace std;

int main()
{
  unsigned f1 = 1, f2 = 2, f3;
  unsigned sum = f2;
  f3 = f1 + f2;
  while(f3 < 4000000){
    if((f3 & 1) == 0){
      sum += f3;
    }

    f3 = f1 + f2;
    f1 = f2;
    f2 = f3;
  }
  cout<<sum<<endl;
}
