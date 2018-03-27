#include <bits/stdc++.h>

using namespace std;

class SoundexIndexing{
  public:
    SoundexIndexing();
    string encode(string name);
  private:
    map<char, int> enc;
};

SoundexIndexing::SoundexIndexing(){
  vector<vector<char> > m;
  m.push_back({'A', 'E', 'I', 'O', 'U', 'Y', 'W', 'H'});
  m.push_back({'B', 'P', 'F', 'V'});
  m.push_back({'C', 'S', 'K', 'G', 'J', 'Q', 'X', 'Z'});
  m.push_back({'D', 'T'});
  m.push_back({'L'});
  m.push_back({'M', 'N'});
  m.push_back({'R'});


  for(int i = 0;  i < m.size(); i++){
    vector<char>& l = m[i];
    for(int j = 0; j < l.size(); j++){
      enc[l[j]] = i;
    }
  }
}

string SoundexIndexing::encode(string name){
  ostringstream ss;
  ss<<name[0];

  int cnt = 0;
  for(int i = 1; i < name.length(); i++){
    if(enc[name[i]] == 0)continue;

    if(enc[name[i]] == enc[name[i - 1]])continue;

    ss<<enc[name[i]];
    cnt++;
    if(cnt == 3 )break;
  }

  while(cnt != 3){
    ss<<'0';
    cnt++;
  }

  return ss.str();
}

int main(){
  SoundexIndexing soundex;
  string name, code;
  printf("         %-25s%s\n", "NAME", "SOUNDEX CODE");
  while(true){
    cin>>name;
    if(cin.eof())break;
    code = soundex.encode(name);
    printf("         %-25s%s\n", name.c_str(), code.c_str());
  }

  printf("%19s%s\n", "","END OF OUTPUT");
}
