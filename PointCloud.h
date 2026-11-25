
#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <iostream>
#include <vector>
#include <array>
#include <cstddef>

// Шаблонный класс облака точек
template <typename T, int Dimensions>
class PointCloud {
private:
    std::vector<std::array<T, Dimensions>> points;

public:
    // Добавление точки
    void addPoint(const std::array<T, Dimensions>& point) {
        points.push_back(point);
    }

    // Получение количества точек
    std::size_t size() const {
        return points.size();
    }

    // Получение всех точек
    const std::vector<std::array<T, Dimensions>>& getPoints() const {
        return points;
    }

    // Вывод облака
    void print() const {
        std::cout << "Облако точек (" << Dimensions << "D):\n";

        for (const auto& point : points) {
            std::cout << "(";

            for (int i = 0; i < Dimensions; ++i) {
                std::cout << point[i];

                if (i < Dimensions - 1) {
                    std::cout << ", ";
                }
            }

            std::cout << ")\n";
        }
    }
};

#endif
