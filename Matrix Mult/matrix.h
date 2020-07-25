#include <vector>

using namespace std;
class Matrix {
	
  /* List class attributes */
  private: 
  	vector<vector<int> > matrix_1;
  	vector<vector<int> > matrix_2;
  	int A,B,C;
  public:
  	vector<vector<int> > matrix_mult();
  	void load_matrix(vector<vector<int> > m1,vector<vector<int> > m2,int A,int B,int C);
    
};

