#include <bits/stdc++.h>

using namespace std;

const unsigned N = 1000009;
unsigned cycle[N];

unsigned c(unsigned x)
{
  if(x == 1){
    return 1;
  }
  if(x < N && cycle[x] != 0){
    return cycle[x];
  } 

  if(x & 1 == 1){
    return 1 + c(3*x + 1);
  }

  return c(x/2) + 1;
}

void init()
{
  for(unsigned i = 1; i < N; i++)
  {
    cycle[i] = c(i);
  }
}

unsigned max_cycle(unsigned i, unsigned j){
  unsigned m = cycle[j];
  for(unsigned k = i;  k < j; k++){
    if(cycle[k] > m){
      m = cycle[k];
    }
  }
  return m;
}

int main()
{
  memset(cycle, 0, N);  
  init();
  unsigned i, j;
  while(EOF != scanf("%u%u", &i, &j)){
    printf("%u %u %u\n", i, j, max_cycle(min(i, j), max(i, j)));
  }
}
