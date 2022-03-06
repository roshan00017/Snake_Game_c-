#include <graphics.h>
#include "snakeBody.h"
#include "food.h"

int main()
{
    initwindow(800,800,"SNAKE GAME");
    snakeBody body;
    food fruit;
    int length,count=0;
    bool playing=true;
    char lengtharr[3];
    fruit.generate(body.getPosx(), body.getPosy());
    int page=0;

    while(1)
    {
            setactivepage(page);
            setvisualpage(1-page);
            cleardevice();
            setcolor(BLUE);

            setfillstyle(SOLID_FILL, BLUE);


            if(GetAsyncKeyState(VK_LEFT))
            {    body.changeDirTo(LEFT);    }
            if(GetAsyncKeyState(VK_UP))
            {    body.changeDirTo(UP);      }
            if(GetAsyncKeyState(VK_RIGHT))
            {    body.changeDirTo(RIGHT);   }
            if(GetAsyncKeyState(VK_DOWN))
            {    body.changeDirTo(DOWN);    }
            if(GetAsyncKeyState(VK_ESCAPE))
                  break;

            if(playing==true && !body.update())
            {
                  playing = false;
            }
            body.drawSnake();


            if(fruit.update(body.getPosx(), body.getPosy()))
            {
                 fruit.generate(body.getPosx(), body.getPosy());
                 body.appendSnake();
            }

            // BOXES
            setcolor(LIGHTCYAN);
                 rectangle(0,0,30,510);
                 rectangle(30,0,800,30);
                 //rectangle(480,0,510,510);
                 rectangle(30,480,800,510);
                 //rectangle(510,0,800,20);
                 //rectangle(510,250,800,270);
                 rectangle(770,30,800,480);
                 //rectangle(510,490,800,510);
                 //rectangle(780,270,800,490);
                 rectangle(0,510,30,800);
                 rectangle(480,510,510,800);
                 rectangle(770,510,800,800);
                 setfillstyle(SOLID_FILL, LIGHTCYAN);
                 floodfill(15,250,LIGHTCYAN);
                 floodfill(250,10,LIGHTCYAN);
                  floodfill(250,495,LIGHTCYAN);
                  floodfill(790,150,LIGHTCYAN);
                  floodfill(10,640,LIGHTCYAN);
                  floodfill(490,520,LIGHTCYAN);
                  floodfill(780,520,LIGHTCYAN);

            // SCORE
                 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
                 setcolor(GREEN);
                 outtextxy(50,550, " Your");
                 outtextxy(50, 620, "Length");
                 length = body.getlength();
                 lengtharr[0]=char(48+length/10);
                 lengtharr[1]=char(48+length%10);
                 lengtharr[2]='\0';
                 outtextxy(150, 590, lengtharr);


            // STATUS
                 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
                 outtextxy(520, 550, "STATUS :-");
                 if (body.getlength() == 10)
                 {
                      outtextxy(520, 580, "YOU WON !");
                      playing=false;
                 }
                 else if(playing)
                 {
                      outtextxy(520, 580, "PLAYING");
                 }
                 else
                 {
                      outtextxy(520, 580, "GAME OVER");
                 }
                 settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
                 outtextxy(520,620,"PRESS 'ESC' to EXIT");


            fruit.draw();
            page = 1-page;
            delay(100);
    }

    getch();
    closegraph();
}
