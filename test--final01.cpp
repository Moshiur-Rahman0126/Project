#include<bits/stdc++.h>
#include<stdio.h>
#include<istream>
using namespace std;
#include<conio.h>
#include<fstream>
#include<graphics.h>
#define round(a) ((int)(a+0.5))
int k;
float xmin,ymin,xmax,ymax,arr[20],m;
void clipl(float x1,float y1,float x2,float y2)
{
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    else
        m=100000;
    if(x1 >= xmin && x2 >= xmin)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(x1 < xmin && x2 >= xmin)
    {
        arr[k]=xmin;
        arr[k+1]=y1+m*(xmin-x1);
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(x1 >= xmin  && x2 < xmin)
    {
        arr[k]=xmin;
        arr[k+1]=y1+m*(xmin-x1);
        k+=2;
    }
}

void clipt(float x1,float y1,float x2,float y2)
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=100000;
    if(y1 <= ymax && y2 <= ymax)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(y1 > ymax && y2 <= ymax)
    {
        arr[k]=x1+m*(ymax-y1);
        arr[k+1]=ymax;
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(y1 <= ymax  && y2 > ymax)
    {
        arr[k]=x1+m*(ymax-y1);
        arr[k+1]=ymax;
        k+=2;
    }
}

void clipr(float x1,float y1,float x2,float y2)
{
    if(x2-x1)
        m=(y2-y1)/(x2-x1);
    else
        m=100000;
    if(x1 <= xmax && x2 <= xmax)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(x1 > xmax && x2 <= xmax)
    {
        arr[k]=xmax;
        arr[k+1]=y1+m*(xmax-x1);
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(x1 <= xmax  && x2 > xmax)
    {
        arr[k]=xmax;
        arr[k+1]=y1+m*(xmax-x1);
        k+=2;
    }
}

void clipb(float x1,float y1,float x2,float y2)
{
    if(y2-y1)
        m=(x2-x1)/(y2-y1);
    else
        m=100000;
    if(y1 >= ymin && y2 >= ymin)
    {
        arr[k]=x2;
        arr[k+1]=y2;
        k+=2;
    }
    if(y1 < ymin && y2 >= ymin)
    {
        arr[k]=x1+m*(ymin-y1);
        arr[k+1]=ymin;
        arr[k+2]=x2;
        arr[k+3]=y2;
        k+=4;
    }
    if(y1 >= ymin  && y2 < ymin)
    {
        arr[k]=x1+m*(ymin-y1);
        arr[k+1]=ymin;
        k+=2;
    }
}


int main()
{
int gdriver=DETECT,gmode,n,poly[20],i;
float xi,yi,xf,yf,polyy[20];
system("cls");

    char se[10];
    ifstream x;
    x.open("results.txt");
    x>>xmin>>xmax>>ymin>>ymax;
    for(i=0;i<4;i++)
    {
        x>>se[i];
    }

    x>>n;
    for(int i=0;i<2*n;i++)
	x>>polyy[i];

         cout<<"Xmin-->> "<<xmin<<" \nXmax-->> "<<xmax<<" \nYmin-->> "<<ymin<<" \nYmax-->> "<<ymax<<endl;
      cout<<"\nSequence-->> " ;
         for(i=0;i<4;i++)
    {
        cout<<se[i]<<" ";
    }
     cout<<endl;
    cout<<"No. of Polygon--->> "<<n<<endl;
 int p=1;
     for(i=0;i<2*n;i++)
    {
        if(i%2==0) {cout<<"P"<<p<<" : ("<<polyy[i];p++;}

        else cout<<", "<<polyy[i]<<") "<<endl;
    }

    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];
    for(i=0;i < 2*n+2;i++)
	poly[i]=round(polyy[i]);
    initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
    setcolor(WHITE);

/*int g1=getmaxx();
int g2=getmaxy();*/

  if(xmin<0 || xmax<0 || ymin<0 || ymax<0)
{


     rectangle(xmin+200,ymax+200,ymax+200,ymin+200);
    cout<<"\t\tUNCLIPPED POLYGON";
int z=0,f=0;
while(poly[z])
    {
        if(poly[z]<0)
        {
            for(int b=0;b < 2*n+2;b++)
            {
                poly[b]=poly[b]+200;
            }
            setfillstyle(SOLID_FILL,RED);
    fillpoly(n,poly); f=1;
            break;
        }

    }
    if(f==0){
    //drawpoly(n,poly);
    setfillstyle(SOLID_FILL,RED);
    fillpoly(n,poly);
    }
}

else
{

    setcolor(WHITE);
     rectangle(xmin,ymax,ymax,ymin);
    cout<<"\t\tUNCLIPPED POLYGON";
    //drawpoly(n,poly);
    setfillstyle(SOLID_FILL,RED);
    fillpoly(n,poly);
}

	getch();
    cleardevice();

int z;
k=0;
for(z=0;z<4;z++)
{
    if(se[z]=='L')
    {cout<<"\nLeft-->> ";
      k=0;
    for(i=0;i < 2*n;i+=2)
		clipl(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
    for(i=0;i < k;i++)
		polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];

    }

     else if(se[z]=='T')
    {
     cout<<"\nTop-->> ";
      k=0;
    for(i=0;i < 2*n;i+=2)
		clipt(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
    for(i=0;i < k;i++)
		polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];

    }

      else if(se[z]=='R')
    {
     cout<<"\nRight-->> ";
     k=0;
    for(i=0;i < 2*n;i+=2)
		clipr(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
    for(i=0;i < k;i++)
		polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];

    }

  else if(se[z]=='B')
    {
      cout<<"\nBottom-->> ";
      k=0;
    for(i=0;i < 2*n;i+=2)
		clipb(polyy[i],polyy[i+1],polyy[i+2],polyy[i+3]);
    n=k/2;
    for(i=0;i < k;i++)
		polyy[i]=arr[i];
    polyy[i]=polyy[0];
    polyy[i+1]=polyy[1];

    }

for(i=0;i < k;i++)
		poly[i]=round(arr[i]);

for(i=0;i<k;i++)
    {
        if(i%2==0)cout<<"( "<<poly[i]<<" , ";
        else cout<<poly[i]<<"), ";
    }

int f=0;
for(i=0;i < k;i++)
{
    if(poly[i]<0){f=1;}
}


if(xmin<0 || xmax<0 || ymin<0 || ymax<0)
{

    if(f==1)
    {
        for(int b=0;b < k;b++)
            {
                poly[b]=poly[b]+200;
            }
            if(k){
            setfillstyle(SOLID_FILL,RED);
            fillpoly(k/2,poly);}
    }
    else{
            if(k){
        setfillstyle(SOLID_FILL,RED);
    fillpoly(k/2,poly);}
    }
setcolor(WHITE);
    rectangle(xmin+200,ymax+200,xmax+200,ymin+200);
}

else
{

     if(f==1)
    {
        for(int b=0;b < k;b++)
            {
                poly[b]=poly[b]+200;
            }
            if(k){
            setfillstyle(SOLID_FILL,RED);
            fillpoly(k/2,poly);}
    }
    else{
            if(k){
        setfillstyle(SOLID_FILL,RED);
    fillpoly(k/2,poly);}
    }
setcolor(WHITE);
     rectangle(xmin,ymax,xmax,ymin);
}

    /*if(k)
    {
        setfillstyle(SOLID_FILL,RED);
        fillpoly(k/2,poly);
    }

    setcolor(WHITE);
    rectangle(xmin,ymax,xmax,ymin);*/

getch();
cleardevice();

}



cout<<"\nClipped Polygon..";
closegraph();
}

