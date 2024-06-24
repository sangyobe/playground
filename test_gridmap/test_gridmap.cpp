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

void testBoxIterator(LocalGridMap &gridmap)
{
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "Iterate cells inside a given box shape..." << std::endl;
    std::cout << std::endl;

    LocalGridMap::Index boxStart, boxEnd;
    LocalGridMap::Position boxStartPosition, boxEndPosition;
    boxStartPosition(0) = -0.35;
    boxStartPosition(1) = 0.15;
    boxEndPosition(0) = -0.15;
    boxEndPosition(1) = 0.35;
    gridmap.GetIndexFromPosition(boxStartPosition, boxStart);
    gridmap.GetIndexFromPosition(boxEndPosition, boxEnd);
    // boxStart(0) = 7;
    // boxStart(1) = 2;
    // boxEnd(0) = 9;
    // boxEnd(1) = 3;
    LocalGridMapBoxIterator itr(gridmap, boxStart, boxEnd);
    while (!itr.IsEnd())
    {
        std::cout << (*itr)(0) << ", " << (*itr)(1) << std::endl;
        gridmap.SetLayerData("height_map", *itr, 4.0);
        ++itr;
    }
    std::cout << std::endl;
}

void testCircleIterator(LocalGridMap &gridmap)
{
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "Iterate cells inside a given circle shape..." << std::endl;
    std::cout << std::endl;

    LocalGridMap::Position circleCenter;
    LocalGridMap::ValueType circleRadius;
    circleCenter(0) = 0.25;
    circleCenter(1) = -0.25;
    circleRadius = 0.25;
    LocalGridMapCircleIterator itr(gridmap, circleCenter, circleRadius);
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
    testBoxIterator(gridmap);

    // test circle iterator
    testCircleIterator(gridmap);

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