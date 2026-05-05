#include <iostream>
#include "Shop.hpp"
#include "Official.hpp"

int main() {
    // Устанавливаем кодировку для корректного отображения кириллицы (для Windows)
    setlocale(LC_ALL, "ru_RU.UTF-8");

    try {
        // 1. Создаем центральный узел управления (Official)
        // Он автоматически создаст объекты Account, Storage и Sale внутри себя
        Official* globalControl = new Official();

        // 2. Создаем магазин
        Shop myShop;

        // 3. Загружаем пользователей в вектор Shop
        // Внутри CompletionUsersVector() мы будем передавать globalControl 
        // каждому созданному пользователю через setOfficial()
        myShop.CompletionUsersVector(globalControl);

        std::cout << "========================================" << std::endl;
        std::cout << "   СИСТЕМА УПРАВЛЕНИЯ МАГАЗИНОМ ТЕЛЕФОНОВ" << std::endl;
        std::cout << "========================================" << std::endl;

        // 4. Запускаем главный цикл (Авторизация -> Меню)
        myShop.Start();

        // 5. Очистка ресурсов перед выходом
        delete globalControl;

    }
    catch (const std::exception& e) {
        std::cerr << "Критическая ошибка системы: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Неизвестная ошибка выполнения." << std::endl;
        return 1;
    }

    std::cout << "\nПрограмма успешно завершена. До свидания!" << std::endl;
    return 0;
}