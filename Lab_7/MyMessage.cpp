/**************************************************************************************
 * Filename: MyMessage.cpp
 * Developer: Perkova Elena
 * Description: ������ୠ� 7 ������� 4-5
 * ��᫥������� �++ ����ᮢ � IDE Qt Creator
 * ***********************************************************************************/

#include <iostream>
#include <chrono>
#include "MyMessage.h"


// �८�ࠧ������ ⨯� ᮮ�饭�� � �⠥��� ��ப�
std::string MyMessage::getTypeString(MessageType type) const {
  switch (type) {
    case MessageType::EMERGENCY:   return "EMERGENCY";   // ���਩��� �����
    case MessageType::ERROR:       return "ERROR";       // �訡�� �믮������
    case MessageType::WARNING:     return "WARNING";     // �।�०�����
    case MessageType::SYSTEM_INFO: return "SYSTEM_INFO"; // ���⥬��� ᮮ�饭��
    case MessageType::SERVICE_INFO: return "SERVICE_INFO"; // ��ࢨ᭠� ���ଠ��
    case MessageType::DEBUG:       return "DEBUG";       // �⫠��筠� ���ଠ��
    default:                       return "UNKNOWN";     // ��������� ⨯ (����)
  }
}

// ��ଠ�஢���� �뢮� ᮮ�饭��
void MyMessage::printMessage(MessageType type, const std::string& message, const std::string& function) {
  // ��ଠ�: "<��� ᮮ�饭��> <����� ᮮ�饭��> <��樮��� �㭪��"
  std::string logEntry = getTypeString(type) + ": " + message;

  // ������塞 ���ଠ�� � �㭪樨 ⮫쪮 �᫨ ��� 㪠����
  if (!function.empty()) {
    logEntry += " [" + function + "]";
  }

  // ���࠭塞 � ����� � �뢮��� � ���᮫�
  messageHistory.push_back(logEntry);
  std::cout << logEntry << std::endl;
}

// �᭮���� ��⮤ ����஢����
void MyMessage::log(MessageType type, const std::string& message, const std::string& function) {
  printMessage(type, message, function);
}

// ���樠����஢���� ��⮤� ��� ������� ⨯� ᮮ�饭��
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

// ���������� ᮮ�饭�� � ��।�
void MyMessage::addToQueue(MessageType type, const std::string& message, const std::string& function) {
  // ������㥬 ���⥪� ��� ������᭮�� ����㯠 � ��।�
  std::lock_guard<std::mutex> lock(queueMutex);

  // ������塞 ᮮ�饭�� � ��।�
  messageQueue.emplace(type, message, function);

  // �������塞 ������騩 ��⮪
  queueCV.notify_one();
}
// ��ࠡ�⪠ ��।� ᮮ�饭��
void MyMessage::processQueue() {
  while (true) {
    std::unique_lock<std::mutex> lock(queueMutex);

    // ������� ᮮ�饭�� ��� ᨣ���� ��⠭����
    queueCV.wait(lock, [this]() {
      return !messageQueue.empty() || stopFlag;
    });

    // �஢��塞 �᫮��� ��室�
    if (stopFlag && messageQueue.empty()) {
      return;
    }
    // ��������� ᮮ�饭�� �� ��।�
    if (!messageQueue.empty()) {
      auto message = messageQueue.front();
      messageQueue.pop();
      lock.unlock(); // ����� ��� 㬥��襭�� �६��� �����஢��

      // �����㥬 ᮮ�饭��
      log(std::get<0>(message), std::get<1>(message), std::get<2>(message));
    }
  }
}

// ��⠭���� ��ࠡ�⪨ ᮮ�饭��
void MyMessage::stopProcessing() {
  {
     std::lock_guard<std::mutex> lock(queueMutex);
     stopFlag = true;
  }
  queueCV.notify_one(); // ���������㥬 ������騩 ��⮪
}

namespace Workers {
  void fillRandomNumbers(std::vector<int>& array, MyMessage& logger) {
  // ��������� �㭪樨
  }

  void filterArray(std::vector<int>& array, MyMessage& logger) {
  // ��������� �㭪樨
  }

  void printArray(const std::vector<int>& array, MyMessage& logger) {
  // ��������� �㭪樨
  }
}

