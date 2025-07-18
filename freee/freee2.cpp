#include <vector>
#include <map>
#include <stack>
#include <iostream>
using namespace std;

/**
前処理として、例えばnums[j]を見ているとき左側(i<j)の自分より小さい要素の数と、右側の自分より小さい要素の数(j<i)を計算します。
スタックの更新方法は
1.スタックに値が入っていなければ自分自身を追加
2.スタックに値が入っている
    1.その値とnums[j]を比較して
        1.nums[j]の方が大きければそのスタックのleft_biggerの値に+1したものをcount(暫定のnums[j]より小さい要素の数)に保存。これを繰り返す。
        2.nums[j]以下だった場合countをleft_bigger[j]に入れて終了

上記の操作を右側も同じように行う。
*/
vector<int> solution(vector<int> nums) {
    // TODO: Implement me!
    
    //配列の長さを取得
    int n = nums.size();


    //左側の自分未満の要素の数
    vector<int> left_bigger(n, 0);
    //右側の自分未満の要素の数
    vector<int> right_bigger(n, 0);

    //自分自身のみの配列があるので1は確定
    vector<int> ans(n, 1);

    stack<int> sta;
    for(int i = 0; i < n; i++) {
        int count = 0;
        while (sta.size() && nums[sta.top()] < nums[i]) {
            count += left_bigger[sta.top()] + 1;
            sta.pop();
        }
        left_bigger[i] = count;
        sta.push(i);
    }
    //スタックを初期化
    while(sta.size()) sta.pop();

    //右側も同じように処理する
    for(int i = n - 1; i >= 0; i--) {
        int count = 0;
        while(sta.size() && nums[sta.top()] < nums[i]) {
            count += right_bigger[sta.top()] + 1;
            sta.pop();
        }
        right_bigger[i] = count;
        sta.push(i);
    }
    for (int i = 0; i < n; i++) {
        ans[i] += (left_bigger[i] + right_bigger[i]);
    }
    return ans;
}



int main() {
    vector<int> nums = {3,4,1,6,9,3};
    vector<int> ans = solution(nums);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<endl;
    }
}
/**
 * @brief 以下に、計算量を改善するためのアイデアをいくつか提案します。

前処理として、左側の大きい要素の数と右側の大きい要素の数を累積的に計算する。

これにより、それぞれのカウントを独立して計算する必要がなくなります。
左側から右に向かって進む際に、カウントを更新していくことで効率的に累積的なカウントを求めることができます。
スタックを使用して最大値の位置を追跡する。

スタックを使用して、現在の最大値の位置とその数を保持します。
配列を順番に走査しながら、スタックを更新していきます。
スタックのトップには、現在の最大値とその数が保持されるようにします。
これらのアイデアを組み合わせて、効率的な実装を行うことができます。以下に、改良された実装の例を示します。

この改良された実装では、前処理としてスタックを使用して累積的なカウントを計算し、各要素の条件を満たす部分配列の数を求めています。計算量はO(n)となり、効率的な実行が可能となります。
ただし、このアプローチは配列を2回走査するため、空間計算量がO(n)となります。もし追加の空間を使わずに計算量を改善する必要がある場合は、動的計画法（DP）などの別のアプローチを検討することもできます。
 * 
 */