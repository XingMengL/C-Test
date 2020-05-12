#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;
	string s2("Hi");
	string s3 = s2;
	string s4(10,'$');
	string s5 = "Hi";

	string s6  = s2 + s4;
	cin>>s1;
	
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;

	system("pause");
	return 0;

}