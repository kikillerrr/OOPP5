
#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <iostream>
#include <vector>
#include <array>

// Шаблонный класс облака точек
template <typename T>
class PointCloud {
private:
    std::vector<std::array<T, 2>> points;

public:
    // Добавление точки
    void addPoint(const std::array<T, 2>& point) {
        points.push_back(point);
    }

    // Получение количества точек
    std::size_t size() const {
        return points.size();
    }

    // Вывод количества точек
    void printSize() const {
        std::cout << "Количество точек: "
                  << points.size() << '\n';
    }
};

#endif
