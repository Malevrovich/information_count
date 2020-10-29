#include <iostream>
#include <cmath>

using namespace std;

/*
таблица частотностей, первая буква не факт, что A
12.7
9.06
8.17
7.51
6.97
6.75
6.33
6.09
5.99
4.25
4.03
2.78
2.76
2.41
2.36
2.23
2.02
1.97
1.93
1.49
0.98
0.77
0.15
0.15
0.1
0.05
 */

int main(){
	int n = 26;
	double sum = 0;
	for(int i = 0; i != n; i++){
		double tmp;
		cin >> tmp;
		sum += tmp * log(tmp / 100) / log(0.5);
//		cout << tmp * log(tmp / 100) / log(0.5) << endl;
	}
	cout << sum / 100 << " бит" << endl;
	return 0;
}



