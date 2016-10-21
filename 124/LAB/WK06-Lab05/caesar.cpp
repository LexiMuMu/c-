/*
	Caeser Cipher program.

*/

#include <iostream>
#include <fstream>
using namespace std;

char encrypt(char ch, int k)
{  
	if ('A' <= ch && ch <= 'Z'- k)
		return static_cast<char>(ch + ( k ) );
	else if ('a' <= ch && ch <= 'z'- k)
		return static_cast<char>(ch + ( k ) );
	else if ((ch+k) > 'Z')
		return static_cast<char>(ch + k - 26);
	else if ((ch+k) > 'z')
		return static_cast<char>(ch + k - 26);	
	else 
		return ch;
}

void encrypt_file(ifstream& in, ofstream& out, int k)
{  
	char ch;
	while(!in.eof())
	{
		in.get(ch);
		if (in.good())
			out.put(encrypt(ch, k));
	} 
}

int main(int argc, char* argv[])
{  
	const int MAX = 128;
	char source[MAX];
	char output[MAX];
	int key;
	ifstream ins;
	ofstream outs;
	
	cout << "Enter Cipher key: ";
	cin >> key;
	while (key < 0 || key > 26)
	{
		cout << "Please re-input the key, make sure it is between 0-26." << endl;
		cout << "Enter Cipher key: ";
		cin >> key;
	}
	
	cout << "Enter the name of the file to encrypt: ";
	cin >> source;
	
	cout << "Enter the name of the file to write output to: ";
	cin >> output;
	
	ins.open(source, ios::in);
	outs.open(output, ios::out);
	
	if (ins.fail() || outs.fail())
	{
		cerr << "An error occured" << endl;
	}
	else
	{
		encrypt_file(ins, outs, key);
		ins.close();
		outs.close();
	}
	
	return 0;
}
