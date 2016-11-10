#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
stack<unsigned int> Numbers;
int main()
{
	unsigned int temp;
	while(true){
		scanf("%d",&temp);
		if(temp == 0){
			break;
		} 
		Numbers.push(temp);
	}
	while(!Numbers.empty()){
		printf("%d ",Numbers.top());
		Numbers.pop();
	}
	printf("\n");
	return 0;
}