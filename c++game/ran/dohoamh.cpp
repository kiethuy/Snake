#include <iostream>
#include"mylib.h"
using namespace std;

int main()
{
    int x = 5;
    int y = 0;
    int i = 1;
    int check=0;// =1 chạm biên dưới, =0 chạm biên trên,  =2 chạm biên trái , =3 chạm biên phải;
    int x1 = x;
    int y1 = y;
    while (6)
    {
        gotoXY(x1, y1);
        cout << "      ";
        gotoXY(x, y);
        cout << "\\\\\\";
        x1 = x;
        y1 = y;
        SetColor(i);
        i++;
        if (i > 15)
        {
            i = 1;
        }
        //kiem tra co nhap tu ban phim ko
        if (_kbhit())      // kbhit: ktra xem có nhap ki tu từ bàn phím ko
        {
            char kitu = _getch();// ĐỌC DỮ LIỆU BỘ NHỚ ĐỆM
            if (kitu == -32)      //-32 là phím mã kép
            {
                kitu = _getch();
                if (kitu == 72)     //72 là mã của phím đi lên(kết hợp phím kép)
                {
                    check = 1;
                }
                else if (kitu == 80) ///đi xuống
                {
                    check = 0;
                }
                else if (kitu == 75)   //sang trái
                {
                    check = 3;
                }
                else if (kitu == 77)    //sang phải
                {
                    check = 2;
                }
            }
        }
        if (check == 2)
        {
            x++;
        }
        else if (check == 3)
        {
            x--;
        }
        if (check == 0)
        {
            y++;
        }
        else if (check == 1)
        {
            y--;
        }
        //
        if (x == 100)
        {
            check = 3;
        }
        else if (x == 0)
        {
            check = 2;
        }
        if (y == 28)
        {
            check = 1;
        }
        else if (y == 0)
        {
            check = 0;
        }
        Sleep(80);
       
    }
    _getch();
}

