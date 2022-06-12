#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc251/tasks/abc251_c
// 丁寧に読んで書く 
// map を使って O(N log N)
struct poem{
    int index;
    int score;
};
void solve(){ 
    int N; cin >> N;
    map<string,int> mp;
    // original
    vector<poem> v;
    REP(i,N){
        string s; cin >> s;
        int t; cin >> t;
        if(mp[s]==0){
            v.emplace_back((poem){i+1,t});
            ++mp[s];
        }
    }
    // best
    poem ans = {-1,-1};
    for(poem p:v){
        if(ans.score<p.score){
            ans = p;
        }
    }
    cout << ans.index << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}