#include <iostream>
#include <cstdarg>

using namespace std;

void MyFunc(int a, int b, const char* szTypes, ...)
{
    union Printable_t {
        int     i;
        float   f;
        char    c;
        char   *s;
    } Printable;
    
    cout << "hello world" << endl;

    va_list vl;                                     // 가변 인자 위치를 가리키는 포인터
    va_start(vl, szTypes);                          // 가변 인자 위치(vl)를 szTypes 아규먼트 다음으로 설정
    for (int i =0; szTypes[i] != '\0'; i++) {
        switch (szTypes[i]) {
            case 'i':
                Printable.i = va_arg(vl, int);      // int 사이즈 만큼 리턴하고, 가변 인자 포인터를 그만큼 증가시킴
                cout << Printable.i << endl;
                break;
            case 'f':
                Printable.f = va_arg(vl, double);
                cout << Printable.f << endl;
                break;
            case 'c':
                Printable.c = va_arg(vl, int);
                cout << Printable.c << endl;
                break;
            case 's':
                Printable.s = va_arg(vl, char*);
                cout << Printable.s << endl;
                break;
            default:
                break;
        }
    }
    va_end(vl);
}

int main()
{
    MyFunc(1, 2, "fcsi", 32.4f, 'a', "Test string", 4);

    return 0;
}