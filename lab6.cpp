#include <Windows.h>
#include "Interface.cpp"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Interface<bool>::core();
    return 0;
}
