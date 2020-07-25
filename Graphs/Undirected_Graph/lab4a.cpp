/* 	EE580 -- Kunal Sheth
	USC ID:3656712856
	Lab 4 of 595 -- Part A -- Undirected Graph
	Referenced from 1st: https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
	Referenced from 2nd : https://www.geeksforgeeks.org/check-if-a-given-graph-is-bipartite-using-dfs/
*/

#include <iostream> 
#include <vector>
#include <fstream>
#include <string>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
int V;
ofstream outfile;
bool isBipartite(vector<vector<int> > G, int src) 
{  
    int colorArr[V]; 
    for (int i = 0; i < V; ++i) 
    colorArr[i] = -1; 
    colorArr[src] = 1; 
    queue <int> q; 
    q.push(src); 
  
    while (!q.empty()) 
    { 
  
        int u = q.front(); 
        q.pop(); 
  
       if (G[u][u] == 1) 
    return false;  
  
     for (int v = 0; v < V; ++v) 
        { 
                 if (G[u][v] && colorArr[v] == -1) 
            { 
                colorArr[v] = 1 - colorArr[u]; 
                q.push(v); 
            } 
  
            else if (G[u][v] && colorArr[v] == colorArr[u]) 
                return false; 
        } 
    }  
return true; 
} 
int minKey(int key[], bool mstSet[])  
{  
     
    int min = INT8_MAX, min_index;  
  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  return min_index;  
}  

void printMST(int parent[], vector<vector<int> > graph)  
{ 
	vector< pair<int,pair<int,int> > > ans;
    for (int i = 1; i < V; i++)  
    {
    	ans.push_back({graph[parent[i]][i],{parent[i],i}});
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
        outfile<<ans[i].second.first<<" "<<ans[i].second.second<<endl;  
}  
void primMST(vector<vector<int> > graph)  
{  
      
    int parent[V];    
    int key[V];  
    bool mstSet[V];  
    
    for (int i = 0; i < V; i++)  
        key[i] = INT8_MAX, mstSet[i] = false;  
        
    key[0] = 0;  
    parent[0] = -1;   
    
    for (int count = 0; count < V - 1; count++) 
    {  
   
        int u = minKey(key, mstSet);  
        mstSet[u] = true;  
        
        for (int v = 0; v < V; v++)  
          if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])  
                parent[v] = u, key[v] = graph[u][v];  
    }  
  printMST(parent, graph);  
}  
  

int main(int argc, char* argv[]) {
	
 	 fstream file;
	  int M; 
    string word, filename; 
    filename = argv[1]; 
    file.open(filename.c_str()); 
    file >> word;
    V = stoi(word);
    int N=V;
    file >> word;
    M = stoi(word);
    vector<vector<int> > mtx(N, vector<int> (N, 0));
	for(int i=0;i<M;i++)
	{
		file >> word;
		int p = stoi(word);
		file >> word;
		int q = stoi(word);
		file >> word;
		int r = stoi(word);
		mtx[p][q]=r;
	}
	
   outfile.open("result.txt");
	isBipartite(mtx, 0) ? outfile << "Yes"<<endl : outfile << "No"<<endl;
	primMST(mtx); 

return 0;	
}
