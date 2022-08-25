link:- https://codeforces.com/problemset/problem/1593/E
code:-
  /******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        
        vector<vector<int>>graph(n+1);
        map<int,int>m;
        for(int i=0;i<n-1;i++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
            m[a]++;m[b]++;
        }
        if(n<=k){cout<<0<<endl;}
        else{
        queue<int>q;
        for(int i=1;i<graph.size();i++){
            if(graph[i].size()==1){
                q.push(i);
            }
        }
        vector<int>vis(n+1);
        while(q.size()>0 && k>0){
            
            int c=q.size();
            for(int i=0;i<c;i++){
            int cur = q.front();
            q.pop();
            vis[cur]=1;
            n--;
            for(auto x:graph[cur]){
                if(!vis[x]){
                    m[x]--;
                    if(m[x]==1)q.push(x);
                    
                }
            }
            }
            k--;
            
        }
        cout<<n<<endl;
        }
        
    }

    return 0;
}
