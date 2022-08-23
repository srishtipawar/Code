Link: - https://codeforces.com/problemset/problem/913/B
Code:-
#include <bits/stdc++.h>

using namespace std;


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
    int ovr=0;
    for(int i=1;i<graph.size();i++){
        
        if(graph[i].size()!=0){
            ovr++;
            
        }
    }
    // cout<<ovr<<endl;
    int cur=0;
    for(int i=1;i<graph.size();i++){
        
        if(graph[i].size()!=0){
            int c=0;
            for(int j=0;j<graph[i].size();j++){
                if(graph[graph[i][j]].size()==0)c++;
            }
            if(c>=3)cur++;
            
        }
    }
    if(cur==ovr){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;
}
