#include <iostream> 
#include <vector> 
#include "matrix.h"
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
  int A,B,C;
  vector<int> t;
  //read file 1
  fstream file; 
    string word, filename; 
    filename = argv[1]; 
    file.open(filename.c_str()); 
    file >> word;
    A = stoi(word);
    file >> word;
    B = stoi(word);
    vector<vector<int> > m1(A, vector<int> (B, 0));
    while (file >> word) 
    {
        t.push_back(stoi(word));
    } 
    int k=0;
    for (int i=0; i<A; i++)
    {
      for(int j=0; j<B; j++)
      {
        m1[i][j]=t[k++];
      }
      cout<<endl;
    }
    //read file 2
    vector<int> t2;
    fstream file2; 
    filename = argv[2]; 
    file2.open(filename.c_str()); 
    file2 >> word;
    B= stoi(word);
    file2 >> word;
    C = stoi(word);
    vector<vector<int> > m2(B, vector<int> (C, 0));
    while (file2 >> word) 
    {
        t2.push_back(stoi(word));
    } 
    k=0;
    for (int i=0; i<B; i++)
    {
      for(int j=0; j<C; j++)
      {
        m2[i][j]=t2[k++];
      }
    }


	Matrix task ;
	task.load_matrix(m1,m2,A,B,C); 
  	vector<vector<int> > r = task.matrix_mult();

    ofstream outfile;
   outfile.open("result.txt");
   outfile<<A<<" "<<C<<endl;
  	for(int i=0;i<A;i++)
  	{
  		for(int j=0;j<C;j++) outfile<<r[i][j]<<" ";
  		outfile<<endl;
	  }
	  outfile.close();
  return 0;
} 
