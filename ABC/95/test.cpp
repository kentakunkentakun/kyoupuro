#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() { 
  int a;
  cin>>a;
  vector<int> b(a,0);
  for(int i = 0; i < (int)b.size(); i++) {
    b[i] = 100-i;
    cout<<b[i]<<endl;
  }
  sort(b.begin(), b.end());
  for(int i = 0; i < (int)b.size(); i++) {
    cout<<b[i]<<endl;
  }
}
