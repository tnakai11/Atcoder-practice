#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc215/tasks/abc215_d
// 総当たりは 10^5 * 10^5 ステップだけ調査する必要があるため厳しい
// A_i に含まれる約数の数は √A_i 以下
// 約数の列挙に O (N √max(A))
// 倍数のマッピングに O(M √max(A))
int N,M; 
vector<int> a;
map<int,int> mp;
vector<int> isOK(100005,1);
vector<int> ans;
void solve(){ 
    cin >> N >> M;
    REP(i,N){
        int x; cin >> x;
        a.emplace_back(x);
    }
    for(int x: a){
        int p = 2;
        while(p<=sqrt(x)){
            while(x%p==0){
                ++mp[p];
                x /= p;
            }
            ++p;
        }
        ++mp[x];
    }
    for(int p=2;p<=M;++p){
        if(mp[p]==0) continue;
        for(int q=p;q<=M;q+=p){
            isOK[q] = 0;
        }
    }
    for(int x=1;x<=M;++x){
        if(isOK[x]) ans.emplace_back(x);
    }
    cout << ans.size() << '\n';
    for(int x:ans){
        cout << x << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}