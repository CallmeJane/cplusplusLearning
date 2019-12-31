#pragma once
#include<vector>
using std::vector;
vector<int> merge_sort(vector<int> ia, int start, int end)
{
	vector<int> ret;
	if (start < end)
	{
		int center = (start + end) / 2;
		vector<int> ret1=merge_sort(ia, start, center);
		vector<int> ret2=merge_sort(ia, center + 1, end);
		auto iter1 = ret1.begin(), iter2 = ret2.begin();
		for (; iter1 = ret1.end(), iter2 != ret2.end();)
		{
			if (*iter1>*iter2)
			{
				ret.push_back(*iter2);
				iter2++;
			}
			else
			{
				ret.push_back(*iter1);
				iter1++;
			}
		}
		if (iter1 != ret1.end())
		{
			for (; iter1 != ret1.end();)
			{
				ret.push_back(*iter1);
				iter1++;
			}
		}
		else if (iter2 != ret2.end())
		{
			for (; iter2 != ret2.end();)
			{
				ret.push_back(*iter2);
				iter2++;
			}
		}
	}
	else
	{
		ret.push_back(ia[start]);
	}
	return ret;
}
