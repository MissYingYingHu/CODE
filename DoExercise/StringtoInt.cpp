#include<iostream>
#include<string.h>
#include<vector>
#include<string>
#include<windows.h>
using namespace std;

class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        if(length <= 0 || iniString.empty() )
        {
            return NULL;
        }
        int BlackCount = 0;
		int tmp = 0;
        while(tmp < length)
		{
            if(iniString[tmp] == ' ')
            {
                ++BlackCount;
            }
            ++tmp;
        }
        int newend = length + BlackCount*2 ;
		iniString.resize(newend + 1);
		int oldend = length;
        while(oldend >= 0 && newend > oldend)
        {
            if(iniString[oldend] == ' ')
            {
                iniString[newend--] = '0';
                iniString[newend--] = '2';
                iniString[newend--] = '%';
            }
			else
			{
				iniString[newend--] = iniString[oldend];
			}
			--oldend;
        }
        return iniString;
    }
};

//2.在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
class Solution {
public:
bool Find(int target, vector<vector<int> > array) 
{    
	//注意vector<vector <int> >为二维数组
	int Row = array.size();     //直接调用
	int Col = array[0].size();
	int row = 0;
	int col = Col - 1;
	while(row < Row && col >= 0)
	{
		if(array[row][col] == target)
		{
			return true;
		}
		else if(array[row][col] > target)
		{
			--col;
		}
		else
		{
			++row;
		}
	}
	return false;
}
};



int main()
{
	Replacement str;
	string iniString = " ";
	cout<<str.replaceSpace(iniString,iniString.size())<<endl;;
	system("pause");
	return 0;
}