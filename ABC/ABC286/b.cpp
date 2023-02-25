#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
// https://atcoder.jp/contests/abc286/tasks/abc286_b
// naの間にyを挿入すればOK
void solve(){ 
    int N; cin >> N;
    string s; cin >> s;
    REP(i,N){
        char c = s[i];
        cout << c;
        if(c!='n') continue;
        if(i+1>=N) continue;
        char d = s[i+1];
        if(d=='a') cout << 'y';
    }
    cout << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}