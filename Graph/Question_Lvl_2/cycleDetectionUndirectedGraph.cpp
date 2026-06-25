class Solution {
  public:
  
    
    bool bfsDetectCycle(unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<int> &parent, int src)
    {
        queue<int> q;
        
        q.push(src);
        visited[src] = true;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            for(auto i : adj[front])
            {
                if(visited[i] && parent[front] != i) return true;
                else if(!visited[i])
                {
                    visited[i] = true;
                    parent[i] = front;
                    q.push(i);
                }
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        
        for(auto i : edges)
        {
            int src = i[0];
            int des = i[1];
            
            adj[src].push_back(des);
            adj[des].push_back(src);
        }
        
        bool flag = false;
        for(int i = 0; i < V; i++)
        {
            if(!visited[i]) flag = flag || bfsDetectCycle(adj, visited, parent, i);
            if(flag) return true;
        }
        
        return false;
    }
};

class Solution {
  public:
  
    
    bool bfsDetectCycle(unordered_map<int, vector<int>> &adj, vector<bool> &visited, vector<int> &parent, int src)
    {
        queue<int> q;
        
        q.push(src);
        visited[src] = true;
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            
            for(auto i : adj[front])
            {
                if(visited[i] && parent[front] != i) return true;
                else if(!visited[i])
                {
                    visited[i] = true;
                    parent[i] = front;
                    q.push(i);
                }
            }
        }
        
        return false;
    }
    bool dfsDetectCycle(unordered_map<int, vector<int>> &adj, vector<bool> &visited, int parent, int src)
    {
        visited[src] = true;
        bool flag = false;
        for(auto i : adj[src])
        {
            if(visited[i] && parent != i) return true;
            else if(!visited[i])
            {
                flag = dfsDetectCycle(adj, visited, src, i);
                if(flag) return true;
            }
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);
        
        for(auto i : edges)
        {
            int src = i[0];
            int des = i[1];
            
            adj[src].push_back(des);
            adj[des].push_back(src);
        }
        
        bool flag = false;
        for(int i = 0; i < V; i++)
        {
            if(!visited[i]) flag = flag || dfsDetectCycle(adj, visited, -1, i);
            if(flag) return true;
        }
        
        return false;
    }
};