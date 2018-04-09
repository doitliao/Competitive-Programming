#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned a,b,c;
  while(!cin.eof()) {
    cin>>a;
    if(cin.eof())break;
    char *x = (char*)&a;
    char *y = (char*)&b;
    y[0] = x[3];
    y[1] = x[2];
    y[2] = x[1];
    y[3] = x[0];

    cout<<(int)a<<" converts to "<<(int)b<<endl;
  }
}
