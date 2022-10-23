#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc267/tasks/abc267_a
// if 文で曜日ごとに分岐させるので十分
// 曜日と１週間の何日目であるかとをマッピングさせておくと多少マシ?
void solve(){ 
    map<string,int> mp;
    mp["Monday"] = 1;
    mp["Tuesday"] = 2;
    mp["Wednesday"] = 3;
    mp["Thursday"] = 4;
    mp["Friday"] = 5;
    mp["Saturday"] = 6;
    string s; cin >> s;
    int ans = mp["Saturday"] - mp[s];
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}