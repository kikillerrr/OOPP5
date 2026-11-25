
#include <iostream>
#include "PointCloud.h"

int main() {
    PointCloud<double> cloud;

    cloud.addPoint({1.0, 2.0});
    cloud.addPoint({3.0, 4.0});

    std::cout << "Лабораторная работа №5\n";
    std::cout << "Шаблонный класс PointCloud\n";

    cloud.printSize();

    return 0;
}
