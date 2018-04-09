#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <cstdio>

using namespace std;

double INF = 1e100;
double EPS = 1e-12;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
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

int main() {
  int n = 0;
  while(true) {
    scanf("%d", &n);
    if(n == 0)break;

    double x1, y1, x2, y2;
    vector< vector<PT> > line_list;
    set<unsigned> top_sticks;
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
      vector<PT> x;
      x.push_back(PT(x1, y1));
      x.push_back(PT(x2, y2)); 
      line_list.push_back(x);
      for(set<unsigned>::iterator it = top_sticks.begin(); it != top_sticks.end(); ){
        unsigned line = *it;
        if(SegmentsIntersect(line_list[line][0], line_list[line][1], line_list[line_list.size() - 1][0], line_list[line_list.size() - 1][1])) {
          top_sticks.erase(it++);
        } else {
          it++;
        }
      }

      top_sticks.insert(line_list.size() - 1);

    }

    printf("Top sticks:");
    for(set<unsigned>::iterator it = top_sticks.begin(); it != top_sticks.end(); ){
      printf(" %u", *it + 1);
      it++;
      if(it == top_sticks.end()){
        printf(".\n");
      }else{
        printf(",");
      }
    }

  }
}
