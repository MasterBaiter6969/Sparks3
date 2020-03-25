#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	
	ifstream testnaBaza ("testnaBaza.txt", ifstream::in);
	
	char c = testnaBaza.get();
	
	string podaci = "";
	
	for(int i = 0; testnaBaza.good(); i++){
		podaci = podaci + c;
		//cout << c;
		c = testnaBaza.get();
	}
	
	cout << podaci;
	
	return 0;
}
