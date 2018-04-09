#include <bits/stdc++.h>

using namespace std;

class DNA {
  public:
    DNA(string x):s(x){
      sortedness = 0;
      for(int i = 0; i < s.size(); i++){
        for(int j = i + 1; j < s.size(); j++){
          if(s[i] > s[j]) sortedness++;
        }
      }
    }
    string s;
    int sortedness;
};

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    int n, m;
    scanf("%d%d", &n,&m);
    vector<DNA> d;
    string s;
    for(int i = 0;  i < m; i++){
      cin>>s;
      d.push_back(DNA(s));
    }
    
    stable_sort(d.begin(), d.end(), [] (const DNA &a, const DNA &b){
          return a.sortedness < b.sortedness;
        });

    for(int i = 0; i < m; i ++) {
      cout<<d[i].s<<endl;
    }

    if(t){
      cout<<endl;
    }
  }

}
