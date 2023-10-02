#include<iostream>
#include"mylib.h"
using namespace std;
#define max 150
int sl = 4;


void tuong_tren()
{
	int y = 1;
	for (int x = 3; x <= 75; x++)
	{
		gotoXY(x, y);
		cout << "*";
	}
}
void tuong_duoi()
{
	int y = 23;
	for (int x = 3; x <= 75; x++)
	{
		gotoXY(x,y);
		cout << "*";
	}
}
void tuong_trai()
{
	int x = 3;
	for (int y = 1; y <= 23; y++)
	{
		gotoXY(x, y);
		cout << "*";
	}
}
void tuong_phai()
{
	int x = 75;
	for (int y = 1; y <= 23; y++)
	{
		gotoXY(x, y);
		cout << "*";
	}
}
void ve_tuong()
{
	SetColor(50);
	tuong_tren();
	tuong_duoi();
	tuong_trai();
	tuong_phai();
}
void tao_ran(int toadox[], int toadoy[])
{
	int x = 32;
	int y = 11;
	for (int i = 0; i < sl; i++)
	{
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}
void ve_ran(int toadox[], int toadoy[])
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		if (i == 0)
		{
			cout << "O";
		}
		else
		{
			cout << "o";
		}
	}
}
void xoa_du_lieu(int toadox[],int toadoy[])
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toadox[i], toadoy[i]);
		cout << " ";
	}
}
void them(int a[], int x)
{
	for (int i = sl - 1; i >= 0; i--)
	{
		a[i + 1] = a[i];
	}
	a[0] = x;
	sl++;
}
void xoa(int a[], int vitri)
{
	for (int i = vitri; i < sl; i++)
	{
		a[i] = a[i + 1];
	}
	sl--;
}
bool ran_cham_tuong(int x, int y)
{
	//tường trên
	if (y == 1 && (x >= 3 && x <= 75))
	{
		return true;
	}
	//tường dưới
	else if (y == 23 && (x >= 3 && x <= 75))
	{
		return true;
	}
	//tường trái
	else if (x == 3 && (y >= 1 && y <= 23))
	{
		return true;
	}
	//tường phải
	else if (x == 75 && (y >= 1 && x <= 23))
	{
		return true;
	}
	return false;
}
bool ran_cham_than(int toadox[], int toadoy[])
{
	for (int i = 1; i < sl; i++)
	{
		if ((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i]))
		{
			return true;
		}
	}
	return false;
}
bool ran_chet(int toadox[], int  toadoy[])
{
	bool kt1 = ran_cham_than(toadox, toadoy);
	bool kt2 = ran_cham_tuong(toadox[0], toadoy[0]);
	if (kt1 == true || kt2 == true)
	{
		return true;
	}
}
bool moi_trung_than(int xmoi, int ymoi, int toadox[], int toadoy[])
{
	for (int i = 0; i < sl; i++)
	{
		if (xmoi == toadox[i] && ymoi == toadoy[i])
		{
			return true;
		}
	}
	return false;
}
void tao_moi(int &xmoi, int &ymoi, int toadox[], int toadoy[])
{
	// công thức random : rand()%(b-a+1)+a
	// tạo mồi trong khuôn
	do
	{
		//4 <= xqua <= 74
		xmoi = rand() % (74 - 4 + 1) + 4;
		//2 <= yqua <= 25
		ymoi = rand() % (22 - 2 + 1) + 2;
	} while (moi_trung_than(xmoi, ymoi, toadox, toadoy) == true);
	
	SetColor(3);
	gotoXY(xmoi, ymoi);
	cout << "o";
	
}
bool ran_an_moi(int xmoi, int ymoi, int toadox[], int toadoy[])
{
	if (toadox[0] == xmoi && toadoy[0] == ymoi)
	{
		return true;
	}
	return false;
}

// khi rắn di chuyển thêm ptu mới vào đầu mảng, xóa 1 vị trí cuối mảng sau đó gọi hàm vẽ rắn
void xu_li_ran(int toadox[], int toadoy[], int x,int y,int &xmoi,int &ymoi)
{
	//b1: them toa do moi vao dau mang
	them(toadox, x);
	them(toadoy, y);
	if (ran_an_moi(xmoi, ymoi, toadox, toadoy) == false)
	{
		xoa(toadox, sl - 1);
		xoa(toadoy, sl - 1);
	}
	else
	{
		tao_moi(xmoi, ymoi, toadox, toadoy);
	}
	
		
	//b3 ve ran
	ve_ran(toadox, toadoy);
}

int main()
{
	
	bool gameover = false;
	
	int x = 32, y = 11, i = 1;
	
	int check = 2;// =1 chạm biên dưới, =0 chạm biên trên,  =2 chạm biên trái , =3 chạm biên phải;
	int toadox[max];
	int toadoy[max];
	ve_tuong();
	tao_ran(toadox, toadoy);
	srand(time(NULL));   //kết hợp random
	int xmoi, ymoi;
	tao_moi(xmoi, ymoi, toadox, toadoy);
	
	ve_ran(toadox, toadoy);
	
		while (gameover==false)
		{

			xoa_du_lieu(toadox, toadoy);
			SetColor(i);
			i++;
			if (i > 8)
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
					if (kitu == 72 && check != 0)     //72 là mã của phím đi lên(kết hợp phím kép)
					{
						check = 1;
					}
					else if (kitu == 80 && check != 1) ///đi xuống
					{
						check = 0;
					}
					else if (kitu == 75 && check != 2)   //sang trái
					{
						check = 3;
					}
					else if (kitu == 77 && check != 3)    //sang phải
					{
						check = 2;
					}
				}
			}
			if (check == 0)
			{
				y++;
			}
			else if (check == 1)
			{
				y--;
			}
			else if (check == 2)
			{
				x++;
			}
			else if (check == 3)
			{
				x--;
			}
			xu_li_ran(toadox, toadoy, x, y, xmoi, ymoi);
			gameover = ran_chet(toadox, toadoy);


			Sleep(120);
		}
		
	
	_getch();
}