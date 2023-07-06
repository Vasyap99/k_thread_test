#include <iostream>
#include <string>
#include <thread>
#include <vector> 

using namespace std;


vector<int> m={12,54,732,74,22,953,345,245,14,3653,764,84,341,6436,2347,6731,4552,367,427,381,624};
int M=5;

void write_msg(const std::string msg)
{
    std::cout << msg << std::endl;
}
 

int *result;

void calc(int n,int b,int e){
    cout << "thread " << b << " " << e << endl;
    int sum=0;
    for(int i=b;i<e;i++) sum+=m[i];
    result[n]=sum;
}




int main()
{

    //size of a part
    int sz=m.size() / M;

    if(m.size() % M != 0) sz++;

    cout << sz;

    //
    thread **ts=new thread*[M];

    //
    result=new int[M];

    //cycle
    for(int j=0;j<M;j++){
	int e=j*sz+sz;
	if(e>m.size()) e=m.size();
	ts[j]=new thread(calc,j,j*sz,e);
    }

    for(int j=0;j<M;j++){
	cout << "joining " << j << endl;
	ts[j]->join();
    }

    int sum=0;
    for(int j=0;j<M;j++) sum+=result[j];
    cout << sum << endl;

    int sum1=0;
    for(int j=0;j<m.size();j++) sum1+=m[j];
    cout << sum1 << endl;




    delete[]ts;
    delete[]result;

    std::thread t(write_msg, "Hello, world!");
    t.join();
    return 0;
}