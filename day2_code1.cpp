link:-https://codeforces.com/problemset/problem/580/C
code:-
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>&graph,int cur,int co,int m,vector<int>&v,int &ans,vector<int>&vis){
    if(co>m)return;
    if(v[cur]==1)co++;
    // cout<<co<<endl;
    vis[cur]=1;
    if(co>m)return;
    
    // if(graph[cur].size()==1){
    //     if(co<=m)ans++;
        
    //     return;
    // }
    int f=0;
    for(auto x:graph[cur]){
        if(!vis[x]){
            f=1;
            if(v[x]==0)dfs(graph,x,0,m,v,ans,vis);
            else dfs(graph,x,co,m,v,ans,vis);
        }
    }
    if(f==0){
        if(co<=m)ans++;
        return;
    }
    return;
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n+1);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v[i+1]=a;
    }
    vector<int> vis(n+1,0);
    vector<vector<int>> graph(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int ans=0;
    dfs(graph,1,0,m,v,ans,vis);
    cout<<ans<<endl;

    return 0;
}
