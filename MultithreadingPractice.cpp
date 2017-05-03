/*
 * MultithreadingPractice.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: iNviNciBLe
 */
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <chrono>
#include <mutex>
#include <fstream>
#include <future>

using namespace std;

/*
//Example of passing objects to the thread
class A {
public:
	//Example of functor
	void operator()() const{
		this_thread::sleep_for(3s);
		cout << "Class A" << endl;
	}
};

int main(){
	A obj;
	thread t(obj);
	cout << "From main" <<  endl;
	t.join();
	cout << "Done" ;
	return 0;
}
*/

//Very Important
//Reaource Acquisition is Resource Initialization
//Creating the wrapper class

/*
class thread_guard{
	thread& t;
public:
	explicit thread_guard(thread& t_):t(t_)
	{}
	~thread_guard(){
		if(t.joinable()){
			t.join();
		}
	}

	//Copy constructor
	thread_guard(thread_guard const&) = delete;
	//Copy assignment
	thread_guard operator=(thread_guard const&)=delete;
};*/

//Mutex Example. Data Race handling.

/*class LogFile{
	mutex mu;
	ofstream f;
public:
	LogFile(){
		f.open("input");
	}
	//Common Resource
	void shared_print(string msg, int id){
		lock_guard<mutex> locker(mu);
		f << msg << id << endl;
	}
};

void f(LogFile& log){
	for(int i = 1; i <= 100;++i)
		log.shared_print(string("From f: "),i);
}

int main(){
	LogFile log;
	thread t(f,ref(log));
	for(int i =1 ; i <=100 ; ++i)
		log.shared_print(string("From main: "),i);
	t.join();
	return 0;
}
*/

//Example of Async,Future
int factorial(int N){
	int res = 1;
	for(int i = N; i > 1; --i)
		res *= i;
	return res;
}

int main(){
	int x;
	future<int> fu = async(factorial,4);
	x = fu.get();
	cout << x;
	return 0;
}
