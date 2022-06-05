#include<stdio.h> 
#include<windows.h>   
#include<conio.h>   

int high,width;   //定義邊界 
int position_x,position_y;  //飛機位置 

int bullet_x,bullet_y; 
 //子彈位置 
int enemy_x1,enemy_y1;  
int enemy_x2,enemy_y2;  
int enemy_x3,enemy_y3;  
int enemy_x4,enemy_y4;  
int enemy_x5,enemy_y5;  

int score;    //獲得分數 
int me=1;    //飛機狀態 
void gotoxy(int x,int y);   //游標移動到(x,y)位置
void first();     //初始化介面
int color(int c);       //更改文字顏色
void explation();   //遊戲右側顯示 
void scoreandtips();  //顯示遊戲提示 
void show();   //顯示遊戲介面 
void endgame();   //遊戲結束 
/**
 * 文字顏色函式   
 */
int color(int c)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);    //更改文字顏色
 return 0;
}
 
 /**
 * 設定游標位置SD
 */
void gotoxy(int x,int y)
{
  	COORD c;
  	c.X=x;
  	c.Y=y;
  	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
 
 
 
void first() //開始介面
{
	int n;
 	color(15);
 	gotoxy(43,10);
 	printf("串串的懷舊小遊戲");
 	
 	color(11);
	gotoxy(25,22);
 	printf("1.開始遊戲");
	gotoxy(45,22);
 	printf("2.遊戲說明");
 	gotoxy(65,22);
 	printf("3.退出遊戲");
 	gotoxy(40,27);
 	
 	color(5);
 	printf("請選擇 1 2 3:");    
	color(14);
	scanf("%d",&n);   //輸入選項
	switch (n)
	  {
	   case 1:
	   system("cls");
	   show();
	     break;
	   case 2:
	     explation();    //遊戲說明函式
	     break;
	   case 3:
	     exit(0);    //退出遊戲
	     break;
	 default:  
	  color(12);
	  gotoxy(40,28);
	  printf("請輸入1-3之間的數!");
	  _getch();  //輸入任意鍵
	  system("cls"); //清屏
	  first();
	  }
	}
	 
	 
void explation() //遊戲提示 
	{
	int i,j = 1;
	system("cls");
	color(10);
	gotoxy(44,1);
	printf("遊戲說明");
	color(2);
	for (i = 3; i <= 28; i++)  //輸出上下邊框===
	 {
		for (j = 6; j <= 80; j++) //輸出左右邊框||
	 	{
	 		 gotoxy(j,i);
	  		if (i == 3 || i == 28) printf("成");
	  		else if (j == 6 || j == 80) printf("發");
	 }
	 }
	color(6);
	gotoxy(20,5);
	printf("1. 這裡是第一組成發");
	color(4);
	gotoxy(20,8);
	printf("2. 為了增加遊戲難度，t s c f 分別控制人物的上下左右移動");
	color(5);
	gotoxy(20,11);
	printf("3.按空格發射子彈，打中符號即可得到一分，");
	color(5);
	gotoxy(20,12);
	printf("其中有兩個$，一個扣兩分，另一個扣一分，打中?扣一分");
	gotoxy(20,14);
	color(9);
	printf("4.碰到奇怪的符號死亡");
	color(8);
	gotoxy(20,17);
	printf("5. 玩的愉快！！！");
	color(7);
	gotoxy(20,20);
	printf("/*****按任意鍵返回主頁面*****/");
	_getch();      
	system("cls");
	first();
	}
	 
void scoreandtips()//遊戲側邊提示 
	{
	gotoxy(65,8);
	color(14);
	printf("遊戲得分：%d ",score);
	gotoxy(65,10);
	printf("用t c f s 分別控人物的移動");
	gotoxy(65,12);
	printf("按下空格鍵即為發射炮彈");
	gotoxy(65,14);
	printf("天上掉下來的就是糟糕的東西");
	
	}
	 
	 
void HideCursor() // 用於隱藏游標
	{
	 CONSOLE_CURSOR_INFO cursor_info = {1,0}; // 第二個值為0表示隱藏游標
	 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
	}
	 
	 
void startup()   //資料初始化 
	{
	high=20;   //定義遊戲介面的高度 
	width=50;   //遊戲介面的寬度 
	 
	position_x=high-3;  //定義飛機的初始位置 
	position_y=width/2;
	 
	bullet_x=0;
	bullet_y=position_y; 
	enemy_x1=0;
	enemy_y1=1;	
	enemy_x2=0;
	enemy_y2=15;
	enemy_x3=0;
	enemy_y3=14;
	enemy_x4=0;
	enemy_y4=7;
	enemy_x5=0;
	enemy_y5=9;
										
	score=0;
	 
	me=1;    //飛機完好 
	 
	HideCursor();
	}
	 
void show()    //顯示介面 
	{
	 
	int i,j,k;
	for(i=0;i<high;i++)
	 {
	for(j=0;j<width;j++)
	 {
	  	if(me==0)
	  	break;
	  	else if((i==position_x)&&(j==position_y)) //飛機座標 
	  	{	
	  		
	  		printf("串");
	  	}
	  	else if((i==enemy_x1)&&(j==enemy_y1))  
	  		printf("#");
	  	else if((i==enemy_x2)&&(j==enemy_y2))  
	  		printf("@");
	  	else if((i==enemy_x3)&&(j==enemy_y3))  
	  		printf("%");
	  	else if((i==enemy_x4)&&(j==enemy_y4))  
	  		printf("?");
	  	else if((i==enemy_x5)&&(j==enemy_y5))  
	  		printf("$");
	  
	  		
	  	else if((i==bullet_x)&&(j==bullet_y))  //子彈座標 
	   		printf("1");
	  	else if ((j==width-1)||(i==high-1)||(j==0)||(i==0))  //列印邊界 
	 		 printf("-");
	  	else
	 		 printf(" ");
		 }
		printf("\n"); 
		 }
	 	printf("\n");
	 	if((position_x==enemy_x1)&&(position_y==enemy_y1))
	 	{
	 
	 		me--;   
	 		}
		 
		if((position_x==enemy_x2)&&(position_y==enemy_y2))
	 	{
	 
	 		me--;   
	 	}
		
		if((position_x==enemy_x3)&&(position_y==enemy_y3))
	 	{
	 		me--;   
		 }
		if((position_x==enemy_x4)&&(position_y==enemy_y4))
	 	{
	 		me--;   
		 } 
		if((position_x==enemy_x5)&&(position_y==enemy_y5))
	 	{
	 		me--;   
		 } 
		
		if(me==0)	
			{
				system("cls");
			 } 
		else
	 	{
	 		printf("分數 %d",score);
	  	}
	  
	 
	 }
	 
void endgame()
	{
	int k,f;
	system("cls");
	gotoxy(20,8);
	printf("真是太可惜了。");
	printf("輸入1再玩一次，輸入2返回主選單，輸入3退出遊戲");
	int x = 25;
    int y = 10;
    gotoxy(x, y  ); printf( " _         _______    _______    _______       ");
    gotoxy(x, y+1); printf( "| |       |  ___  |  |  _____|  |  _____|       ");
    gotoxy(x, y+2); printf( "| |       | |   | |  | |        | |_____         ");
    gotoxy(x, y+3); printf( "| |       | |   | |  | |_____   |  _____|      ");
    gotoxy(x, y+4); printf( "| |       | |   | |  |_____  |  | |                    ");
    gotoxy(x, y+5); printf( "| |____   | |___| |   _____| |  | |_____          ");
    gotoxy(x, y+6); printf( "|______|  |_______|  |_______|  |_______|           ");
	scanf("%d",&k);
	system("cls");
	switch(k) 
	 {
	  	case 1:
	   		printf("重新玩遊戲");
	   		system("cls");
	  		startup();   // 資料初始化
	  		show();
	   		break;
		case 2:
			printf("返回主選單");
	   		system("cls");
	   		first();
	   		startup();   
	   		break;
	  	case 3:
	   		printf("退出");
	   		exit(0); 
	   		break;
	  	default:
	   		color(12);
	   		gotoxy(40,28);
	   		system("cls");
	   		printf("輸入錯誤,輸入任意鍵回到主選單");
	   		_getch();  //輸入任意鍵
	   		first(); 
	   		startup();   
	   		system("cls");  //清屏
	 	} 
	}
	 
	 
void withoutInpute()   //與使用者輸入無關
	{
	if(bullet_x>0)    //子彈上升效果 
	bullet_x--;
	if((bullet_x==enemy_x1)&&(bullet_y==enemy_y1)) //子彈命中敵機 
	 	{
	 	score++;
	 	bullet_x=-1; 
	 	enemy_x1=1;
	 	enemy_y1=2+rand()%width-2;
	 	} 
	if((bullet_x==enemy_x2)&&(bullet_y==enemy_y2)) //子彈命中敵機 
	 	{
	 	score++;
	 	bullet_x=-1; 
	 	enemy_x2=1;
	 	enemy_y2=2+rand()%width-2;
	 	} 
	if((bullet_x==enemy_x3)&&(bullet_y==enemy_y3)) //子彈命中敵機 
	 	{
	 	score++;
	 	bullet_x=-1; 
	 	enemy_x3=1;
	 	enemy_y3=2+rand()%width-2;
	 	} 
	if((bullet_x==enemy_x4)&&(bullet_y==enemy_y4)) //子彈命中敵機 
	 	{
	 	score--;
	 	bullet_x=-1; 
	 	enemy_x4=1;
	 	enemy_y4=2+rand()%width-2;
	 	} 	
	if((bullet_x==enemy_x5)&&(bullet_y==enemy_y5)) //子彈命中敵機 
	 	{
	 	score++;
	 	score++;
	 	bullet_x=-1; 
	 	enemy_x5=1;
	 	enemy_y5=2+rand()%width-2;
	 	} 
	
	static int speed;
	if(speed<30)   
	 	speed++;
	if(speed==30)
	 	{
	 	if(enemy_x1<high)
	  		enemy_x1++;
	  	if(enemy_x2<high)
	  		enemy_x2++;
	  	if(enemy_x3<high)
	  		enemy_x3++;
	  	if(enemy_x4<high)
	  		enemy_x4++;
	  	if(enemy_x5<high)
	  		enemy_x5++;
		
	else if(speed>10)
	 	{
	  		enemy_x1=0;
	  		enemy_y1=2+rand()%width-2;
	  		enemy_x2=0;
	  		enemy_y2=2+rand()%width-2;
	  		enemy_x3=0;
	  		enemy_y3=2+rand()%width-2;
	  		enemy_x4=0;
	  		enemy_y4=2+rand()%width-2;
	  		enemy_x5=0;
	  		enemy_y5=2+rand()%width-2;
	  		
	 	}
		 speed=0;
	 }
	 
	 
	 
	 
	}
void withInpute()   //與使用者輸入有關 
	{
	 char input;
	if(kbhit())     //控制飛機方向 
	 {
	 	input=getch();
	if((input=='t')&&position_x>1)
	 	position_x--; 
	 	
	if((input=='x')&&position_x<high-2)
		position_x++; 
		
	if((input=='s')&&position_y>1)
		position_y--;
		 
	if((input=='f')&&position_y<width-2)
		position_y++;
		
	if(input==' ')
	 {
		bullet_x=position_x-1;
	  	bullet_y=position_y;
	 }
	 }
	}
	 
	int main()
	{
	 system("mode con cols=100 lines=30");  //設定控制檯的寬高
	 first();
	 startup();   // 資料初始化
	 //explation();
	 while(1)   // 遊戲迴圈執行
	 {
	 gotoxy(0,0);
	 show();   // 顯示畫面
	 scoreandtips(); 
	 if(me == 0)
	 {
	  	endgame(); 
	 }
	 withoutInpute(); // 與使用者輸入無關的更新
	 withInpute();  // 與使用者輸入有關的更新
	 }
	 return 0;
	 } 
