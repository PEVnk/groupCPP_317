#include <iostream>    // ������砥� ������⥪� ��� �����/�뢮��
#include <iomanip>     // ������砥� ������⥪� ��� �ଠ�஢���� �����/�뢮��
using namespace std;   // ������砥� ����࠭�⢮ ����

// main - ������� �㭪�� � ���ன ��稭����� �ᯮ������ �ணࠬ��
/*--------------------------------------------------------------------------*/
int main()
{ /* ������ ᪮��� - ��砫� ����� �⥩⬥��, ���� �⭮��騩�� � �㭪樨 main */
// ���� �㭪樨

//������� 1.1.

#if 0
�뢮� � ���᮫�
#endif
  std::cout << "����� ��㯯� 317, 䠪���� �������⥫쭮�� ��ࠧ������" << std::endl;
  std::cout << "���ࠡ��稪� �ணࠬ�� 1. ��મ�� ����� �������஢��" << std::endl;
  std::cout << "                       2. ______________" << std::endl;
  std::cout << "����� ������୮� ࠡ��� 1" << std::endl;
  std::cout << endl;

/*��ꥬ *.exe 䠩�� � ०��� �⫠��� 65 ��,
 * � ०��� ���᪠ 17 ��*/


//������� 1.2.

#if 0
  �뢮� � ���᮫�
#endif

// ��⠭���� 䫠�� �뢮��
  cout.setf(ios::fixed);
  cout << setw(10)<< "*****" << setw(35) << "�����" << setw(35)<< "*****" << setw(10) << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout.setf( ios::left);
  cout << "                                               �������: ���. ��ࠧ������"
     << endl;
  cout << "                                               ��㯯�: 317" << endl;
  cout << "                                               ��㤥��: ��મ�� �����"
     <<endl;
  cout.unsetf( ios::left);  // ��⨥ 䫠��
  cout << endl;
  cout << setw(50) << "���� 2024" << endl;
  cout << endl;

 //������� 1.3


  //�襭�� ��ࢮ� ����� �� ���᫥��� ᪮���
  double DistanceS,TimeT, SpeedV;
  cout << "������ ����ﭨ� DistanceS(��): ";
  cin >> DistanceS;
  cout << "������ �६� TimeT(�): ";
  cin >> TimeT;
  SpeedV=DistanceS/TimeT;
  cout << "������� ��אַ��������� ��������: " << SpeedV << " ��/�" << endl;

  //�襭�� ��ன ����� �� ���᫥��� �᪮७��
  double InitialSpeed,FinalSpeed,Time,AccelerationA;
  cout << "������ ��砫��� ᪮���� InitialSpeed (�/�): ";
  cin >> InitialSpeed;
  cout << "������ ������� ᪮���� FinalSpeed (�/�): ";
  cin >> FinalSpeed;
  cout << "������ �६� Time(�): ";
  cin >> Time;
  AccelerationA=(FinalSpeed-InitialSpeed)/Time;
  cout << "�᪮७��: " << AccelerationA << " �/�2" << endl;

  //�襭�� ���쥩 ����� �� ���᫥��� ࠤ��� ��㣠
  double Pi,RadiusR,LengthCircle;
  Pi=3.14;
  cout << "������ ����� ���㦭��� (�): ";
  cin >> LengthCircle;
  RadiusR=LengthCircle/(2*Pi);
  cout << "������ ���㦭���: " << RadiusR << " �" << endl;

} /* ������� ᪮��� - ����砭�� ����� �⥩⬥��, ���� �⭮��騩�� � �㭪樨 main */
/*--------------------------------------------------------------------------*/
// end main_cpp
/*--------------------------------------------------------------------------*/
