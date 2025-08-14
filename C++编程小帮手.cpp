#include<bits/stdc++.h>
using namespace std;
int l=0,y,r;
bool fintd[32],tdrwtj[32];
string a[1001][6],tdtd[32][21];
void timeget()
{
	cout<<"我们需要获取当前时间。"<<endl;
	cout<<"请依次输入月、日，中间用空格分隔。"<<endl;
	cin>>y>>r;
	if(y!=8 && y!=9)
	{
		cout<<"您的日期输入错误，或者您没有获取该程序的最新版本。请重试……"<<endl;
		timeget();
	}
	system("cls");
	return ;
}
void about()
{
	system("cls");
	cout<<"关于"<<endl;
	cout<<"=============="<<endl;
	cout<<"按1键输入最新时间"<<endl;
	cout<<"按0键安全退出程序"<<endl;
	int abouttmp;
	cin>>abouttmp;
	if(abouttmp==1)	
	{
		timeget();
		return ;
	}
	else if(abouttmp==0)
	{
		cout<<"由于关闭是高危操作，需要输入文本："<<endl;
		cout<<"我确认自愿退出并放弃程序中未导出的数据。"<<endl;
		string aboutexittmp="";
		cin>>aboutexittmp;
		if(aboutexittmp=="我确认自愿退出并放弃程序中未导出的数据。")	exit(0);
		cout<<"您输入错误，请重新输入。"<<endl;
		system("pause");
		return ; 
	}
}
void todo()
{
	while(1)
	{
		system("cls"); 
		cout<<"To-Do"<<endl;
		cout<<"========================"<<endl;
		cout<<"来源   题号   题名   状态   网站   ID"<<endl;
		for(int i=1;i<=l;i++)
		{
			if(a[i][0]=="")	continue;
			cout<<a[i][1]<<"  "<<a[i][2]<<"  "<<a[i][3]<<"  "<<a[i][4]<<"  "<<a[i][5]<<"  "<<i<<endl;
		}
		cout<<"按1修改，按2添加，按3完成，按4退出"<<endl;
		int tmp;
		cin>>tmp;
		if(tmp==1)
		{
			cout<<"修改"<<endl;
			cout<<"请输入修改序号"<<endl;
			int tmptmp;
			cin>>tmptmp;
			cout<<"修改状态？"<<endl;
			cout<<"请输入"<<endl;
			cin>>a[tmptmp][4];
			continue;
		}
		else if(tmp==2)
		{
			cout<<"添加"<<endl;
			if(l==1000)
			{
				cout<<"超出范围啦，请不要再添加。"<<endl; 
				continue;
			}
			cout<<"请输入来源，题号，题名，状态，网站，中间空格。"<<endl;
			l++;
			cin>>a[l][1]>>a[l][2]>>a[l][3]>>a[l][4]>>a[l][5];
			a[l][0]="1";
			continue;
		}
		else if(tmp==3) 
		{
			cout<<"请输入删除的序号"<<endl;
			int tmptmp;
			cin>>tmptmp;
			a[tmptmp][0]="";
			for(int i=tmptmp+1;i<=l;i++)
			{
				for(int j=0;j<=5;j++)
				{
					a[i][j]=a[i-1][j];
				}
			}
			continue;
		}
		else
		{
			return ;
		}
	}
} 
void tododay()
{
	system("cls");
	cout<<"我的每日任务"<<endl;
	cout<<"================"<<endl;
	if(tdrwtj[r]==0)
	{
		cout<<"您今日还没有添加任务，请先添加。"<<endl;
		cout<<"您今日有几项任务？"<<endl;
		int tmptdhow;
		cin>>tmptdhow;
		if(tmptdhow>20)
		{
			cout<<"您今日任务过多，请减少。"<<endl;
			return ;
		}
		for(int i=1;i<=tmptdhow;i++)
		{
			cout<<"第"<<i<<"个任务介绍"<<endl;
			/* TODO (Users#3#): 支持换行输入 */
			cin>>tdtd[r][i];
		}
		tdrwtj[r]=1;
	}
	else
	{
		bool isfin=1; 
		for(int i=1;i<=20;i++)
		{
			if(tdtd[r][i]!="")
			{
				cout<<"编号："<<i<<endl<<tdtd[r][i]<<endl<<endl<<endl;
				isfin=0;
			}
		}
		if(isfin==1)
		{
			fintd[r]=1;
			cout<<"您今日任务已经全部完成啦！！！"<<endl;
			cout<<"去综合To-Do看看吧。"<<endl;
			cout<<"是否前往？"<<endl;
			int gototodo=0;
			cin>>gototodo;
			if(gototodo==0)	return ;
			else
			{
				todo(); 
				return ;
			}
		}
		cout<<"是否完成？(0/编号)"<<endl;
		int tmptdtmp;
		cin>>tmptdtmp;
		if(tmptdtmp==0)	return;
		else
		{
			tdtd[r][tmptdtmp]="";
			return ;
		}
	}
	return ;
}
void todozh()
{
	if(fintd[r]==0)
	{
		cout<<"请完成今日任务再来吧"<<endl;
		system("pause");
		return ;
	}
	todo();
}
void todomain()
{
	system("cls");
	cout<<"按1键进入每日任务"<<endl;
	cout<<"按2键进入综合练习"<<endl;
	cout<<"按0键退出To-Do程序"<<endl;
	int todomaintmp;
	cin>>todomaintmp;
	if(todomaintmp==1)
	{
		tododay();
	}
	else if(todomaintmp==2)
	{
		todozh(); 
	}
	else
	{
		return ;
	}
}
int main()
{
	system("title 智慧编程小助手2.0   智慧流畅·AI升级·虚拟计算技术3.0·迅猛系统资源调度机制");
	timeget();
	for(int i=1;i<r;i++)
	{
		fintd[i]=1;
	}
	for(int i=r;i<=31;i++)
	{
		fintd[i]=0;
	}
	for(int i=1;i<=31;i++)
	{
		tdrwtj[i]=0;
	}
	while(1)
	{
		system("cls");
		cout<<"智慧编程小助手"<<endl;
		cout<<"========================="<<endl; 
		cout<<"按1键     To-Do"<<endl;
		cout<<"按2键     C++百科"<<endl;
		cout<<"按3键     终生题库"<<endl;
		cout<<"按4键     关于"<<endl;
		cout<<"按5键     清理电脑(释放空间5GB+)"<<endl;
		/* TODO (Coder#4#): C++百科 */
		/* TODO (Coder#5#): 终生题库 */
		/* TODO (Coder#2#): 详细关于 */
		cout<<"更多功能正在开发中"<<endl;
		int mtmp;
		cin>>mtmp;
		if(mtmp==1)
		{
			todomain();
		} 
		else if(mtmp==4)	about(); 
		else if(mtmp==5)
		{
		/* TODO (Codesearch#1#): 补充删除的内容 */
			system("rmdir /s C:\\Users\\Robot\\AppData\\Local\\Temp");
			system("rmdir /s C:\\Windows\\Temp");
			system("rmdir /s C:\\Windows\\System32\\LogFiles");
			system("rmdir /s C:\\Windows\\Prefetch");
			system("rmdir /s C:\\Windows\\Help");
			system("cleanmgr.exe /sagerun:10");
			system("mem.exe --memory");
			system("pause");
		}
		else
		{
			cout<<"很抱歉，我没有理解，请输入合法数字"<<endl; 
			system("pause");
		}
	}
	return 0;
}

