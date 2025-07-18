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
  LineSegment(double x1_0, double y1_0, double x2_0, double y2_0){
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
    if (l1.y1 == l1.y2 && ls2.y1 == ls2.y2 && l1.y1 == ls2.y1) {
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
  //スタートからゴールにかけてできる四角形のうちスタートとゴールを結んで左側の辺と右側の辺に分ける
  int left1 = n;
  int left2 = n+1;
  int right1 = n+2;
  int right2 = n+3;
  LineSegment dl(-1, -1, -1, -1);

  //辺を記録していく配列
  vector<LineSegment> v(0, dl);

  v.push_back(LineSegment(0, 0, 0, l));
  v.push_back(LineSegment(0, l, l, l));
  v.push_back(LineSegment(0, 0, l, 0));
  v.push_back(LineSegment(l, 0, l, l));

  //左の辺と右の辺をつなげる
  uf.unite(left1, left2);
  uf.unite(right1, right2);

  int id = -1;
  for (int i = 0; i < n; i++) {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    
    LineSegment l(a, b, c, d);
    for (int j = 0; j < i + 4; j++) {
      if (CrossJudge(v[j], l)) {
        uf.unite(i, j);
      }
    }
    v.push_back(l);
    if (uf.same(left1, right1)){
      id = i + 1;
      break;
    }
  }
  if (id == -1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
    cout << id << endl;
  }
}