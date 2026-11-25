
#include <iostream>
#include "PointCloud.h"

int main() {
    std::cout << "===== ЛАБОРАТОРНАЯ РАБОТА №5 =====\n\n";

    // Создаем двумерное облако и загружаем точки
    PointCloud<double, 2> cloud2D;

    if (!cloud2D.loadFromFile("points2d.txt")) {
        std::cerr << "Не удалось загрузить двумерные точки.\n";
        return 1;
    }

    std::cout << "Двумерное облако успешно загружено.\n";
    std::cout << "Количество точек: "
              << cloud2D.size() << "\n\n";

    printCloud(cloud2D);

    auto center2D = calculateCentroid(cloud2D);

    std::cout << "\nЦентроид 2D: ("
              << center2D[0] << ", "
              << center2D[1] << ")\n\n";

    // Создаем трехмерное облако и загружаем точки
    PointCloud<double, 3> cloud3D;

    if (!cloud3D.loadFromFile("points3d.txt")) {
        std::cerr << "Не удалось загрузить трехмерные точки.\n";
        return 1;
    }

    std::cout << "Трехмерное облако успешно загружено.\n";
    std::cout << "Количество точек: "
              << cloud3D.size() << "\n\n";

    printCloud(cloud3D);

    auto center3D = calculateCentroid(cloud3D);

    std::cout << "\nЦентроид 3D: ("
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

    // Проверка расстояния между точками
    std::array<double, 2> pointA = {0.0, 0.0};
    std::array<double, 2> pointB = {3.0, 4.0};

    std::cout << "Расстояние между точками: "
              << distanceBetween(pointA, pointB) << "\n\n";

    // Общий счетчик точек
    std::cout << "Общее количество точек во всех облаках: "
              << PointCloud<double, 2>::getTotalPoints()
              << "\n\n";

    // Сохранение точек в файлы
    if (cloud2D.saveToFile("output2d.txt") &&
        cloud3D.saveToFile("output3d.txt")) {
        std::cout << "Точки успешно сохранены в файлы.\n";
    } else {
        std::cout << "Ошибка при сохранении точек.\n";
    }

    std::cout << "\n===== ПРОГРАММА ЗАВЕРШЕНА =====\n";

    // Проверка перегрузки операторов ввода и вывода
    PointCloud<double, 2> testCloud;

    std::cout << "\nВведите количество точек и их координаты:\n";

    if (std::cin >> testCloud) {
        std::cout << "\nРезультат ввода:\n";
        std::cout << testCloud;
    } else {
        std::cout << "Ошибка ввода данных.\n";
    }

    return 0;
}
