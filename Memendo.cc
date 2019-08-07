#include <stdio.h>
#include<string>

class Memento {
public:
	Memento(int n, std::string s) {
		_s = s;
		_money = n;
	}
	void setMoney(int n) {
		_money = n;
	}

	int getMoney() {
		return _money;
	}

	void setState(std::string s) {
		_s = s;
	}

	std::string getState() {
		return _s;
	}

private:
	int _money;
	std::string _s;
};

class Worker {
public:
	Worker(std::string name, int money, std::string s) {
		_name = name;
		_money = money;
		_s = s;
	}

	void show() {
		printf("%s现在有钱%d元,生活状态%s！\n", _name.c_str(), _money, _s.c_str());
	}

	void setState(int money, std::string s) {
		_money = money;
		_s = s;
	}

	Memento* createMemnto() {
		return new Memento(_money,_s);
	}

	void restoreMemnto(Memento* m) {
		_money = m->getMoney();
		_s = m->getState();
	}
private:
	std::string _name;
	int _money;
	std::string _s;
};

class WorkerStorage {
public:
	void setMemento(Memento* m) {
		_memento = m;
	}

	Memento* getMement() {
		return _memento;
	}
private:
	Memento* _memento;
};

int main() {

	Worker* zhangsan = new Worker("张三", 10000, "富裕");
	zhangsan->show();

	//记住张三现在的状态
	WorkerStorage* storage = new WorkerStorage;
	storage->setMemento(zhangsan->createMemnto());

	//张三赌博输了钱，只剩下10元
	zhangsan->setState(10, "贫困");
	zhangsan->show();

	//经过努力张三又回到了之前的状态。
	zhangsan->restoreMemnto(storage->getMement());
	zhangsan->show();
	return 0;
}

