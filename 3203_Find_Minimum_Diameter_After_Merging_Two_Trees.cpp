/*Can you solve this real interview question? Find Minimum Diameter After Merging Two Trees - There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

You must connect one node from the first tree with another node from the second tree with an edge.

Return the minimum possible diameter of the resulting tree.

The diameter of a tree is the length of the longest path between any two nodes in the tree.

 

Example 1:[https://assets.leetcode.com/uploads/2024/04/22/example11-transformed.png]

Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]

Output: 3

Explanation:

We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.

Example 2:

[https://assets.leetcode.com/uploads/2024/04/22/example211.png]

Input: edges1 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]], edges2 = [[0,1],[0,2],[0,3],[2,4],[2,5],[3,6],[2,7]]

Output: 5

Explanation:

We can obtain a tree of diameter 5 by connecting node 0 from the first tree with node 0 from the second tree.

 

Constraints:

 * 1 <= n, m <= 105
 * edges1.length == n - 1
 * edges2.length == m - 1
 * edges1[i].length == edges2[i].length == 2
 * edges1[i] = [ai, bi]
 * 0 <= ai, bi < n
 * edges2[i] = [ui, vi]
 * 0 <= ui, vi < m
 * The input is generated such that edges1 and edges2 represent valid trees.*/


class Solution {
private:
    void build(vector<vector<int>>& adj, vector<vector<int>>& edges, int n){
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
    }
    void get(pair<int, int>& p, vector<vector<int>>& adj, int node, int dis, vector<int>& vis){
        int d = p.second;
        vis[node] = 1;
        if(dis>d){
            p.second = dis;
            p.first = node;
        }
        for(auto it: adj[node]){
            if(!vis[it]){
                get(p, adj, it, dis+1, vis);
            }
        }
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<vector<int>> adj1(n), adj2(m);

        build(adj1, edges1, n);
        build(adj2, edges2, m);

        //for first tree
        //this stores the farthest node from node 0, max dist of that node from 0
        vector<int>vis(n);
        pair<int, int> p1 = {-1, INT_MIN};
        get(p1, adj1, 0, 0, vis);
        //this stores the farthest node from the node farthest from 0, dia
        vis = vector<int>(n, 0);
        pair<int, int> p2 = {-1, INT_MIN};
        get(p2, adj1, p1.first, 0, vis);

        int d1 = p2.second;

        //now for the other tree
        p1 = {-1, INT_MIN};
        vis = vector<int>(m, 0);
        get(p1, adj2, 0, 0, vis);
        p2 = {-1, INT_MIN};
        vis = vector<int>(m, 0);
        get(p2, adj2, p1.first, 0, vis);

        int d2 = p2.second;
        if(edges1.empty()) d1 = 0;
        if(edges2.empty()) d2 = 0;

        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};