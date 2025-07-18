#include <iostream>
#include <vector>
using namespace std;

//二つの配列を引数にとり、お互いの最初の値を比較する。
bool compareInterval(vector<int> interval1, vector<int> interval2) {
    return interval1[0] < interval2[0]; //最初の値で昇順ソート
}

vector<vector<int>> solution(vector<vector<int>> intervals) {
    // TODO: Implement me!

    // compareIntervalを使用して最初の配列の値を基に昇順ソートする
    sort(intervals.begin(), intervals.end(), compareInterval);

    vector<vector<int>> ans;
    //　昇順ソートしているのでintervalsの先頭の配列が、最初の区間の要素であることは保証されている
    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        //ひとつ前の区間と重なっていたらマージ
        //重なっていなかったら新たな区間としてans配列に追加
        if (intervals[i][0] <= ans.back()[1]) {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        } else {
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}