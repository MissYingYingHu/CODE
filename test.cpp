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

//2.��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
class Solution {
public:
bool Find(int target, vector<vector<int> > array) 
{    
	//ע��vector<vector <int> >Ϊ��ά����
	int Row = array.size();     //ֱ�ӵ���
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