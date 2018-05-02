#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>
using namespace std;
//same_vec compares the identitiy of 2 vectors without 
//considering the order and multiplicities
bool same_vec(vector<int> a, vector<int> b) {

	bool element_same = true;

	//If one elemnt in vector a is not in vector b, end the loop with flag false
	//otherwise, remain the flag true till the loop ends
	for (unsigned int j = 0; j < a.size() && element_same == true; j++) {
		
		//compare a[j] with all elements in vector b: 
		//if same, set flag true and end the loop; otherwize, set flag false.
		element_same = false;
		for (unsigned int i = 0; element_same != true && i < b.size(); i++){
				if (a[j] == b[i])
					element_same = true;
				else
					element_same = false;
		}

	}

	return element_same;

}
// isInt() parses a string var and decide whether it
// can be translated to represent an int type number
bool isInt(string str) {

	bool isDigit = true;
	char ch = '-';

	if (str[0] == ch && str.size() >= 2) {	//Deal with the 1st digit
		isDigit = true;						//with possible '-' 
		if (str.size()> 10 ) {				// and overflow
			isDigit = false;
		}
	}	
	else if (str[0] >= '0' && str[0] <= '9' ){
			isDigit = true;
			if (str.size()> 9) {
				isDigit = false;
			}
		}
		else 
			isDigit = false;
	

	for (int i = 1; i < str.size(); i++) {	//Deal with the 
		if (str[i] < '0' || str[i] > '9')	//digits following the 
			isDigit = false;				
	}

	return isDigit;
}
//strToInt() converts a numeric string 
//representing int number to a int type number
int strToInt(string str) {

	istringstream streami;	//stream object created
	streami.str(str);		//store str to the stream
	int i;
	streami >> i;			//input the stored string to i

	return i;
}



int main() {

	int countVi1 = 0;
	int countVi2 = 0;
	vector<int> vi1, vi2;
	string str;	//str is used to store the input string temporarily

	//propmt the user to enter the size of the first vector
	cout << "This program serves to compare the identity of two int vectors.\n";
	cout << "How many elements do you want to include in the first vector?\n";
	cin >> str;
	
	// Store the size of vi1 if the input is a positive integer
	while (!(isInt(str)) || strToInt(str) < 1 ) {
		cout << "Please enter an positive integer(range: less than 1 billion): ";
		cin >> str;
	}
	countVi1 = strToInt(str);
	
	int temp;
	//propmt the user to enter the elemennts of the first vector
	for (int i = 0; i < countVi1; i++) {

		cout << "Please enter the #" << i + 1 << " element of the first vector: "<< endl;
		cin >> str;
	//Store the element of vi1 if the input is an integer
	//Otherwise, ask agian for the integer type input
		while (!(isInt(str))) {
			cout << "Please enter an integer(range: abs less than 1 billion):";
			cin >> str;
		}
		temp = strToInt(str);

		vi1.push_back(temp);
		
	}
	
	//propmt the user to enter the elemennts of the second vector
	cout << "How many elements do you want to include in the second vector?\n";
	cin >> str;
	// Store the size of vi1 if the input is a positive integer
	while (!(isInt(str)) || strToInt(str) < 1) {
		cout << "Please enter an positive integer(range: less than 1 billion):";
		cin >> str;
	}
	countVi2 = strToInt(str);

	//Store the element of vi2 if the input is an integer
	//Otherwise, ask agian for the integer type input
	for (int i = 0; i < countVi2; i++) {

		cout << "Please enter the #" << i + 1 << " element of the second vector: " << endl;
			cin >> str;

			while (!(isInt(str))) {
				cout << "Please enter an integer(range: abs less than 1 billion):";
				cin >> str;
			}
			temp = strToInt(str);

			vi2.push_back(temp);

	}

	//Display the 2 input vectors
	cout << "The 1st vector is: {";
	for (unsigned int i = 0; i < vi1.size(); i++){
		cout << vi1[i];
		if (i + 1 < vi1.size())
			cout << ", ";
	}
	cout << "}\n";
	
	cout << "The 2nd vector is: {";
	for (unsigned int i = 0; i < vi2.size(); i++) {
		cout << vi2[i];
		if (i + 1 < vi2.size())
			cout << ", ";
	}
	cout << "}\n";

	//Decide and Display the result
	if (same_vec(vi1, vi2) == true && same_vec(vi2, vi1) ==true)
		cout << "The 2 vectors are identical."<<endl;
	else
		cout << "The two vectors are different."<<endl;

	return 0;
}

