
#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <iostream>
#include <vector>
#include <array>
#include <cstddef>
#include <type_traits>
#include <cmath>

// Основной шаблонный класс
template <typename T, int Dimensions>
class PointCloud {
    static_assert(std::is_arithmetic<T>::value,
                  "PointCloud supports only arithmetic types");

private:
    std::vector<std::array<T, Dimensions>> points;

public:
    void addPoint(const std::array<T, Dimensions>& point) {
        points.push_back(point);
    }

    std::size_t size() const {
        return points.size();
    }

    const std::vector<std::array<T, Dimensions>>& getPoints() const {
        return points;
    }

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

// Частичная специализация для трехмерного облака
template <typename T>
class PointCloud<T, 3> {
    static_assert(std::is_arithmetic<T>::value,
                  "PointCloud supports only arithmetic types");

private:
    std::vector<std::array<T, 3>> points;

public:
    void addPoint(const std::array<T, 3>& point) {
        points.push_back(point);
    }

    std::size_t size() const {
        return points.size();
    }

    const std::vector<std::array<T, 3>>& getPoints() const {
        return points;
    }

    void print() const {
        std::cout << "Специализированное трехмерное облако:\n";

        for (const auto& point : points) {
            std::cout << "("
                      << point[0] << ", "
                      << point[1] << ", "
                      << point[2] << ")\n";
        }
    }

    static std::array<T, 3> crossProduct(
        const std::array<T, 3>& a,
        const std::array<T, 3>& b) {

        return {
            a[1] * b[2] - a[2] * b[1],
            a[2] * b[0] - a[0] * b[2],
            a[0] * b[1] - a[1] * b[0]
        };
    }
};

// Глобальная шаблонная функция вычисления центроида
template <typename T, int Dimensions>
std::array<double, Dimensions> calculateCentroid(
    const PointCloud<T, Dimensions>& cloud) {

    std::array<double, Dimensions> center{};

    if (cloud.size() == 0) {
        return center;
    }

    for (const auto& point : cloud.getPoints()) {
        for (int i = 0; i < Dimensions; ++i) {
            center[i] += static_cast<double>(point[i]);
        }
    }

    for (int i = 0; i < Dimensions; ++i) {
        center[i] /= cloud.size();
    }

    return center;
}

// Вторая глобальная шаблонная функция — расстояние между точками
template <typename T, std::size_t Dimensions>
double distanceBetween(
    const std::array<T, Dimensions>& a,
    const std::array<T, Dimensions>& b) {

    double sum = 0.0;

    for (std::size_t i = 0; i < Dimensions; ++i) {
        double difference =
            static_cast<double>(a[i]) -
            static_cast<double>(b[i]);

        sum += difference * difference;
    }

    return std::sqrt(sum);
}

#endif
