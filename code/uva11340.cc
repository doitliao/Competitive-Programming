#include <bits/stdc++.h>

using namespace std;

int main() {
  int t, K, M;
  scanf("%d", &t);
  while(t--){
    scanf("%d", &K);
    map<char, double> price;
    char c[2];
    char ch;
    double p;
    for(int i = 0; i < K; i++){
      scanf("%s %lf", c, &p);
      ch = c[0];
      price[ch] = p;
    }

    scanf("%d", &M);
    int i = 0;
    double x = 0;
    string zz;
    getline(cin, zz);
    while(i < M) {
      while(true) {
        ch = getchar();
        if(ch == '\n'){
          break;
        }
        if(price.find(ch) != price.end())
          x += price[ch];
      }
      i++;
    }
    cout.setf(ios::fixed); cout << setprecision(2);
    cout<<x/ 100.0<<"$"<<endl;
    cout.unsetf(ios::fixed);
  }
}
