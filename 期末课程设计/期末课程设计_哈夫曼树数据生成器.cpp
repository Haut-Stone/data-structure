/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-20 20:27:44
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-21 09:18:50
*/

//这种庞大的数据量还是用程序生成吧。
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <time.h>
#include <set>
#define WERITE_WEIGHT freopen("hfmTree.txt", "w", stdout)
using namespace std;


int main(void)
{
	WERITE_WEIGHT;

	//生成哈夫曼编码的权值
	srand(time(NULL));
	cout<<126-32+2<<endl;
	for(int i=32;i<=126;i++){
		double weight = 1+(rand()%1000)/10.0;
		cout<<char(i)<<':'<<weight<<endl;
	}
	cout<<endl;
	cout<<':'<<"5.0"<<endl;
	return 0;
}