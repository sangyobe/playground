#include "gridMap.h"
#include <atomic>

// using namespace dtControl;
typedef dtControl::GridMap<10, 10, SYSREAL> LocalGridMap;
using namespace std;

int main()
{
    double tmp = NAN; // 0.0;
    if (isnan(tmp) != 0)
        cout << "NAN !!!" << endl;
    else
        cout << "not NAN !!!" << endl;

    LocalGridMap gridMap;

    // set sample data
    for (int i = 0; i < 10; i++)
    {
        LocalGridMap::Index index;
        index << i, i;
        gridMap.SetLayerData("height_map", index, 0.1 * i);
    }

    std::atomic<bool> bRun{true};
    LocalGridMap::Position center;
    center.SetFill(0.0);
    while (bRun.load())
    {
        cout << "(type \'q\' to quit) >\n";
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "q" || cmd == "quit")
        {
            bRun = false;
        }
        else if (cmd == "s")
        {
            gridMap.Print();
        }
        else if (cmd == "w")
        {
            center(1) += 0.05;
            gridMap.SetCenterPosition(center);
            gridMap.Print();
        }
        else if (cmd == "x")
        {
            center(1) -= 0.05;
            gridMap.SetCenterPosition(center);
            gridMap.Print();
        }
        else if (cmd == "d")
        {
            center(0) += 0.05;
            gridMap.SetCenterPosition(center);
            gridMap.Print();
        }
        else if (cmd == "a")
        {
            center(0) -= 0.05;
            gridMap.SetCenterPosition(center);
            gridMap.Print();
        }
    }

    return 0;
}