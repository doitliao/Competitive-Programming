#include <bits/stdc++.h>

using namespace  std;

vector<int> A;
map<int, int> m;
int max_sum(int i, int j) {
  int idx = i * (i - 1) / 2 + j - 1;
  if (idx >= A.size())return 0;
  if(m[idx] == 0){
    m[idx] = A[idx] + max(max_sum(i+1, j), max_sum(i+1, j + 1));
  }
  return m[idx];
}

int main() {
  int x;
  while(EOF != scanf("%d", &x)) {
    A.push_back(x);
  }

  cout<<A.size()<<endl;
  cout<<max_sum(1, 1)<<endl;
}
