
#include <iostream>
#include "PointCloud.h"

int main() {
    std::cout << "Лабораторная работа №5\n\n";

    // Создаем двумерное облако
    PointCloud<double, 2> cloud2D;

    cloud2D.addPoint({1.0, 2.0});
    cloud2D.addPoint({3.0, 4.0});

    printCloud(cloud2D);

    auto center2D = calculateCentroid(cloud2D);

    std::cout << "Центроид 2D: ("
              << center2D[0] << ", "
              << center2D[1] << ")\n\n";

    // Создаем трехмерное облако
    PointCloud<double, 3> cloud3D;

    cloud3D.addPoint({1.0, 2.0, 3.0});
    cloud3D.addPoint({4.0, 5.0, 6.0});

    printCloud(cloud3D);

    auto center3D = calculateCentroid(cloud3D);

    std::cout << "Центроид 3D: ("
              << center3D[0] << ", "
              << center3D[1] << ", "
              << center3D[2] << ")\n\n";

    // Проверка векторного произведения
    std::array<double, 3> vectorA = {1.0, 0.0, 0.0};
    std::array<double, 3> vectorB = {0.0, 1.0, 0.0};

    auto cross = PointCloud<double, 3>::crossProduct(
        vectorA, vectorB);

    std::cout << "Векторное произведение: ("
              << cross[0] << ", "
              << cross[1] << ", "
              << cross[2] << ")\n\n";

    // Проверка расстояния
    std::array<double, 2> pointA = {0.0, 0.0};
    std::array<double, 2> pointB = {3.0, 4.0};

    std::cout << "Расстояние между точками: "
              << distanceBetween(pointA, pointB) << "\n\n";

    // Общий счетчик точек
    std::cout << "Общее количество точек во всех облаках: "
              << PointCloud<double, 2>::getTotalPoints()
              << '\n';

    return 0;
}
