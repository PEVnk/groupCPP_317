/**************************************************************************************
 * Filename: MyMessage.h
 * Developer: Perkova Elena
 * Description: ������ୠ� 7 ������� 4-5
 * ��᫥������� � �++ ��������筮��, �訡��, �⫠��� ������ ���� � IDE Qt Creator
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
  EMERGENCY,    // ���਩��� ᮮ�饭��
  ERROR,        // �訡��
  WARNING,      // �।�०�����
  SYSTEM_INFO,  // ���⥬��� ���ଠ��
  SERVICE_INFO, // ��ࢨ᭠� ���ଠ��
  DEBUG         // �⫠��筠� ���ଠ��
};

class MyMessage {
public:
  MyMessage() {} //���������

  // ��⮤� ��� ����஢����
  //�᭮���� ��⮤ ����஢����
  void log(MessageType type, const std::string& message, const std::string& function = "");
  //��⮤� ��� ������� ⨯� ᮮ�饭��
  void logEmergency(const std::string& message, const std::string& function = "");
  void logError(const std::string& message, const std::string& function = "");
  void logWarning(const std::string& message, const std::string& function = "");
  void logSystemInfo(const std::string& messag, const std::string& function = "");
  void logServiceInfo(const std::string& message, const std::string& function = "");
  void logDebug(const std::string& message, const std::string& function = "");

  // ���������� ᮮ�饭�� � ��।� ��� ��������筮� ��ࠡ�⪨
  void addToQueue(MessageType type, const std::string& message, const std::string& function = "");
  // �᭮���� 横� ��ࠡ�⪨ ᮮ�饭�� �� ��।� (�믮������ � �⤥�쭮� ��⮪�)
  void processQueue();
  // ������ ��⠭���� ��ࠡ�⪨ ᮮ�饭��
  void stopProcessing();

private:
  std::vector<std::string> messageHistory; // ����� ��� ᮮ�饭��
  std::queue<std::tuple<MessageType, std::string, std::string>> messageQueue; //��।�
  std::mutex queueMutex; // ���⥪� ��� ᨭ�஭���樨 ����㯠 � ��।�
  std::condition_variable queueCV; // �᫮���� ��६����� ��� �������� ᮮ�饭��
  bool stopFlag = false; // ���� ��⠭���� ������

  // �८�ࠧ������ MessageType � ��ப���� �।�⠢�����
  std::string getTypeString(MessageType type) const;
  //��⮤ �뢮�� ᮮ�饭��
  void printMessage(MessageType type, const std::string& message, const std::string& function);
};

//����稥 �㭪樨
namespace Workers {
  //�㭪�� ���������� ���ᨢ� ��砩�묨 �᫠��
  void fillRandomNumbers(std::vector<int>& array, MyMessage& logger);
  //�㭪�� 䨫���樨 ���祭�� ���ᨢ�
  void filterArray(std::vector<int>& array, MyMessage& logger);
  //�㭪�� �뢮�� ���ᨢ� � ���᮫�
  void printArray(const std::vector<int>& array, MyMessage& logger);
}

// ����⠭�� ��� ��������樨
namespace Config {
  constexpr int ARRAY_SIZE = 100;   // ������ ��⮢��� ���ᨢ�
  constexpr int MIN_VALUE = -126;   // �������쭮� �����⨬�� ���祭��
  constexpr int MAX_VALUE = 356;    // ���ᨬ��쭮� �����⨬�� ���祭��
}

#endif // MYMESSAGE_H
