#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//:が含まれている位置
int koron(string s) {
  if (s.find(':' != std::string::npos)) {
    return s.find(':');
  }
  return -1;
}
int main() {
  map<int, string> t;
  string ans = "";
  while(1) {
    string a;
    cin>>a;
    //コロンの位置
    int k = koron(a);
    if (k == -1) {
      int m = stoi(a);
      for(auto p : t){
        if (m%p.first == 0) {
          ans += p.second;
        }
      }
      if (ans == "") {
        ans = a;
      }
      break;
    } else {
      int i = stoi(a.substr(0, k));
      string j = a.substr(k+1, a.size());
      t[i] = j;
    }
  }
  cout<<ans<<endl;
  return 0;
}
