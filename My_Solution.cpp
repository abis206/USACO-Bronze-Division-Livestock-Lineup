#include <bits/stdc++.h>
#define pb push_back


using namespace std;
const int MAXN = 100005;
typedef long long ll;
string s1[22];
string s2[22];
string names[] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
map<string, int> M;
int res[22];
int vis[22];
int n;
int op = 0;
bool check(){
    for(int i=0;i<n;i++){
        if(abs(vis[M[s1[i]]] - vis[M[s2[i]]]) != 1)return 0;
    }
    return true;
}
void func(int x){
    if(x == 8){
        if(check()){
            for(int i=0;i<8;i++){
                cout<<names[res[i]]<<"\n";
            }
            exit(0);
        }
        else{
            return;
        }
    }
    for(int i=0;i<8;i++){
        if(vis[i] != -1)continue;
        vis[i] = x+1;
        res[x] = i;
        func(x+1);
        vis[i] = -1;
        res[x] = 0;
    }
}

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s1[i]>>s2[i]>>s2[i]>>s2[i]>>s2[i]>>s2[i];
    }
    sort(names, names+8);
    for(int i=0;i<8;i++){
        M[names[i]] = i;
    }
    memset(vis, -1, sizeof(vis));
    func(0);
    return 0;
}

