#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
struct UnionFind
{
  vector<T> par;
  vector<T> rank;
  vector<T> sizes;
  UnionFind(T n):par(n),rank(n,0),sizes(n,1){
    for(T i=0;i<n;i++){
      par[i]=i;
    }
  }
  T root(T x){
    return par[x]==x?x:par[x]=root(par[x]);
  }

  bool unite(T x,T y){
    if(x==y) return false;
    x=root(x); y=root(y);
    if(x==y) return false;
    if(rank[x]<rank[y]) swap(x,y);
    if(rank[x]==rank[y]) rank[x]++;
    par[y]=x;
    sizes[x]=sizes[x]+sizes[y];
    return true;
  }
  bool same(T x,T y){
    return root(x)==root(y);
  }
  T size(T x){
    return sizes[root(x)];
  }
};


struct LineSegment
{
  double x1, y1, x2, y2;
  LineSegment(int x1_0, int y1_0, int x2_0, int y2_0){
    x1 = x1_0;
    y1 = y1_0;
    x2 = x2_0;
    y2 = y2_0;
  };
};

bool CrossJudge(LineSegment l1, LineSegment ls2)
{
  double s, t;
  s = (l1.x1 - l1.x2) * (ls2.y1 - l1.y1) - (l1.y1 - l1.y2) * (ls2.x1 - l1.x1);
  t = (l1.x1 - l1.x2) * (ls2.y2 - l1.y1) - (l1.y1 - l1.y2) * (ls2.x2 - l1.x1);
  if (s * t > 0){
    return false;
  }
    
  s = (ls2.x1 - ls2.x2) * (l1.y1 - ls2.y1) - (ls2.y1 - ls2.y2) * (l1.x1 - ls2.x1);
  t = (ls2.x1 - ls2.x2) * (l1.y2 - ls2.y1) - (ls2.y1 - ls2.y2) * (l1.x2 - ls2.x1);
  if (s * t > 0) {
    return false;
  } 


  if (s == 0 && t == 0) {
    if (l1.y1 == l1.y1 && ls2.y1 == ls2.y2 && l1.y1 == ls2.y1) {
      if (max(l1.x1, l1.x2) < min(ls2.x1, ls2.x2) || max(ls2.x1, ls2.x2) < min(l1.x1, l1.x2)){
        return false;
      } else {
        return true;
      }
    } else if (l1.x1 == l1.x2 && ls2.x1 == ls2.x2 && l1.x1 == ls2.x1) {
      if (max(l1.y1, l1.y2) < min(ls2.y1, ls2.y2) || max(ls2.y1, ls2.y2) < min(l1.y1, l1.y2)){
        return false;
      } else {
        return true;
      }
    } else {
      return false;
    }
  }
  return true;
}

int main()
{
  int n;
  double l;
  cin >> n >> l;
  UnionFind<int> uf(n + 4);
  int left1 = n;
  int left2 = n+1;
  int right1 = n+2;
  int right2 = n+3;
  
  vector<LineSegment> v(0);
  
  pair<double, double> left1_p1 = make_pair(0, 0), left1_p2 = make_pair(0, l), left2_p1 = make_pair(0, l), left2_p2 = make_pair(l, l);
  pair<double, double> right1_p1 = make_pair(0, 0), right1_p2 = make_pair(l, 0), right2_p1 = make_pair(l, 0), right2_p2 = make_pair(l, l);

  v.push_back(LineSegment(0, 0, 0, l));
  v.push_back(LineSegment(0, l, l, l));
  v.push_back(LineSegment(0, 0, l, 0));
  v.push_back(LineSegment(l, 0, l, l));

  uf.unite(left1, left2);
  uf.unite(right1, right2);

  for (int i = 0; i < n; i++) {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    pair<double, double> p1 = make_pair(a, b), p2 = make_pair(c, d);
    
    LineSegment l(a, b, c, d);
    for (int j = 0; j < i; j++) {
      if (CrossJudge(v[j], l))
        uf.unite(i, j);
    }
    v.push_back(l);
    if (uf.same(left1, right1)){
      break;
    }
  }

  if (id == n) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}