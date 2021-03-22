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
	cout << "请输入总人数" << endl;
	cin >> n;
	cout << "请输入循环报数间隔" << endl;
	cin >> m;
	cout << "请输入从几号开始报数" << endl;
	cin >> p;
	cout << "请输入报数顺序 1为正方向，0为反方向" << endl;
	cin >> direction;
	cout << endl;
	DoubleCirLinklist dcList(n);
	dcList.SetMark(p);
	for (int i = 0; i < n - 1; i++)
	{
		dcList.Move(direction, m - 1);
		cout << dcList.Delete(direction) << "号被淘汰" << endl;
	}
	cout << endl;
	cout << "最终留下的是 ";
	dcList.Print();
	cout << "号" << endl;
	return 0;
}