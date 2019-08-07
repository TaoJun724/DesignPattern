#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


//适配器 模式就是讲写好的接口转换为想要的目标接口

struct MyPrint{
	void operator()(int v1,int v2)
	{
		cout << v1+v2 << endl;
	}
};

//定义目标接口 我要是配偶 适配成什么样的
class Targe{
	public:
		virtual void operator()(int v) = 0;
};

//写适配器
class Adapter : public Targe{
	public:
	Adapter(int param)
	{
		this -> _param = param;
	}
		virtual void operator()(int v){
			print(v,_param);
		}
	public:
		MyPrint print;
		int _param;
};


Adapter MyBind(int v){
	return Adapter(v);	
}

int main()
{
	vector<int> v;
	for(int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
  for_each(v.begin(),v.end(),MyBind(10));
}

