/**************************************************************************************
 * Filename: MyMessage.cpp
 * Developer: Perkova Elena
 * Description: Лабораторная 7 задания 4-5
 * Исследование С++ классов в IDE Qt Creator
 * ***********************************************************************************/

#include <iostream>
#include <chrono>
#include "MyMessage.h"


// Преобразование типа сообщения в читаемую строку
std::string MyMessage::getTypeString(MessageType type) const {
  switch (type) {
    case MessageType::EMERGENCY:   return "EMERGENCY";   // Аварийная ситуация
    case MessageType::ERROR:       return "ERROR";       // Ошибка выполнения
    case MessageType::WARNING:     return "WARNING";     // Предупреждение
    case MessageType::SYSTEM_INFO: return "SYSTEM_INFO"; // Системное сообщение
    case MessageType::SERVICE_INFO: return "SERVICE_INFO"; // Сервисная информация
    case MessageType::DEBUG:       return "DEBUG";       // Отладочная информация
    default:                       return "UNKNOWN";     // Неизвестный тип (защита)
  }
}

// Форматированный вывод сообщения
void MyMessage::printMessage(MessageType type, const std::string& message, const std::string& function) {
  // Формат: "<Тип сообщения> <Текст сообщения> <Опционно Функция"
  std::string logEntry = getTypeString(type) + ": " + message;

  // Добавляем информацию о функции только если она указана
  if (!function.empty()) {
    logEntry += " [" + function + "]";
  }

  // Сохраняем в историю и выводим в консоль
  messageHistory.push_back(logEntry);
  std::cout << logEntry << std::endl;
}

// Основной метод логирования
void MyMessage::log(MessageType type, const std::string& message, const std::string& function) {
  printMessage(type, message, function);
}

// Специализированные методы для каждого типа сообщений
void MyMessage::logEmergency(const std::string& message, const std::string& function) {
  log(MessageType::EMERGENCY, message, function);
}

void MyMessage::logError(const std::string& message, const std::string& function) {
  log(MessageType::ERROR, message, function);
}

void MyMessage::logWarning(const std::string& message, const std::string& function) {
    log(MessageType::WARNING, message, function);
}

void MyMessage::logSystemInfo(const std::string& message, const std::string& function) {
  log(MessageType::SYSTEM_INFO, message, function);
}
void MyMessage::logServiceInfo(const std::string& message, const std::string& function) {
  log(MessageType::SERVICE_INFO, message, function);
}

void MyMessage::logDebug(const std::string& message, const std::string& function) {
  log(MessageType::DEBUG, message, function);
}

// Добавление сообщения в очередь
void MyMessage::addToQueue(MessageType type, const std::string& message, const std::string& function) {
  // Блокируем мьютекс для безопасного доступа к очереди
  std::lock_guard<std::mutex> lock(queueMutex);

  // Добавляем сообщение в очередь
  messageQueue.emplace(type, message, function);

  // Уведомляем ожидающий поток
  queueCV.notify_one();
}
// Обработка очереди сообщений
void MyMessage::processQueue() {
  while (true) {
    std::unique_lock<std::mutex> lock(queueMutex);

    // Ожидаем сообщений или сигнала остановки
    queueCV.wait(lock, [this]() {
      return !messageQueue.empty() || stopFlag;
    });

    // Проверяем условие выхода
    if (stopFlag && messageQueue.empty()) {
      return;
    }
    // Извлекаем сообщение из очереди
    if (!messageQueue.empty()) {
      auto message = messageQueue.front();
      messageQueue.pop();
      lock.unlock(); // Анлок для уменьшения времени блокировки

      // Логируем сообщение
      log(std::get<0>(message), std::get<1>(message), std::get<2>(message));
    }
  }
}

// Остановка обработки сообщений
void MyMessage::stopProcessing() {
  {
     std::lock_guard<std::mutex> lock(queueMutex);
     stopFlag = true;
  }
  queueCV.notify_one(); // Разблокируем ожидающий поток
}

namespace Workers {
  void fillRandomNumbers(std::vector<int>& array, MyMessage& logger) {
  // Реализация функции
  }

  void filterArray(std::vector<int>& array, MyMessage& logger) {
  // Реализация функции
  }

  void printArray(const std::vector<int>& array, MyMessage& logger) {
  // Реализация функции
  }
}

