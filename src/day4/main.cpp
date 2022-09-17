#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<map>
#include"ReadFile.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;
using std::map;

void tokenize(const string &str, vector<string> &ll)
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
				ll.push_back(tok);
				tok = "";
			}
		}
		else
			tok += chr;
	}
	if(tok.length() > 0)
		ll.push_back(tok);
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

bool isAnagram(string w1, string w2)
{
	if(w1.length() != w2.length()) return false;
	map<char,int> mp1, mp2;
	for(char c : w1)
		mp1[c]++;
	for(char c : w2)
		mp2[c]++;
	if(mp1 == mp2) return true;
	return false;
}

/////

int main()
{
	int answer1 = 0;
	int answer2 = 0;

	vector<string> lns;
	readInput(lns);
	for(string ln : lns)
	{
		vector<string> words;
		tokenize(ln, words);

		//part1
		unordered_map<string,int> mp;
		for(string word : words)
			mp[word]++;
		bool isValid = true;
		for(auto it = mp.begin(); it != mp.end(); ++it)
		{
			if(it->second > 1)
			{
				isValid = false;
				break;
			}
		}
		if(isValid) answer1++;

		//part2
		bool hasAnagram = false;
		for(int i = 0; i < words.size(); i++)
		{
			string w1 = words[i];
			for(int j = 0; j < words.size(); j++)
			{
				if(i == j) continue;
				string w2 = words[j];
				if(isAnagram(w1, w2))
				{
					hasAnagram = true;
					break;
				}
			}
			if(hasAnagram) break;
		}
		if(!hasAnagram) answer2++;
	}

	cout << "PART1 answer = " << answer1 << endl; //466
	cout << "PART2 answer = " << answer2 << endl; //251

	return 0;
}
