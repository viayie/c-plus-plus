#include <iostream>

using namespace std;

/************抽象层*************/
//抽象CPU类
class CPU
{
public:
	virtual void caculate() = 0;
};

//抽象显卡类
class CARD
{
public:
	virtual void dis() = 0;
};

//抽象的内存类
class Memory
{
public:
	virtual void storage() = 0;
};

//架构类
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


/************实现层*************/
//具体Intel CPU
class InterCPU : public CPU
{
public:
	virtual void caculate()
	{
		cout << "InterCPU caculating..." << endl;
	}
};
//具体Intel CARD
class InterCard : public CARD
{
public:
	virtual void dis()
	{
		cout << "InterCard displaying..." << endl;
	}
};
//具体Intel Memory
class InterMemory : public Memory
{
public:
	virtual void storage()
	{
		cout << "InterMemory storaging..." << endl;
	}
};
//具体Nvidia CARD
class NvidiaCard : public CARD
{
public:
	virtual void dis()
	{
		cout << "NvidiaCard displaying..." << endl;
	}
};
//具体Kingston Memory
class KingstonMem : public Memory
{
public:
	virtual void storage()
	{
		cout << "KingstonMem storaging..." << endl;
	}
};
/******************************/

/************业务层*************/
int main()
{
	//组装第一台电脑
	CPU* intelCpu = new InterCPU;
	CARD* intelCard = new InterCard;
	Memory* intelMem = new InterMemory;

	Computer* com1 = new Computer(intelCpu, intelCard, intelMem);
	com1->work();
	delete com1;

	//组装第二台电脑。。。。。
	
	return 0;
}

/******************************/