#include <bits/stdc++.h>
using namespace std;
// https://atcoder.jp/contests/abc226/tasks/abc226_b
// 数列を文字列とみなして重複を除けばOK
// 要素数を M , 要素の最大値を A として O( N + M log A )
void solve(){ 
    int N; cin >> N;
    map<string,int> mp;
    int ans = 0;
    string s;
    while(getline(cin,s)){
        if(s.size() && mp[s]==0){
            ++mp[s];
            ++ans;
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  solve();
  return 0;
}