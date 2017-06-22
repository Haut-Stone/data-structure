/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-19 15:28:13
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-21 22:45:14
*/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define N 1000
#define INF 99999999
#define ture true
#define READ_ASCLL freopen("/Users/li/GitHub/data-structure/期末课程设计/ascll.txt", "r", stdin)
#define READ_CONSOLEIN freopen("/Users/li/GitHub/data-structure/期末课程设计/consoleIn.txt", "r", stdin)
#define READ_CONSOLEOUT freopen("/Users/li/GitHub/data-structure/期末课程设计/consoleOut.txt", "r", stdin)
#define READ_HUFFMANCODE freopen("/Users/li/GitHub/data-structure/期末课程设计/huffmanCode.txt", "r", stdin)
#define READ_TREE freopen("/Users/li/GitHub/data-structure/期末课程设计/tree.txt", "r", stdin)
#define READ_WAITFORTRAN freopen("/Users/li/GitHub/data-structure/期末课程设计/waitForTran.txt", "r", stdin)
#define READ_WEIGHT freopen("/Users/li/GitHub/data-structure/期末课程设计/weight.txt", "r", stdin)
#define READ_HUFFMANCODEPRINT freopen("/Users/li/GitHub/data-structure/期末课程设计/huffmanCodePrint.txt", "r", stdin)
#define WERITE_ASCLL freopen("/Users/li/GitHub/data-structure/期末课程设计/ascll.txt", "w", stdout)
#define WERITE_CONSOLEIN freopen("/Users/li/GitHub/data-structure/期末课程设计/consoleIn.txt", "w", stdout)
#define WERITE_CONSOLEOUT freopen("/Users/li/GitHub/data-structure/期末课程设计/consoleOut.txt", "w", stdout)
#define WERITE_HUFFMANCODE freopen("/Users/li/GitHub/data-structure/期末课程设计/huffmanCode.txt", "w", stdout)
#define WERITE_TREE freopen("/Users/li/GitHub/data-structure/期末课程设计/tree.txt", "w", stdout)
#define WERITE_WAITFORTRAN freopen("/Users/li/GitHub/data-structure/期末课程设计/waitForTran.txt", "w", stdout)
#define WERITE_WEIGHT freopen("/Users/li/GitHub/data-structure/期末课程设计/weight.txt", "w", stdout)
#define WERITE_HUFFMANCODEPRINT freopen("/Users/li/GitHub/data-structure/期末课程设计/huffmanCodePrint.txt", "w", stdout)
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
	int flag;

	Node(){
		id = 0;
		value = 0;
		weight = 0;
		parent = 0;
		lChild = 0;
		rChild = 0;
		vis = 0;
		flag = 0;
	}
	Node(int I, int VA, int W, int P, int L, int R, int VI, int F){
		id = I;
		value = VA;
		weight = W;
		parent = P;
		lChild = L;
		rChild = R;
		vis = VI;
		flag = F;
	}
}huffmanNode[N];
 
void readFromConsole();//with powerful check function
int huffmanCoding();//construct huffmantree and coding
void aTob();//ascll to binary
void bToa();//binary to ascll
void readFromFile();
void extract();
int compress();//返回添加的补码的个数
void saveTree(int allNodeNumber);//save structer.
void probabilityStatistics();//analysis the content
void showTheTreeInConsole(int NodeId);
void showTheCodeInConsoloAndSaveIt();
void showHuffmanCodeInConsole();
void saveTheTreeConstruct();

int aNum;
int command;
stack<string> format, temp;
string a = "|   ";
string b = "    ";
map<char, string> huffmanCode;
map<char, double> dic;

int main(void){

	READ_CONSOLEIN;
	WERITE_CONSOLEOUT;

	cout<<"HELLO!"<<endl;
	cout<<"would like input the data from file or console?"<<endl;

	while(command <= 0){
		cout<<"1:console, 2:file"<<endl;
		cin>>command;
		cin.clear();
		cin.ignore(1024, '\n');//忽略回车和回车前的1024个字符
		if(command <= 0 || command > 2) cout<<"WARNING: The input num must be 1 or 2"<<endl;
	}

	if(command == 1){
		readFromConsole();
	}else{
		probabilityStatistics();
		readFromFile();
	}

	int all = huffmanCoding();
	showHuffmanCodeInConsole();
	aTob();
	bToa();
	showTheCodeInConsoloAndSaveIt();
	READ_CONSOLEIN;
	WERITE_CONSOLEOUT;
	showTheTreeInConsole(all);
	saveTheTreeConstruct();
	compress();
	return 0;
}

void readFromFile(){

	READ_WEIGHT;
	WERITE_CONSOLEOUT;

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

void readFromConsole(){
	READ_CONSOLEIN;
	WERITE_CONSOLEOUT;

	aNum = 0;

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
	cout<<"Please input each ascll with value with a format like a:54"<<endl;
	for(int i=1;i<=aNum;i++){
		cout<<"case "<<i<<" = ";
		while(1){
			scanf("%c", &tempChar);
			cin>>format;

			for(map<char, double>::iterator it = dic.begin();it!=dic.end();it++){
				if(it->first == tempChar){
					cout<<"Tiis ascll have been joined, try another."<<endl;
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

int huffmanCoding(){
	READ_CONSOLEIN;
	WERITE_CONSOLEOUT;
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

	saveTree(allNodeNumber);
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
	return allNodeNumber;
}

void showHuffmanCodeInConsole(){
	READ_CONSOLEIN;
	WERITE_CONSOLEOUT;

	for(map<char, string>::iterator it = huffmanCode.begin();it!=huffmanCode.end();it++){
		if(it->first == '\n'){
			cout<<"\\n: "<<it->second<<endl;
		}else{
			cout<<it->first<<": "<<it->second<<endl;
		}
	}
}

void aTob(){
	READ_WAITFORTRAN;
	WERITE_HUFFMANCODE;

	char inChar;
	if(command == 1) cout<<"please input the string"<<endl;
	while(scanf("%c", &inChar) != EOF){
		cout<<huffmanCode[inChar];
	}	
}

void bToa(){
	READ_HUFFMANCODE;
	WERITE_CONSOLEOUT;

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
	
	WERITE_ASCLL;
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

void probabilityStatistics(){
	READ_WAITFORTRAN;
	WERITE_WEIGHT;

	char solo;
	int cnt = 0;
	int row[300];
	memset(row, 0, sizeof(row));

	while(scanf("%c", &solo) != EOF){
		cnt++;
		row[int(solo)]++;
	}

	int anotherCnt = 0;
	for(int i=32;i<=126;i++){
		if(row[i] != 0) anotherCnt++;
	}
	if(row[10] != 0) anotherCnt++;

	cout<<anotherCnt<<endl;
	for(int i=32;i<=126;i++){
		if(row[i] != 0){
			cout<<char(i)<<':'<<double(row[i])/cnt<<endl;
		}
	}
	if(row[10] != 0) cout<<endl<<':'<<double(row[10])/cnt<<endl;
}

void saveTree(int allNodeNumber){
	FILE *hfmTree;
	hfmTree = fopen("hfmTree", "wb");
	fwrite(huffmanNode+1, sizeof(Node), allNodeNumber, hfmTree);
	fclose(hfmTree);
}

void showTheCodeInConsoloAndSaveIt(){
	READ_HUFFMANCODE;
	WERITE_CONSOLEOUT;

	FILE *huffmanCodePrint;
	huffmanCodePrint = fopen("huffmanCodePrint.txt", "w");

	int cnt = 0;
	char solo;
	while(scanf("%c", &solo) != EOF){
		printf("%c", solo);
		fprintf(huffmanCodePrint, "%c", solo);
		cnt++;
		if(cnt >= 50){
			printf("\n");
			fprintf(huffmanCodePrint, "\n");
			cnt = 0;
		}
	}
	fclose(huffmanCodePrint);
}

void showTheTreeInConsole(int NodeId){

	string c;
	while(!format.empty()){
		c = format.top();
		format.pop();
		temp.push(c);
	}

	while(!temp.empty()){
		c = temp.top();
		cout<<c;
		temp.pop();
		format.push(c);
	}

	
	if(huffmanNode[NodeId].lChild == 0 && huffmanNode[NodeId].rChild == 0){
		if(huffmanNode[NodeId].value == '\n'){
			cout<<"+---"<<"\\n"<<':'<<huffmanNode[NodeId].weight<<endl;
		}else{
			cout<<"+---"<<huffmanNode[NodeId].value<<':'<<huffmanNode[NodeId].weight<<endl;
		}
	}else{
		cout<<"+---"<<huffmanNode[NodeId].weight<<endl;
	}

	//如果父节点有左儿子
	if(huffmanNode[huffmanNode[NodeId].parent].lChild != 0 && huffmanNode[huffmanNode[NodeId].parent].flag == 0){
		format.push(a);
		huffmanNode[huffmanNode[NodeId].parent].flag = 1;
	}else{
		format.push(b);
	}
	
	if(huffmanNode[NodeId].rChild != 0) showTheTreeInConsole(huffmanNode[NodeId].rChild);
	if(huffmanNode[NodeId].lChild != 0) showTheTreeInConsole(huffmanNode[NodeId].lChild);

	format.pop();
}

void saveTheTreeConstruct()
{
	READ_CONSOLEOUT;
	WERITE_TREE;

	FILE * treePrint;
	treePrint = fopen("tree.txt", "w");
	char solo;
	while(scanf("%c", &solo) != EOF){
		printf("%c", solo);
	}
}

int compress()
{
	READ_HUFFMANCODE;
	WERITE_CONSOLEOUT;

	unsigned char solo;
	char temp;
	int cnt = 0;
	int ans = 0;
	int res = 0;

	FILE *code;
	code = fopen("huffmanCode", "wb");

	while(scanf("%c", &temp) != EOF){
        ans = ans * 2 + (temp - '0');
        cnt++;
        if(cnt == 8){
            cnt = 0;
            printf("%d   ", ans);
            solo = char(ans);
            fwrite(&solo, sizeof(unsigned char), 1, code);
            ans = 0;
        }
    }
    
   	if(cnt != 0){
   		res = cnt;
        while(cnt <=8){
        	ans = ans * 2;
        	cnt++;
        }
        printf("%d   ", ans);
        solo = char(ans);
        fwrite(&solo, sizeof(unsigned char), 1, code);
    }
    fclose(code);
    return res;
}

void extract(){
	//这里解码的原理和编码是一样的。
}