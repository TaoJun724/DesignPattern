#include<list>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Hero{
	public:	
		virtual void Update() = 0;
};

class HeroA : public Hero{
 public:
		HeroA(){
			cout << "英雄A在打BOSS"<<endl;
		}
		virtual void Update()
		{
			cout << "A停止打BOSS,待机，，，"<<endl;
		}
};




class HeroB : public Hero{
 public:
		HeroB(){
			cout << "英雄B在打BOSS"<<endl;
		}
		virtual void Update()
		{
			cout << "B停止打BOSS,待机，，，"<<endl;
		}
};
class HeroC : public Hero{
 public:
		HeroC(){
			cout << "英雄C在打BOSS"<<endl;
		}
		virtual void Update()
		{
			cout << "C停止打BOSS,待机，，，"<<endl;
		}
};
class HeroD : public Hero{
 public:
		HeroD(){
			cout << "英雄D在打BOSS"<<endl;
		}
		virtual void Update()
		{
			cout << "D停止打BOSS,待机，，，"<<endl;
		}
};

//观察目标
class Boss{
	public:
		virtual void addHero(Hero* hero) = 0;
		virtual void delHero(Hero* hero) = 0;
		//通知观察者
		virtual void notify() = 0;
};

//具体的观察者 BOSSA
class BOSSA : public Boss{
public:
	virtual void addHero(Hero* hero){
		plist.push_back(hero);
	}
	void delHero(Hero* hero)
	{
		plist.remove(hero);
	}

	virtual void notify()
	{
		for(list<Hero*>::iterator it = plist.begin();it != plist.end();it++){
			(*it) -> Update();
		}
	}
public:
	list<Hero*> plist;
};

int main()
{
	//创建观察者
	Hero* A = new HeroA;
	Hero* B = new HeroB;
  //Hero* C = new HeroC;
  //Hero* D = new HeroD;
	//创建观察目标
	Boss* bossA = new BOSSA;
	bossA -> addHero(A);
	bossA -> addHero(B);

	cout << "heroB阵亡" << endl;
	bossA -> delHero(B);
	cout << "Boss死了...通知其他英雄停止攻击，抢装备.."<< endl;

	bossA ->notify();
}
