#include<iostream>
#include<thread>
using namespace std;
 
void proc(int no);
 
int main(){
    thread thread1(proc, 1);
    thread thread2(proc, 2);
 
    thread1.join();
    thread2.join();
 
    return 0;
}
 
void proc(int no){
    for(int i = 0; i < 10; i++){
        cout << "Thread # : " << no << " / Count : " << i << endl;
    }
}