class Solution {
public:
    int StrToInt(string str) {
        if(str.size() <= 0)
        {
            return 0;
        }
        int flag = 0;
        int number = 0;
        int i = 0;
        while(i < str.size())
        {
            if(str[i] == '+')
            {
                flag = 1;
                ++i;
            }
            else if(str[i] == '-')
            {
                flag = -1;
                ++i;
            }
            if(str[i] >= '0' && str[i] <= '9')
            {
                number = number*10 + str[i] - '0';
                ++i;
            }
            else
            {
                number = 0;
                break;
            }
        }
		if(flag != 0)
		{
			number *= flag;
		}

        return number;
    }
};

class StringRotation {
public:
    string rotateString(string A, int n, int p) {
		A += A;
		return A.substr((p+1)%n,n);
    }
};
int main()
{
	StringRotation s;
	string str = "ABCDEFGH";
	cout<<s.rotateString(str,8,4)<<endl;

	Solution s;
	string str = "la123423";
	cout<<s.StrToInt(str)<<endl;;

	system("pause");
	return 0;
}
