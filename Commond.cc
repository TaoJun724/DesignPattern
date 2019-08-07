#include<unistd.h>
#include<queue>
#include<iostream>
#include<vector>
#include<string>
using namespace std;



//协议处理类
class HandleClientProtocol{
public:
	//处理增加金币
	void AddMoney(){
		cout << "增加给玩家的金币" << endl;
	}
	//处理增加等级
	void AddGrade(){
		cout <<"玩家升级"<<endl;
	}
	//处理增加钻石
	void AddDiamond(){
		cout << "玩家增加金币"<<endl;
	}
};


//命令接口
class Command{
	public:
		virtual void handle() = 0;//处理客户端请求的接口
};

class AddMoneyCom : public Command{
	public:
		AddMoneyCom(HandleClientProtocol* pro)
		{
			this -> _pro = pro;
		}
		virtual void handle(){
			this -> _pro -> AddMoney();
		}
	public:
		HandleClientProtocol* _pro;
};





class AddDiamondCom : public Command{
	public:
		AddDiamondCom(HandleClientProtocol* pro)
		{
			this -> _pro = pro;
		}
		virtual void handle(){
			this -> _pro -> AddDiamond();
		}
	public:
		HandleClientProtocol* _pro;
};

class AddGradeCom : public Command{
	public:
		AddGradeCom(HandleClientProtocol* pro)
		{
			this -> _pro = pro;
		}
		virtual void handle(){
			this -> _pro -> AddGrade();
		}
	public:
		HandleClientProtocol* _pro;
};



class Server{
	public:
		void addRequest(Command* com){
			_com.push(com);
		}

		void startHandle(){
			while(!_com.empty()){

				sleep(100);
				Command* com = _com.front();
				com -> handle();
				_com.pop();
			}
		}
	public:
		queue<Command*> _com;
};




int main()
{
	HandleClientProtocol* protocol = new HandleClientProtocol;
  //客户端增加钻石与金币的请求
	Command* addmoney = new AddMoneyCom(protocol);
	Command* adddiamond = new AddDiamondCom(protocol);
  //服务器添加请求
	Server* server = new Server;
	server->addRequest(addmoney);
	server->addRequest(adddiamond);

	//服务器执行
	server->startHandle();
	return 0;
}
