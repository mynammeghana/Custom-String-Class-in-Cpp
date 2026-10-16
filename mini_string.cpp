#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;
class STRING;
istream& operator >>(istream&,STRING &);
ostream& operator <<(ostream&,STRING &);
char* STRCPY(STRING &,const STRING &);
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
int STRLEN(const STRING&);
char* STRSTR(STRING&,char*);

class STRING
{
	public: 
	char *p1;   
	STRING(const char *s){
	       	p1=new char[strlen(s)+1];
		strcpy(p1,s);
	}




STRING(const STRING& s2)
{
    if (s2.p1 == nullptr)
    {
        p1 = nullptr;
        return;
    }

    int n = STRLEN(s2);
    p1 = new char[n + 1];

    for (int i = 0; i < n; i++)
        p1[i] = s2.p1[i];

    p1[n] = '\0';
}


	STRING(){
        p1=NULL;
	}

	void getdata(){
        cout << p1 << endl;
	}
	
	const char* operator =(const char *e){
        if(p1!=NULL)
	delete[] p1;
	int i;
	for(i=0;e[i];i++);
	p1=new char[i+1];
        for(int j=0;j<i;j++)
	p1[j]=e[j];
	p1[i]='\0';
	return p1;
	}



STRING& operator=(const STRING& t1)
{
    if (this == &t1)
        return *this;

    if (t1.p1 == nullptr)
    {
        delete[] p1;
        p1 = nullptr;
        return *this;
    }

    int n = STRLEN(t1);
    char* temp = new char[n + 1];

    for (int i = 0; i < n; i++)
        temp[i] = t1.p1[i];

    temp[n] = '\0';

    delete[] p1;
    p1 = temp;

    return *this;
}



STRING operator +(const STRING &s) const
{
    STRING s1;

    int i, j;

    for(i = 0; p1[i] != '\0'; i++);
    for(j = 0; s.p1[j] != '\0'; j++);

    s1.p1 = new char[i + j + 1];

    for(int k = 0; k < i; k++)
        s1.p1[k] = p1[k];

    for(int k = 0; k < j; k++)
        s1.p1[i + k] = s.p1[k];

    s1.p1[i + j] = '\0';

    return s1;
}


        char& operator [](int i){
	cout << "subscript" << endl;
        return p1[i];
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
friend char* STRCPY(STRING &,const STRING &);
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
friend int STRLEN(const STRING&);
friend char* STRSTR(STRING&,char*);
};



istream& operator >>(istream& in,STRING & s1){
	cout << "extraction" << endl;
	FILE *fp=fopen("string","r");
	if(fp==0)
	{
		printf("file not present\n");
		return in;
	}
	int i=0,j=0;
	char ch;
	while((fgetc(fp))!=EOF)
		i++;
	rewind(fp);
	char *temp=new char[i+1];
	while((ch=fgetc(fp))!=EOF)
	{
		temp[j]=ch;
		j++;
	}
         temp[i]='\0';
         delete[] s1.p1;
	s1.p1=temp;
	//in >> s1.p1;
	return in;
}

ostream& operator <<(ostream& out ,STRING & s){
cout << "insersion" << endl; 
out << s.p1 ;//<< endl;
return out;
}


char* STRCPY(STRING& t1, const STRING& t2)
{
    if (t2.p1 == nullptr)
    {
        delete[] t1.p1;
        t1.p1 = nullptr;
        return t1.p1;
    }

    int n = STRLEN(t2);
    char* temp = new char[n + 1];

    for (int i = 0; i < n; i++)
        temp[i] = t2.p1[i];

    temp[n] = '\0';

    delete[] t1.p1;
    t1.p1 = temp;

    return t1.p1;
}





char* STRNCPY(STRING& t1, STRING& t2, int n)
{
    if (n < 0)
        return t1.p1;

    int i = 0;

    if (t2.p1 != nullptr)
    {
        while (i < n && t2.p1[i] != '\0')
            i++;
    }

    char* temp = new char[i + 1];

    for (int j = 0; j < i; j++)
        temp[j] = t2.p1[j];

    temp[i] = '\0';

    delete[] t1.p1;
    t1.p1 = temp;

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

char* STRCAT(STRING &t1, STRING &t2) {
    cout << " concatenated 2nd string to first" << endl;
    int i, j;
    for(i = 0; t1.p1[i]; i++);
    for(j = 0; t2.p1[j]; j++);
    
    char *temp = new char[i + j + 1];
    
    for(int k = 0; k < i; k++)
        temp[k] = t1.p1[k];
        
    for(int k = 0; k < j; k++)
        temp[i + k] = t2.p1[k];
        
    temp[i + j] = '\0';
    
    delete[] t1.p1;
    t1.p1 = temp;
    
    return t1.p1;
}


char* STRNCAT(STRING &t1, STRING &t2, int m) {
    cout << " concatenated m no. of char of 2nd string to first" << endl;
    int i, j;
    for(i = 0; t1.p1[i]; i++);
    
    for(j = 0; j < m && t2.p1[j]; j++);
    
    char *temp = new char[i + j + 1];
    
    for(int k = 0; k < i; k++)
        temp[k] = t1.p1[k];
        
    for(int k = 0; k < j; k++)
        temp[i + k] = t2.p1[k];
        
    temp[i + j] = '\0';
    
    delete[] t1.p1;
    t1.p1 = temp;
    
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

int STRLEN(const STRING& t1) {
    if (t1.p1 == nullptr) {
        return 0; 
    }
    
    int n = 0;
    while (t1.p1[n] != '\0') {
        n++;
    }
    return n;
}


char* STRSTR(STRING& t1, char* m)
{
    if (t1.p1 == nullptr || m == nullptr)
        return nullptr;

    if (m[0] == '\0')
        return t1.p1;

    int i, j;

    for (i = 0; t1.p1[i] != '\0'; i++)
    {
        for (j = 0; m[j] != '\0'; j++)
        {
            if (t1.p1[i + j] == '\0' ||
                t1.p1[i + j] != m[j])
                break;
        }

        if (m[j] == '\0')
            return t1.p1 + i;
    }

    return nullptr;
}
int main()
{
STRING s=("embedded");
STRING s1,s2(s);
	s1=s;
	s="zxy",s1="123";
	cout<<"using + Operator:";
	STRING s4=s1+s;
	cout<< s4 << endl;;
	cout<<"using [i] operator :";
	//STRING s3=s2[5];
	cout << s2[5] << endl;
	cin>>s;
	cout << s;// << endl;
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
	cout<<"strcpy:" <<STRCPY(s,s1)<<endl;
	cout<<"strncpy:"<<STRNCPY(s,s1,3)<<endl;
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
cout<<"strstr:s=vector india,ind : ";
cout<<STRSTR(s,p)<<endl;
cout<<"strlen:s=vector india: ";
cout<<STRLEN(s)<<endl; 	
return 0;
}

