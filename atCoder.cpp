#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;
    vector<int> size;
    vector<int> maxNode;
    long totalSum;

public:
    UnionFind(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        maxNode.resize(n + 1);
        totalSum = 0;
        
        // Initialize each node as its own parent
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            maxNode[i] = i;
            totalSum += i;  // Initially, each node is its own network
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) return;  // Already in same network
        
        // Union by size
        if (size[rootX] < size[rootY]) {
            swap(rootX, rootY);
        }
        
        // Update total sum by removing old max values
        totalSum -= maxNode[rootX];
        totalSum -= maxNode[rootY];
        
        // Merge smaller set into larger set
        parent[rootY] = rootX;
        size[rootX] += size[rootY];
        maxNode[rootX] = max(maxNode[rootX], maxNode[rootY]);
        
        // Add new max value to total sum
        totalSum += maxNode[rootX];
    }

    long getTotalSum() {
        return totalSum;
    }
};

vector<long> networkSums(int c_nodes, vector<int> c_from, vector<int> c_to) {
    UnionFind uf(c_nodes);
    vector<long> result;
    
    for (int i = 0; i < c_from.size(); i++) {
        uf.unite(c_from[i], c_to[i]);
        result.push_back(uf.getTotalSum());
    }
    
    return result;
}

int main() {
    // Test Case 1
    int nodes1 = 5;
    vector<int> from1 = {1, 2, 1, 4};
    vector<int> to1 = {2, 3, 3, 5};
    vector<long> result1 = networkSums(nodes1, from1, to1);
    cout << "Test Case 1: ";
    for (long sum : result1) {
        cout << sum << " ";
    }
    cout << endl;  // Expected: 14 12 12 8
    
    // Test Case 2
    int nodes2 = 1;
    vector<int> from2 = {1};
    vector<int> to2 = {1};
    vector<long> result2 = networkSums(nodes2, from2, to2);
    cout << "Test Case 2: ";
    for (long sum : result2) {
        cout << sum << " ";
    }
    cout << endl;  // Expected: 1
    
    // Test Case 3
    int nodes3 = 2;
    vector<int> from3 = {1, 2};
    vector<int> to3 = {2, 1};
    vector<long> result3 = networkSums(nodes3, from3, to3);
    cout << "Test Case 3: ";
    for (long sum : result3) {
        cout << sum << " ";
    }
    cout << endl;  // Expected: 2 2
    
    return 0;
}