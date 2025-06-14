/**************************************************************************************
 * Filename: lab8.h
 * Developer: Perkova Elena
 * Description: ������ୠ� 8
 * ��᫥������� � �++ �⠭���⭮� ������⥪� 蠡����� (STL), ��ॣ�㧪� �����஢
 * ************************************************************************************/

#ifndef LAB_8_H
#define LAB_8_H


#include <vector>  // ��� �ᯮ�짮����� std::vector
#include <list>  // ��� �ᯮ�짮����� std::list
#include <string>
#include <mutex>
#include <thread>
#include <stdexcept>
#include <atomic>

//������� 1

//�������� N ��砩��� �ᥫ � �����頥� �� � �����
std::vector<int> generateRandomNumbers(int N);

// �뢮��� ᮤ�ন��� ���⥩��� �� 10 ����⮢ � ��ப�
void printContainer(const std::vector<int>& container);

//�뢮��� ᮤ�ন��� ���⥩��� � ���⭮� ���浪�
void printContainerReverse(const std::vector<int>& container);

// ������뢠�� ������⢮ 㭨������ �ᥫ � ���⥩���
int countUniqueNumbers(const std::vector<int>& container);


//������� 2
//===== ����� a)=====
std::vector<int> replaceEvenWithListOdd(std::vector<int>& vec, std::list<int>& lst);
void printVector(const std::vector<int>& vec);
void printList(const std::list<int>& lst);

//===== ����� b)=====
void addAverageToList(std::list<double>& lst);

//===== ����� c)=====
void processFavoriteColors();
void printColors(const std::vector<std::pair<int, std::string>>& colors);

//������� 3

class DataSizeConverter {
public:
  // ���������
  DataSizeConverter(double value, const std::string& unit);


  // �᭮���� �㭪�� �������樨
  void convert();

  // �뢮� १���⮢
  void printResults() const;

private:
  double inputValue;           // �室��� ���祭��
  std::string inputUnit;       // �室��� ������ ����७��
  std::vector<double> results; // �������� �������樨

  // �ᯮ����⥫�� ��⮤�
  void convertFromBit();
  void convertFromByte();
  void convertFromKbyte();
  void convertFromMbyte();
  void convertFromGbyte();
  void convertFromMiB();

  // �஢�ઠ �室��� ������
  bool isValidUnit() const;
};

//������� 4
class TreeNode {
private:
  int value;
  TreeNode* parent = nullptr;
  std::vector<TreeNode*> children;

public:
  explicit TreeNode(int val); //��������� explicit ��� �।���饭�� ���� �८�ࠧ������
  ~TreeNode(); //������塞 �������� ~TreeNode(), ����� ४��ᨢ�� 㤠��� �� ���୨� 㧫�

  // ����頥� ����஢���� � ��ᢠ������
  TreeNode(const TreeNode&) = delete;
  TreeNode& operator=(const TreeNode&) = delete;

  TreeNode* AddChild(int child_value);
  void Print(int depth = 0) const;
};

//������� 5

template <typename T>
class CircularBuffer {
public:
  //���� ��������� � �뤥������ �����
  explicit CircularBuffer(size_t size);
  //��������
  ~CircularBuffer();

  // ����頥� ����஢����
  CircularBuffer(const CircularBuffer&) = delete;
  CircularBuffer& operator=(const CircularBuffer&) = delete;

  //�⥭�� ����� �� �������
  T operator[](size_t index) const;

  // �᭮��� ����樨
  void add(const T& value);
  void next();

  // ��⮤� �뢮��
  void printAll() const;
  void printRange(size_t index1, size_t index2) const;

  // ��⮪���� ������
  void startWriterThread();
  void stopWriterThread();
  bool isRunning() const;

private:
  T* buffer;                  // �����⥫� �� ����
  size_t capacity;            // ������� ����
  size_t head = 0;            // ������ ������ (������)
  size_t tail = 0;            // ������ 墮�� (�⥭��)
  mutable std::mutex mtx;     // ���⥪� ��� ��⮪�������᭮��
  std::atomic<bool> running;  // ���� ࠡ��� ��⮪�

  //��⮪���� �㭪�� �����
  void writerThreadFunc();

};

#endif // LAB_8_H
