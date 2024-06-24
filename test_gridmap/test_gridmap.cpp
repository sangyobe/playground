#include "gridMap.h"
#include "gridMapBoxIterator.hpp"
#include "gridMapCircleIterator.hpp"
#include "gridMapIterator.hpp"
#include <atomic>

// using namespace dtControl;
#define GRID_SIZE_X 20
#define GRID_SIZE_Y 20
typedef dtControl::GridMap<GRID_SIZE_X, GRID_SIZE_Y, SYSREAL> LocalGridMap;
typedef dtControl::GridMapIterator<LocalGridMap> LocalGridMapIterator;
typedef dtControl::GridMapBoxIterator<LocalGridMap> LocalGridMapBoxIterator;
typedef dtControl::GridMapCircleIterator<LocalGridMap> LocalGridMapCircleIterator;
using namespace std;

int main()
{
    LocalGridMap gridmap;

    // test iterator
    // LocalGridMapIterator gridMapItr(gridmap);
    // while (!gridMapItr.IsEnd())
    // {
    //     std::cout << (*gridMapItr)(0) << ", " << (*gridMapItr)(1) << std::endl;
    //     ++gridMapItr;
    // }

    // test box iterator
    // LocalGridMap::Index boxStart, boxEnd;
    // boxStart(0) = 7;
    // boxStart(1) = 2;
    // boxEnd(0) = 9;
    // boxEnd(1) = 3;
    // LocalGridMapBoxIterator boxItr(gridmap, boxStart, boxEnd);
    // while (!boxItr.IsEnd())
    // {
    //     std::cout << (*boxItr)(0) << ", " << (*boxItr)(1) << std::endl;
    //     ++boxItr;
    // }

    // test circle iterator
    LocalGridMap::Position circleCenter;
    LocalGridMap::ValueType circleRadius;
    circleCenter(0) = 0.25;
    circleCenter(1) = 0.25;
    circleRadius = 0.1;
    LocalGridMapCircleIterator circleItr(gridmap, circleCenter, circleRadius);
    while (!circleItr.IsEnd())
    {
        std::cout << (*circleItr)(0) << ", " << (*circleItr)(1) << std::endl;
        ++circleItr;
    }

    // set sample data
    for (int i = 0; i < 4; i++)
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