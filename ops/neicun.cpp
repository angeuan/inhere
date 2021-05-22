/*可变分区存储管理方案中的内存分配

本程序包括:FIFO,最优适应分配算法,最坏适应算法


input file:freememory.txt

data:

10 15

30 5

50 20

80 12

120 25

160 18

200 8

 

VC++调试通过

 

*/

#include <stdio.h>

#include <string.h>

#include <iostream>

#include <iomanip>
using namespace std;
const int MAXJOB = 100; //定义表最大记录数

typedef struct node

{

    int start;

    int length;

    char tag[20];

} job;

job frees[MAXJOB]; //定义空闲区表

int free_quantiry; //空闲区域的个数

job occupys[MAXJOB]; //定义已分配区表

int occupy_quanity;

//初始化函数

void initial()

{

    int i;

    for (i = 0; i < MAXJOB; i++)

    {

        frees[i].start = -1;

        frees[i].length = 0;

        strcpy(frees[i].tag, "free");

        occupys[i].start = -1;

        occupys[i].length = 0;

        strcpy(occupys[i].tag, "");
    }

    free_quantiry = 0;

    occupy_quanity = 0;
}

//读数据函数

int readData()

{

    FILE *fp;

    char fname[20];

    cout << "请输入初始空闲表文件名:" << endl;

    cin >> fname;

    if ((fp = fopen(fname, "r")) == NULL)

    {

        cout << "错误，文件打不 开，请检查文件名" << endl;
    }

    else

    {

        while (!feof(fp))

        {

            fscanf(fp, "%d %d", &frees[free_quantiry].start, &frees[free_quantiry].length);

            free_quantiry++;
        }

        return 1;
    }

    return 0;
}

//sort

void sort() //按空闲区起始地址排序

{

    int i, j, p;

    for (i = 0; i < free_quantiry; i++)

    {

        p = i;

        for (j = i + 1; j < free_quantiry; j++)

        {

            if (frees[j].start < frees[p].start)

            {

                p = j;
            }
        }

        if (p != i)
        {
            frees[free_quantiry] = frees[i];
            frees[i] = frees[p];
            frees[p] = frees[free_quantiry];
        }
    }
}

//显示函数

void view()

{

    int i;

    cout << endl
         << "----------------------------------------------------------" << endl;

    cout << "当前空闲表:" << endl;

    cout << "起始地址 长度 状态" << endl;

    for (i = 0; i < free_quantiry; i++)

    {

        cout.setf(ios::hex);

        cout.width(12);

        cout << frees[i].start;

        cout.width(10);

        cout << frees[i].length;

        cout.width(8);

        cout << frees[i].tag << endl;
    }

    cout << endl
         << "-----------------------------------------------" << endl;

    cout << "当前已分配表:" << endl;

    cout << "起始地址 长度 占用作业名" << endl;

    for (i = 0; i < occupy_quanity; i++)

    {

        cout.setf(ios::hex);

        cout.width(12);

        cout << occupys[i].start;

        cout.width(10);

        cout << occupys[i].length;

        cout.width(8);

        cout << occupys[i].tag << endl;
    }
}

//最先适应分配算法

void first_fit()

{

    char job_name[20];

    int job_length;

    int i, j, flag, t;

    cout << "请输入新申请内存空间的作业名和空间大小:" << endl;

    cin >> job_name;

    cin >> job_length;

    flag = 0;

    for (i = 0; i < free_quantiry; i++)

    {

        if (frees[i].length >= job_length)

        {

            flag = 1;
        }
    }

    if (flag == 0)

    {

        cout << endl
             << "Sorry,当前没有能满足你申请长度的空闲内存,请稍侯再试.." << endl;
    }

    else

    {

        t = 0;

        i = 0;

        while (t == 0)

        {

            if (frees[i].length >= job_length)

            {

                t = 1;
            }

            i++;
        }

        i--;

        occupys[occupy_quanity].start = frees[i].start;

        strcpy(occupys[occupy_quanity].tag, job_name);

        occupys[occupy_quanity].length = job_length;

        occupy_quanity++;

        if (frees[i].length > job_length)

        {

            frees[i].start += job_length;

            frees[i].length -= job_length;
        }

        else

        {

            for (j = i; j < free_quantiry - 1; j++)

            {

                frees[j] = frees[j + 1];
            }

            free_quantiry--;

            cout << "内存分配成功" << endl;
        }
    }
}

//最优适应分配算法

void best_fit()

{

    char job_name[20];

    int job_length;

    int i, j, flag, t;

    cout << "请输入新申请内存空间的作业名和空间大小:" << endl;

    cin >> job_name;

    cin >> job_length;

    flag = 0;

    for (i = 0; i < free_quantiry; i++)

    {

        if (frees[i].length >= job_length)

        {

            flag = 1;
        }
    }

    if (flag == 0)

    {

        cout << "Sorry,当前没有能满足你申请长度的空闲内存,请稍候再试" << endl;
    }

    else

    {

        t = 0;

        i = 0;

        while (t == 0)

        {

            if (frees[i].length >= job_length)

            {

                t = 1;
            }

            i++;
        }

        i--;

        for (j = 0; j < free_quantiry; j++)

        {

            if ((frees[j].length >= job_length) && frees[j].length < frees[i].length)

            {

                i = j;
            }
        }

        occupys[occupy_quanity].start = frees[i].start;

        strcpy(occupys[occupy_quanity].tag, job_name);

        occupys[occupy_quanity].length = job_length;

        occupy_quanity++;

        if (frees[i].length > job_length)

        {

            frees[i].start += job_length;

            frees[i].length -= job_length;
        }

        else

        {

            for (j = i; j < free_quantiry - 1; j++)

            {

                frees[j] = frees[j + 1];
            }

            free_quantiry--;

            cout << "内存分配成功" << endl;
        }
    }
}

//最坏适应算法

void worst_fit()

{

    char job_name[20];

    int job_length;

    int i, j, flag, t;

    cout << "请输入新申请内存空间的作业名和空间大小:" << endl;

    cin >> job_name;

    cin >> job_length;

    flag = 0;

    for (i = 0; i < free_quantiry; i++)

    {

        if (frees[i].length >= job_length)

        {

            flag = 1;
        }
    }

    if (flag == 0)

    {

        cout << endl
             << "Sorry,当前没有能满足你申请长度的空闲内存,请稍候再试" << endl;
    }

    else

    {

        t = 0;

        i = 0;

        while (t == 0)

        {

            if (frees[i].length >= job_length)

            {

                t = 1;
            }

            i++;
        }

        i--;

        for (j = 0; j < free_quantiry; j++)

        {

            if ((frees[j].length >= job_length) &&

                (frees[j].length > frees[i].length))

            {

                i = j;
            }
        }

        occupys[occupy_quanity].start = frees[i].start;

        strcpy(occupys[occupy_quanity].tag, job_name);

        occupys[occupy_quanity].length = job_length;

        occupy_quanity++;

        if (frees[i].length > job_length)

        {

            frees[i].start += job_length;

            frees[i].length -= job_length;
        }

        else

        {

            for (j = i; j < free_quantiry - 1; j++)

            {

                frees[j] = frees[j + 1];
            }

            free_quantiry--;

            cout << "内存分配成功" << endl;
        }
    }
}

//撤销作业

void finished()

{

    char job_name[20];

    int i, j, flag, p = 0;

    int start;

    int length;

    cout << "请输入要撤销的作业名:" << endl;

    cin >> job_name;

    flag = -1;

    for (i = 0; i < occupy_quanity; i++)

    {

        if (!strcmp(occupys[i].tag, job_name))

        {

            flag = i;

            start = occupys[i].start;

            length = occupys[i].length;
        }
    }

    if (flag == -1)

    {

        cout << "没有这个作业" << endl;
    }

    else

    {

        for (i = 0; i < free_quantiry; i++)

        {

            if ((frees[i].start + frees[i].length) == start)

            {

                if (((i + 1) < free_quantiry) && (frees[i + 1].start == start + length))

                {

                    frees[i].length = frees[i].length + frees[i + 1].length;

                    for (j = i + 1; j < free_quantiry; j++)

                    {

                        frees[j] = frees[j + 1];
                    }

                    free_quantiry--;

                    p = 1;
                }

                else

                {

                    frees[i].length += length;

                    p = 1;
                }
            }

            if (frees[i].start == (start + length))

            {

                frees[i].start = start;

                frees[i].length += length;

                p = 1;
            }
        }

        if (p == 0)

        {

            frees[free_quantiry].start = start;

            frees[free_quantiry].length = length;

            free_quantiry++;
        }

        for (i = flag; i < occupy_quanity; i++)

        {

            occupys[i] = occupys[i + 1];
        }

        occupy_quanity--;
    }
}

//显示版权信息函数

void version()

{

    cout << endl
         << endl;

    cout << " ┏━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;

    cout << " ┃　　   可变分区存储管理方案中的内存分配       ┃" << endl;

    cout << " ┠───────────────────────┨" << endl;

    cout << " ┃　　　　　　    sicauos    　 　　　　　    　┃" << endl;

    cout << " ┃　　　　　version 2020 build 0520　　　 　　　┃" << endl;

    cout << " ┗━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;

    cout << endl
         << endl;
}
int main()

{

    int flag = 0;

    int t = 1;

    int chioce = 0;

    version();

    initial();

    flag = readData();

    view();

    while (flag == 1)
    {

        sort();

        cout << endl
             << endl
             << "=========================================================" << endl;

        cout << " 可变分区存储管理模拟系统" << endl;

        cout << "=========================================================" << endl;

        cout << " 1.first fit申请空间 2.best fit申请空间 3.worst fit申请空间 4.撤消作业  0.退出" << endl;

        cout << "请选择:";

        cin >> chioce;

        switch (chioce)
        {

        case 1:

            first_fit();

            view();

            break;

        case 2:

            best_fit();

            view();

            break;

        case 3:

            worst_fit();

            view();

            break;

        case 4:

            finished();

            view();

            break;

        case 0:

            flag = 0;

            break;

        default:

            cout << "选择错误!" << endl;
        }
    }
}
