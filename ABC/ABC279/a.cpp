#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc279/tasks/abc279_a
// v,wの個数を数えればOK
void solve(){ 
    string s; cin >> s;
    int v=0,w=0;
    for(char c:s){
        if(c=='v'){
            ++v;
        }else{
            ++w;
        }
    }
    int ans = 1*v + 2*w;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}