/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-06-21 21:21:09
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-06-21 21:43:27
 */

//压缩的核心
//

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define R_EAD freopen("/Users/li/GitHub/data-structure/期末课程设计/huffmanCode.txt", "r", stdin)
using namespace std;


unsigned char solo;
char temp;
int cnt = 0;
int ans = 0;

int main(void)
{
    R_EAD;
    FILE * code;
    code = fopen("/Users/li/GitHub/data-structure/期末课程设计/huffmanCode", "wb");
    
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
        while(cnt <=8){
        	ans = ans * 2;
        	cnt++;
        }
        printf("%d   ", ans);
        solo = char(ans);
        fwrite(&solo, sizeof(unsigned char), 1, code);
    }
    
    fclose(code);
    return 0;
}