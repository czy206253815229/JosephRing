#include <iostream>
#include"DoubleCirLinklist.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int n, m, p;
	bool direction;
	cout << "������������" << endl;
	cin >> n;
	cout << "������ѭ���������" << endl;
	cin >> m;
	cout << "������Ӽ��ſ�ʼ����" << endl;
	cin >> p;
	cout << "�����뱨��˳�� 1Ϊ������0Ϊ������" << endl;
	cin >> direction;
	cout << endl;
	DoubleCirLinklist dcList(n);
	dcList.SetMark(p);
	for (int i = 0; i < n - 1; i++)
	{
		dcList.Move(direction, m - 1);
		cout << dcList.Delete(direction) << "�ű���̭" << endl;
	}
	cout << endl;
	cout << "�������µ��� ";
	dcList.Print();
	cout << "��" << endl;
	return 0;
}