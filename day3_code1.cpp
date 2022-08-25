link: - https://codeforces.com/problemset/problem/763/A
code:-
  /******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;
bool dfs(vector<vector<int>> &graph,int cur,vector<int>&vis,vector<int> &color,int r1){
    vis[cur]=1;
    int f=0;bool c=true;
    // bool k = true;
    for(auto x:graph[cur]){
        if(!vis[x]){
            f=1;
            c=c&dfs(graph,x,vis,color,r1);
            // cout<<x<<" "<<c<<endl;
            if(cur!=r1 && color[cur]!=color[x])return false;
        }
    }
    // cout<<c<<endl;
    return c;
    
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> color(n+1);
    for(int i=1;i<n+1;i++){
        int a;cin>>a;
        color[i] = a;
    }
    
    vector<bool>v(n+1,false);
    int r1=-1,r2=-1;
    for(int i=1;i<graph.size();i++){
        for(auto x: graph[i]){
            if(color[i]!=color[x]){
                r1=i;r2=x;
                break;
            }
        }
    }
    if(r1==-1){
        cout<<"YES"<<endl;
        cout<<1<<endl;
    }
    else{
        vector<int> vis1(n+1);
        // cout<<r1<<endl;
        bool a = dfs(graph,r1,vis1,color,r1);
        vector<int>vis2(n+1);
        bool b = dfs(graph,r2,vis2,color,r2);
        // cout<<a<<b;
        if(a){
            cout<<"YES"<<endl;
            cout<<r1<<endl;
        }else if(b){
            cout<<"YES"<<endl;
            cout<<r2<<endl;
        }else cout<<"NO"<<endl;
    }

    return 0;
}
