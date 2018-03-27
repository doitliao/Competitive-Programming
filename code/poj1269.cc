#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <cstdio>
using namespace std;

double INF = 1e100;
double EPS = 1e-12;

class PT {
  public:
      double x, y; 
      PT() {}
      PT(double x, double y) : x(x), y(y) {}
      PT(const PT &p) : x(p.x), y(p.y)    {}
      PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
      PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
      PT operator * (double c)     const { return PT(x*c,   y*c  ); }
      PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q) {return p.x*q.x + p.y*q.y; }
double dist2(PT p, PT q) { return dot(p-q, p-q );}
double cross(PT p, PT q) { return p.x*q.y - p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
    return os << "(" << p.x << "," << p.y << ")"; 
}

// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) { 
  return fabs(cross(b-a, c-d)) < EPS; 
}

bool LinesCollinear(PT a, PT b, PT c, PT d) { 
  return LinesParallel(a, b, c, d)
      && fabs(cross(a-b, a-c)) < EPS
      && fabs(cross(c-d, c-a)) < EPS; 
}

// determine if line segment from a to b intersects with 
// line segment from c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (LinesCollinear(a, b, c, d)) {
    if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
      dist2(b, c) < EPS || dist2(b, d) < EPS) return true;
    if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
      return false;
    return true;
  }
  if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
  if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
  return true;
}

// compute intersection of line passing through a and b
// with line passing through c and d, assuming that unique
// intersection exists; for segment intersection, check if
// segments intersect first
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b=b-a; d=c-d; c=c-a;
  assert(dot(b, b) > EPS && dot(d, d) > EPS);
  return a + b*cross(c, d)/cross(b, d);
}

PT getPT()
{
  int x, y;
  scanf("%d%d", &x, &y);
  return PT(x, y);
}

int main(){
  int N;
  cin>>N;
  printf("INTERSECTING LINES OUTPUT\n");
  while(N--){
    PT a = getPT(); 
    PT b = getPT(); 
    PT c = getPT(); 
    PT d = getPT(); 

    if(LinesCollinear(a, b, c, d)){
      printf("LINE\n");
    }else if(LinesParallel(a, b, c, d)){
      printf("NONE\n");
    }else{
      PT p = ComputeLineIntersection(a, b, c, d);
      printf("POINT %.2lf %.2f\n", p.x, p.y);
    }
  }


  printf("END OF OUTPUT\n");
}
