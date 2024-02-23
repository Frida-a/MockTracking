using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

// backtracking

// dfs
void construct(int nNode, vector<vector<int>> graph){
    vector<vector<int>> adjList(nNode, vector<int>());//adj style
    vector<bool> visited(nNode, false);

    //无向图
    for (const auto & edge: graph){
        adjList[edge[1]].push_back(edge[0]);
        adjList[edge[0]].push_back(edge[1]);
    }
    
}
//or backtracking
void dfs(int u, vector<bool>& visited, vector<vector<int>>& adjList){
    //终止条件
    
    for (int i = 0; i <adjList[u].size(); i++){ 
        int j = adjList[u][i];
        if (!visited[j]){ 
            visited[j] = true;
            dfs(j, visited, adjList);
            //视情况是否要回溯
        }
    }
}


// bfs
void bfs(vector<bool>& visited, vector<vector<int>>& adjList){
    queue<int> q;
    visited[0] = true; // 表示1号点已经被遍历过
    q.push(0);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        
        for (int i = 0; i <adjList[t].size(); i++){
            int j = adjList[t][i];
            if (!visited[j])
            {
                visited[j] = true; // 表示点j已经被遍历过
                q.push(j);
            }
        }
    }
}


// topological sort
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0), res;
    for (const auto & prerequisite: prerequisites) {
        graph[prerequisite[1]].push_back(prerequisite[0]);
        ++indegree[prerequisite[0]];
    }
    queue<int> q;
    for (int i = 0; i < indegree.size(); ++i) {
        if (!indegree[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        res.push_back(u);
        q.pop();
        for (auto v: graph[u]) {
            --indegree[v];
            if (!indegree[v]) {
                q.push(v);
            }
        }
    }
    for (int i = 0; i < indegree.size(); ++i) {
        if (indegree[i]) {
            return vector<int>();
        }
    }
    return res;
}


// shortest path

// Dijkstra
// 思路：在还未确定最短路的点里找距离最小的点
/*




*/



// bellman-ford

// floyd


// MST
// prim

// kruskal

// maxflow
// ford-fulkerson

// hungary

