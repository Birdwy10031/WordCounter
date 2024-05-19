#include <iostream>

#include <string>
#include <fstream>
using namespace std;
int WordCount(char op, const string& filePath)
{
	if(op!='w'&&op!='c')
	{
		cout << "Invalid Arg1.";
		return 0;
	}
	ifstream ifs(filePath);
	if (!ifs.is_open())
	{
		cout << "failed to open.";
		return 0;
	}
	string line;
	int charSum = 1;
	int wordSum = 0;
	while (getline(ifs, line))
	{
		if (line[0] != ',' && line[0] != ' '&&line[0]!='\t'&&line[0]!='\0') wordSum++;//���鿪ͷ�Ƿ�word
		for (int i = 1; i < line.size(); i++, charSum++)
		{
			while((line[i]==','||line[i]==' '||line[i]=='\t'))
			{
				i++;
				charSum++;
				if (i >= line.size()) break;
			}//��ȥword�ָ���
			if (i<line.size()&&line[i - 1] == ',' || line[i - 1] == ' '||line[i-1]=='\t') wordSum++;//ǰ����ȥ�ָ��������ͳ��word��
		}
		charSum++;//ͳ��\n
	}
	return op == 'w' ? wordSum : charSum;
}
int main(int argc,char* argv[])
{
	cout << "\n";
	cout << "Program Name: ";
	cout << argv[0];
	cout<<"\n";
	cout << "Count: " + std::to_string(WordCount(argv[1][1], argv[2])) + "\n";

	return 0;
}

