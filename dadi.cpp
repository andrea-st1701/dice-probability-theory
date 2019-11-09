#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;
void tira(float v[], float n)
{
int a, b;
for (int i=0; i<n; i++)
	{
		a=rand()%6+1;
		b=rand()%6+1;
		v[a+b-1]++;			
	}
}
void color(float v[], float a, int i)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,  FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
	if(v[i]/a*100>2.75)
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
		}
	if(v[i]/a*100>5.53)
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
		}
	if(v[i]/a*100>8.31)
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
		}
	if(v[i]/a*100>11)
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_RED);
		}
	if(v[i]/a*100>13.86)
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		}
	if(v[i]/a*100>16.64)
		{
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
		}
		
}
void disegna(float f)
{
	
		for(int c=0; c<f; c++)
		{
			cout<<"#";
		}
		cout<<"\n";
		for(int c=0; c<f; c++)
		{
			cout<<"#";
		}
	
}
void dividi(float v[])
{
	int e=0;
	float a=0;
	bool flag=true;
	while(flag)
	{
		flag=false;
		for(int i=0; i<12; i++)
		{
			if(v[i]>80)
			{
				flag=true;
				break;
			}
		}
		if (flag)
		{
			for(int i=0; i<12; i++)
			{
				v[i]=v[i]/10;
			}
			e++;
		}
	}
	for(int i=0; i<12; i++)
	{
		a+=v[i];
	}
	for(int i=0; i<12; i++)
	{
		color(v, a, i);
		disegna(v[i]);
		cout<<"\n"<<i+1<<" comparso: "<<v[i]<<"* 10^"<<e<<" volte\n";
	}
}
void legenda( float v[])
{
	float a=0, b;
	for(int i=0; i<12; i++)
	{
		float z=i;
		v[i]=z/36+0.001;
	}
	cout<<"Legenda:\n";
	for(int i=0; i<12; i++)
	{
		a+=v[i];
	}
	for(float i=1; i<7; i++)
	{
		cout<<endl;
		color(v, 1, i);
		disegna(3);
		cout<<" per percentuali maggiori di "<<i/36*100<<"%\n";
		
	}
	color(v, 1, 0);
	cout<<"\n\nE' stata considerata un' incertezza dello 0.02%\n\n";
}

int main()
{
	float n, v[12];
	color(v, 1, 0);

	for(int i=0; i<12; i++)
	{
		v[i]=0;
	}

	cout<<"quanti tiri vuoi fare? Tira pure quanto vuoi!"<<endl;
	cin>>n;
	srand(time(NULL));
	tira(v, n);
	dividi(v);
	color(v, 1, 0);
	cout<<"\n\n";
	for(int c=0; c<160; c++)
	{
		cout<<"/";
	}
	cout<<"\n";
	legenda(v);
	system("PAUSE");


}










