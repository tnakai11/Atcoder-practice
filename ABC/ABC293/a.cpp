#include <bits/stdc++.h>
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc293/tasks/abc293_a
// 愚直にやるか出力順を入れ替える O(|S|)
void solve(){ 
    string s; cin >> s;
    int N = s.size();
    REP(i,N/2){
        swap(s[i*2+1],s[i*2]);
    }
    cout << s << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}
