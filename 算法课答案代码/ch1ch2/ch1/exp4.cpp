#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct DataStruct				//��������ݽṹ
{	vector<string> data;		//���������Ԫ��
	map<string,int> ht;			//��map���Ԫ�ص��±�
};
void Insert(DataStruct &ds,string str)		//����Ԫ��str
{	ds.data.push_back(str);
	int i=ds.data.size()-1;					//��ȡ���Ԫ�ص��±�
	ds.ht[str]=i;
}
bool Searchi(DataStruct ds,int i,string &str)	//�����±�Ϊi��Ԫ��str
{	if(i<0 || i>=ds.data.size())
		return false;
	str=ds.data[i];
	return true;
}
int Searchs(DataStruct ds,string &str)		//����ֵΪstr��Ԫ���±�
{	map<string,int>::iterator it;
	it=ds.ht.find(str);
	if (it!=ds.ht.end())
		return it->second;
	else
		return -1;
}
bool Delete(DataStruct &ds,string str)		//ɾ��Ԫ��str
{	int i=Searchs(ds,str);					//����Ԫ��str���±�
	if(i==-1) return false;					//û��strԪ�ط���false
	int j=ds.data.size()-1;					//��βԪ���±�
	ds.data[i]=ds.data[j];					//i�±�Ԫ����βԪ�����
	ds.ht[ds.data[j]]=i;					//�޸Ĺ�ϣ����ԭ��βԪ�ص��±�
	ds.data.pop_back();					//��data��ɾ��βԪ��
}
void Display(DataStruct ds)				//�������Ԫ��
{	vector<string>::iterator it;
	for (it=ds.data.begin();it!=ds.data.end();it++)
		cout << *it << " ";
	cout << endl;
}
void main()
{
	DataStruct ds;
	string str;
	cout << "ʵ����" << endl;	
	Insert(ds,"Mary");
	Insert(ds,"Smitch");
	Insert(ds,"John");
	Insert(ds,"Anany");
	cout << "  " << "���β���Mary,Smitch,John,Anany" << endl;
	cout << "  Ԫ�ر�: "; Display(ds);
	str="John";
	cout << "  " << str << "���±�:" << Searchs(ds,str) << endl;
	cout << "  ɾ��" << str << endl;
	Delete(ds,str);
	cout << "  ɾ�����Ԫ�ر�: "; Display(ds);
} 
