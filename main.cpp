
#include <iostream>
#include "PointCloud.h"

int main() {
    std::cout << "Лабораторная работа №5\n\n";

    PointCloud<double, 2> cloud2D;

    cloud2D.addPoint({1.0, 2.0});
    cloud2D.addPoint({3.0, 4.0});

    cloud2D.print();

    std::cout << "\n";

    PointCloud<double, 3> cloud3D;

    cloud3D.addPoint({1.0, 2.0, 3.0});
    cloud3D.addPoint({4.0, 5.0, 6.0});

    cloud3D.print();

    std::cout << "\n";

    std::array<double, 3> vectorA = {1.0, 0.0, 0.0};
    std::array<double, 3> vectorB = {0.0, 1.0, 0.0};

    auto result = PointCloud<double, 3>::crossProduct(
        vectorA, vectorB);

    std::cout << "Векторное произведение: ("
              << result[0] << ", "
              << result[1] << ", "
              << result[2] << ")\n";

    return 0;
}
