#include <iostream>

using namespace std;

/************�����*************/
//����CPU��
class CPU
{
public:
	virtual void caculate() = 0;
};

//�����Կ���
class CARD
{
public:
	virtual void dis() = 0;
};

//������ڴ���
class Memory
{
public:
	virtual void storage() = 0;
};

//�ܹ���
class Computer
{
public:
	Computer(CPU* cpu, CARD* card, Memory* mem)
	{
		this->cpu = cpu;
		this->card = card;
		this->mem = mem;
	}
	void work()
	{
		this->card->dis();
		this->cpu->caculate();
		this->mem->storage();
	}
	~Computer()
	{
		if (this->card != NULL)
			delete this->card;
		if (this->cpu != NULL)
			delete this->cpu;
		if (this->mem != NULL)
			delete this->mem;
	}
private:
	CPU* cpu;
	CARD* card;
	Memory* mem;
};
/******************************/


/************ʵ�ֲ�*************/
//����Intel CPU
class InterCPU : public CPU
{
public:
	virtual void caculate()
	{
		cout << "InterCPU caculating..." << endl;
	}
};
//����Intel CARD
class InterCard : public CARD
{
public:
	virtual void dis()
	{
		cout << "InterCard displaying..." << endl;
	}
};
//����Intel Memory
class InterMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "InterMemory storaging..." << endl;
	}
};
//����Nvidia CARD
class NvidiaCard : public CARD
{
public:
	virtual void dis()
	{
		cout << "NvidiaCard displaying..." << endl;
	}
};
//����Kingston Memory
class KingstonMem : public Memory
{
public:
	virtual void storage()
	{
		cout << "KingstonMem storaging..." << endl;
	}
};
/******************************/

/************ҵ���*************/
int main()
{
	//��װ��һ̨����
	CPU* intelCpu = new InterCPU;
	CARD* intelCard = new InterCard;
	Memory* intelMem = new InterMemory;

	Computer* com1 = new Computer(intelCpu, intelCard, intelMem);
	com1->work();
	delete com1;

	//��װ�ڶ�̨���ԡ���������
	
	return 0;
}

/******************************/