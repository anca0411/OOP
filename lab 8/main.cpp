#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>

using namespace std;

string to_lowercase(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] > 'A' || s[i] < 'Z')
			s[i] = tolower(s[i]);
	}
	return s;
}
int main()
{
	string prop;
	ifstream fin("input.txt");
	getline(fin, prop);
	string delimitatori(".,?!; ");
	int start = 0;
	map<string, int> word;
	if (!fin)
	{
		printf("error la deschiderea fisierului: input.txt");
		return 0;
	}
	while (true)
	{
		
		int end = prop.find_first_of(delimitatori, start); //de la pozitia start gaseste mi un delimitator
		if (end == string::npos) { end = prop.size(); }
		else
		{
			string subprop = prop.substr(start, end - start); // extrage un cuvant de la start de lungimea end-start
			if (!subprop.empty())
			{
				subprop = to_lowercase(subprop);
				//cout << subprop;
				word[subprop]++;
			}
		}
		if (end == prop.size()) break;
		start = end + 1;
	}
	//map<string, int>::iterator it;
	//for (it = word.begin(); it != word.end(); it++)
	//	cout << it->first << " => " << it->second << endl;
	struct Compare {
		bool operator()(pair<string, int> a, pair<string, int> b)
		{
			if (a.second != b.second)
				return a.second < b.second;  //frecventa mai mare
			return a.first>b.first;          //lexicografic
		}
	};
	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;

	for (auto it = word.begin(); it != word.end(); it++)
		pq.push(*it);
	while (pq.empty() == false)
	{
		cout << pq.top().first << "=>" << pq.top().second << endl;
		pq.pop();
	}
}