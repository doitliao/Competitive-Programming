#include <bits/stdc++.h>

using namespace std;

class Score {
  public:
    Score(){
      id = -1;
      score = 0;
      cnt = 0;
      total_p = 0;
      pro.clear();
      a.clear();
    }
    int cnt;
    int score;
    int id;
    int total_p;
    map<int, int> pro;
    map<int, bool> a;

    void ic(int i, int p, int t){
      id = i;
      if(a[p] != true){
        pro[p] += 20;
      }
    }

    void ac(int i, int p, int t){
      id = i;
      if(a[p] != true){
        a[p] = true;
        score += t + pro[p];
        cnt++;
        total_p += pro[p];
      }
    }

    void submission(int i, int p, int t){
      id = i;
    }
};

int main() {
  int t;
  scanf("%d", &t);
  string line;
  getline(cin, line);
    getline(cin, line);

  while(t--) {
    vector<Score> s(109);
    //map<int, map<int, >
    while(true){
      getline(cin, line);
      if(line == "" || cin.eof())break;

      istringstream is(line);
      int c,p,t;
      string ch;

      is>>c>>p>>t>>ch;

      if(ch[0] == 'I'){
        s[c].ic(c, p, t);
      }else if(ch[0] == 'C'){
        s[c].ac(c, p, t);
      }else{
        s[c].submission(c, p, t);
      }
    }
   
    sort(s.begin(), s.end(), [](const Score & a, const Score &b){
        if(a.cnt != b.cnt)return a.cnt > b.cnt;
        else if(a.score != b.score){
          return a.score < b.score;
        }else {
         return a.id < b.id; 
        }
        });

    for(int i = 0; i < s.size(); i ++){
      if(s[i].id == -1)continue;
      cout<<s[i].id<<" "<<s[i].cnt<<" "<<s[i].score<<endl;
    }

    if(t != 0){
      cout<<endl;
    }
  }
}
