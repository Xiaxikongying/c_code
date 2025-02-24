#include <iostream>
using namespace std;
struct Classmate
{
    int age;
    string name;
};

int main()
{
    Classmate Cl[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> Cl[i].name>> Cl[i].age;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << Cl[i].name<< " " << Cl[i].age << endl;
    }
    
    return 0;
}
