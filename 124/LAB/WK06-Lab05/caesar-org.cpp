/*
	Caeser Cipher program.

*/

#include <iostream>
#include <fstream>
using namespace std;

char encrypt(char ch, int k)
{  
	if ('A' <= ch && ch <= 'Z')
		return static_cast<char>('A' + ( k ) );
	if ('a' <= ch && ch <= 'z')
		return static_cast<char>(ch + ( k ) );
	return ch;
}

void encrypt_file(ifstream& in, ofstream& out, int k)
{  
	char ch;
	while(!in.eof())
	{
		in.get(ch);
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
