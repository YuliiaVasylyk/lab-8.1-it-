// Lab_08_1(it).cpp
// <������� ���>
// ����������� ������ �8.1(����������� �����)
// ����� �� ����� ������� � �������� ����� 
// ������ 2

#include <iostream>
#include <windows.h>

using namespace std;

int Count(char* str)
{
	int k = 0;
	for (int i = 1; str[i] != 0; i++)
		if (str[i] == '+' || str[i] == '-' || str[i] == '=')
			k++;
	return k;
}

char* Change(char* str)
{
	size_t len = strlen(str);
	char* tmp = new char[len * 2 + 1];
	char* t = tmp;
	tmp[0] = '\0';
	size_t i = 0;
	while (i < len && str[i] != 0)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '=')
		{
			strcat_s(t, sizeof(t), "**");
			t += 2;
			i++;
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	*t++ = str[i++];
	*t++ = str[i++];
	*t = '\0';
	strcpy_s(str, sizeof(tmp) + 50, tmp);
	return tmp;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char str[101];
	cout << "������ ������� �����:" << endl;
	cin.getline(str, 100);
	cout << "˳������ ����� ������ " << Count(str) << " ������� '+ - ='" << endl;
	char* dest = new char[151];
	dest = Change(str);

	cout << "������������� ������� �����: " << dest << endl;

	return 0;
}