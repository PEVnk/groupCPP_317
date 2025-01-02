#ifndef T3_H
#define T3_H

#include <string>

//������� 1
//���⨯� �㭪権
double math_prob(double total_ev,double favor_ev);

//������� 2
void printChar(int a='a', char b='b',char c='c', char d='d');

//������� 3
// ������� ������쭮� ��६�����
extern int globalVar;
// ���⨯ �㭪樨 � trailing return type
auto initVars() -> void;

//������� 4
// ����᫥��� Animal
enum class Animals {
  PIG,
  CHICKEN,
  GOAT,
  CAT,
  DOG
};

//���⨯� �㭪権
void getAnimalName(Animals animal);
void printNumberOfLegs(Animals animal);

//������� 5
// �㭪樨 ��� ���� ��ࠬ��஢ ⨯� int
int max(int a, int b);
int min(int a, int b);

// ��ॣ�㦥��� �㭪樨 ��� ��ࠬ��஢ ⨯� unsigned short
unsigned short max(unsigned short a, unsigned short b);
unsigned short min(unsigned short a, unsigned short b);

// ��ॣ�㦥��� �㭪樨 ��� ��� ��ࠬ��஢ ⨯� int
int max(int a, int b, int limit);
int min(int a, int b, int limit);

//������� 6
//�㭪樨 �८�ࠧ������ ⨯��
int impConvers1(int x, float y, double z, unsigned short k);
int stCastConvers1(int x, float y, double z, unsigned short k);
int cStyleCastConvers1(int x, float y, double z, unsigned short k);

unsigned short impConvers2(int x, float y, double z);
unsigned short stCastConvers2(int x, float y, double z);
unsigned short cStyleCastConvers2(int x, float y, double z);

double impConvers3(int x, float y, double z);
double stCastConvers3(int x, float y, double z);
double cStyleCastConvers3(int x, float y, double z);

unsigned int impConvers4(int x, float y, unsigned short k);
unsigned int stCastConvers4(int x, float y, unsigned short k);
unsigned int cStyleCastConvers4(int x, float y, unsigned short k);

short impConvers5(int x, float y);
short stCastConvers5(int x, float y);
short cStyleCastConvers5(int x, float y);

//������� 7
//������� ����⠭� ��� �⠦��
enum class Level {
  PARKING=0,
  GROCERY_STORE=1,
  GYM=2,
  STORES=3,
  PLAYGROUND=4,
  FOOD_COURT=5,
  CINEMA=6,
  ROOF=7
};
//���⨯ �㭪樨
std::string getlevellName(Level level);

#endif // T3_H
