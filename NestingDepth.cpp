#include <iostream>
#include <string>

using namespace std;

string stringDepth(string S);
string addBrackets(int num);

string reduce(string s, string p);

int main() {

    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
    	string S;
        cin >> S;

        string depth;
        depth = stringDepth(S);

        cout << "Case #" << i + 1 << ": " << depth << endl; 
    }
}

string stringDepth(string S) {
	int stringLength = S.length();
	string newString = "";
	int count = 0;
	
	for (int i = 0; i < stringLength; i++) {
		int currentNum = S[i] - '0';
		
		if (currentNum != 0) {
			string individualString = addBrackets(currentNum);

			newString = newString + individualString;
		}
		else {
			newString = newString + "0";
		}
	}
	// cout << "Before reduction: ";
	// cout << newString << endl;

	string finalString = reduce(newString, ")(");
	return finalString;
}

string addBrackets(int num) {
	string returnString = to_string(num);

	for (int i = 0; i < num; i++){
		string brackets = "(";
		returnString = brackets + returnString;
	}

	for (int i = 0; i < num; i++){
		string brackets = ")";
		returnString = returnString + brackets;
	}

	return returnString;
}

string reduce(string s, string p) { 
  	string::size_type n = p.length();

  	for (string::size_type i = s.find(p); i != string::npos; i = s.find(p))
  		s.erase(i, n);

  	return s;
}



