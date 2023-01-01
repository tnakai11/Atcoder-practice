#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
// https://atcoder.jp/contests/abc279/tasks/abc279_c
// 縦書きの文字列が横に並んでいると読み替える O(HW)
// 保有する文字列の種類と数が一致するか調べる O(W log W)程度
void solve(){ 
    // input
    int H,W; cin >> H >> W;
    string s[H],t[H];
    REP(i,H) cin >> s[i];
    REP(i,H) cin >> t[i];
    // transform
    map<string, int> mp,np;
    REP(j,W){
        string x = "";
        string y = "";
        REP(i,H){
            x += string(1,s[i][j]);
            y += string(1,t[i][j]);
        }
        mp[x] += 1;
        np[y] += 1;
    }
    // check
    bool ok = true;
    for(auto i = mp.begin(); i != mp.end() ; ++i) {
        string x = i->first;
        if(mp[x]!=np[x]){
            ok = false;
            break;
        }
        if(!ok) break;
    }
    // answer
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}