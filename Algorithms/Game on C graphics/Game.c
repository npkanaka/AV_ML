#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
void intro();
void ball();
void loading();
void menu();
void game();
void garage();
int maxx=640,maxy=480;
int i,coins,vc=1,totplay,dcoins,bcoins;
long int bscore,score=0;
char name[10];
int main()
{
int gm,gd=DETECT;
char ch;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
intro();
return 1;
}
// Intro
void intro()
{
int ch;
char printname[50],playname[10];
setcolor(RED);
rectangle(1,1,639,479);
setbkcolor(BLUE);
setcolor(WHITE);
rectangle(160,120,480,240);
setfillstyle(10,WHITE);
floodfill(200,200,WHITE);
settextstyle(1,HORIZ_DIR,7);
setcolor(RED);
outtextxy(maxx*(1.5/4),(maxy*(1.5/4))-40,"CARZ");
setcolor(YELLOW);
settextstyle(0,0,1);
outtextxy(maxx*(1.5/4)+150,(maxy*(1.5/4))+40,"2D Racing");
setcolor(BROWN);
settextstyle(3,0,1);
outtextxy((maxx*((1.5/4))-200),(maxy*(1.5/4))+100,"Enter Player name :");
settextstyle(2,0,2);
outtextxy(585,460,"Nikhilpa1");
setcolor(WHITE);
rectangle((maxx*((1.5/4))),(maxy*(1.5/4))+105,(maxx*((1.5/4))+150),(maxy*(1.5/4))+124);
setcolor(WHITE);
gotoxy(32,19);
scanf("%s",name);
cleardevice();
setbkcolor(0);
setcolor(WHITE);
settextstyle(3,0,3);
sprintf(printname,"Welcome %s , Ready to race ?",name);
sprintf(playname,"%s",name);
outtextxy(120,200,printname);
settextstyle(3,0,2);
setcolor(BLUE);
outtextxy(230,450,"( Yes(Y) / No(else) )");
ch=getch();
if(ch=='y')
{
cleardevice();
setcolor(YELLOW);
outtextxy(150,220,"Kick-off   &   Start your journey...");
delay(3500);
cleardevice();
setcolor(BLUE);
outtextxy(10,40,"Hey  ");
outtextxy(50,40,playname);
outtextxy(10,65,"Here are some points worth remembering...");
setcolor(WHITE);
outtextxy(10,140,"| Use arrow keys to interact and to control the vehicle |");
setcolor(YELLOW);
outtextxy(10,180,"| Score counts after attaining the top speed |");
outtextxy(10,220,"| Collect coins to customize your vehicle in the Garage |");
outtextxy(10,260,"| Customize by selecting the color using return key |");
settextstyle(0,0,1);
setcolor(WHITE);
outtextxy(220,450,"[ Press any key to continue ]");
getch();
cleardevice();
loading();
cleardevice();
menu();
}
else
{
cleardevice();
intro();
}
}
// Second screen (MAIN MENU)
void menu()
{
int n=1,ch;
long int a,dscore;
setbkcolor(0);
setfillstyle(1,LIGHTBLUE);
fillellipse(320,240,370,290);
setcolor(MAGENTA);
settextstyle(8,0,2);
outtextxy(60,340,"Your-score");
outtextxy(440,340,"Personal-best");
outtextxy(280,265,"Coins");
setcolor(YELLOW);
/*U score*/rectangle(40,370,200,410);
/*P best*/rectangle(440,370,600,410);
/* coins */rectangle(230,294,390,334);
gotoxy(8,25);
fprintf(stdout,"%ld",score);
gotoxy(38,20);
fprintf(stdout,"%d",coins);
gotoxy(58,25);
fprintf(stdout,"%ld",bscore);
rectangle(230,101,380,130);
rectangle(230,141,380,170);
rectangle(230,181,380,210);
settextstyle(2,0,6);
setcolor(YELLOW);
outtextxy(236,104,"Start Game");
outtextxy(236,144,"Garage");
outtextxy(236,184,"Exit Game");
while(1)
{
if(kbhit())
{
ch=getch();
if(ch==72)
{
if(n==1)
n=3;
else
n=n-1;
}
if(ch==80)
{
if(n==3)
n=1;
else
n=n+1;
}
if(ch=='\r')
{
delay(50);
if(n==1)
{
game();
}
if(n==2)
garage();
if(n==3)
{
closegraph();
}
}
setfillstyle(1,9);
bar(210,100,229,240);
setcolor(YELLOW);
if(n==1)
outtextxy(210,105,"->");
else if(n==2)
outtextxy(210,145,"->");
else if(n==3)
outtextxy(210,185,"->");
}
}
}
void garage()
{
int q,ch,p=50;
cleardevice();
setbkcolor(7);
for(q=0;q<=15;q++)
{
setfillstyle(1,q);
bar((q*40),0,50+(q*40),40);
}
setcolor(RED);
while(1)
{
if(kbhit())
{
ch=getch();
setfillstyle(1,0);
bar(0,41,640,80);
if(ch==75)
p=p-40;
else if(ch==77)
p=p+40;
else if(ch=='\r')
{
setfillstyle(1,(p/40)+1);
bar(200,200,400,400);
settextstyle(2,0,6);
outtextxy(420,300,"Spray for 500 Coins");
ch=getch();
if(ch==27)
continue;
if(ch=='\r')
{
if(((p/40)+1)==0||7||8||15)
break;
if(coins>=500)
{
vc=q;
coins=coins-500;
}
break;
}
}
outtextxy(45+p,60,"^");
}
}
cleardevice();
menu();
}
void game()
{
int ch,i=0,j=40,/*score*/pscore,pb=0,/*Delay of road lines*/speed=500,/*Vehicle-stats*/health=100,/*Headlamp*/hl=1,/*Movement*/m=0,n=0,/*Big-dirt*/bd,d3x=0,s3=15,d3y=530,s2random,d2x=0,abd,probd3,prob2,d2y=530,numrandom,d2random,s2=25,sd,dy=0,dx=0,drandom,srandom,d3random,s3random,s=25,/*Coins*/crandom=1,cx=0,cy=0;
loading();
setbkcolor(0);
setcolor(WHITE);
sound(80);
line(100,0,100,480);
line(120,0,120,480);
line(220,0,220,480);
line(420,0,420,480);
line(520,0,520,480);
line(540,0,540,480);
line(0,0,0,480);
line(639,0,639,480);
// Off-road
setfillstyle(2,BROWN);
floodfill(50,10,WHITE);
floodfill(550,10,WHITE);
// Borders
setfillstyle(8,WHITE);
floodfill(110,10,WHITE);
floodfill(530,10,WHITE);
//Road
setfillstyle(1,8);
floodfill(130,10,WHITE);
floodfill(230,10,WHITE);
floodfill(430,10,WHITE);
// Dashboard
setcolor(CYAN);
settextstyle(1,0,2);
outtextxy(560,50,"SCORE");
setcolor(YELLOW);
outtextxy(560,125,"COINS");
setcolor(WHITE);
outtextxy(12,50,"HEALTH");
gotoxy(72,6);
printf("%ld",score);
gotoxy(5,6);
printf("^!");
gotoxy(72,11);
printf("%d",coins);
while(1)
{
sound(20);
// Lines /_\
setcolor(WHITE);
setfillstyle(1,WHITE);
bar(317,i,323,j);
i+=70;
j+=70;
if(j>=480)
{
delay(speed);
if(speed!=30)
speed-=5;
i=i-480;
j=j-480;
setcolor(8);
bar(316,0,322,479);
setfillstyle(1,8);
floodfill(318,20,8);
}
if(speed<=80)
{
nosound();
sound(40);
}
else if(speed<=250)
{
nosound();
sound(30);
}

//Dirt
if(dy>=530)
{
dy=0,dx=0;
drandom=random(4);
dx=dx+((drandom)*100);
srandom=random(2);
if(srandom==0)
s=25;
else
s=15;
}
prob2=random(20);
if(d2y>=530&&prob2==10)
{
d2x=0,d2y=0;
d2random=drandom+1;
if(d2random>=4)
d2random=d2random-4;
d2x=d2x+((d2random)*100);
s2random=random(2);
if(s2random==0)
s2=25;
else
s2=15;
}

probd3=random(103);
if(d3y>=530&&probd3==100&&speed<=50)
{
d3x=0,d3y=0;
d3random=drandom+2;
if(d3random>=4)
d3random=d3random-4;
d3x=d3x+((d3random)*100);
s3random=random(2);
if(s3random==0)
s3=25;
else
s3=15;
}
if(cy>=700)
{
cx=0,cy=0;
crandom=random(2);
cx=cx+((crandom)*100);
}
//erasing previous layers
setcolor(8);
setfillstyle(1,8);
fillellipse(155+dx,dy,s,s);
fillellipse(175+dx,5+dy,s,s);
fillellipse(155+d2x,d2y,s2,s2);
fillellipse(175+d2x,5+d2y,s2,s2);
fillellipse(155+d3x,d3y,s3,s3);
fillellipse(175+d3x,5+d3y,s3,s3);
/*coin*/fillellipse(170+cx,cy,5+(crandom*5),5+(crandom*5));
if(pb>=500)
{
score=score+(pb/500);
gotoxy(72,6);
printf("%ld",score);
}
// Vehicle Health
abd=0;
if((110+dx<370+m)&&(370+m<(210+dx))&&(420+n<=dy)&&(dy<=460+n))
{
if(s==15)
health=health-25;
else
health=health-50;
dy+=50;
abd++;
}
if( ( (110+d2x<370+m)&&(370+m<210+d2x)&&(410+n<=d2y)&&(d2y<=460+n) ) )
{
pb=pb-20;
if(s2==15)
health=health-25;
else
health=health-50;
d2y+=50;
abd++;
}
if( ( (110+d3x<370+m)&&(370+m<210+d3x)&&(410+n<=d3y)&&(d3y<=460+n) ) )
{
pb=pb-20;
if(s3==15)
health=health-25;
else
health=health-50;
d3y+=50;
abd++;
}
if(abd!=0)
{
gotoxy(5,6);
printf("%d",health);
if(health<=0)
{
sound(50);
delay(500);
nosound();
cleardevice();
setbkcolor(0);
setcolor(RED);
settextstyle(1,0,5);
outtextxy(200,200,"GAME OVER !!");
delay(4000);
if(score>bscore)
bscore=score;
cleardevice();
menu();
}
sound(70);
nosound();
}
//coins
if((110+cx<370+m)&&(370+m<210+cx)&&(420+n<=cy)&&(cy<=460+n))
{
if(crandom==1)
coins=coins+10;
else
coins=coins+5;
pb=pb+20;
cy=cy+300;
gotoxy(72,11);
printf("%d",coins);
}
//new pieces
dy=dy+4;
d2y=d2y+5;
d3y=d3y+3;
cy=cy+2;
setcolor(0);
setfillstyle(1,0);
/* 1 */  fillellipse(155+dx,dy,s,s);
fillellipse(175+dx,5+dy,s,s);
/* 2 */ fillellipse(155+d2x,d2y,s2,s2);
fillellipse(175+d2x,5+d2y,s2,s2);
/* 3 */ fillellipse(155+d3x,d3y,s3,s3);
fillellipse(175+d3x,5+d3y,s3,s3);
setfillstyle(1,YELLOW);
fillellipse(170+cx,cy,5+(crandom*5),5+(crandom*5));
setcolor(BROWN);
settextstyle(2,0,3);
if(crandom==0)
outtextxy(169+cx,cy-5,"5");
else
outtextxy(165+cx,cy-5,"10");
//Vehicle
//tyres
setcolor(0);
setfillstyle(1,BLACK);
bar(357+m,425+n,360+m,435+n);
bar(380+m,425+n,383+m,435+n);
bar(353+m,445+n,357+m,455+n);
bar(383+m,445+n,387+m,455+n);
//body of the vehicle
setcolor(vc);
line(360+m,420+n,380+m,420+n);
line(355+m,460+n,360+m,420+n);
line(385+m,460+n,380+m,420+n);
line(355+m,460+n,385+m,460+n);
line(365+m,419+n,375+m,419+n);
setfillstyle(5,vc);
floodfill(370+m,440+n,vc);
// Head lamp
hl=hl*(-1);
if(hl<0)
{
setcolor(YELLOW);
line(362+m,418+n,366+m,415+n);
line(374+m,415+n,378+m,418+n);
line(374+m,463+n,378+m,461+n);
line(374+m,461+n,378+m,463+n);
}
//Movement
if(kbhit())
{
ch=getch();
if(ch==72||80||75||77||27)
{
pb=pb+10;
setcolor(6);
setfillstyle(1,8);
bar(350+m,415+n,390+m,463+n);
if(ch==75 &&m!=-200)
m=m-100;
else if(ch==77 &&m!=100)
m=m+100;
else if(ch==72 &&n!=-225)
n=n-75;
else if(ch==80 &&n!=0)
n=n+75;
else if(ch==27)
{
nosound();
cleardevice();
menu();
}
}
}
}
}
void ball(int *x, int *y, int *f, int *i, int val, int tmp) {
int maxy = getmaxy();
setcolor(LIGHTRED);
setfillstyle(SOLID_FILL, LIGHTRED);
pieslice(*x, *y, 0, 360, 10);
if (*i % 5 == 0)
{
if (tmp)
 {
*x = *x + 3;
}
 else
  {
*x = *x - 3;
}
*i = 0;
}
if (*f)
 {
*y = *y - 10;
}
 else
  {
*y = *y + 10;
}
if (*y >= maxy)
 {
*f = 1;
}
 else if (*y <= val)
 {
*f = 0;
}
*i = *i + 1;
}

void loading()
{
int k=0,i,s[5],x[5],y[5],f[5],midy,maxy;
for (i = 0; i < 4; i++)
{
s[i] = 0;
}
midy = getmaxy() / 2;
maxy = getmaxy();
setbkcolor(0);
x[0] = 0, y[0] = 0;
x[1] = 150, y[1] = maxy;
x[2] = getmaxx() - 100, y[2] = midy;
x[3] = getmaxx(), y[3] = maxy;
while (k!=1000)
{
cleardevice();
setcolor(WHITE);
settextstyle(2,0,6);
outtextxy(310,240,"Loading...");
ball(&x[0], &y[0], &f[0], &s[0], 0, 1);
ball(&x[1], &y[1], &f[1], &s[1], midy, 1);
ball(&x[2], &y[2], &f[2], &s[2], midy, 0);
ball(&x[3], &y[3], &f[3], &s[3], 0, 0);
k+=10;
delay(25);
}
cleardevice();
}