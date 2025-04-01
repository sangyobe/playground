#include <iostream>
#include <string>
#include <string_view>

using namespace std;

int main(int argc, char *argv[])
{
    u32string u32_str = U"UTF-32 문자열";
    cout << u32_str.size() << endl;

    u16string u16_str = u"UTF-16 문자열";
    cout << u16_str.size() << endl;

    string u8_str = u8"UTF-8 문자열";
    cout << u8_str.size() << endl;

    return 0;
}