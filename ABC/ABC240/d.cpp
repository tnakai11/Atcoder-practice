#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc240/tasks/abc240_d
// (値,連続数)のペアをスタックすれば O(N) でいけるはず

struct block {
    int key;
    int num;
};
void solve(){ 
    int N; cin >> N;
    stack<block> st;
    st.push({0,0});
    int ans = 0;
    REP(i,N){
        int a; cin >> a;
        block b = st.top();
        if(b.key!=a){
            st.push({a,1});
            ++ans;
        }else{
            int nextNum = b.num + 1;
            if(nextNum<a){
                st.pop();
                st.push({a,nextNum});
                ++ans;
            }else{
                st.pop();
                ans -= (a-1);
            }
        }
        cout << ans << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}