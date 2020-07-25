/*		EE580 -- Kunal Sheth
		USC ID: 3656712856
		Lab 4 of EE595 Part B -- Directed Graph
*/		

#include <iostream> 
#include <vector>
#include <fstream>
#include <string>
#include<stack>
using namespace std;
void dfs(vector<vector<int> >& mtx,vector<bool>& visited,int v,stack<int>& stk,int N)
{
	visited[v]=true;
	for(int i=N-1;i>=0;i--)
	{
		if(mtx[v][i] && !visited[i])
		{
			dfs(mtx,visited,i,stk,N);
		}
	}
	stk.push(v);
}
int main(int argc, char* argv[]) {
	
 	 fstream file;
	  int N,M; 
    string word, filename; 
    filename = argv[1]; 
    file.open(filename.c_str()); 
    file >> word;
    N = stoi(word);
    file >> word;
    M = stoi(word);
    vector<vector<int> > mtx(N, vector<int> (N, 0));
	for(int i=0;i<M;i++)
	{
		file >> word;
		int p = stoi(word);
		file >> word;
		int q = stoi(word);
		mtx[p][q]=1;
	}
	vector<bool> visited(N,false);
	stack<int> stk;
	for(int i=N-1;i>=0;i--)
	{
		if(!visited[i])
		dfs(mtx,visited,i,stk,N);
	}
	 ofstream outfile;
   outfile.open("result.txt");
   
	while(!stk.empty()) outfile<<stk.top()<<" ",stk.pop();
	outfile.close();
	return 0;
	
}
