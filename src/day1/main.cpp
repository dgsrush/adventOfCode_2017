#include<iostream>
#include<fstream>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::fstream;

int main()
{
	string ln;
	fstream inf("input.txt", std::ios_base::in);
	inf >> ln;
	inf.close();

	int answer1 = 0;
	int answer2 = 0;

	int half = ln.length() / 2;
	int cnt = ln.length() - 1;
	for(int i = 0; i < cnt; i++)
	{
		if(ln[i] == ln[i+1])
			answer1 += ln[i] - 48;

		int nxt = i + half;
		if(nxt > cnt) nxt -= (cnt + 1);
		if(ln[i] == ln[nxt])
			answer2 += ln[i] - 48;
	}

	if(ln[cnt] == ln[0])
		answer1 += ln[cnt] - 48;

	if(ln[cnt] == ln[half - 1])
		answer2 += ln[cnt] - 48;

	cout << "PART1 answer = " << answer1 << endl; //1150
	cout << "PART2 answer = " << answer2 << endl; //1064

	return 0;
}
