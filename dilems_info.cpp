#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

bool isalpha(char a){
	return (a >= 'a' && a <= 'z');
}

char tolower(char a){
	switch(a){
	case 'A':
		return 'a';
	case 'B':
		return 'b';
	case 'C':
		return 'c';
	case 'D':
		return 'd';
	case 'E':
		return 'e';
	case 'F':
		return 'f';
	case 'G':
		return 'g';
	case 'H':
		return 'h';
	case 'I':
		return 'i';
	case 'J':
		return 'j';
	case 'K':
		return 'k';
	case 'L':
		return 'l';
	case 'M':
		return 'm';
	case 'N':
		return 'n';
	case 'O':
		return 'o';
	case 'P':
		return 'p';
	case 'Q':
		return 'q';
	case 'R':
		return 'r';
	case 'S':
		return 's';
	case 'T':
		return 't';
	case 'U':
		return 'u';
	case 'V':
		return 'v';
	case 'W':
		return 'w';
	case 'X':
		return 'x';
	case 'Y':
		return 'y';
	case 'Z':
		return 'z';
	default:
		return a;
	}
}

int getInd(char a){
	if(a == ' '){
		return 26;
	} else if(isalpha(a)){
		return a - 'a';
	}
	return -1;
}

int main(){
	vector<vector<int>> dilems(27, vector<int>(27, 0));

	ifstream in("input.txt");
	int counter = 0;

	char p;
	in >> p;
	p = tolower(p);
	counter++;

	char a;
	while(in.peek() != -1){
		a = in.peek();
		in.ignore(1);
		a = tolower(a);

		int ind_a = getInd(a);
		int ind_p = getInd(p);

		if(ind_a != -1 && ind_a != 26 && ind_p != -1){
			dilems[ind_p][ind_a]++;
			counter++;
		}

		p = a;
	}
	counter--;

	int n = dilems.size();
	for(int i = 0; i != n; i++){
		for(int k = 0; k != n; k++){
			cout << dilems[i][k] << '\t';
		}
		cout << endl;
	}

	vector<double> probability(26);

	for(int i = 0; i != 26; i++){
		for(int k = 0; k != 27; k++){
			probability[i] += dilems[k][i];
		}
		probability[i] /= counter;
	}

	double info = 0;

	for(auto i: probability){
		info += i * log(i) / log(0.5);
	}

	cout << info << endl;
}
