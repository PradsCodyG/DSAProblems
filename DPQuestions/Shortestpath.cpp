//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> dist(n+1,1e9),parent(n+1);
        dist[1]=0;
        for(int i=1;i<=n;i++)         parent[i]=i;
        set<pair<int,int>> s;
        s.insert({0,1});
        while(!s.empty())
        {
          auto it=*(s.begin());
          int node=it.second;
          int dis=it.first;
          s.erase(it);
          for(auto i:adj[node])
          {
              int adjnode=i.first;
              int w=i.second;
              if(w+dis<dist[adjnode])
              {
                  if(dist[adjnode]!=1e9)
                   s.erase({dist[adjnode],adjnode});
                dist[adjnode]=w+dis;
                parent[adjnode]=node;
                s.insert({dist[adjnode],adjnode});
              }
          }
        }
          if(dist[n]==1e9)
           return {-1};
           int node=n;
           vector<int> ans;
           while(parent[node]!=node)
           {
               ans.push_back(node);
               node=parent[node];
           }
           ans.push_back(1);
           reverse(ans.begin(),ans.end());
           return ans;
          
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends