#include <iostream>
#include <vector>
using namespace std;

// Class representing a graph using adjacency list
class Graph {
    int vertices; // Number of vertices in the graph
    vector<vector<int>> adj; // Adjacency list representation

    // Utility function to find bridges in the graph
    void bridgeUtil(int u, vector<bool>& visited, int parent[], int disc[], int low[], int& time);

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int v);
    
    // Function to add an edge between two vertices
    void addEdge(int u, int v);
    
    // Function to find and print all bridges in the graph
    void findBridges();
};

// Constructor implementation
Graph::Graph(int v) {
    this->vertices = v; // Set the number of vertices
    adj.resize(v); // Resize the adjacency list to hold 'v' vertices
}

// Function to add an edge between vertices u and v
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v); // Add v to u's list
    adj[v].push_back(u); // Add u to v's list (undirected graph)
}

// Utility function to perform DFS and find bridges
void Graph::bridgeUtil(int u, vector<bool>& visited, int parent[], int disc[], int low[], int& time) {
    visited[u] = true; // Mark the current node as visited
    disc[u] = low[u] = ++time; // Initialize discovery time and low value

    // Explore all adjacent vertices
    for (int v : adj[u]) {
        if (!visited[v]) { // If v is not visited
            parent[v] = u; // Set parent of v
            bridgeUtil(v, visited, parent, disc, low, time); // Recur for DFS

            // Check if the subtree rooted at v has a connection back to one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // If the lowest vertex reachable from subtree under v is below u in DFS tree, then u-v is a bridge
            if (low[v] > disc[u]) {
                cout << "Bridge found: " << u << " - " << v << endl; // Print the bridge
            }
        } else if (v != parent[u]) { // Update low value of u for parent function calls
            low[u] = min(low[u], disc[v]);
        }
    }
}

// Function to find all bridges in the graph
void Graph::findBridges() {
    vector<bool> visited(vertices, false); // Mark all vertices as not visited
    int disc[vertices], low[vertices], parent[vertices]; // Arrays to store discovery times, low values, and parent vertices
    int time = 0; // Initialize time

    // Initialize parent and visited arrays
    for (int i = 0; i < vertices; i++) {
        parent[i] = -1; // No parent for root
        visited[i] = false; // Mark all vertices as not visited
    }

    // Call the recursive helper function to find bridges for all vertices
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            bridgeUtil(i, visited, parent, disc, low, time); // Call the utility function
        }
    }
}

int main() {
    Graph g(6); // Create a graph with 6 vertices

    // Adding edges to the graph to ensure there are bridges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5); // Adding a bridge edge
    g.addEdge(5, 3); // Adding a bridge edge

    cout << "Bridges in the graph:\n"; // Output message
    g.findBridges(); // Find and print bridges

    return 0; // Exit the program
}