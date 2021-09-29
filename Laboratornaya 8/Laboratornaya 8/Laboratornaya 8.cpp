#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

const int maxn = 1000;
  //Во входном файле записан русский текст, содержащий не более 1000 слов
 //Вывести в алфавитном порядке слова текста, все буквы которых различны
//Оставльные слова инвертировать и вывести в соответствии с убыванием длины.

int main()
{
	setlocale(LC_ALL, "Russian");

	ifstream fin;
	ofstream fout;

	fin.open("input.txt");

	string buff;
	string words[maxn];
	string words1[maxn];
	string words2[maxn];

	char c;
	int n = 0;
	while (fin.good())
	{
		c = tolower(fin.get());
		int b = c;
		if (b >= -32 && b <= -1 && c != ' ')
		{
			buff += c;
		}
		else if ((buff.empty() == false) || (fin.good() == false))
		{
			words[n] = buff;
			n++;
			buff.clear();
		}
	}
	int s1 = 0;
	int s2 = 0;
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		buff = words[i];
		int p = buff.size();
		for (int j = 0; j < p - 1; j++)
		{
			for (int k = j + 1; k < p; k++)
			{
				if (buff[j] == buff[k]) count += 1;
			}
		}

		if (count == 0)
		{
			words1[s1] = words[i];
			s1 += 1;
		}
		else
		{
			words2[s2] = words[i];
			s2 += 1;
		}
	}
	string buff1, buff2, t;

	for (int i = 0; i < s1 - 1; i++)
	{
		buff1 = words1[i];
		int b1 = buff1[0];

		for (int j = i + 1; j < s1; j++)
		{
			buff2 = words1[j];
			int b2 = buff2[0];

			if (b1 > b2)
			{
				t = words1[i];
				words1[i] = words1[j];
				words1[j] = t;
				buff1 = words1[i];
				b1 = buff1[0];
			}
		}
	}

	for (int i = 0; i < s2; i++)
	{
		buff = words2[i];
		int p = buff.size();
		if (p % 2 == 0)
		{
			for (int j = 0; j < (p / 2); j++)
			{
				c = buff[j];
				buff[j] = buff[p - j - 1];
				buff[p - j - 1] = c;
			}
		}
		words2[i] = buff;
	}

	for (int i = 0; i < s2 - 1; i++)
	{
		for (int j = i + 1; j < s2; j++)
		{
			if (words2[i].size() < words2[j].size())
			{
				buff = words2[i];
				words2[i] = words2[j];
				words2[j] = buff;
			}
		}
	}

	for (int i = 0; i < s1; i++)
	{
		cout << words1[i] << endl;
	}
	for (int i = 0; i < s2; i++)
	{
		cout << words2[i] << endl;
	}
}