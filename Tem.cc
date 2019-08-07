#include<iostream>
using namespace std;

class DrinkTemplate{
	public:	
		//煮水
		virtual void BoildWater() = 0;
		//冲水
		virtual void Brew() = 0;
		//倒入杯中
		virtual void PourInCup() = 0;
		//加辅料
		virtual void AddSomething() = 0;

		//模板方法
		void Make(){
			BoildWater();
			Brew();
			PourInCup();
			AddSomething();
		}
};


//冲咖啡
class Coffee : public DrinkTemplate{
public:	
		//煮水
		virtual void BoildWater(){
			cout << "农夫水"<< endl;
		}
		//冲水
		virtual void Brew(){
			cout << "冲咖啡"<<endl;
		}
		//倒入杯中
		virtual void PourInCup(){
			cout << "倒咖啡"<<endl;
		}
		//加辅料
		virtual void AddSomething(){
			cout <<"加牛奶"<<endl;
		}
};


//冲茶
class Tea : public DrinkTemplate{
public:	
		//煮水
		virtual void BoildWater(){
			cout << "水"<< endl;
		}
		//冲水
		virtual void Brew(){
			cout << "铁观音"<<endl;
		}
		//倒入杯中
		virtual void PourInCup(){
			cout << "倒茶"<<endl;
		}
		//加辅料
		virtual void AddSomething(){
			cout <<"加柠檬"<<endl;
		}
};

int main()
{
	Tea* tea = new Tea;
	tea->Make();

	Coffee* cof = new Coffee;
	cof->Make();
}
