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
	vector <int> A;
	vector <int> B;
};

Result read(string filename) {
	vector<int> A, B;
	Result ab;
	string line;
	ifstream infile;
	infile.open (filename.c_str());

	while (getline(infile, line) && !line.empty()) {
		istringstream iss(line);
		A.resize(A.size() + 1);
		int a, j = 0;
		while (iss >> a) {
			A.push_back(a);
			j++;
		}
	}

	while (getline(infile, line)) {
		istringstream iss(line);
		B.resize(B.size() + 1);
		int a;
		int j = 0;
		while (iss >> a) {
			B.push_back(a);
			j++;
		}
	}

	infile.close();
	ab.A = A;
	ab.B = B;
	return ab;
}

vector <int> scatter(vector <int> A, vector <int> B) {
	int n = A.size();
	int index = B.size();

	// initialise C with 0s
	vector<int> C(index, 0);

	for (int i = 0; i < index; i++) {
			C[i] = A[i];
		}
	return C;
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
	vector <int> C  = scatter(result.A, result.B);
    parsec_roi_end();
	//printMatrix(C);
	return 0;
}
