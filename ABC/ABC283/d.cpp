#include <bits/stdc++.h>
using namespace std;
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
// https://atcoder.jp/contests/abc283/tasks/abc283_d
// 状況を整理する
// - 括弧が閉じている文字列を良い文字列とする
// - S1~Sn まで文字を見ていく
// - Si が英小文字なら対応する文字のフラグを立てる。フラグがすでに立っていれば失敗。
// - Si がとじ括弧なら対応する括弧で閉じている部分についてフラグをリセットする。
// 失敗パターン
// - (a()a)
// - (a(a))
// - (a((a)))
// 成功パターン
// - (a)(a)
// 英小文字は高々26なのでそれぞれの文字についてダブりがないか調べればO(S)で通せそう
void solve(){ 
    string s; cin >> s;
    bool ok = true;
    for(char target='a';target<='z';++target){
        int depth = 0;
        int targetDepth = -1;
        for(char c:s){
            if(c=='('){
                ++depth;
                continue;
            }
            if(c==')'){
                if(targetDepth==depth) targetDepth = -1;
                --depth;
                continue;
            }
            if(c==target){
                if(targetDepth>=0){
                    ok = false;
                    break;
                }
                targetDepth = depth;
            }
        }
        if(!ok) break;
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}