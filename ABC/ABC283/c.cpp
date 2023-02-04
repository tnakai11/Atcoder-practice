#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc283/tasks/abc283_c
// Sの最大値が巨大なので数として扱うのは厳しい
// 文字列として下からパースすればよさそう
void solve(){ 
    string s; cin >> s;
    int N = s.size();
    int ans = 0;
    for(int i=N-1;i>=0;--i){
        ++ans;
        if(i==0){
            continue;
        } 
        if(s[i]!='0'){
            continue;
        }
        int j = i-1;
        if(s[j]=='0'){
            --i;
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}