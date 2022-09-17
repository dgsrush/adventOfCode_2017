#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;

int main()
{
	int inp = 325489;
	int answer1 = 0;
	int x = 0;
	int y = 0;
	char dir = 'R';
	int amt = 1;
	int dircnt = 0;

	for(int i = 1; i <= inp; i++)
	{
		if(i == inp)
			answer1 = abs(x) + abs(y);

		if(dir == 'R')
		{
			x++;
			dircnt++;
			if(dircnt == amt) { dircnt = 0; dir = 'U'; }
		}
		else if(dir == 'U')
		{
			y++;
			dircnt++;
			if(dircnt == amt) { dircnt = 0; dir = 'L'; amt++; }
		}
		else if(dir == 'L')
		{
			x--;
			dircnt++;
			if(dircnt == amt) { dircnt = 0; dir = 'D'; }
		}
		else if(dir == 'D')
		{
			y--;
			dircnt++;
			if(dircnt == amt) { dircnt = 0; dir = 'R'; amt++; }
		}
	}

	cout << "PART1 answer = " << answer1 << endl; //552

	/////

	int answer2 = 0;
	x = 0;
	y = 0;
	dir = 'R';
	amt = 1;
	dircnt = 0;
	unordered_map<string,int> mp;

	while(true)
	{
		int val = 0;
		string xy1 = std::to_string(y-1) + ":" + std::to_string(x);
		string xy2 = std::to_string(y-1) + ":" + std::to_string(x-1);
		string xy3 = std::to_string(y-1) + ":" + std::to_string(x+1);
		string xy4 = std::to_string(y+1) + ":" + std::to_string(x);
		string xy5 = std::to_string(y+1) + ":" + std::to_string(x-1);
		string xy6 = std::to_string(y+1) + ":" + std::to_string(x+1);
		string xy7 = std::to_string(y) + ":" + std::to_string(x+1);
		string xy8 = std::to_string(y) + ":" + std::to_string(x-1);
		if(mp.count(xy1) == 1) val += mp[xy1];
		if(mp.count(xy2) == 1) val += mp[xy2];
		if(mp.count(xy3) == 1) val += mp[xy3];
		if(mp.count(xy4) == 1) val += mp[xy4];
		if(mp.count(xy5) == 1) val += mp[xy5];
		if(mp.count(xy6) == 1) val += mp[xy6];
		if(mp.count(xy7) == 1) val += mp[xy7];
		if(mp.count(xy8) == 1) val += mp[xy8];

		string xy = std::to_string(y) + ":" + std::to_string(x);
		if(mp.empty()) val = 1;
		mp[xy] = val;

		if(val > inp)
		{
			answer2 = val;
			break;
		}

		if(dir == 'R')
		{
			x++;
			dircnt++;
			if(dircnt == amt) { dircnt = 0; dir = 'U'; }
		}
		else if(dir == 'U')
		{
			y++;
			dircnt++;
			if(dircnt == amt) { dircnt = 0; dir = 'L'; amt++; }
		}
		else if(dir == 'L')
		{
			x--;
			dircnt++;
			if(dircnt == amt) { dircnt = 0; dir = 'D'; }
		}
		else if(dir == 'D')
		{
			y--;
			dircnt++;
			if(dircnt == amt) { dircnt = 0; dir = 'R'; amt++; }
		}
	}

	cout << "PART2 answer = " << answer2 << endl; //330785

	return 0;
}
