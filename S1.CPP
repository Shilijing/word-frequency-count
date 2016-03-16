#include <iostream>
#include <string>
using namespace std;
  
struct Word   
{
     string Str;
     int Count;
};
 
void CalcCount(Word *words,string &content,int size)        
{
	int i;                                                  
    for ( i = 0; i < size; i++ )
    {
		if(words[i].Str==content )
         {
			words[i].Count++;
            return;
         }
		else if(words[i].Str=="" )
             break;
    }
     words[i].Str=content;
     words[i].Count=1;
}

int main()  
{  
	Word *words;  
	string content;  
	cout<<"";  
	getline(cin, content);  
   
    int wCount = 1;  
	for(unsigned int i=0;i<content.length();i++)  
	{  if(content[i]==' ') 
	wCount++;  
    }  
     words = new Word[wCount];  
     string::size_type offset=content.find(' ');  
     while(offset!=string::npos)  
     {  
         string wStr=content.substr(0, offset);  
         content.erase(0, offset+1);  
         CalcCount(words, wStr, wCount);  
         offset = content.find(' ');  
     }  
     CalcCount(words,content,wCount); 
void SortWordDown(Word *words, int size)   
{  
	for(int i=0; i<size;i++)  
	{  
		for(intj=0;j<size-1;j++)  
		{  
			if(words[j].Count<words[j+1].Count)  
			{  words[j].exchange(words[j+1]); } 
		} 
	}
}
return 0;
}