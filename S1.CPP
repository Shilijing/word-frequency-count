#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

void call(char a[][100]){
	char word[100];
	ifstream in("D:\\cp.txt");
	int q=0;
	char character;
	if(in) 
	{
		in>>noskipws;
		while(in>>character) 
		{ 
			int p=0;
			if(character>='A'&&character<='Z'||character>='a'&&character<='z') 
			{ 
				word[p++]=character;
			}
			else 
			{ 
				continue;
			}
			while(in>>character&&character>='A'&&character<='Z'||character>='a'&&character<='z')
			{ 
				word[p++]=character;
			}
			word[p]='\0'; 
			if (strlen(word)>=4) 
			{ 
				strcpy(a[q++], strlwr(word)); 
			}
		}
		in.close();
	}
}

int main()
{
	char temp[100][100]={0};
	char a[100][100]={0};
	int count[100]={0};
	call(a); 
	strcpy(temp[0],a[0]); 
	int num=1;
	for(int q=0;*a[q];q++) 
	{ 
		for(int p=0;*temp[p];p++) 
		{ 
			if(!strcmp(temp[p],a[q])) 
			{ 
				count[p]++;
			}
			else if(p==num-1)
			{ 
				strcpy(temp[num++],a[q]); 
			}
		}
	}
	for(int p=0;p<num-1;p++)
	{ 
		cout<<temp[p]<<":"<<count[p]<<endl;
	}
	return 0;
}