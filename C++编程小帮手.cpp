#include<bits/stdc++.h>
using namespace std;
int l=0,y,r,bkl=1;
bool fintd[32],tdrwtj[32];
string a[1001][6],tdtd[32][21],ver="V0.1.1",bk[1010][3];
void timeget()
{
	cout<<"我们需要获取当前时间。"<<endl;
	cout<<"请依次输入月、日，中间用空格分隔。"<<endl;
	cin>>y>>r;
	if(y>=13)
	{
		cout<<"您的日期输入错误，请重试……"<<endl;
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
			cout<<"您今日任务已全部完成。"<<endl;
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
		system("cls");
		tododay(); 
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
void baike()
{
	system("cls");
	cout<<"百科"<<endl;
	cout<<"============="<<endl;
	cout<<"你要加入百科(1)还是查询百科(2)？"<<endl;
	int bktmp;
	cin>>bktmp;
	if(bktmp==1)
	{
		if(bkl>=1000)
		{
			cout<<"你的百科数量太多了，暂不能添加。"<<endl;
			system("pause");
			return ;
		}
		cout<<"添加百科向导"<<endl;
		cout<<"请输入百科名称"<<endl;
		cin>>bk[bkl][1];
		cout<<"请输入百科内容"<<endl;
		cin>>bk[bkl][2];
		cout<<"感谢添加！"<<endl;
		bkl++;
		system("pause");
		return ;
	}
	else
	{
		cout<<"请直接输入百科名称，将进行精确查找。"<<endl;
		string bkcintmp;
		cin>>bkcintmp;
		for(int i=1;i<=bkl;i++)
		{
			if(bk[i][1].find(bkcintmp)<=100000)
			{
				cout<<bk[i][2]<<endl;
				system("pause");
				return ;
			}
		}
		cout<<"没有找到……换个搜索词试试吧，或者尝试添加。"<<endl;
		system("pause");
	}
	return ;
}
int main()
{
	system("title 智慧编程小助手");
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
		cout<<"按2键     百科"<<endl;
		cout<<"按3键     终生题库"<<endl;
		cout<<"按4键     关于"<<endl;
		cout<<"按5键     清理电脑"<<endl;
		/* TODO (Coder#4#): C++百科 */
		/* TODO (Coder#5#): 终生题库 */
		/* TODO (Coder#2#): 详细关于 */
		cout<<"更多功能正在开发中"<<endl;
		int mtmp;
		cin>>mtmp;
		if(mtmp==1)	todomain();
		else if(mtmp==2)	baike();
		else if(mtmp==4)	about(); 
		else if(mtmp==5)
		{
			system("cleansystem.bat"); 
			bool memtemp;
			cout<<"是否清理内存？"<<endl;
			cin>>memtemp;
			if(memtemp==1)	system("mem.exe --memory");
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
