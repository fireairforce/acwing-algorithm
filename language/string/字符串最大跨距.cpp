#include<iostream>
using namespace std;
int main()
{
    string s,s1,s2;
    cin>>s;
    int index1=s.find(","),index2=s.rfind(",");
    s1=s.substr(index1+1,index2-index1-1);
    s2=s.substr(index2+1);
    s=s.substr(0,index1);
    auto q=s.find(s1),w=s.rfind(s2);
    if(q==string::npos||w==string::npos||(w<=q+s1.size()))
        cout<<-1<<endl;
    else
        cout<<w-q-s1.size()<<endl;
    return 0;
}


// abcd123ab888efghij45ef67kl,ab,ef