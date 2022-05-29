#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc250/tasks/abc250_b
// やるだけ
// 記述量をうまく減らしたい
char func(char c){
    if(c=='.') return '#';
    return '.';
}
void solve(){ 
    int N,A,B; cin >> N >> A >> B;
    REP(tileH,N){
        char c = '.';
        if(tileH%2) c = '#';

        string s = "";
        REP(tileW,N){
            if(tileW%2==0){
                s += string(B,c);
            }else{
                s += string(B, func(c));
            }
        }

        REP(a,A){
            cout << s << '\n';
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}