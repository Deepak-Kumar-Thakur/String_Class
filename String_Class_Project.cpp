/*STRING CLASS*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class STRING
{
	char *ptr;
	public:
		STRING(void);
		STRING(STRING& obj);
		STRING(const char *const ptr1);
		char*& get_ptr(void);		
		void operator=(STRING& obj);
		void operator=(const char *const ptr);
		friend istream& operator>>(istream&, STRING&);
		friend ostream& operator<<(ostream&, STRING);
		char& operator[](int i);
		STRING& operator+(STRING& obj);
		bool operator>(STRING& obj);	
		bool operator<(STRING& obj);
		bool operator>=(STRING& obj);
		bool operator<=(STRING& obj);
		bool operator!=(STRING& obj);
		bool operator==(STRING& obj);
		~STRING()
		{
			delete[]ptr;
		}
};
STRING::STRING()
{
	ptr=NULL;
}
STRING::STRING(const char *const ptr1)
{
	int i=0;
	ptr=new char;
	while(ptr1[i])
	{				
		ptr[i]=ptr1[i];
		i++;
		ptr=(char*)realloc(ptr, i+1);
	}
	ptr[i]=0;
}
STRING::STRING(STRING& obj)
{
	int i=0;
	ptr=new char;
	while(obj.ptr[i])
	{				
		ptr[i]=obj.ptr[i];
		i++;
		ptr=(char*)realloc(ptr, i+1);
	}
	ptr[i]=0;
}
char*& STRING::get_ptr(void)
{
	return(ptr);
}
void STRING::operator=(const char *const ptr1)
{	
	delete[]ptr;
	int i=0;
	ptr=new char;
	while(ptr1[i])
	{				
		ptr[i]=ptr1[i];
		i++;
		ptr=(char*)realloc(ptr, i+1);
	}
	ptr[i]=0;
}
void STRING::operator=(STRING& obj)
{
	delete[]ptr;
	int i=0;
	ptr=new char;
	while(obj.ptr[i])
	{				
		ptr[i]=obj.ptr[i];
		i++;
		ptr=(char*)realloc(ptr, i+1);
	}
	ptr[i]=0;
}
istream& operator>>(istream& din, STRING& obj)
{
	char ch;
	obj.ptr=new char;
	int i=1;
	while(1)
	{
		ch=din.get();
		if((ch==' ')||(ch=='\n'))
		{	
			obj.ptr[i-1]=0;
			return (din);
		}
		obj.ptr[i-1]=ch;
		i++;
		obj.ptr=(char*)realloc(obj.ptr, i);
	}
}
ostream& operator<<(ostream& dout, STRING obj)
{
	int i=0;	
	while(obj.ptr[i])
	{
		dout<<obj.ptr[i];
		i++;
	}
	return(dout);
}
char& STRING::operator[](int i)
{
	return(ptr[i]);
}
STRING& STRING::operator+(STRING& obj)
{
	int string_length, i, j;
	for(i=0; ptr[i]; i++);
	string_length=i;
	for(i=string_length, j=0; obj[j]; j++)
	{
		ptr[i]=obj[j];
		i++;
		ptr=(char*)realloc(ptr, i+1);
	}
	ptr[i]=0;
	return (*this);
}
bool STRING::operator>(STRING& obj)
{
	int i=0;
	while(1)
	{
		if(ptr[i] > obj.ptr[i])
			return (1);
		if(ptr[i] < obj.ptr[i])
			return (0);
		if((ptr[i]==0) || (obj.ptr[i]==0))
			return(0);
		i++;
	}	
}
bool STRING::operator<(STRING& obj)
{	
	int i=0;
	while(1)
	{
		if(ptr[i] < obj.ptr[i])
			return (1);
		if(ptr[i] > obj.ptr[i])
			return (0);
		if((ptr[i]==0) || (obj.ptr[i]==0))
			return(0);
		i++;
	}	
}
bool STRING::operator>=(STRING& obj)
{
	int i=0;
	while(1)
	{
		if(ptr[i] > obj.ptr[i])
			return (1);
		if(ptr[i] < obj.ptr[i])
			return (0);
		if((ptr[i]==0) && (obj.ptr[i]==0))
			return(1);
		i++;
	}	
}
bool STRING::operator<=(STRING& obj)
{
	int i=0;
	while(1)
	{
		if(ptr[i] < obj.ptr[i])
			return (1);
		if(ptr[i] > obj.ptr[i])
			return (0);
		if((ptr[i]==0) && (obj.ptr[i]==0))
			return(1);
		i++;
	}	
}
bool STRING::operator!=(STRING& obj)
{
	int i=0;
	while(1)
	{
		if(ptr[i] != obj.ptr[i])
			return (1);
		if((ptr[i]==0)&&(obj.ptr[i]==0))
			return (0);
		i++;
	}
}
bool STRING::operator==(STRING& obj)
{
	int i=0;
	while(1)
	{
		if(ptr[i] != obj.ptr[i])
			return (0);
		if((ptr[i]==0) && (obj.ptr[i]==0))
			return (1);
		i++;
	}
}
int STRCMP(STRING& obj1, STRING& obj2)
{
	int i=0;
	while(1)
	{
		if(obj1[i] != obj2[i])
			return (obj1[i] - obj2[i]);
		if((obj1[i]==0) && (obj2[i]==0))
			return (0);
		i++;
	}
}
void STRCPY(STRING& obj1, STRING& obj2)
{
	delete[]obj1.get_ptr();
	obj1.get_ptr()=new char;
	int i=0;
	while(obj2[i])
	{
		obj1[i]=obj2[i];
		i++;
		obj1.get_ptr()=(char*)realloc(obj1.get_ptr(), i+1);
	}
	obj1[i]=0;
}				
int STRLEN(STRING& obj)
{
	int string_length=0;
	while(obj[string_length])
		string_length++;
	return (string_length);
}
void STRNCPY(STRING& obj1, STRING& obj2, int noc)
{
	delete[]obj1.get_ptr();
	int i=0;
	obj1.get_ptr()=new char;
	while(noc)
	{
		obj1[i]=obj2[i];
		i++;
		obj1.get_ptr()=(char*)realloc(obj1.get_ptr(), i+1);
		noc--;
	}
	obj1[i]=0;
}
int STRNCMP(STRING& obj1, STRING& obj2, int noc)
{
	
	int i=0;
	while(noc)
	{
		if(obj1[i] != obj2[i])
			return (obj1[i] - obj2[i]);
		i++;
		noc--;
	}
	return (0);
}
void STRREV(STRING& obj)
{
	char temp;
	int i, j;
	for(i=0, j=STRLEN(obj)-1; i<j; i++, j--)
	{
		temp=obj[i];
		obj[i]=obj[j];
		obj[j]=temp;
	}
}
char* STRCHR(STRING& obj, char ch)
{
	int i=0;
	while(obj[i])
	{
		if(ch==obj[i])
			return (&(obj[i]));
		i++;
	}
	return (0);
}
char* STRSTR(STRING& obj1, STRING& obj2)
{
	int i, j, count, string_length=STRLEN(obj2);
	for(i=0; obj1[i]; i++)
	{
		for(j=0, count=0; obj2[j]; )
		{
			if(obj1[i]==obj2[j])
			{
				i++;
				j++;
				count++;
			}
			else
				break;
		}
		if(count==string_length)
			return (obj1.get_ptr()+i-count);
	}
	return (0);
}
void STRCAT(STRING& obj1, STRING& obj2)
{
	int string_length=STRLEN(obj1);
	int i, j;
	for(i=string_length, j=0; obj2[j]; j++)
	{
		obj1[i]=obj2[j];
		i++;
		obj1.get_ptr()=(char*)realloc(obj1.get_ptr(), i+1);
	}
	obj1[i]=0;
}
void STRNCAT(STRING& obj1, STRING& obj2, int noc)
{
	int string_length=STRLEN(obj1);
	int i, j;
	for(i=string_length, j=0; noc; j++, noc--)
	{
		obj1[i]=obj2[j];
		i++;
		obj1.get_ptr()=(char*)realloc(obj1.get_ptr(), i+1);
	}
	obj1[i]=0;
}
int main(void)
{
	STRING str1("Hello "),str2("World");
	cout<<"str1[]="<<str1<<endl;
	cout<<"str2[]="<<str2<<endl;	
	return 0;
}	
