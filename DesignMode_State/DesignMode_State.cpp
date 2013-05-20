#include <iostream>
using namespace std;

/*
״̬ģʽ ʵ��
���ģ���һ������ݲ�ͬ״̬�в�ͬ����Ϊʱ������״̬�Ƚ϶࣬ʹ����������жϹ��ڸ���ʱ�����Կ��ǽ������֡�            

  ���ߣ��뿪��˼��
  ʱ�䣺2012-11-30
*/
class Work;
/************************************************************************/
class State
{
public:
	virtual void Action(Work *pw)=0;//action����״̬������
};


class Work
{
	
	
public:
	State *m_pS;//ά��һ��״̬�Ķ���
	int nFlag;//һ��״̬λ��־����Ҫͨ��ָ�����
	Work():nFlag(0),m_pS(NULL)
	{
		//m_pS = NULL;
		//nFlag = 0;
	}
	void SetState(State *p)//���õ�ǰ״̬
	{
		m_pS = p;
	}
	void WorkAction()//����״̬��ȡ�ж�
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

	w.nFlag = 9;				// ������ֻ��Ҫ�޸��Լ��ڲ��ı�־ֵ�����ܴﵽ��ͬ״̬��Ŀ��
	w.WorkAction();
	w.nFlag = 4;
	w.WorkAction();
	delete s;
	s = NULL;
	return 0;
};