#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<string> tmp(N);
  for (int i = 0; i < N; i++) {
    cin>>tmp[i];
  }
  int n;
  cin>>n;
  for(int i = 0; i < n; i++){
    int l;
    cin>>l;
    //置換する文字列と、置換後の文字列を格納するmap
    map<string, string> table;
    
    for(int j = 0; j < l; j++){
      string a, b;
      cin>>a>>b;
      table[a] = b;
    }

    //置換後の文字列を格納する変数
    string ans = "";
    //置換がうまくいくかどうかを判定する変数
    bool valid = true;

    for(int j = 0; j < N; j++) {
      //置換対象の文字列だったら
      if (tmp[j][0] == '#') {
        //置換対象の文字列がmapにあるかどうか
        if (table.count(tmp[j])) {
          ans += table[tmp[j]];
        } else {
          valid = false;
        }
      } else {
        ans += tmp[j];
      }
      ans += " ";
    }
    if (valid) {
      cout<<ans<<endl;
    } else {
      cout<<"Error: Lack of data"<<endl;
    }
  }
}