#include<iostream>
#include<string>
#include<vector>
#include"ReadFile.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

void tokenize(const string &str, vector<int> &ll)
{
	string delims("\t ");
	string tok("");
	for(int i = 0; i < str.length(); i++)
	{
		string chr(1, str[i]);
		if(delims.find(chr) != string::npos)
		{
			if(tok.length() > 0)
			{
				ll.push_back(std::stoi(tok));
				tok = "";
			}
		}
		else
			tok += chr;
	}
	if(tok.length() > 0)
		ll.push_back(std::stoi(tok));
}

void readInput(vector<string> &lns)
{
	mhr::ReadFile inf("input.txt");
	string ll;
	while(inf.readLine(ll))
	{
		if(ll.length() > 0)
			lns.push_back(ll);
	}
	inf.close();
}

int main()
{
	vector<string> lns;
	readInput(lns);

	int answer1 = 0;
	int answer2 = 0;

	for(string ln : lns)
	{
		vector<int> ll;
		tokenize(ln, ll);

		/////

		int min = INT_MAX;
		int max = 0;
		for(int i : ll)
		{
			if(i < min) min = i;
			if(i > max) max = i;
		}
		answer1 += (max - min);

		/////

		bool done = false;
		for(int i1 : ll)
		{
			for(int i2 : ll)
			{
				if(i1 == i2) continue;
				if((i1 % i2) == 0)
				{
					answer2 += i1 / i2;
					done = true;
				}
				else if((i2 % i1) == 0)
				{
					answer2 += i2 / i1;
					done = true;
				}
				if(done) break;
			}
			if(done) break;
		}
	}

	cout << "PART1 answer = " << answer1 << endl; //42299
	cout << "PART2 answer = " << answer2 << endl; //277

	return 0;
}
