/********************************************************************************
 * Filename: task1.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * Lab No: 9
 * File Description: advanced I/O
 * Date Last Modified: 15/10/2015
 *********************************************************************************/


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Format
{
    friend ostream& operator<<(ostream &, const Format &);
    private:
        string base;
        int length;
        char pad;
    public:
        Format(string, int, char);
};

Format::Format(string b, int l, char p)
{
    base = b;
    length = l;
    pad = p;
}

ostream& operator<<(ostream &out, const Format &f)
{
    if(f.base == "oct")
        out.setf(ios::oct, ios::basefield);
    else if(f.base == "hex")
        out.setf(ios::hex, ios::basefield);
    else if(f.base == "dec")
        out.setf(ios::dec, ios::basefield);
    out << setfill(f.pad) << setw(f.length);
    return out;
}

int main()
{
    cout << Format("oct", 10, '#') << 20 << endl;
    cout << Format("hex", 8, '!') << 20 << endl;
    cout << Format("dec", 12, '@') << 20 << endl;
    return 0;
}


