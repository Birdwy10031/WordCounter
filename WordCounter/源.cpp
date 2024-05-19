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
		if (line[0] != ',' && line[0] != ' '&&line[0]!='\t'&&line[0]!='\0') wordSum++;//检验开头是否含word
		for (int i = 1; i < line.size(); i++, charSum++)
		{
			while((line[i]==','||line[i]==' '||line[i]=='\t'))
			{
				i++;
				charSum++;
				if (i >= line.size()) break;
			}//略去word分隔符
			if (i<line.size()&&line[i - 1] == ',' || line[i - 1] == ' '||line[i-1]=='\t') wordSum++;//前面略去分隔符的情况统计word数
		}
		charSum++;//统计\n
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

