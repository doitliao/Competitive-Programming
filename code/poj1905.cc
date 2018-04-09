//#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>

double INF = 1e100;
double EPS = 1e-12;

int main()
{
  double L, n, L2;
  double C, R, theta;

  while (true){
    scanf("%lf%lf%lf", &L, &n, &C);
    if (L == -1 && n == -1 && C == -1){
      break;
    }

    L2 = ( 1 + n*C) * L;

    double low = 0, high = L * 0.5;
    double h = 0;
    while ((high - low) > EPS) {
      h = (low + high) / 2;
      R = (4 * h * h + L * L) / h / 8;
      double LL = 2 * R * asin(L / 2 / R);
      if (LL < L2) {
        low = h;
      }else{
        high = h;
      }
    } 

    printf("%.3lf\n", h);
  }
}
