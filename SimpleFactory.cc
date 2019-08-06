#include<iostream>
#include<string>

using namespace std;

//定义车的接口
class Car
{
	public:
		virtual void Run() = 0;
};

//具体的宝马类（实现）
class BMW : public Car
{
	public:
		virtual void Run()
		{
			cout << "i am BMW" << endl;
		}
};

//具体的奥迪类
class OOOO : public Car
{
	public:
		virtual void Run()
		{
			cout << "i am OOOO" << endl;
		}
};

class Factory
{
	public:
		//根据客户端不同需求生产宝马或者奥迪
		//客户端传参，工厂类利用参数判断生产哪个产品
		static Car* ProductCar(string mess)
		{
				if(mess == "BMW")
					return new BMW;
				else if(mess == "OOOO")
					return new OOOO;
		}
};


int main()
{
	Factory::ProductCar("OOOO")->Run();
}
