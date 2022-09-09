#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void parsec_roi_begin() 
{

}

void parsec_roi_end() 
{

}


struct Result {
	vector< vector<int> > A;
};

Result read(string filename) {
	vector< vector<int> > A;
	Result ab;
	string line;
	ifstream infile;
	infile.open (filename.c_str());

	int i = 0;
	while (getline(infile, line) && !line.empty()) {
		istringstream iss(line);
		A.resize(A.size() + 1);
		int a, j = 0;
		while (iss >> a) {
			A[i].push_back(a);
			j++;
		}
		i++;
	}

	infile.close();
	ab.A = A;
	return ab;
}

int * gather(vector <int> A) {
	int n = A.size();

	// initialise C with 0s
  int index[5] = {1,2,3,4,5};
  int indexlen = sizeof(index) / sizeof(int);
	int newlen = indexlen;
	int C[newlen] = {};

	for (int i = 0; i < indexlen; i++) {
		for (int j = 0; j < n; j++) {
				if (index[i] == j) {
          C[i] = A[j];
          break;
        }
		}
	}
	return C;
}

void printMatrix(vector< vector<int> > matrix) {
	vector< vector<int> >::iterator it;
	vector<int>::iterator inner;
	for (it=matrix.begin(); it != matrix.end(); it++) {
		for (inner = it->begin(); inner != it->end(); inner++) {
			cout << *inner;
			if(inner+1 != it->end()) {
				cout << "\t";
			}
		}
		cout << endl;
	}
}

int main (int argc, char* argv[]) {
	string filename;
	if (argc < 3) {
		filename = "2000.in";
	} else {
		filename = argv[2];
	}
	Result result = read (filename);
    parsec_roi_begin();
	int *C = gather(result.A);
    parsec_roi_end();
	//printMatrix(C);
	return 0;
}
