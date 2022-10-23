#include <bits/stdc++.h>
using namespace std;
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
// https://atcoder.jp/contests/abc271/tasks/abc271_d
// 愚直に全パターンを調べるとO(2^N) となり無理
// DPなら O(NS) でいける
// と思ったら１例を出力する必要があるのか
// ホップ前の値も格納しておいて逆にたどる
struct choice{
    int can;
    int pre;
    char hand;
};

choice dp[105][10005]; // i 枚目を選んだ時 j は可能か
void solve(){ 
    int N,S; cin >> N >> S;
    dp[0][0] = {1,0,'N'};
    for(int i=1;i<=N;++i){
        int a,b; cin >> a >> b;
        for(int j=0;j<S;++j){
            if(dp[i-1][j].can==1){
                int nextJH = j + a;
                if(nextJH<=S){
                    dp[i][nextJH] = {1,j,'H'};
                }
                int nextJT = j + b;
                if(nextJT<=S){
                    dp[i][nextJT] = {1,j,'T'};
                }
            }
        }
    }
    if(dp[N][S].can==0){
        cout << Linn;
        return;
    }
    cout << Liny;
    stack<char> ans;
    int turn = N;
    int v = S;
    while(turn>0){
        char h = dp[turn][v].hand;
        ans.push(h);
        v = dp[turn][v].pre;
        --turn;
    }
    while(!ans.empty()){
        char h = ans.top(); ans.pop();
        cout << h;
    }
    cout << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}