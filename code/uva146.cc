#include <bits/stdc++.h>

using namespace std;

int main() {
  while(true){
    string s;
    getline(cin, s);
    if(s == "#")break;

    if(next_permutation(s.begin(), s.end())){
      cout<<s<<endl; 
    }else{
      cout<<"No Successor"<<endl;
    }
  }
}
