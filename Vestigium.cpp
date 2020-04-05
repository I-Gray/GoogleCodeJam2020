#include <iostream>

using namespace std;

const int MAX = 100;
int matrix[MAX][MAX];

void makeMatrix(int n, int caseNum);
bool checkRepeatedRows(int row, int n);
bool checkRepeatedCols(int col, int n);

int main() {

    int cases;
    //cout << "Enter the number of test cases: ";
    cin >> cases;
    
    for (int i = 0; i < cases; i++) {
    	int N;
    	//cout << "Enter N for case #" << i + 1 << ": ";
        cin >> N;

        makeMatrix(N, i);
    }
}

void makeMatrix(int n, int caseNum) {

	int trace = 0;

	bool checkRows = false; 
	int repeatRowsCount = 0;

	bool checkCols = false;
	int repeatColsCount = 0;
	int i, k;

	for (i = 0; i < n; i++) {
		for (k = 0; k < n; k++) {

			int currentNum;
			cin >> currentNum;

			matrix[i][k] = currentNum;

			if (i == k) {
				trace = trace + matrix[i][k];
			}

			
		}
		bool checkRows = checkRepeatedRows(i, n);

		if (checkRows) {
			repeatRowsCount++;
		}
	}	

	for (int j = 0; j < n; j++) {
			bool checkCols = checkRepeatedCols(j, n);
			
			if (checkCols) {
				repeatColsCount++;
			}
	}

	

	cout << "Case #" << caseNum + 1 << ": " << trace << " " << repeatRowsCount << " " << repeatColsCount << endl; 
}

bool checkRepeatedRows(int row, int n) {
	bool hasRepeat = false;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (matrix[row][i] == matrix[row][j]) {
				hasRepeat = true;
			}
		}
	}
	return hasRepeat;
}


bool checkRepeatedCols(int col, int n) {
	bool hasRepeat = false;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (matrix[i][col] == matrix[j][col]) {
					hasRepeat = true;
			}
		}
	}

	return hasRepeat;
}








