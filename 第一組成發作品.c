#include<stdio.h> 
#include<windows.h>   
#include<conio.h>   

int high,width;   //�w�q��� 
int position_x,position_y;  //������m 

int bullet_x,bullet_y; 
 //�l�u��m 
int enemy_x1,enemy_y1;  
int enemy_x2,enemy_y2;  
int enemy_x3,enemy_y3;  
int enemy_x4,enemy_y4;  
int enemy_x5,enemy_y5;  

int score;    //��o���� 
int me=1;    //�������A 
void gotoxy(int x,int y);   //��в��ʨ�(x,y)��m
void first();     //��l�Ƥ���
int color(int c);       //����r�C��
void explation();   //�C���k����� 
void scoreandtips();  //��ܹC������ 
void show();   //��ܹC������ 
void endgame();   //�C������ 
/**
 * ��r�C��禡   
 */
int color(int c)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);    //����r�C��
 return 0;
}
 
 /**
 * �]�w��Ц�mSD
 */
void gotoxy(int x,int y)
{
  	COORD c;
  	c.X=x;
  	c.Y=y;
  	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
 
 
 
void first() //�}�l����
{
	int n;
 	color(15);
 	gotoxy(43,10);
 	printf("��ꪺ�h�¤p�C��");
 	
 	color(11);
	gotoxy(25,22);
 	printf("1.�}�l�C��");
	gotoxy(45,22);
 	printf("2.�C������");
 	gotoxy(65,22);
 	printf("3.�h�X�C��");
 	gotoxy(40,27);
 	
 	color(5);
 	printf("�п�� 1 2 3:");    
	color(14);
	scanf("%d",&n);   //��J�ﶵ
	switch (n)
	  {
	   case 1:
	   system("cls");
	   show();
	     break;
	   case 2:
	     explation();    //�C�������禡
	     break;
	   case 3:
	     exit(0);    //�h�X�C��
	     break;
	 default:  
	  color(12);
	  gotoxy(40,28);
	  printf("�п�J1-3��������!");
	  _getch();  //��J���N��
	  system("cls"); //�M��
	  first();
	  }
	}
	 
	 
void explation() //�C������ 
	{
	int i,j = 1;
	system("cls");
	color(10);
	gotoxy(44,1);
	printf("�C������");
	color(2);
	for (i = 3; i <= 28; i++)  //��X�W�U���===
	 {
		for (j = 6; j <= 80; j++) //��X���k���||
	 	{
	 		 gotoxy(j,i);
	  		if (i == 3 || i == 28) printf("��");
	  		else if (j == 6 || j == 80) printf("�o");
	 }
	 }
	color(6);
	gotoxy(20,5);
	printf("1. �o�̬O�Ĥ@�զ��o");
	color(4);
	gotoxy(20,8);
	printf("2. ���F�W�[�C�����סAt s c f ���O����H�����W�U���k����");
	color(5);
	gotoxy(20,11);
	printf("3.���Ů�o�g�l�u�A�����Ÿ��Y�i�o��@���A");
	color(5);
	gotoxy(20,12);
	printf("�䤤�����$�A�@�Ӧ�����A�t�@�Ӧ��@���A����?���@��");
	gotoxy(20,14);
	color(9);
	printf("4.�I��_�Ǫ��Ÿ����`");
	color(8);
	gotoxy(20,17);
	printf("5. �����r�֡I�I�I");
	color(7);
	gotoxy(20,20);
	printf("/*****�����N���^�D����*****/");
	_getch();      
	system("cls");
	first();
	}
	 
void scoreandtips()//�C�����䴣�� 
	{
	gotoxy(65,8);
	color(14);
	printf("�C���o���G%d ",score);
	gotoxy(65,10);
	printf("��t c f s ���O���H��������");
	gotoxy(65,12);
	printf("���U�Ů���Y���o�g���u");
	gotoxy(65,14);
	printf("�ѤW���U�Ӫ��N�O�V�|���F��");
	
	}
	 
	 
void HideCursor() // �Ω����ô��
	{
	 CONSOLE_CURSOR_INFO cursor_info = {1,0}; // �ĤG�ӭȬ�0������ô��
	 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
	}
	 
	 
void startup()   //��ƪ�l�� 
	{
	high=20;   //�w�q�C������������ 
	width=50;   //�C���������e�� 
	 
	position_x=high-3;  //�w�q��������l��m 
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
	 
	me=1;    //�������n 
	 
	HideCursor();
	}
	 
void show()    //��ܤ��� 
	{
	 
	int i,j,k;
	for(i=0;i<high;i++)
	 {
	for(j=0;j<width;j++)
	 {
	  	if(me==0)
	  	break;
	  	else if((i==position_x)&&(j==position_y)) //�����y�� 
	  	{	
	  		
	  		printf("��");
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
	  
	  		
	  	else if((i==bullet_x)&&(j==bullet_y))  //�l�u�y�� 
	   		printf("1");
	  	else if ((j==width-1)||(i==high-1)||(j==0)||(i==0))  //�C�L��� 
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
	 		printf("���� %d",score);
	  	}
	  
	 
	 }
	 
void endgame()
	{
	int k,f;
	system("cls");
	gotoxy(20,8);
	printf("�u�O�ӥi���F�C");
	printf("��J1�A���@���A��J2��^�D���A��J3�h�X�C��");
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
	   		printf("���s���C��");
	   		system("cls");
	  		startup();   // ��ƪ�l��
	  		show();
	   		break;
		case 2:
			printf("��^�D���");
	   		system("cls");
	   		first();
	   		startup();   
	   		break;
	  	case 3:
	   		printf("�h�X");
	   		exit(0); 
	   		break;
	  	default:
	   		color(12);
	   		gotoxy(40,28);
	   		system("cls");
	   		printf("��J���~,��J���N��^��D���");
	   		_getch();  //��J���N��
	   		first(); 
	   		startup();   
	   		system("cls");  //�M��
	 	} 
	}
	 
	 
void withoutInpute()   //�P�ϥΪ̿�J�L��
	{
	if(bullet_x>0)    //�l�u�W�ɮĪG 
	bullet_x--;
	if((bullet_x==enemy_x1)&&(bullet_y==enemy_y1)) //�l�u�R���ľ� 
	 	{
	 	score++;
	 	bullet_x=-1; 
	 	enemy_x1=1;
	 	enemy_y1=2+rand()%width-2;
	 	} 
	if((bullet_x==enemy_x2)&&(bullet_y==enemy_y2)) //�l�u�R���ľ� 
	 	{
	 	score++;
	 	bullet_x=-1; 
	 	enemy_x2=1;
	 	enemy_y2=2+rand()%width-2;
	 	} 
	if((bullet_x==enemy_x3)&&(bullet_y==enemy_y3)) //�l�u�R���ľ� 
	 	{
	 	score++;
	 	bullet_x=-1; 
	 	enemy_x3=1;
	 	enemy_y3=2+rand()%width-2;
	 	} 
	if((bullet_x==enemy_x4)&&(bullet_y==enemy_y4)) //�l�u�R���ľ� 
	 	{
	 	score--;
	 	bullet_x=-1; 
	 	enemy_x4=1;
	 	enemy_y4=2+rand()%width-2;
	 	} 	
	if((bullet_x==enemy_x5)&&(bullet_y==enemy_y5)) //�l�u�R���ľ� 
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
void withInpute()   //�P�ϥΪ̿�J���� 
	{
	 char input;
	if(kbhit())     //�������V 
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
	 system("mode con cols=100 lines=30");  //�]�w�����i���e��
	 first();
	 startup();   // ��ƪ�l��
	 //explation();
	 while(1)   // �C���j�����
	 {
	 gotoxy(0,0);
	 show();   // ��ܵe��
	 scoreandtips(); 
	 if(me == 0)
	 {
	  	endgame(); 
	 }
	 withoutInpute(); // �P�ϥΪ̿�J�L������s
	 withInpute();  // �P�ϥΪ̿�J��������s
	 }
	 return 0;
	 } 
