/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-19 15:28:13
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-20 22:29:55
*/


/*
		要求有以下这么几个：
		1.从终端读入字母的种类个数N，之后是n个字符n个权值。（包括空格和换行）建立哈夫曼树并保存于文件中。
		2.从文件中导入哈夫曼树，并对文章的正文进行编码，然后保存。
		3.从文件中导入哈夫曼树，并对编码进行翻译，让后保存。
		4.以紧凑格式将编码在终端打印出来，每行50个代码，同时将此字符形式的编码文件写入文件。
		5.在终端上显示具有树形结构的哈夫曼树。（很有用）
		
		6.对文件的错误输入进行检查。
		7.统计进行编码的时间。
		8.将这个项目做成以个库。
*/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define NULLVALUE 0
#define N 1000
#define INF 99999999
#define ture true
#define READ_CODE freopen("CodeFile.txt", "r", stdin)
#define READ_TEXT freopen("ToBeTran.txt", "r", stdin)
#define READ_WEIGHT freopen("hfmTree.txt", "r", stdin)
#define INPUT_TEST freopen("in.txt", "r", stdin)
#define OUTPUT_TEST freopen("out.txt", "w", stdout)
#define WERITE_CODE freopen("CodeFile.txt", "w", stdout)
#define WERITE_TEXT freopen("TextFile.txt", "w", stdout)
#define WERITE_TREE freopen("TreePrint.txt", "w", stdout)
// #define READ_CODE freopen("/Users/li/GitHub/data-structure/期末课程设计/CodeFile.txt", "r", stdin)
// #define READ_TEXT freopen("/Users/li/GitHub/data-structure/期末课程设计/ToBeTran.txt", "r", stdin)
// #define READ_WEIGHT freopen("/Users/li/GitHub/data-structure/期末课程设计/hfmTree.txt", "r", stdin)
// #define INPUT_TEST freopen("/Users/li/GitHub/data-structure/期末课程设计/in.txt", "r", stdin)
// #define OUTPUT_TEST freopen("/Users/li/GitHub/data-structure/期末课程设计/out.txt", "w", stdout)
// #define WERITE_CODE freopen("/Users/li/GitHub/data-structure/期末课程设计/CodeFile.txt", "w", stdout)
// #define WERITE_TEXT freopen("/Users/li/GitHub/data-structure/期末课程设计/TextFile.txt", "w", stdout)
// #define WERITE_TREE freopen("/Users/li/GitHub/data-structure/期末课程设计/TreePrint.txt", "w", stdout)
using namespace std;

struct Node
{
	int id;
	char value;
	double weight;
	int parent;
	int lChild;
	int rChild;
	int vis;
	// Node();
	// Node(int ID, char VALUE, double WEIGHT, int PARENT, int LCHILD, int RCHILD, int VIS){
	// 	id = ID;
	// 	value = VALUE;
	// 	weight = WEIGHT;
	// 	parent = PARENT;
	// 	lChild = LCHILD;
	// 	rChild = RCHILD;
	// 	vis = VIS;
	// }
}huffmanNode[N];
 
void iReadFromConsole();//with powerful check function
void readFromFile();
void huffmanCoding();
bool FileCheck();
void aTob();//ascli to binary
void bToa();//binary to ascil
void probabilityStatistics();
void showTheTreeInConsole();
void showHuffmanCodeInConsole();

int aNum;
map<char, string> huffmanCode;
map<char, double> dic;
priority_queue<int> priorityQueue;


int main(void)
{
	INPUT_TEST;
	int command = 0;
	cout<<"HELLO!"<<endl;
	cout<<"would like input the data from file or console?"<<endl;

	while(command <= 0){
		cout<<"1:console, 2:file"<<endl;
		cin>>command;
		cin.clear();
		cin.ignore(1024, '\n');//忽略回车和回车前的1024个字符
		if(command <= 0) cout<<"WARNING: The input num must be 1 or 2"<<endl;
	}

	
	if(command == 1){
		iReadFromConsole();
	}else{
		readFromFile();
	}

	huffmanCoding();
	showHuffmanCodeInConsole();
	aTob();
	bToa();
	OUTPUT_TEST;
	printf("YES\n");
	return 0;
}

void readFromFile()
{
	READ_WEIGHT;
	if(!FileCheck()){

	}

	char tempChar;
	double tempValue;
	char format;

	cin>>aNum;
	getchar();
	for(int i=1;i<=aNum;i++){
		scanf("%c", &tempChar);
		cin>>format>>tempValue;
		cin.ignore(1024, '\n');
		dic[tempChar] = tempValue;
	}
}

bool FileCheck()
{
	return true;
}

void iReadFromConsole()
{
	aNum = NULLVALUE;

	while(aNum <= 0){
		cout<<"Please input the aNum = ";
		cin>>aNum;
		cin.clear();
		cin.ignore(1024, '\n');//忽略回车和回车前的1024个字符
		if(aNum <= 0) cout<<"WARNING: The input num must larger than zero and not in alpha "<<endl;
	}

	char tempChar;
	char format;

	cout<<"there are totally "<<aNum<<" cases"<<endl;
	cout<<"Please input each ascil with value with a format like a:54"<<endl;
	for(int i=1;i<=aNum;i++){
		cout<<"case "<<i<<" = ";
		while(1){
			scanf("%c", &tempChar);
			cin>>format;

			for(map<char, double>::iterator it = dic.begin();it!=dic.end();it++){
				if(it->first == tempChar){
					cout<<"Tiis ascli have been joined, try another."<<endl;
					cout<<"case "<<i<<" = ";
					cin.ignore(1024,'\n');
					continue;
				}
			}

			if(format != ':'){
				cout<<"The format must be [a:v]"<<endl;
				cout<<"case "<<i<<" = ";
				cin.ignore(1024,'\n');
				continue;
			}else{
				double tempValue = 0.0;
				cin>>tempValue;
				cin.clear();
				cin.ignore(1024, '\n');
				if(tempValue <= 0){
					 cout<<"WARNING: the input must be a double and larger than zero"<<endl;
					 cout<<"case "<<i<<" = ";
					 continue;
				}else{
					dic[tempChar] = tempValue;
					break;
				}
			}
		}
	}
	return;
}

void huffmanCoding()
{	
	//现在有了存在map里的数据
	memset(huffmanNode, 0, sizeof(huffmanNode));
	int cnt = 1;
	for(map<char, double>::iterator it = dic.begin();it!=dic.end();it++,cnt++){
		huffmanNode[cnt].id = cnt;
		huffmanNode[cnt].value = it->first;
		huffmanNode[cnt].weight = it->second;
	}
	int allNodeNumber = (--cnt)*2-1;

	//之后用优先队列来代替
	for(int k=cnt+1;k<=allNodeNumber;k++){
		double min1 = INF;
		double min2 = INF;
		int id1 = 0;
		int id2 = 0;
		for(int i=1;i<=k-1;i++){
			if(!huffmanNode[i].vis){
				if(huffmanNode[i].weight < min2){
					if(huffmanNode[i].weight < min1){
						min2 = min1;
						id2 = id1;
						min1 = huffmanNode[i].weight;
						id1 = i;
					}else{
						min2 = huffmanNode[i].weight;
						id2 = i;
					}
				}
			}
		}

		huffmanNode[id1].parent = k;
		huffmanNode[id1].vis = 1;
		huffmanNode[id2].parent = k;
		huffmanNode[id2].vis = 1;
		huffmanNode[k].id = k;
		huffmanNode[k].weight = min1 + min2;
		huffmanNode[k].lChild = id1;
		huffmanNode[k].rChild = id2;
	}

	//编码
	char soloCode[N];
	soloCode[cnt-1] = '\0';
	for(int i=1;i<=cnt;i++){
		int start = cnt-1;
		int now = i;
		char nowValue = huffmanNode[now].value;
		int father = huffmanNode[i].parent;
		while(father != 0){
			if(huffmanNode[father].lChild == now){
				soloCode[--start] = '0';
			}else{
				soloCode[--start] = '1';
			}
			now = father;
			father = huffmanNode[father].parent;
		}
		char temp[N];
		strcpy(temp, &soloCode[start]);
		huffmanCode[nowValue] = temp;
	}
}

void showHuffmanCodeInConsole()
{
	for(map<char, string>::iterator it = huffmanCode.begin();it!=huffmanCode.end();it++){
		if(it->first == '\n'){
			cout<<"\\n: "<<it->second<<endl;
		}else{
			cout<<it->first<<": "<<it->second<<endl;
		}
	}
}

void aTob()
{
	READ_TEXT;

	char inChar;
	cout<<"please input the string"<<endl;
	WERITE_CODE;
	while(scanf("%c", &inChar) != EOF){
		cout<<huffmanCode[inChar];
	}	
}

void bToa()
{
	OUTPUT_TEST;
	READ_CODE;

	char inCode[999999];
	int len;
	cout<<"please input the code"<<endl;

	while(1){
		cin>>inCode;
		len = strlen(inCode);
		for(int i=0;i<len;i++){
			if(inCode[i] != '0' && inCode[i] != '1'){
				cout<<"the code can only fill with 0 or 1"<<endl;
				cout<<"please input the code"<<endl;
				cin.ignore(1024,'\n');
				continue;
			}
		}
		break;
	}
	

	int mapLen;
	int first = 0;
	
	WERITE_TEXT;
	while(first < len){
		for(map<char, string>::iterator it = huffmanCode.begin();it!=huffmanCode.end();it++){
			mapLen = it->second.length();
			char temp[N];
			for(int i=0;i<mapLen;i++){
				temp[i] = inCode[first + i];
				temp[i+1] = '\0';
			}
			if(strcmp(temp, it->second.c_str()) == 0){
				cout<<it->first;
				first += mapLen;
				break;
			}
		}
	}
	cout<<endl;
}
