#include "gridMap.h"
#include "gridMapIterator.h"
#include <atomic>

// using namespace dtControl;
typedef dtControl::GridMap<10, 10, SYSREAL> LocalGridMap;
typedef dtControl::GridMapIterator<dtControl::GridMap<10, 10, SYSREAL>> LocalGridMapIterator;
using namespace std;

int main()
{
    LocalGridMap gridmap;

    // test iterator
    LocalGridMapIterator gridMapItr(gridmap);
    while (!gridMapItr.IsEnd())
    {
        std::cout << (*gridMapItr)(0) << ", " << (*gridMapItr)(1) << std::endl;
        ++gridMapItr;
    }

    // set sample data
    for (int i = 0; i < 10; i++)
    {
        LocalGridMap::Index index;
        index << i, i;
        gridmap.SetLayerData("height_map", index, 0.1 * i);
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
            gridmap.Print();
        }
        else if (cmd == "w")
        {
            center(1) += 0.05;
            gridmap.SetCenterPosition(center);
            gridmap.Print();
        }
        else if (cmd == "x")
        {
            center(1) -= 0.05;
            gridmap.SetCenterPosition(center);
            gridmap.Print();
        }
        else if (cmd == "d")
        {
            center(0) += 0.05;
            gridmap.SetCenterPosition(center);
            gridmap.Print();
        }
        else if (cmd == "a")
        {
            center(0) -= 0.05;
            gridmap.SetCenterPosition(center);
            gridmap.Print();
        }
    }

    return 0;
}