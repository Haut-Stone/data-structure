/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-19 15:28:13
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-20 18:08:16
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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;


void read();//读取数据并配合有强大的错误处理功能。
void huffmanCoding();
void aTob();
void bToa();
void showTheTree();

int aNum;
map<char, double> dic;


int main(void)
{
	// INPUT_TEST;
	read();
	printf("YES\n");
	return 0;
}

void read()
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

}



