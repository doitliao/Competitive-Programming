#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  n --;
  int x = n / 3;
  int y = n / 5;
  int z = n / 15;

  int sum = 3 * x * (x + 1) / 2  + 5 * y * (y + 1) / 2 - 15 * z * (z + 1) / 2;

  cout<<x<<" "<<y<<" "<<z<<endl;

  cout<<sum<<endl;
}
