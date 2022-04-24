#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc243/tasks/abc243_d
// 途中でオーバーフローするパターンにどう対処すべきか
// U で undo される部分を読み飛ばせばいけそう
void solve(){ 
    ll N,X; cin >> N >> X;
    string s; cin >> s;
    vector<int> shouldSkip(N,0);
    int uCounter = 0;
    for(int i=N-1;i>=0;--i){
        if(s[i]=='U'){
            ++uCounter;
        }else{
            if(uCounter){
                shouldSkip[i] = 1;
                --uCounter;
            }
        }
    }
    int skipCounter = 0;
    REP(i,N){
        if(shouldSkip[i]){
            ++skipCounter;
            continue;
        }
        if(s[i]=='U'){
            if(skipCounter){
                shouldSkip[i] = 2;
                --skipCounter;
            }
        }
    }
    if(DEBUG){
        REP(i,N) cout << shouldSkip[i]<< ' ';
        cout << '\n';
    }
    REP(i,N){
        if(shouldSkip[i]) continue;
        if(s[i]=='U'){
            X /= 2;
        }
        else if(s[i]=='L'){
            X = X*2;
        }
        else if(s[i]=='R'){
            X = X*2 + 1;
        }
    }
    cout << X << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}