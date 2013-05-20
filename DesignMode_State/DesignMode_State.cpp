#include <iostream>
using namespace std;

/*
状态模式 实例
核心：当一个类根据不同状态有不同的行为时，并且状态比较多，使得在类里的判断过于复杂时，可以考虑将本类拆分。            

  作者：离开的思绪
  时间：2012-11-30
*/
class Work;
/************************************************************************/
class State
{
public:
	virtual void Action(Work *pw)=0;//action放在状态里面做
};


class Work
{
	
	
public:
	State *m_pS;//维护一个状态的对象
	int nFlag;//一个状态位标志，需要通过指针访问
	Work():nFlag(0),m_pS(NULL)
	{
		//m_pS = NULL;
		//nFlag = 0;
	}
	void SetState(State *p)//设置当前状态
	{
		m_pS = p;
	}
	void WorkAction()//根据状态采取行动
	{
		m_pS->Action(this);
	}
};

class StateA:public State
{
public:
	virtual void Action(Work *pw)
	{
		cout<<"The A Action!"<<endl;
	}
};

class StateC:public State
{
public:
	StateC()
	{
		cout<<"StateC construct"<<endl;
	}
	~StateC()
	{
		cout<<"StateC desstruct"<<endl;
	}
	virtual void Action(Work *pw)
	{

		cout<<"The C Action!"<<endl;
	}
};
class StateB:public State
{
public:
	virtual void Action(Work *pw)
	{
		
		if ((pw->nFlag == 3)&&(pw->m_pS!=NULL))
		{
			pw->SetState(new StateC);
			pw->WorkAction();
		}
		else if(pw->nFlag < 5)
		{
			cout<<"The B Action!"<<endl;
		}
	}
};


/************************************************************************/
int main()
{
	Work w;
	State *s = new StateB;
	w.SetState(s);
	w.WorkAction();

	w.nFlag = 9;				// 动作类只需要修改自己内部的标志值，就能达到不同状态的目的
	w.WorkAction();
	w.nFlag = 4;
	w.WorkAction();
	delete s;
	s = NULL;
	return 0;
};