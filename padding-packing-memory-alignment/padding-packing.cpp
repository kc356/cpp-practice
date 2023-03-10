#include <iostream>

using namespace std;

struct emp 
{
    char c;
    // pad[3]
    int x;
};

struct foo
{
    char c;
    // pad[3]
    int x;
    char d;
    // pad[3]
};

struct foo_reordered
{
    int x; // memory address: M
    char c; // memory address: M + 4
    char d; // memory address: M + 5
    //pad[2]
};

#pragma pack(1)
struct foo_packed
{
    char c;
    int x;
    char d;
};

struct foo_pragma_packed
{
    char c;
    int x;
    char d;
}__attribute__((__packed__));

int main()
{
    cout << "sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(char): " << sizeof(char) << endl;

    cout << "sizeof(emp): " << sizeof(emp) << endl;
    cout << "sizeof(foo): " << sizeof(foo) << endl;

    cout << "sizeof(foo_reordered): " << sizeof(foo_reordered) << endl;
    cout << "sizeof(foo_packed): " << sizeof(foo_packed) << endl;
    cout << "sizeof(foo_pragma_packed): " << sizeof(foo_pragma_packed) << endl;

    return 0;
}