#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
// https://atcoder.jp/contests/abc271/tasks/abc271_c
// 歯抜けを見つけたら上から順に売っていく
// どこまで売ったかはインデックスで管理
// 計算量はO(N)
// ダブりを考慮する必要がある
int read[300005];
void solve(){ 
    int N; cin >> N;
    set<int> s;
    REP(i,N){
        int a; cin >> a;
        s.insert(a);
    }
    vector<int> v(ALL(s));
    int stock = N - v.size();
    
    int ans = 0;
    int unreadLeft = 0;
    int soldLeft = v.size();
    for(int x=1;x<=N;++x){
        if(v[unreadLeft]==x){
            ++ans;
            ++unreadLeft;
        }else{
            while(stock<2 && unreadLeft<soldLeft){
                soldLeft -=1;
                ++stock;
            }
            if(stock>=2){
                ++ans;
                stock -= 2;
            }else{
                break;
            }
        }
        if(soldLeft<=unreadLeft) break;
    }
    ans += stock/2;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}