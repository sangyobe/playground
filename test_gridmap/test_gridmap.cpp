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

void testIterator(LocalGridMap &gridmap)
{
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "Iterate all cells..." << std::endl;
    std::cout << std::endl;

    LocalGridMapIterator itr(gridmap);
    while (!itr.IsEnd())
    {
        std::cout << (*itr)(0) << ", " << (*itr)(1) << std::endl;
        ++itr;
    }
    std::cout << std::endl;
}

void testBoxIterator(LocalGridMap &gridmap, LocalGridMap::Position center, LocalGridMap::Size rect)
{
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "Iterate cells inside a given box shape..." << std::endl;
    std::cout << std::endl;

    LocalGridMapBoxIterator itr(gridmap, center, rect);
    while (!itr.IsEnd())
    {
        std::cout << (*itr)(0) << ", " << (*itr)(1) << std::endl;
        gridmap.SetLayerData("height_map", *itr, 4.0);
        ++itr;
    }
    std::cout << std::endl;
}

void testCircleIterator(LocalGridMap &gridmap, LocalGridMap::Position center, LocalGridMap::ValueType radius)
{
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "Iterate cells inside a given circle shape..." << std::endl;
    std::cout << std::endl;

    LocalGridMapCircleIterator itr(gridmap, center, radius);
    while (!itr.IsEnd())
    {
        std::cout << (*itr)(0) << ", " << (*itr)(1) << std::endl;
        gridmap.SetLayerData("height_map", *itr, 8.0);
        ++itr;
    }
    std::cout << std::endl;
}

int main()
{
    LocalGridMap gridmap;

    // set sample data
    LocalGridMapIterator gridMapItr(gridmap);
    while (!gridMapItr.IsEnd())
    {
        if ((*gridMapItr)(0) == (*gridMapItr)(1))
        {
            gridmap.SetLayerData("height_map", *gridMapItr, 0.1);
        }
        else
        {
            gridmap.SetLayerData("height_map", *gridMapItr, 0.0);
        }
        ++gridMapItr;
    }

    // test iterator
    // testIterator(gridmap);

    // test box iterator
    LocalGridMap::Position boxCenter;
    boxCenter(0) = 0.0;
    boxCenter(1) = 0.5;
    LocalGridMap::Size boxRect;
    boxRect(0) = 0.1 - 1e-6;
    boxRect(1) = 0.1 - 1e-6;
    testBoxIterator(gridmap, boxCenter, boxRect);

    // test circle iterator
    LocalGridMap::Position circleCenter;
    circleCenter(0) = 0.5;
    circleCenter(1) = 0.5;
    LocalGridMap::ValueType circleRadius;
    circleRadius = 0.10;
    testCircleIterator(gridmap, circleCenter, circleRadius);

    std::atomic<bool> bRun{false};
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