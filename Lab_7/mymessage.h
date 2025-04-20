/**************************************************************************************
 * Filename: MyMessage.h
 * Developer: Perkova Elena
 * Description: Лабораторная 7 задания 4-5
 * Исследование в С++ многопоточности, ошибок, отладки блоков кода в IDE Qt Creator
 * ************************************************************************************/


#ifndef MYMESSAGE_H
#define MYMESSAGE_H

#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include <queue>
#include <condition_variable>

enum class MessageType {
  EMERGENCY,    // Аварийное сообщение
  ERROR,        // Ошибка
  WARNING,      // Предупреждение
  SYSTEM_INFO,  // Системная информация
  SERVICE_INFO, // Сервисная информация
  DEBUG         // Отладочная информация
};

class MyMessage {
public:
  MyMessage() {} //Конструктор

  // Методы для логирования
  //Основной метод логирования
  void log(MessageType type, const std::string& message, const std::string& function = "");
  //Методы для каждого типа сообщений
  void logEmergency(const std::string& message, const std::string& function = "");
  void logError(const std::string& message, const std::string& function = "");
  void logWarning(const std::string& message, const std::string& function = "");
  void logSystemInfo(const std::string& messag, const std::string& function = "");
  void logServiceInfo(const std::string& message, const std::string& function = "");
  void logDebug(const std::string& message, const std::string& function = "");

  // Добавление сообщения в очередь для многопоточной обработки
  void addToQueue(MessageType type, const std::string& message, const std::string& function = "");
  // Основной цикл обработки сообщений из очереди (выполняется в отдельном потоке)
  void processQueue();
  // Сигнал остановки обработки сообщений
  void stopProcessing();

private:
  std::vector<std::string> messageHistory; // История всех сообщений
  std::queue<std::tuple<MessageType, std::string, std::string>> messageQueue; //Очередь
  std::mutex queueMutex; // Мьютекс для синхронизации доступа к очереди
  std::condition_variable queueCV; // Условная переменная для ожидания сообщений
  bool stopFlag = false; // Флаг остановки логгера

  // Преобразование MessageType в строковое представление
  std::string getTypeString(MessageType type) const;
  //Метод вывода сообщения
  void printMessage(MessageType type, const std::string& message, const std::string& function);
};

//Рабочие функции
namespace Workers {
  //Функция заполнения массива случайными числами
  void fillRandomNumbers(std::vector<int>& array, MyMessage& logger);
  //Функция фильтрации значений массива
  void filterArray(std::vector<int>& array, MyMessage& logger);
  //Функция вывода массива в консоль
  void printArray(const std::vector<int>& array, MyMessage& logger);
}

// Константы для демонстрации
namespace Config {
  constexpr int ARRAY_SIZE = 100;   // Размер тестового массива
  constexpr int MIN_VALUE = -126;   // Минимальное допустимое значение
  constexpr int MAX_VALUE = 356;    // Максимальное допустимое значение
}

#endif // MYMESSAGE_H
