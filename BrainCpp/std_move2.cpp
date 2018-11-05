#include <iostream>
#include <vector>

using namespace std;

class MyContainer {
private:
	vector<int> * bucket;
	vector<int> v;
	int count;
	int value;

public:
	// 생성자 
	MyContainer(int cnt, int val) {
		cout << "생성자 호출" << endl;
		for(auto i = 0; i < cnt; ++i) { 
			v.push_back(val);
		}
		bucket = &v;
		count = cnt;
		value = val;
		cout << "bucket: " << bucket << endl;
	}

	// 복사 생성자
	MyContainer(const MyContainer& copy) {
		cout << "복사 생성자 호출" << endl;
		auto val = copy.v.begin();
		for(auto i = 0; i < copy.count; ++i) {
			v.push_back(*(val + i));
		}
		bucket = &v;
		count = copy.count;
		cout << "bucket: " << bucket << endl;
	}

	// 이동 생성자
	MyContainer(MyContainer&& move) {
		cout << "이동 생성자 호출" << endl;
		bucket = &(move.v);
		count = move.count;
		move.count = 0;
		cout << "bucket : " << bucket << endl;
	}

	// 이동 대입 연산자
	MyContainer operator= (MyContainer&& move) {
		cout << "이동 대입 연산자 호출" << endl;
		// swap(count, move.count);
		count = move.count;
		v.clear();
		for(auto i = move.v.begin(); i != move.v.end(); ++i) {
			v.push_back(move.value);
		}
		bucket = &v;
		count << "bucket: " << bucket << endl;
		return *this;
	}

	void showContainer() {
		cout << "[showContainer]" << endl;
		for(auto i = (*bucket).begin(); i != (*bucket).end(); ++i) {
			cout << *i << " ";
		}
		cout << endl;
		auto i = (*bucket).begin();
		cout << &(*i) << endl;
	}	
};

MyContainer CreateMyContainer(int m, int n) { 
	return MyContainer(m, n);
}

int main() {
	MyContainer myCon1(20, 1);
	MyCon1.showContainer();
	MyContainer myCon2 = myCon1;
	myCon2.showContainer();
	MyContainer myCon3(20, 3);
	myCon3.showContainer();
	MyContainer myCon4(std::move(myCon3));
	myCon4.showContainer();
	myContainer myCon5(20, 5);                                                                                         
	myCon5.showContainer();
	myCon5 = CreateMyContainer(20, 7);
	myCon5.showContainer();

	return 0;
}