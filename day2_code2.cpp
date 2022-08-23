link:-https://cses.fi/problemset/task/1674/
code:-
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>&graph,int cur,vector<int>&ans){
    int c=0;
    if(graph[cur].size()==0){
        ans[cur]=0;return;
    }
    for(auto x:graph[cur]){
        dfs(graph,x,ans);
        c+=ans[x]+1;
    }
    ans[cur]=c;
    return;
}

int main()
{
    int n;
    cin>>n;
    int j=2;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<n-1;i++){
        int a;
        cin>>a;
        graph[a].push_back(j);
        j++;
    }
    vector<int>ans(n+1);
    dfs(graph,1,ans);
    for(int i=1;i<n+1;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
