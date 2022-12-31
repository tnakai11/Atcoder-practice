#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
// https://atcoder.jp/contests/abc277/tasks/abc277_b
// やるだけ
void solve(){ 
    int N; cin >> N;
    map<string,int> mp;
    bool ans = true;
    REP(i,N){
        string s; cin >> s;
        // ダブり
        if(mp[s]>0){
            ans = false;
        }
        ++mp[s];
        // 1文字目
        char c = s[0];
        if(!( 
            c=='H' || 
            c=='D' ||
            c=='C' ||
            c=='S' 
        )){
            ans = false;
        }
        // 2文字目
        char d = s[1];
        if( 
            d=='A' || 
            d=='T' ||
            d=='J' ||
            d=='Q' ||
            d=='K'
        ){
            continue;
        }
        int diff = d-'0';
        if(
            2 <= diff &&
            diff <= 9
        ){
            continue;
        }
        ans = false;
    }
    // ans
    cout << (ans?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}