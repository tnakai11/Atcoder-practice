#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc276/tasks/abc276_a
// 後ろから見ていく。 O(len(S))
void solve(){ 
    string s; cin >> s;
    int N = s.size();
    int ans = -1;
    for(int i=N-1;i>=0;--i){
        if(s[i]=='a'){
            ans = i+1;
            break;
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}