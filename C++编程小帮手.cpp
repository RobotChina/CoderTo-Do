#include<bits/stdc++.h>
using namespace std;
int l=0,y,r;
bool fintd[32],tdrwtj[32];
string a[1001][6],tdtd[32][21];
void timeget()
{
	cout<<"������Ҫ��ȡ��ǰʱ�䡣"<<endl;
	cout<<"�����������¡��գ��м��ÿո�ָ���"<<endl;
	cin>>y>>r;
	if(y!=8 && y!=9)
	{
		cout<<"��������������󣬻�����û�л�ȡ�ó�������°汾�������ԡ���"<<endl;
		timeget();
	}
	system("cls");
	return ;
}
void about()
{
	system("cls");
	cout<<"����"<<endl;
	cout<<"=============="<<endl;
	cout<<"��1����������ʱ��"<<endl;
	cout<<"��0����ȫ�˳�����"<<endl;
	int abouttmp;
	cin>>abouttmp;
	if(abouttmp==1)	
	{
		timeget();
		return ;
	}
	else if(abouttmp==0)
	{
		cout<<"���ڹر��Ǹ�Σ��������Ҫ�����ı���"<<endl;
		cout<<"��ȷ����Ը�˳�������������δ���������ݡ�"<<endl;
		string aboutexittmp="";
		cin>>aboutexittmp;
		if(aboutexittmp=="��ȷ����Ը�˳�������������δ���������ݡ�")	exit(0);
		cout<<"������������������롣"<<endl;
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
		cout<<"��Դ   ���   ����   ״̬   ��վ   ID"<<endl;
		for(int i=1;i<=l;i++)
		{
			if(a[i][0]=="")	continue;
			cout<<a[i][1]<<"  "<<a[i][2]<<"  "<<a[i][3]<<"  "<<a[i][4]<<"  "<<a[i][5]<<"  "<<i<<endl;
		}
		cout<<"��1�޸ģ���2��ӣ���3��ɣ���4�˳�"<<endl;
		int tmp;
		cin>>tmp;
		if(tmp==1)
		{
			cout<<"�޸�"<<endl;
			cout<<"�������޸����"<<endl;
			int tmptmp;
			cin>>tmptmp;
			cout<<"�޸�״̬��"<<endl;
			cout<<"������"<<endl;
			cin>>a[tmptmp][4];
			continue;
		}
		else if(tmp==2)
		{
			cout<<"���"<<endl;
			if(l==1000)
			{
				cout<<"������Χ�����벻Ҫ����ӡ�"<<endl; 
				continue;
			}
			cout<<"��������Դ����ţ�������״̬����վ���м�ո�"<<endl;
			l++;
			cin>>a[l][1]>>a[l][2]>>a[l][3]>>a[l][4]>>a[l][5];
			a[l][0]="1";
			continue;
		}
		else if(tmp==3) 
		{
			cout<<"������ɾ�������"<<endl;
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
	cout<<"�ҵ�ÿ������"<<endl;
	cout<<"================"<<endl;
	if(tdrwtj[r]==0)
	{
		cout<<"�����ջ�û���������������ӡ�"<<endl;
		cout<<"�������м�������"<<endl;
		int tmptdhow;
		cin>>tmptdhow;
		if(tmptdhow>20)
		{
			cout<<"������������࣬����١�"<<endl;
			return ;
		}
		for(int i=1;i<=tmptdhow;i++)
		{
			cout<<"��"<<i<<"���������"<<endl;
			/* TODO (Users#3#): ֧�ֻ������� */
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
				cout<<"��ţ�"<<i<<endl<<tdtd[r][i]<<endl<<endl<<endl;
				isfin=0;
			}
		}
		if(isfin==1)
		{
			fintd[r]=1;
			cout<<"�����������Ѿ�ȫ�������������"<<endl;
			cout<<"ȥ�ۺ�To-Do�����ɡ�"<<endl;
			cout<<"�Ƿ�ǰ����"<<endl;
			int gototodo=0;
			cin>>gototodo;
			if(gototodo==0)	return ;
			else
			{
				todo(); 
				return ;
			}
		}
		cout<<"�Ƿ���ɣ�(0/���)"<<endl;
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
		cout<<"����ɽ�������������"<<endl;
		system("pause");
		return ;
	}
	todo();
}
void todomain()
{
	system("cls");
	cout<<"��1������ÿ������"<<endl;
	cout<<"��2�������ۺ���ϰ"<<endl;
	cout<<"��0���˳�To-Do����"<<endl;
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
	system("title �ǻ۱��С����2.0   �ǻ�������AI������������㼼��3.0��Ѹ��ϵͳ��Դ���Ȼ���");
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
		cout<<"�ǻ۱��С����"<<endl;
		cout<<"========================="<<endl; 
		cout<<"��1��     To-Do"<<endl;
		cout<<"��2��     C++�ٿ�"<<endl;
		cout<<"��3��     �������"<<endl;
		cout<<"��4��     ����"<<endl;
		cout<<"��5��     �������(�ͷſռ�5GB+)"<<endl;
		/* TODO (Coder#4#): C++�ٿ� */
		/* TODO (Coder#5#): ������� */
		/* TODO (Coder#2#): ��ϸ���� */
		cout<<"���๦�����ڿ�����"<<endl;
		int mtmp;
		cin>>mtmp;
		if(mtmp==1)
		{
			todomain();
		} 
		else if(mtmp==4)	about(); 
		else if(mtmp==5)
		{
		/* TODO (Codesearch#1#): ����ɾ�������� */
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
			cout<<"�ܱ�Ǹ����û����⣬������Ϸ�����"<<endl; 
			system("pause");
		}
	}
	return 0;
}

