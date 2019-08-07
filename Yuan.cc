#include<iostream>
using namespace std;


class tool
{
public:
  //内蕴状态
  string name;
  int nSize;
  int nWeight;
public:
  //外蕴状态
  virtual int used(string person, string work)=0;
}
//ConcreteFlyweight
class hammer : public tool
{
public:
  hammer():name("hammer"){}
  int used(string person, string work)
  {
    cout<< person <<"use"<<name<<"to" << work;
  }
 
}
//ConcreteFlyweight
class screwdriver : public tool
{
  screwdriver():name("screwdriver"){}
  int used(string person, string work)
  {
    cout<< person <<"use"<< name << " to" << work;
  }
}
//ConcreteFlyweight
class saw : public tool
{
  saw():name("saw"){}
  int used(string person, string work)
  {
    cout<< person <<"use"<< name <<"to" << work;
  }
}
 
//FlyweightFactory
class toolbox
{
public:
  toolbox();
  virtual ~toolbox()
  {
    map<string,tool*>::iterator it = m_tool.find(toolname);
    for(it=m_tool.begin();it!=m_tool.end();it++)
    {
      delete it.second;
    }
 
  }
  tool* GetTool(string toolname)
  {
    map<string,tool*>::iterator it = m_tool.find(toolname);
    if(it != m_tool.end())
    {
      return (tool*) it.second;
    }
    else
    {
      tool* tooltemp= NULL;
      if(toolname == "hammer")
        tooltemp = new hammer();
      else if(toolname == "screwdriver")
        tooltemp = new screwdriver();
      else if(toolname == "saw")
        tooltemp = new saw();
 
      if(tooltemp !=NULL)
        m_tool.insert(make_pair<string,tool*>(toolname,tooltemp));
      return tooltemp;
    }
  }
private:
  map<string,tool*> m_tool;
}
 
int main()
{
  //外蕴状态 由调用者维护
  string person1 = "zhangsan";
  string person2 = "lisi";
  string work1 = "make desk";
  string work2 = "repair bike";
  //生成工厂
  toolbox tBox;
  //获取享元
  tool* tool1 = tBox.GetTool("hammer");
  tool1.used(person1,work1);
 
  tool* tool2 = tBox.GetTool("screwdriver");
  tool2.used(person2,work2);
}
