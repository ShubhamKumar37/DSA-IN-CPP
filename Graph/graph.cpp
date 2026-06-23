#include<iostream>
#include<list>
#include<unordered_map>
#include<queue>
#include<vector>

using namespace std;

class Graph{
    public:
        unordered_map<int, list<pair<int, int>>> adjList;
        vector<bool> visited = vector<bool>(5, false);

        void addNodeGraph(int u, int v, bool directed, int weight = 0)
        {
            adjList[u].push_back({v, weight});
            if(!directed) adjList[v].push_back({u, weight});
            cout << "\n Node added successfully\n";
        }

        void printGraph()
        {
            for(auto i : adjList)
            {
                cout << i.first << " - ";
                for(auto j : i.second) cout << "{" << j.first << "-" << j.second << "}";
                cout << endl;
            }
        }

        void bfs()
        {
            queue<int> q;
            for(int i = 0; i < 5; i++)
            {
                if(!visited[i])q.push(i);
    
                while(!q.empty())
                {
                    int front = q.front();
                    q.pop();
                    
                    if(!visited[front])
                    {
                        cout << front << " - ";
                        for(auto j : adjList[front]) q.push(j.first);
                    }
                    visited[front] = true;
                }

            }

            for(int i = 0; i < visited.size(); i++) visited[i] = 0;
        }

        void dfs(int src)
        {
            cout << src << " ";
            visited[src] = true; 

            for(auto i : adjList[src]) if(!visited[i.first]) dfs(i.first);
        }
};

int main()
{
    Graph g;
    g.addNodeGraph(0, 1, 1);
    g.addNodeGraph(0, 2, 1, 5);
    g.addNodeGraph(2, 1, 1);
    g.addNodeGraph(2, 3, 1);
    g.addNodeGraph(3, 4, 1, 819);

    g.printGraph();
    g.bfs();

    cout << endl;

    g.dfs(0);

    return 0;
}
