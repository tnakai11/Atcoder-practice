#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
#define Liny "Yes\n"
#define Linn "No\n"
// https://atcoder.jp/contests/abc286/tasks/abc286_d
// 愚直にやると計算ステップ数が 50^50 になり無理
// DPでテーブルを作る方針でとけば　O(N max(B) X))でいけそう
int dp[55][10005]; // i種類目の硬貨まで使って j を達成できるか
void solve(){ 
    int N,X; cin >> N >> X;
    dp[0][0] = 1;
    bool ok = false;
    for(int i=1;i<=N;++i){
        int a,b; cin >> a >> b;
        for(int j=0;j<X;++j){
            if(dp[i-1][j]==0) continue;
            for(int k=0;k<=b;++k){
                int next = j + a*k;
                if(next>X) break;
                dp[i][next] = 1;
                if(next==X) {
                    ok = true;
                    break;
                }
            }
            if(ok) break;
        }
        if(ok) break;
    }
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}