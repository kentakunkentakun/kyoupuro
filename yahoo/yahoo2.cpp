#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, m1, m2, m3, m4;
  cin >> n >> m1 >> m2 >> m3 >> m4;
  vector<vector<string>> list(4, vector<string>(0));
  for (int i = 0; i < n; i++) {
    string s;
    int d;
    cin>>s>>d;

    //tag=0だとS, tag=1だとM, tag=2だとL, tag=3だとX
    int tag = -1;
    if (m1 <= d && d < m2) {
      tag = 0;
    } else if (m2 <= d && d < m3) {
      tag = 1;
    } else if (m3 <= d && d < m4) {
      tag = 2;
    } else {
      tag = 3;
    }

    list[tag].push_back(s);
  }
  
  for (int i = 0; i < 4; i++) {
    if (i == 0) cout<<"S:"<<endl;
    else if (i == 1) cout<<"M:"<<endl;
    else if (i == 2) cout<<"L:"<<endl;
    else cout<<"X:"<<endl;

    for (int j = 0; j < list[i].size(); j++) {
      cout << list[i][j] << endl;
    }
  }
}