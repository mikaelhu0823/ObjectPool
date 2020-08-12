#include <iostream>
#include "ObjectPool.h"


struct TObj {
	TObj(){}
	TObj(int a) { std::cout << "TObj Construct: a=" << a << std::endl; }
	TObj(const int& a, const int& b) { std::cout << "TObj Construct: a=" << a << ", b=" << b << std::endl; }

	void Print(const std::string& str) {
		std::cout << "TObj::Print: " << str << std::endl;
	}
};

void Print(std::shared_ptr<TObj> p, const std::string & str){
	if (p != nullptr) {
		p->Print(str);
	}
}

void TestObjPool() {
	DesignPattern::ObjectPool<TObj> pool;
	pool.Init(3);
	{
		auto p1 = pool.Get();
		Print(p1, "p1");
		auto p2 = pool.Get();
		Print(p2, "p2");
		auto p3 = pool.Get();
		Print(p3, "p3");
	}
	auto p1 = pool.Get();
	Print(p1, "p1");
	auto p2 = pool.Get();
	Print(p2, "p2");
	auto p3 = pool.Get();
	Print(p3, "p3");

	pool.Init(2, 1);
	auto p4 = pool.Get<int>();
	Print(p4, "p4");
	pool.Init(2, 1, 2);
	auto p5 = pool.Get<int, int>();
	Print(p5, "p5");
}

int main(int argc, char** argv) {
	TestObjPool();

	return 0;
}