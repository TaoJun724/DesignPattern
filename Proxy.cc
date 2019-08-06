#include<string>
#include<iostream>
using namespace std;


//代理模式：提供一种代理来控制对其他对象的访问
class AbstractCommonInterface{
public:
	virtual void Run() = 0;
};

class MySystem : public AbstractCommonInterface{
	public:
		virtual void Run()
		{
			cout << "系统启动"<< endl;
		}
};


//必须要有权限的验证，不是所有人都能来启动我的启动，提供用户名与密码
class MySystemProxy : public AbstractCommonInterface{
	public:
	 	MySystemProxy(string name,string password)
		{
			this -> _name = name;
			this -> _password = password;
			pSystem = new MySystem;
		}

		bool check()
		{
			if(_name == "admin" && _password == "admin")
				return true;
			else
				return false;
		}
		virtual void Run(){
				if(check()){
					cout << "验证通过" << endl;
					this -> pSystem -> Run();
				}
				else{
					cout <<"无法启动"<<endl;
				}
		}
		~MySystemProxy(){
			if(pSystem != NULL)
			{
				delete pSystem;
			}
		}
	public:
		MySystem* pSystem;
		string _name;
		string _password;
};


int main()
{
	MySystemProxy* system = new MySystemProxy("admin","admin");
	system -> Run();
	return 0;
}
