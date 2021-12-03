// ƒано л≥терний р€док, €кий м≥стить посл≥довн≥сть символ≥в s[0], ..., s[n], ...
// 1. ѕ≥драхувати к≥льк≥сть входжень кожного ≥з символ≥в У+Ф, У-Ф, У=Ф в посл≥довн≥сть
//s[1], Е, s[n].
// 2.  «ам≥нити кожну пару символ≥в У++Ф, У--Ф, У==Ф тр≥йкою з≥рочок У***Ф.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(char* str,int i,int k);
char* Change(char* str, char* buff, int i, int l);


int main()
{

	char str[101];
	char* buff = new char[strlen(str) * 1.5 + 1];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str,0,0) << " groups of '+' '=' '-'" << endl;
	char* dest = new char[151];
	dest = Change(str,buff,0,0);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}int Count(char* str,int i,int k)
{
	
	if (str[i] == '+' || str[i] == '-' || str[i] == '=')
	{
		k++;
	}

	if (str[i + 1] != '\0')
	{
		return Count(str, i + 1, k);
	}
	else
	{
		return k;
	}

}char* Change(char* str,char *buff,int i,int l)
{
	
	if ((str[i] == '+' && str[i + 1] == '+') || (str[i] == '-' && str[i + 1] == '-') || (str[i] == '=' && str[i + 1] == '='))
	{
		buff[l] = '*';
		buff[l + 1] = '*';
		buff[l + 2] = '*';
		l += 3;
		i++;
	}
	else
	{
		buff[l] = str[i];
		l++;
	}

	if (str[i + 1] != '\0')
	{
		return Change(str, buff, i + 1, l);
	}
	else
	{
		buff[l] = '\0';
		return buff;
	}
}