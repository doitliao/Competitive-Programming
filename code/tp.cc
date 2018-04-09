#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;
class AB{
 public:
    string createString(int N, int K){
        int A = N / 2;
        int B = N - A;
        
        bool finished = false;
        ostringstream ss;

        while(true){
          if(A * B == K){
            while(A--)ss<<'A';
            while(B--)ss<<'B';
            break;
          }else if(A * B > K){
            if(K > A * (B - 1)){
              ss<<'A';
              A--;
              K -= B;
            }else{
              ss<<'B';
              B--;
            }
          }else{
            return "";
          }
        }
        return ss.str();
    }
};

int main()
{
  AB x;
  cout<<x.createString(10, 12)<<endl;
}
