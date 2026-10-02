#include<iostream>
using namespace std;
class STRING;
istream& operator >>(istream&,STRING &);
ostream& operator <<(ostream&,STRING &);
char* STRCPY(STRING &,STRING &);
char* STRNCPY(STRING&,STRING &,int);
int STRCMP(STRING &,STRING &);
int STRNCMP(STRING &,STRING &,int);
char* STRCAT(STRING &,STRING &);
char* STRNCAT(STRING &,STRING &,int);
char* STRREV(STRING &);
char* STRUPR(STRING &);
char* STRLWR(STRING &);
char* STRCHR(STRING &,char);
char* STRRCHR(STRING&,char);
int STRLEN(STRING&);
char* STRSTR(STRING&,char*);

class STRING
{
	char *p1;   
	public: 
	STRING(const char *s){
		p1=new char[90];
		int i=0;
		for(i=0;s[i];i++)
			p1[i]=s[i];
		p1[i]='\0';
		cout << "parametric const" << endl;
	}

	STRING(const STRING &s2){
	p1=new char[90];
	int i;
	for(i=0;s2.p1[i];i++)
	p1[i]=s2.p1[i];
 	p1[i]='\0';
	cout << "copy constructor " << endl;
	cout << p1 << endl;
	}

	STRING(){
	p1=new char[90];
	}

	void getdata(){
        cout << p1 << endl;
	}
	
	const char* operator =(const char *e){
        if(p1!=NULL)
	delete[] p1;
	int i;
	for(i=0;e[i];i++);
	p1=new char[i];
        for(int j=0;j<i;j++)
	p1[j]=e[j];
	p1[i]='\0';
	return p1;
	}

	STRING& operator =(STRING &t1){
			if(p1!=NULL)
				delete []p1;
			int i;
			for(i=0;t1.p1[i];i++);
			p1=new char[i];
        		for(int j=0;j<i;j++)
			p1[j]=t1.p1[j];
			p1[i]='\0';
			return *this;
		}


	STRING operator +(const STRING &s){
         STRING s1;
        cout << "+ overloading" << endl;
	int i,j;
	for(i=0;p1[i];i++)
	s1.p1[i]=p1[i];
	for(j=0;s.p1[j];j++,i++)
	s1.p1[i]=s.p1[j];
	s1.p1[i]='\0';
	return s1;
	}

        STRING operator [](int i){
	STRING s1;
	s1.p1[0]=p1[i];
 	s1.p1[1]='\0';
	cout << "subscript" << endl;
        return s1;
	}

	bool operator <(const STRING &s){
	bool a;
	for(int i=0;p1[i] || s.p1[i] ;i++){
 	if(p1[i]!=s.p1[i])
        {
	if(p1[i]<s.p1[i])
	return 1;
	else 
	return 0;
	}
	}
        return 0;
	}

	bool operator >(const STRING &s){
	bool a;
	for(int i=0;p1[i] || s.p1[i] ;i++){
 	if(p1[i]!=s.p1[i])
        {
	if(p1[i]>s.p1[i])
	return 1;
	else 
	return 0;
	}
	}
        return 0;
	}

	bool operator ==(const STRING &s){
	bool a;
	for(int i=0;p1[i] || s.p1[i] ;i++){
 	if(p1[i]!=s.p1[i])
        {
	return 0;
	}
	}
        return 1;
	}

	bool operator <=(const STRING &s){
	bool a;
	int i;
	for(i=0;p1[i] && s.p1[i] ;i++){
 	if(p1[i]!=s.p1[i])
        {
	if(p1[i]<s.p1[i])
	return 1;
	else
	return 0;
	}
	}
	if(p1[i]=='\0' && s.p1[i]=='\0')
	return 1;
	if(p1[i]<s.p1[i])
        return 1;
	else
	return 0;
	}

	bool operator >=(const STRING &s){
	bool a;
	int i;
	for(i=0;p1[i] && s.p1[i] ;i++){
 	if(p1[i]!=s.p1[i])
        {
	if(p1[i]>s.p1[i])
	return 1;
	else
	return 0;
	}
	}
	if(p1[i]=='\0' && s.p1[i]=='\0')
	return 1;
	if(p1[i]>s.p1[i])
        return 1;
	else 
	return 0;
	}

	bool operator !=(const STRING &s){
	bool a;
	int i;
	for(i=0;p1[i] && s.p1[i] ;i++){
 	if(p1[i]!=s.p1[i])
        {
	return 1;
	}
	}
	if(p1[i]=='\0' && s.p1[i]=='\0')
	return 0;
	else
	return 1;
	}

	~STRING(){
	if(p1!=nullptr){
		delete[] p1;
		p1=nullptr;
	}
	}
friend istream& operator >>(istream&,STRING &);
friend ostream& operator <<(ostream&,STRING &);
friend char* STRCPY(STRING &,STRING &);
friend char* STRNCPY(STRING&,STRING &,int);
friend int STRCMP(STRING &,STRING &);
friend int STRNCMP(STRING &,STRING &,int);
friend char* STRCAT(STRING &,STRING &);
friend char* STRNCAT(STRING &,STRING &,int);
friend char* STRREV(STRING &);
friend char* STRUPR(STRING &);
friend char* STRLWR(STRING &);
friend char* STRCHR(STRING &,char);
friend char* STRRCHR(STRING&,char);
friend int STRLEN(STRING&);
friend char* STRSTR(STRING&,char*);
};



istream& operator >>(istream& in,STRING & s1){
cout << "extraction" << endl;
in >> s1.p1;
return in;
}

ostream& operator <<(ostream& out ,STRING & s){
cout << "insersion" << endl; 
out << s.p1 ;//<< endl;
return out;
}

char* STRCPY(STRING &t1,STRING &t2){
int i;
for(i=0;t2.p1[i];i++)
t1.p1[i]=t2.p1[i];
t1.p1[i]='\0';
//c1(t1);
return t1.p1;
}

char* STRNCPY(STRING &t1,STRING &t2,int n){
int i;
for(i=0;i<n;i++)
t1.p1[i]=t2.p1[i];
t1.p1[i]='\0';
return t1.p1;
}

int STRCMP(STRING &t1,STRING &t2){
int n,i;
for(i=0;t1.p1[i] && t1.p1[i];i++){
if(t1.p1[i]!=t2.p1[i]){
n=(int)t1.p1[i]-(int)t2.p1[i];
return n;             //t1.p1[i]-t2.p1[i];
}
}
if(t1.p1[i]=='\0' && t2.p1[i]=='\0')
return 0;
else
return t1.p1[i]-t2.p1[i];
}

int STRNCMP(STRING &t1,STRING &t2,int m){
int n,i;
for(i=0;i<m;i++){
if(t1.p1[i]!=t2.p1[i]){
n=(int)t1.p1[i]-(int)t2.p1[i];
return n;             //t1.p1[i]-t2.p1[i];
}
}
return 0;
}

char* STRCAT(STRING &t1,STRING &t2){
int i,j,k;
cout << " concatinated 2nd string to first" << endl;
for(i=0;t1.p1[i];i++);
for(j=i,k=0;t2.p1[k];j++,k++)
t1.p1[j]=t2.p1[k];
t1.p1[j]='\0';
return t1.p1;
}

char* STRNCAT(STRING &t1,STRING &t2,int m){
int i,j,k;
cout << " concatinated m no.of char of 2nd string to first" << endl;
for(i=0;t1.p1[i];i++);
for(j=i,k=0;k<m;j++,k++)
t1.p1[j]=t2.p1[k];
t1.p1[j]='\0';
return t1.p1;
}

char* STRREV(STRING &t1){
int i,j;
for(i=0;t1.p1[i];i++);
i--;
for(j=0,i;j<i;i--,j++)
if(t1.p1[i]!=t1.p1[j])
{
char m;
m=t1.p1[i];
t1.p1[i]=t1.p1[j];
t1.p1[j]=m;
}
return t1.p1;
}

char* STRUPR(STRING &t1){
int i;
for(i=0;t1.p1[i];i++)
if(t1.p1[i]>='a' && t1.p1[i]<='z')
t1.p1[i]=t1.p1[i]-32;
return t1.p1;
}

char* STRLWR(STRING &t1){
int i;
for(i=0;t1.p1[i];i++)
if(t1.p1[i]>='A' && t1.p1[i]<='Z')
t1.p1[i]=t1.p1[i]+32;
return t1.p1;
}

char* STRCHR(STRING &t1,char ch){
int i;
for(i=0;t1.p1[i];i++)
if(t1.p1[i]==ch){
return t1.p1+i;
}
return NULL;
}

char* STRRCHR(STRING& t1,char ch){
int i,j;
for(j=0;t1.p1[j];j++);
for(i=--j;i>=0;i--)
if(t1.p1[i]==ch){
return t1.p1+i;
}
return NULL;
}

int STRLEN(STRING& t1){
int n=0;
while(t1.p1[n])
n++;
return n;
}

char *STRSTR(STRING &t1,char *m){
	int i,j,k;
	for(i=0;t1.p1[i]!='\0';i++){
		if(t1.p1[i]==m[0]){
			for(j=0;m[j]!='\0';j++)
				if(t1.p1[i+j]!=m[j] || t1.p1[i+j]=='\0')
					break;
		}
		if(m[j]=='\0')
			return t1.p1+i;
	}
	return NULL;
}

int main()
{
STRING s("embedded"),s1,s2(s);
	s1=s;
	s="zxy",s1="123";
	cout<<"using + Operator:";
	STRING s4=s1+s;
	cout<< s4 << endl;;
	cout<<"using [i] operator :";
	STRING s3=s2[5];
	cout << s3 << endl;
	cin>>s;
	cout << s << endl;
	s="abc",s1="xyz";
	cout<<"abc>xyz"<<endl;
	cout<<(s>s1)<<endl;
	cout<<"abc<xyz"<<endl;
	cout<<(s<s1)<<endl;
	cout<<"abc>=xyz"<<endl;	 
	cout<<(s>=s1)<<endl;
	cout<<"abc<=xyz"<<endl;
	cout<<(s<=s1)<<endl;
	cout<<"abc==xyz"<<endl;
	cout<<(s==s1)<<endl;
	s1="vector india bangalore";	
	cout<<STRCPY(s,s1)<<endl;
	cout<<STRNCPY(s,s1,3)<<endl;
   s="vector india";
cout<<"strupr : ";
       cout<<STRUPR(s)<<endl;
cout<<"stlwr : ";
cout<<STRLWR(s)<<endl;	
s="abc",s1="abz";
cout<<"strcmp:s=abc s1=abz : ";
cout<<STRCMP(s,s1)<<endl;
cout<<"strncmp:s=abc s1=abz,n=2 : ";
cout<<STRNCMP(s,s1,2)<<endl;
s="abc",s1="123";
cout<<"strcmp:s=abc s1=123 :";
cout<<STRCAT(s,s1)<<endl;
cout<<"strncmp:s=abc123 s1=123,n=2 : ";
cout<<STRNCAT(s,s1,2)<<endl;
cout<<"strrev:s=abc12312 : ";
cout<<STRREV(s)<<endl;
s="vector india";
cout<<"strchr:s=vector india ch=e : ";
cout<<STRCHR(s,'e')<<endl;
cout<<"strrchr:s=vector india ch=i : ";
cout<<STRRCHR(s,'i')<<endl;
char p[9]="ind";
cout<<"strstr:s=vector india ,ind : ";
cout<<STRSTR(s,p)<<endl;
cout<<"strlen:s=vector india: ";
cout<<STRLEN(s)<<endl; 	








return 0;
}


