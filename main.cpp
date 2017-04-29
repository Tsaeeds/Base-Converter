
#include <string>
#include <iostream>
#include <vector>
#include<string.h>
#include <math.h>
#include <cstring>
#include <cstdlib>
using namespace std;

void toHex(int q, int b)
{

	vector<char> c;
	char r;

	while (q != 0)
	{

		r = '0' + q%b;
		if (r>'9')
		{
			for (int i = 0, j = 10; i <= 5; i++, j++)
			{

				if ((q%b) == j) c.push_back('A' + i);

			}
		}
		else
		{
			c.push_back(r);
		}


		q = q / b;

	}

	for (int i = c.size() - 1; i >= 0; i--)
	{
		cout << c[i];

	}
	cout << endl;
}
void decimalTo(int n, int b)
{
	vector<int> a;

	int q = n;
	int x;

	if (b == 16)
		toHex(q, b);
	else
	{
		while (q != 0)
		{

			a.push_back(q%b);
			q = q / b;

		}
	}
	for (int i = a.size() - 1; i >= 0; i--)
	{
		cout << a[i];
	}
	cout << endl;
}

int conv(char a) {


	char c = toupper(a);

	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - '7';
}

int hexTo(string n, int b) {

	char a;
	int sum = 0;

	for (int i = n.length() - 1, j =0; i >= 0; i--) {
			a = n[i];

			sum += conv(a) * pow(b, j);
			j++;

	}

	return sum;
}

int anyToDecimal(string n, int b) {
int sum = 0;

if (b == 16)
		return hexTo(n, b);
	else {

		for (int i = n.length() - 1, j = 0; i >= 0; i--, j++) {

			sum +=  ((int)n[i] - 48)*pow(b, j);
		}
		return sum;
	}
}
bool invalid(string n, int b){
for(int i = 0; i<n.length(); i++){
       if(conv(n[i])>=b) return true;
}
return false;
}
int main()
{
	int v1, b1, b2, a;

	string n;
	cout << "Enter a number: ";
    cin >> n;
    cout << endl;



    cout << "Enter the base of the number you entered (e.g. 2, 8, 10, or 16): ";
	cin >> b1;
    cout << endl;

if(invalid(n,b1)){
        cout << "Invalid base for the number you entered. Please try again!" << endl;
        cout << endl;

        }
else{
	cout << "Enter a second base in which you want to convert to (e.g. 2, 8, 10, or 16): ";
	cin >> b2;
	cout << endl;



	if (b1 == 10)
	{
	    cout << n << " of base(" << b1 << ") in base(" << b2 << ") is: ";
		v1 = atoi(n.c_str());
        decimalTo(v1, b2);
        cout << endl;
	}
	else if (b2 == 10) {
            cout << n << " of base(" << b1 << ") in base(" << b2 << ") is: ";
            a = anyToDecimal(n, b1);
		cout << a;
       cout << endl;
	}
	else {
	    cout << n << " of base(" << b1 << ") in base(" << b2 << ") is: ";
		 decimalTo( anyToDecimal(n, b1), b2);
		 cout << endl;
	}
}
	return 0;
}
