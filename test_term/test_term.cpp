#include "dhTerm.h"
#include <chrono>
#include <thread>

int main()
{
    dhTerm::SetupTerminal(false);
    dhTerm::ClearDisp();

    bool fRunMain = true;
    int iCount = 0;
    while (fRunMain) {

        if (dhTerm::kbhit())
        {
            switch(getchar())
            {
//            

            case 'q': fRunMain = 0; break;
            case 'Q': fRunMain = 0; break;
            }

        }
        else {
            PPRINTF(1, 10, "hello");
            PPRINTF(3, 10, "world (%d)", ++iCount);
            std::this_thread::sleep_for(std::chrono::milliseconds(3));
        }
    }

    dhTerm::RestoreTerminal();
    return 0;
}