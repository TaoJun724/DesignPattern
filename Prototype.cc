#include <cstdio>
 
//接口
class CPrototype
{
public:
	CPrototype(){}
	virtual ~CPrototype(){}
 
	virtual CPrototype* Clone() = 0;
};
 
//实现
class CConcretePrototype : public CPrototype
{
public:
	CConcretePrototype():m_counter(0){}
	virtual ~CConcretePrototype(){}
 
	//拷贝构造函数
	CConcretePrototype(const CConcretePrototype& rhs)
	{
		m_counter = rhs.m_counter;
	}
 
	//复制自身
	virtual CPrototype* Clone()
	{
		//调用拷贝构造函数
		return new CConcretePrototype(*this);
	}
 
private:
	int m_counter;
};
 
int main(int argc, char **argv)
{
	//生成对像
	CPrototype* conProA = new CConcretePrototype();
	//复制自身
	CPrototype* conProB = conProA->Clone();
 
	delete conProA; conProA=NULL;
	delete conProB; conProB=NULL;
 
	return 0;
}

