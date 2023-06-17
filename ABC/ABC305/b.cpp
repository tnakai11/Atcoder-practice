#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc305/tasks/abc305_b
// 数直線上の位置を決めて map<char,int> に格納
void solve(){ 
    map<char,int> mp;
    mp['A'] = 0;
    mp['B'] = mp['A']+3;
    mp['C'] = mp['B']+1;
    mp['D'] = mp['C']+4;
    mp['E'] = mp['D']+1;
    mp['F'] = mp['E']+5;
    mp['G'] = mp['F']+9;
    char p,q; cin >> p >> q;
    cout << abs(mp[p]-mp[q]) << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}