//recur.cpp -- using recursion
#include <iostream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;



char* findC(char const* source, char const* obj) {
	char *ptr = nullptr;
	int count = 0;
	
	int i, j , k;
	//if the (remaining)source is not long enough to chceck out obj, terminate loop
	if(strlen(source) >= strlen(obj)){
	//IF ith element in source = jth element in obj, go on checking following elements
	for (i = 0, j = 0; i < strlen(source) -strlen(obj)+1; i++) {
		if (source[i] == obj[j]) {
			k = i;	//copy i to k to protect the possile restart point
			//check elements follwing i and use count as a flag
			for (count = 0; source[k] == obj[j] && j < strlen(obj); k++, j++) {
				//cout << "The pointer is " << (int*)&source[k] << endl;
				count++;
				//If obj checked in source, return &source[i],
				//otherwise, set j = 0 prepare for restart check from source[i+1]
				if (count == strlen(obj)){ 
					ptr = (char*)&source[i];
					//cout << "The pointer is " << (int*)ptr << endl;
					i = strlen(source);
				}
			}
		}
		else{
			j = 0 ;
			//cout << "Char not found."<<endl; 
		}	
	}
	}

	return ptr;
}

//strToCharArray
char* strToCharArray(void) {
	
	string str = "";
	cin >> str;
 
	istringstream streami;	//stream object created
	streami.str(str);		//store str to the stream
	char *pc = new char[str.size()] ;
	streami >> pc;			//input the stored string to i

	return pc;
}


int main() {
	
	char const* source;
	char const* obj;

	cout << "Please enter the source string you want to check: "<< endl;
	source = strToCharArray();
	cout << "Please enter the object string you want to check out: " << endl;
	obj = strToCharArray();
	cout << "The address of the first charcacter in source is: " << (int*)findC(source, obj) << endl;

	return 0;
}
