/*
* ������ୠ� ࠡ�� �2
* ��᫥������� �����-�뢮�� ⨯�� ������ �⠭���⭮� ������⥪� �++
* ���� ������
* Developer: ��મ�� �.�.
*/
/*
* INCLUDE LIBS
*/
#include <iostream> /* ������砥� ������⥪� ��� �����/�뢮�� */
#include <iomanip> //��� setprecision()
#include <cmath>  // ������砥� ������⥪� ��� ��⥬���᪨� �㭪権
#include <bitset> //��� ����筮�� �।�⠢�����
using namespace std; /* ����࠭�⢮ ���� std */

//main - ������� �㭪�� � ���ன ��稭����� �ᯮ������ �ணࠬ��
int main() { // ��砫� ����� �⥩⬥��, ⥫� �㭪樨 main

//������� 1
  cout << "������ ᢮� ������ (������⢮ ������ ���) � ������ Enter" << endl; // �뢮� ᮮ�饭��
  int agePerson;
  cin >> agePerson;    //����砥� ���짮��⥫�᪮� �᫮ � ��࠭塞 ��� � ��६�����
  cout << "������ ᢮� ��� � �� � ������ Enter" << endl; // �뢮� ᮮ�饭��
  int weightPerson;
  cin >> weightPerson; //����砥� ���짮��⥫�᪮� �᫮ � ��࠭塞 ��� � ��६�����
  cout << "������ ᢮� ��� � � � ������ Enter" << endl; // �뢮� ᮮ�饭��
  int heightPerson;
  cin >> heightPerson; //����砥� ���짮��⥫�᪮� �᫮ � ��࠭塞 ��� � ��६�����
  cout << "�᫨ ��稭� ������ 1, ���騭� - 0 � ������ Enter" << endl; // �뢮� ᮮ�饭��
  int genderPerson;
  cin >> genderPerson; //����砥� ���짮��⥫�᪮� �᫮ � ��࠭塞 ��� � ��६�����

  //���� �����쭮�� ��� �� ��㫥 �ப�
  double idealWeight;
  //��� ��稭
  if (genderPerson==1){
      idealWeight=(heightPerson-100)*0.9;
      cout << fixed << setprecision(3);
      cout << "a - �� ��㫥 �ப�: " << idealWeight<< endl;
  //��� ���騭
  } else if (genderPerson==0){
      idealWeight=(heightPerson-100)*0.85;
      cout << fixed << setprecision(3);
      cout << "a - �� ��㫥 �ப�: " << idealWeight<< endl;
  }

  //���� ������ ����� ⥫�
  double bodyMassIndex;
  bodyMassIndex = weightPerson/((heightPerson/100.0)*(heightPerson/100.0));
  cout << "���=" << bodyMassIndex << endl;
  if (bodyMassIndex<=16){
      cout << "b - �� ������� ����� ⥫�: ��ࠦ���� ����� �����" << endl;
  } else if (bodyMassIndex>16 && bodyMassIndex<=18.5){
      cout << "b - �� ������� ����� ⥫�: �������筠� (�����) ���� ⥫�" << endl;
  } else if (bodyMassIndex>18.5 && bodyMassIndex<=25){
      cout << "b - �� ������� ����� ⥫�: ��ଠ" << endl;
  } else if (bodyMassIndex>25 && bodyMassIndex<=30){
      cout << "b - �� ������� ����� ⥫�: �����筠� ���� ⥫� (�।���७��)" << endl;
  } else if (bodyMassIndex>30 && bodyMassIndex<=35){
      cout << "b - �� ������� ����� ⥫�: ���७�� ��ࢮ� �⥯���" << endl;
  } else if (bodyMassIndex>35 && bodyMassIndex<=40){
      cout << "b - �� ������� ����� ⥫�: ���७�� ��ன �⥯���" << endl;
  } else if (bodyMassIndex>40){
      cout << "b - �� ������� ����� ⥫�: ���७�� ���쥩 �⥯��� (��ࡨ����)" << endl;
  }

  //������ ����� ⥫� �� �������
  if (genderPerson==1){
    if (agePerson>=19 && agePerson<=24){
        if (bodyMassIndex<21.4){
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ����� ����� ⥫�" << endl;
        } else if (bodyMassIndex>=21.4 && bodyMassIndex<26.4){
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ��ଠ��� ���" << endl;
        } else {
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: �஡���� � ��譨� ��ᮬ" << endl;
        }
    }
    if (agePerson>=25 && agePerson<=34){
        if (bodyMassIndex<21.6){
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ����� ����� ⥫�" << endl;
        } else if (bodyMassIndex>=21.6 && bodyMassIndex<26.6) {
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ��ଠ��� ���" << endl;
        } else {
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: �஡���� � ��譨� ��ᮬ" << endl;
        }
    }
    if (agePerson>=35 && agePerson<=44){
        if (bodyMassIndex<22.9){
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ����� ����� ⥫�" << endl;
        } else if (bodyMassIndex>= 22.9 && bodyMassIndex<27.9) {
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ��ଠ��� ���" << endl;
        } else {
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: �஡���� � ��譨� ��ᮬ" << endl;
        }
    }
    if (agePerson>=45 && agePerson<=54){
        if (bodyMassIndex<25.8){
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ����� ����� ⥫�" << endl;
        } else if (bodyMassIndex>=25.8 && bodyMassIndex<30.8) {
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ��ଠ��� ��c" << endl;
        } else {
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: �஡���� � ��譨� ��ᮬ" << endl;
        }
    }
    if (agePerson>=55){
        if (bodyMassIndex<26.6){
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ����� ����� ⥫�" << endl;
        } else if (bodyMassIndex>=26.6 && bodyMassIndex<31.6) {
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ��ଠ��� ���" << endl;
        } else {
            cout << "� - �� ������� ����� ⥫� � ��⮬ ������: �஡���� � ��譨� ��ᮬ" << endl;
        }
    }
  } else if (genderPerson==0){
      if (agePerson>=19 && agePerson<=24){
          if (bodyMassIndex<19.5){
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ����� ����� ⥫�" << endl;
          } else if (bodyMassIndex>=19.5 && bodyMassIndex<24.5) {
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ��ଠ��� ���" << endl;
          } else {
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: �஡���� � ��譨� ��ᮬ" << endl;
          }
      }
      if (agePerson>=25 && agePerson<=34){
          if (bodyMassIndex<23.2){
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ����� ����� ⥫�" << endl;
          } else if (bodyMassIndex>=23.2 && bodyMassIndex<28.2) {
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ��ଠ��� ���" << endl;
          } else {
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: �஡���� � ��譨� ��ᮬ" << endl;
          }
      }
      if (agePerson>=35 && agePerson<=44){
          if (bodyMassIndex<23.4){
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ����� ����� ⥫�" << endl;
          } else if (bodyMassIndex>=23.4 && bodyMassIndex<28.4) {
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ��ଠ��� ���" << endl;
          } else {
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: �஡���� � ��譨� ��ᮬ" << endl;
          }
      }
      if (agePerson>=45 && agePerson<=54){
          if (bodyMassIndex<25.2){
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ����� ����� ⥫�" << endl;
          } else if (bodyMassIndex>=25.2 && bodyMassIndex<30.2) {
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ��ଠ��� ���" << endl;
          } else {
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: �஡���� � ��譨� ��ᮬ" << endl;
          }
      }
      if (agePerson>=55){
          if (bodyMassIndex<27.3){
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ����� ����� ⥫�" << endl;
          } else if (bodyMassIndex>=27.3 && bodyMassIndex<32.3) {
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: ��ଠ��� ���" << endl;
          } else {
              cout << "� - �� ������� ����� ⥫� � ��⮬ ������: �஡���� � ��譨� ��ᮬ" << endl;
          }
      }
  }



//������� 2

  //�뢮� ࠧ��� � ����� �᭮��� ⨯�� ������
  cout << "int:\t\t" << sizeof(int) << " bytes;" << endl;
  cout << "bool:\t\t" << sizeof(bool) << " bytes;" << endl;
  cout << "char:\t\t" << sizeof(char) << " bytes;" << endl;
  cout << "float:\t\t" << sizeof(float) << " bytes;" << endl;
  cout << "double:\t\t" << sizeof(double) << " bytes;" << endl;

  cout << "long:\t\t" << sizeof(long) << " bytes;" << endl;
  cout << "long long:\t" << sizeof(long long) << " bytes;" << endl;
  cout << "short:\t" << sizeof(short) << " bytes;" << endl;
  cout << "unsigned int:\t" << sizeof(unsigned int) << " bytes;" << endl;
  cout << "signed int:\t" << sizeof(signed int) << " bytes;" << endl;
  cout << "long double:\t" << sizeof(long double) << " bytes;" << endl;
  cout << "signed short:\t" << sizeof(signed short) << " bytes;" << endl;
  cout << "unsigned short:\t" << sizeof(unsigned short) << " bytes;" << endl;

  //���� �᫮���� ��������� ��� ⨯�� ������
  cout << "��᫮��� �������� int:\t�� " << long(-(pow(2,((sizeof(int)*8)-1)))) << " �� " << long((pow(2,((sizeof(int)*8)-1)))-1) << endl;
  cout << "��᫮��� �������� bool:\t�� " << long(-(pow(2,((sizeof(bool)*8)-1)))) << " �� " << long((pow(2,((sizeof(bool)*8)-1)))-1) << endl;
  cout << "��᫮��� �������� long:\t�� " << long(-(pow(2,((sizeof(long)*8)-1)))) << " �� " << long((pow(2,((sizeof(long)*8)-1)))-1) << endl;
  cout << "��᫮��� �������� signed short � oct:\t�� " << oct << long(-(pow(2,((sizeof(signed short)*8)-1)))) << " �� " << long((pow(2,((sizeof(signed short)*8)-1)))-1) << endl;
  cout << "��᫮��� �������� char � hex:\t�� " << hex<< long(-(pow(2,((sizeof(char)*8)-1)))) << " �� " << long((pow(2,((sizeof(char)*8)-1)))-1) << endl;


//������� 3

  double a1,b1,c,d,f,g,h,k1,l,m;
  cout << "������ ������ �ᥫ � ������饩 �窮�\n"; //�뢮� ᮮ�饭��
  cin >> a1 >> b1 >> c >> d >> f >> g >> h >> k1 >> l >> m; //����砥� ���짮��⥫�᪨� �᫠ � ��࠭塞 �� � ��६����
  double arithmeticMean=(a1+b1+c+d+f+g+h+k1+l+m)/10; //���� �।���� ��䬥��᪮�� �ᥫ
  cout << "�।��� ��䬥��᪮� �ᥫ ࠢ�� " << arithmeticMean << endl;

//������� 4

  double p_1=34.5;
  double p_2=0.004000;
  double p_3=123.005;
  double p_4=146000;
  //��ॢ�� � �ᯮ���樠���� ������
  cout << "p_1="<<scientific<<p_1<<endl;
  cout << "p_2="<<scientific<<p_2<<endl;
  cout << "p_3="<<scientific<<p_3<<endl;
  cout << "p_4="<<scientific<<p_4<<endl;

//������� 5
//1)
  cout << ((true && true) || false) << endl;            //true
  cout << ((false && true) || true) << endl;            //true
  cout << ((false && true) || false || true) << endl;   //true
  cout << ((5 > 6 || 4 > 3) && (7 > 8)) << endl;        //false
  cout << (!(7 > 6 || 3 > 4)) << endl;                  //false

//2)
  //������� �����᪨� ����⠭� � ������� const
  const bool CONST_TRUE=true;
  const bool CONST_FALSE=false;

  //������� �����᪨� ����⠭� � ������� constexpr
  constexpr bool CONSTEXPR_TRUE=true;
  constexpr bool CONSTEXPR_FALSE=false;

  //������� �����᪨� ����⠭� � ������� ����ᮢ
  #define MACRO_TRUE true
  #define MACRO_FALSE false

  //������� 楫��᫥���� ����⠭ � ������� enum
  enum IntegerConst {
      ONE=1,
      TWO=2,
      THREE=3,
      FOUR=4
  };
  //�뢮� १���⮢ ��ࠦ����
  cout << "((CONST_TRUE && CONST_FALSE) || (!CONST_FALSE) && (CONST_TRUE||CONST_FALSE))= "
       << ((CONST_TRUE && CONST_FALSE) || (!CONST_FALSE) && (CONST_TRUE || CONST_FALSE)) << endl;
  cout << "((CONSTEXPR_TRUE && CONSTEXPR_FALSE) || (CONSTEXPR_TRUE && CONSTEXPR_FALSE) || (!CONSTEXPR_TRUE))= "
       <<((CONSTEXPR_TRUE && CONSTEXPR_FALSE) || (CONSTEXPR_TRUE && CONSTEXPR_FALSE) || (!CONSTEXPR_TRUE)) << endl;
  cout << "((MACRO_TRUE || MACRO_FALSE) && (MACRO_TRUE || MACRO_FALSE) && (MACRO_TRUE ||MACRO_FALSE))= "
       << ((MACRO_TRUE || MACRO_FALSE) && (MACRO_TRUE || MACRO_FALSE) && (MACRO_TRUE ||MACRO_FALSE)) << endl;
  cout << "((ONE>TWO) && (THREE<FOUR) && (TWO!=THREE))= " << ((ONE>TWO) && (THREE<FOUR) && (TWO!=THREE)) << endl;


//3)

  const bool variableA=true;
  const bool variableB=false;
  if ((!(variableA && variableB))==((!variableA) || (!variableB)))  //�஢�ઠ �ࠢ��쭮�� ��ࢮ�� ������ ��࣠��
      cout << "���� ����� ��࣠�� �������: �� (a � b) = (�� a) ��� (�� b)" << endl;
  else
      cout << "���� ����� ��࣠�� �� �������" << endl;
  if ((!(variableA || variableB))==((!variableA) && (!variableB)))  //�஢�ઠ �ࠢ��쭮�� ��ண� ������ ��࣠��
      cout << "��ன ����� ��࣠�� �������: �� (a ��� b) = (�� a) � (�� b)" << endl;
  else
      cout << "��ன ����� ��࣠�� �� �������" << endl;

//4)
  cout << "������ 楫��᫥��� ��६����� x, y, z, v" << endl;
  int x,y,z,v;
  bool logicValue;
  cin >> x >> y >> z >> v; //����砥� ���짮��⥫�᪨� �᫠ � ��࠭塞 �� � ��६����
  x=3+4+5; //��ᢠ����� � ���祭�� 12
  cout << "x = " << x << "\ty = " << y << "\tz = " << z << "\tv = " << v << endl;   //�뢮� ����祭��� ���祭��
  x=y=z; //��ᢠ����� � � y ���祭�� ࠢ��� z
  cout << "x = " << x << "\ty = " << y << "\tz = " << z << "\tv = " << v << endl;   //�뢮� ����祭��� ���祭��
  z*=++y+5; //���६��� ��६����� y, y ��ᢠ������� �� ���祭��, z 㬭������� �� y
  cout << "x = " << x << "\ty = " << y << "\tz = " << z << "\tv = " << v << endl;   //�뢮� ����祭��� ���祭��
  logicValue=x || y && z || v; //��ࠦ���� �㤥� false, �᫨ z � v ����砫쭮 ࠢ�� 0
  cout << "logicValue = " << logicValue << endl;

//5)
  unsigned int varNumber,shiftNumber;
  cout << "������ 楫�� �᫮ �� 0 �� 16" << endl;
  cin >> varNumber;
  cout << "������ 楫�� �᫮ ᤢ��� �����" << endl;
  cin >> shiftNumber;
  cout << "� �����筮� �ଠ� " << varNumber << "<<" << shiftNumber << ": " << (varNumber << shiftNumber) << endl;
  cout << "� ��⭠����筮� �ଠ� " << varNumber << "<<" << shiftNumber << ": " << hex << (varNumber << shiftNumber) << endl;
  cout << "� ���쬨�筮� �ଠ� " << varNumber << "<<" << shiftNumber << ": " << oct << (varNumber << shiftNumber) << endl;
  cout << "� ����筮� �ଠ� " << varNumber << "<<" << shiftNumber << ": "
       << bitset<8*sizeof(varNumber << shiftNumber)>(varNumber << shiftNumber) << endl;

//6)

  int a=20, b=10, k=30;
  // �ਮ��� �����஢: 㬭������, �������, ᫮�����, ���⠭��
  int res_1=a+b*1-128/5;
  // �ਮ��� �����஢: ᤢ�� ��ࠢ�, ����⮢�� ���
  int res_2=a | b >> 1;
  // �ਮ��� �����஢: �������, 㬭������; 㬭������ � ������� ����� ����� ���樠⨢����� � �믮������� ᫥�� ���ࠢ�
  int res_3=a/b*k;
  cout << "res_1 = a+b*1-128/5 = " << res_1 << endl;
  cout << "res_2 = a | b >> 1 = " << res_2 << endl;
  cout << "res_3 = a/b*k = " << res_3 << endl;



  cin.clear();
  cin.ignore(32767, '\n');
  cin.get();
  return 0;
}// ������� ᪮��� - ����砭�� ����� �⥩⬥�� ����, �⭮��饣��� � �㭪樨 main
