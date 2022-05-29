#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc249/tasks/abc249_b
// sort してから小文字大文字チェック + 重複チェック
void solve(){ 
    string s; cin >> s;
    sort(ALL(s));
    bool hasBig = false;
    bool hasSmall = false;
    bool duplicate = false;
    REP(i,s.size()){
        char c = s[i];
        if('a' <= c && c <= 'z') hasSmall = true;
        else if('A' <= c && c <= 'Z') hasBig = true;
        if(i+1<s.size() && s[i]==s[i+1]){
            duplicate = true;
            break;
        }
    }
    string ans = Linn;
    if(hasBig && hasSmall && !duplicate) ans = Liny;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}