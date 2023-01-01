#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
// https://atcoder.jp/contests/abc279/tasks/abc279_b
// 愚直に調べても O(len(S)len(T)) となり許容
void solve(){ 
    string s,t; cin >> s >> t;
    bool ans = false;
    int N = s.size();
    int M = t.size();
    REP(start,N){
        if(start+M>N) break;
        bool ok = true;
        REP(i,M){
            char c = s[start+i];
            char d = t[i];
            if(c!=d) {
                ok = false;
                break;
            }
        }
        if(ok){
            ans = true; 
            break;
        }
    }
    cout << (ans?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}