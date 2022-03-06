#ifndef SNAKEBODY_H_INCLUDED
#define SNAKEBODY_H_INCLUDED
#include <graphics.h>

enum DIR {LEFT , UP , RIGHT , DOWN};        // enum for the direction

// position structure
struct POS
{
       int x,y;
       POS()
       {
            x = -50;
            y = 0;
       }
};

// SNAKE CLASS
class snakeBody
{
private:
        POS arr[31];            // THIHS ARRAY IS GOING TO CONTAIN THE POSITIONS OF WHOLE SNAKE
        int direction;          // WORKING WITH ENUM !!!
        int length;             // OBVIOUSLY LENGTH
public :
        snakeBody()
        {
              arr[0].x = 10;        //  INITIAL VALUE X
              arr[0].y = 10;        //  INITIAL VALUE Y
              length = 2;           // INITILAL LENGTH = 2
              direction = RIGHT;    // INITIAL GOING IN RIGHT DIRECTION
        }
        void drawSnake();
        void appendSnake();         // IT IS RESPONSIBLE FOR INCREMENT IN SNAKE'S LENGTH
        void changeDirTo(int);
        int update();
        int getPosx();
        int getPosy();
        int getlength();

};

void snakeBody::drawSnake()         // DRAWING THE WHOLE SNAKE
{
     for(int i=0; i<length ; i++)
     {
          setcolor(WHITE);
          rectangle(arr[i].x , arr[i].y , arr[i].x+10 , arr[i].y+10);
          if(i==0)                                      // HEAD IS OF DIFFERENT COLOR
                  setfillstyle(SOLID_FILL , DARKGRAY);
          else                                          // REST OF THE BODY
                  setfillstyle(SOLID_FILL , LIGHTGRAY);
          floodfill(arr[i].x+5 , arr[i].y+5 , WHITE);
     }
}

void snakeBody::appendSnake()
{
     if(length < 10)                            // PREVENTS THE LENGTH FROM GOING GREATER THAN 29
        length++;
}

void snakeBody::changeDirTo(int newdir)
{
     if(newdir == LEFT || newdir == RIGHT)
     {
            if(direction == UP || direction == DOWN)
                         direction = newdir;
     }
     else if(newdir == UP || newdir == DOWN)
     {
            if(direction == LEFT || direction == RIGHT)
                         direction = newdir;
     }
}

int snakeBody::update()                                                     // THIS FUNCTION ENFORCES THE BASIC
{                                                                           // ALGORITHM FOR MOVING SNAKE
     for(int i=1 ; i<length ; ++i)                                          // BY PROVIDING ALL THE PREVIOUS PARTS
     {                                                                      // THE COORDINATES OF CURRENT PART
             if(arr[0].x == arr[i].x && arr[0].y == arr[i].y)               // HENCE [1] GETS THE POSITION OF [0]
             {                                                              // [2] GETS THE POSITION OF [1] AND SO ON...
                         return 0;                                          // AND LASTLY HEAD([0]) IS GIVEN LATEST VALUES
             }
     }
     for(int i=length ; i>=0 ; --i)
     {
             if(i==0)
             {
                     arr[1].x = arr[0].x;
                     arr[1].y = arr[0].y;
             }
             else
             {
                     arr[i].x = arr[i-1].x;
                     arr[i].y = arr[i-1].y;
             }
     }
     if(direction == LEFT)
     {
                  arr[0].x -= 10;
                  if(arr[0].x == 0)
                  {
                              arr[0].x = 770;
                  }
     }
     else if(direction == RIGHT)
     {
                  arr[0].x += 10;
                  if(arr[0].x == 770)
                  {
                              arr[0].x = 10;
                  }
     }
     else if(direction == UP)
     {
                  arr[0].y -= 10;
                  if(arr[0].y == 0)
                  {
                              arr[0].y = 480;
                  }
     }
     else if(direction == DOWN)
     {
                  arr[0].y += 10;
                  if(arr[0].y == 480)
                  {
                              arr[0].y = 10;
                  }
     }
     return 1;
}

int snakeBody::getPosx()
{
    return arr[0].x;
}

int snakeBody::getPosy()
{
    return arr[0].y;
}

int snakeBody::getlength()
{
    return length;
}


#endif // SNAKEBODY_H_INCLUDED
