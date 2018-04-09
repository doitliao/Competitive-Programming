#include <bits/stdc++.h>

using namespace std;

int main() {
  int x;
  cin>>x;
  while(x--) {
    string line;
    getline(cin, line);
    getline(cin, line);
    getline(cin, line);
    istringstream is(line);
    vector<int> p;
    int n;
    while(!is.eof()) {
      is>>n;
      p.push_back(n - 1);
    }

    n = p.size();
    string z;
    vector<string> arr(n);
    for(int i = 0; i < n; i++) {
      cin>>z;
      arr[p[i]] = z;
    }

    for(string & a: arr){
      cout<<a<<endl;
    }
    if(x){
      cout<<endl;
    }
  }
}
