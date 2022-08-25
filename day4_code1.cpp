link:- https://cses.fi/problemset/task/1132/
code:-
  #include <bits/stdc++.h>

using namespace std;
void dfs(vector<vector<int>>&graph,int cur,int &ans,vector<int> &vis,int dis,int &ovr){
    vis[cur]=1;
    int f=0;
    
    for(auto x:graph[cur]){
        if(!vis[x]){
            f=1;
            dfs(graph,x,ans,vis,dis+1,ovr);
        }
    }
    if(f==0 && dis>ovr){ovr=dis;ans = cur;}
    return;
}
void dfs2(vector<vector<int>>&graph,int cur,vector<int> &vis,vector<int>&v1){
    vis[cur]=1;
    int f=0;
    for(auto x:graph[cur]){
        if(!vis[x]){
            f=1;
            v1[x]=v1[cur]+1;
            // cout<<x<<"?"<<v1[x]<<" ";
            dfs2(graph,x,vis,v1);
        }
    }
    
    return;
}
int main()
{
    
    
        int n;
        cin>>n;
        
        vector<vector<int>>graph(n+1);
        
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            
        }
        vector<int> vis(n+1);
        int ans=1;int ovr=0;
        dfs(graph,1,ans,vis,0,ovr);
        vector<int> vis2(n+1);
        int k=1;
        ovr=0;
        dfs(graph,ans,k,vis2,0,ovr);
        // cout<<k<<endl;
        for(int i=0;i<n+1;i++){
            vis[i]=0;vis2[i]=0;
        }
        vector<int> v1(n+1);
        vector<int> v2(n+1);
        dfs2(graph,ans,vis,v1);
        dfs2(graph,k,vis2,v2);
        for(int i=1;i<n+1;i++){
            
            v1[i] = max(v1[i],v2[i]);
        }
        for(int i=1;i<n+1;i++){
            cout<<v1[i]<<" ";
        }
        cout<<endl;
        

    return 0;
}
