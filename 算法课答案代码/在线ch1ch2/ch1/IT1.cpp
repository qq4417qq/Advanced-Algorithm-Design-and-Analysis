#include<iostream>
#include<string>
#include<vector>
using namespace std;
//��������ʾ
vector<string> vec;		//�洢������
int n;					//������ַ�������
bool islexicalorder()		//�ж�vec�Ƿ����ֵ�������
{	int i=0;
    	while (i<vec.size()-1)
	{	if(vec[i].compare(vec[i+1])>0)
            return false;
        i++;
    }
    return true;
}
bool islengthorder()		//�ж�vec�Ƿ����ַ�����С����
{	int i=0;
    	while(i<vec.size()-1)
	{	if(vec[i+1].size()<vec[i].size())
			return false;
        	i++;
    	}
    	return true;
}
int main()
{	string s;
    	bool flag1,flag2;
    	cin >> n;				//����n
	for (int i=0;i<n;i++)
	{	cin >> s;			//����һ���ַ���
        	vec.push_back(s);	//��ӵ�vec�ַ���������
    	}
    	flag1=islexicalorder();
    	flag2=islengthorder();
	if(flag1 && flag2)
        cout << "both";
    else if(flag1)
        cout << "islexicalorder";
    else if(flag2)
        cout << "lengths";
    else
        cout << "none";
    return 0;
}
