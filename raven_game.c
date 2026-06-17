#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <time.h>
#define _(x,y) for(int i=x;i<y;i++)
#define W 80
#define H 20
/* Raven Game - C17 - 2024-06-05 
             .:::..  .--.
           :-:.    .::----:::::::.
           .=:.    ..=-.-======.   .--...
           .-.-:.  .----.---.           .-.
         .+++=+.  :+++++++++:++++++++++++++
          -++++-.    .=+++++++++++:.     .
         .::::..::.   ..:::::::::..    .
         ..-----.--:.-:  .-:-------:
         ...-++++++++++++-.=. .=:++++++.
         .-----------------:-:.:..-------.   . .
         =++++++++     .      :++-==..=.+++++.         .
         =++++++...               .-+++.   =++++=         .
          .:::::...::::..::. .  ...:.   :::.:. ::::::  .
          .--------------------.:--.-:.--..---:-.----::
         .-+++++++++++++++++++++++++++++++. =++++=:++++.         .    */
         char*V[]={"~v~","-v-","_v_"};int P=8,S,hp=3,fc;
      int EX[4],EY[4],EA[4],BX=-1,BY,EXI=0;int g(){struct 
    timeval v={0};fd_set f;FD_ZERO(&f);FD_SET(0,&f);return 
   select(1,&f,0,0,&v)?getchar():0;}void main(){struct termios
  t;tcgetattr(0,&t);struct termios n=t;n.c_lflag&=~(ICANON|ECHO);
 tcsetattr(0,TCSANOW,&n);srand(time(0));_(0,4){EX[i]=W+(rand()%20
);EY[i]=rand()%(H-2);EA[i]=rand()%3;}printf("\033[2J\033[?25l");
while(hp>0){printf("\033[H");char B[H][W];memset(B,' ',sizeof(B))
;int c=g();if(c=='q')break;if(c=='w'&&P>1)P--;if(c=='s'&&P<H-2)P++
;if(c==' '&&BX<0){BX=6;BY=P;}fc++;_(0,4){EX[i]--;if(EX[i]<0){EX[i
]=W+(rand()%20);EY[i]=rand()%(H-2);}if(abs(EX[i]-4)<3&&EY[i]==P){
hp--;EX[i]=W+(rand()%20);}if(BX>=0&&abs(EX[i]-BX)<2&&EY[i]==BY){S
+=10;EX[i]=W+(rand()%20);BX=-1;}if(fc%3==0)EA[i]=(EA[i]+1)%3;int 
ex=EX[i],ey=EY[i];_(0,3)if(ex+i>=0&&ex+i<W&&ey>=0&&ey<H)B[ey][ex+
i]=V[EA[i]][i];}if(BX>=0){BX+=2;if(BX>=W)BX=-1;else B[BY][BX]='='
;}int pA=(fc/2)%3;_(0,3)if(4+i<W&&P>=0&&P<H)B[P][4+i]=V[pA][i];_(
 0,H){int y=i;_(0,W)putchar(B[y][i]);putchar('\n');}printf(""
  "HP: %d | SCORE: %d | W/S to Fly | Space to Caw-Blast | "
   "Q to Quit\n",hp,S);usleep(40000);}tcsetattr(0,TCSANOW,&
    t);printf("\033[?25h\n--- GAME OVER ---\nFINAL SCORE"
      ": %d\n\n",S);}/*_!!_!!_!!_!!_!!_!!_!!_!!_!!_!!_!
         _!!_!!_!!_!!_!!_!!_!!_!!_!!_!!_!!_!!_!!_!!_
           _!!_!!_!!_!!_!!_!!_!!_!!_!!_!!_!!_!!_
             _!!_!!_!!_!!_!!_!!_!!_!!_!!_!!_
                    \\           //
                     \\         //
                      ||       ||
                      ||       ||
                     /||\     /||\
                    / || \   / || \
                   ^  ^  ^   ^  ^  ^       TahmidRaven*/