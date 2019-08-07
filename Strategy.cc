#include<iostream>
#include<vector>
#include<string>
using namespace std;

//武器策略
class Weapon{
public:
	virtual void UseWeapon() = 0;
};

class Knife : public Weapon{
	public:
		virtual void UseWeapon(){
			cout << "使用匕首"<< endl;
		}
};

class Character{
public:
	void SetWeapon(Weapon* weapon){
		this -> pw = weapon;
	}
	void ThrowWeapon(){
		this -> pw ->UseWeapon();
	}
	public:
		Weapon* pw;
};


int main()
{
	//创建角色
	Character* cha = new Character;
	//武器策略
	Weapon* knife = new Knife;
	

	cha -> SetWeapon(knife);
	cha -> ThrowWeapon();

	delete cha;
	delete knife;
}
