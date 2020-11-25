#include <iostream>
#include <iomanip>
using namespace std;
static const int Max = 100;
int ArrivalTime[Max];					// 到达时间
int ServiceTime[Max];					// 服务时间
int FinishTime[Max];					// 完成时间
int WholeTime[Max];						// 周转时间
double WeightWholeTime[Max];			// 帯权周庄时间
double AverageWT_FCFS, AverageWT_SJF;	// 平均周转时间
double AverageWWT_FCFS, AverageWWT_SJF; //平均帯权周转时间
int Num = 0;
int NowTime = 0;			  // 记录当前时间
double SumWT = 0, SumWWT = 0; //SumW用T来计算总的周转时间， SumWW用T来计算总的帯权周转时间
int i;
// 先到先服务算法
void FCFS() // 找最早到达的。
{
	cout << "--------------------------------------------------------------" << endl;
	cout << "-----------------------------FCFS-----------------------------" << endl;
	cout << "--------------------------------------------------------------" << endl;
	for (i = 0; i < Num; i++)
	{
		if (ArrivalTime[i] > NowTime) // 假如进程到达的时间比现在已经运行的时间NowTime大，说明在NowTime时刻进程未到达
			{
				NowTime = ArrivalTime[i]; // 把进程的到达时间赋给NowTime
			}
		NowTime += ServiceTime[i];									// 把进程的服务时间加到NowTime上
		FinishTime[i] = NowTime;									// 计算完成时间
		WholeTime[i] = FinishTime[i] - ArrivalTime[i];				// 计算周转时间=完成时间- 到达时间
		WeightWholeTime[i] = (double)WholeTime[i] / ServiceTime[i]; // 计算带权周转时间=周转时间
		SumWT += WholeTime[i]; // 计算总的周转时间
		SumWWT += WeightWholeTime[i];  // 计算总的帯权周转时间
	}
	AverageWT_FCFS = SumWT / Num; //均周转时间
	AverageWWT_FCFS = SumWWT / Num;					  // 帯权周转时间
		for (i = 0; i < Num; i++) // 依次输出结果
		{
			cout << " 时刻" << FinishTime[i] - ServiceTime[i] << ": 进程" << i + 1 << " 开始运行。"<< " 其完成时间： "<<FinishTime[i]<<" 周转时间： "<<WholeTime[i]<<setprecision(3)<<" 帯权周转时间："<<WeightWholeTime[i]<<setprecision(3)<<endl;
		} 
		cout<< " 平均周转时间： " << AverageWT_FCFS << endl;
		cout << " 平均帯权周转时间： " << AverageWWT_FCFS << endl;
}
// 输入函数
void input()
{
	cout << " 请输入进程个数： ";
	cin >> Num;
	while (Num > 100 || Num <= 0)
	{
		cout << " 进程个数必须大于0且小于等于100！请重新输入进程个数： ";
		cin >> Num;
	}
	cout << "-----------------------------------------" << endl;
	for (i = 0; i < Num; i++)
	{
		cout << " 请输入第" << i + 1 << " 个进程的到达时间： ";
		cin >> ArrivalTime[i];
	}
	cout << "-----------------------------------------" << endl;
	for (i = 0; i < Num; i++)
	{
		int data = 0;
		cout << " 请输入第" << i + 1 << " 个进程的服务时间： ";
		cin >> data;
		ServiceTime[i] = data;
	}
}
// 主函数
int main()
{
	cout << "*******************************************************************" << endl;
	char flag = 'y';
	NowTime = 0;
	SumWT = 0;
	SumWWT = 0; //数初始化
	input();	  // 输入
	FCFS();
}