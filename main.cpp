
#include <iostream>
#include "PointCloud.h"

int main() {
    std::cout << "Лабораторная работа №5\n\n";

    // Двумерное облако
    PointCloud<double, 2> cloud2D;

    cloud2D.addPoint({1.0, 2.0});
    cloud2D.addPoint({3.0, 4.0});

    cloud2D.print();

    std::cout << "\n";

    // Трехмерное облако
    PointCloud<double, 3> cloud3D;

    cloud3D.addPoint({1.0, 2.0, 3.0});
    cloud3D.addPoint({4.0, 5.0, 6.0});

    cloud3D.print();

    return 0;
}
