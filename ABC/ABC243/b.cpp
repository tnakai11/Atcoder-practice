#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc243/tasks/abc243_b
// 1 は愚直に調べればOK 計算量は O(N)
// 2 はAの中身をmap に控えてから B の各値を突き合わせていく 計算量は O(N log N)
int a[1005];
map<int,int> mp;
void solve(){ 
    int N; cin >> N;
    REP(i,N){
        cin >> a[i];
        ++mp[a[i]];
    }
    int ans1 = 0;
    int ans2 = 0;
    REP(i,N){
        int b; cin >> b;
        if(a[i]==b){
            ++ans1;
        }else{
            if(mp[ b ]>0){
                ++ans2;
            }
        }
    }
    cout << ans1 << '\n';
    cout << ans2 << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}