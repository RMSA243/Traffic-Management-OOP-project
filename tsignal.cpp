#include <iostream>
#include "mygraphics.h"

#include <random>

using namespace std;
int w, h;
class vehicle
{
	//co-ordinates of a vehicle
	int vx1;
	int vx2;
	int vy1;
	int vy2;
public:
	void setco(int tco[])// to set co-ordinates of a vehicle
	{
		vx1 = tco[0];
		vy1 = tco[1];
		vx2 = tco[2];
		vy2 = tco[3];
		
		drawRectangle(vx1, vy1, vx2, vy2, 255, 0, 0, 255, 255, 0);

		delay(100);
	}
	void  setvx1(int a,int r)// to change the coordinates of a car basically to  move the car
	{
		if (vx1 > 880 || vx2 > 880)
			return;
		if (vy1 < 0 || vy2 < 0)
			return;
		drawRectangle(vx1, vy1, vx2, vy2, 0, 255, 255, 0, 255, 255);

		if (r == 1)
		{
			vx1 += a;
			vx2 += a;
			if (vx1 > 880 || vx2>880)
				return;
		}
		else if (r == 3)
		{
			vx1 -= a;
			vx2 -= a;
			if (vy1 < 0 || vy2 < 0)
				return ;
		}
		

		
		drawRectangle(vx1, vy1, vx2, vy2, 255, 0, 0, 255, 255, 0);

	}

	void  setvy1(int a,int r)// to change the coordinates of a car basically to  move the car
	{

		drawRectangle(vx1, vy1, vx2, vy2, 0, 255, 255, 0, 255, 255);

		if (vy1 > 680 || vy2 > 680)
			return;
		drawRectangle(vx1, vy1, vx2, vy2, 0, 255, 255, 0, 255, 255);
		if (r == 2)
		{
			vy1 += a;
			vy2 += a;
			if (vy1 < 0 || vy2 < 0)
				return;
		}

		else if (r == 4)
		{
			vy1 -= a;
			vy2 -= a;
			if (vy1 > 680 || vy2 > 680)
				return;
		}

		drawRectangle(vx1, vy1, vx2, vy2, 255, 0, 0, 255, 255, 0);
	}


	int getvx1() { return vx1; }
	int getvy1() { return vy1; }
	int getvx2() { return vx2; }
	int getvy2() { return vy2; }
};

class road
{
	vehicle * veh;

	int rdx1 = 0;
	int rdy1 = 0;
	int rdx2 = 0;
	int rdy2 = 0;
	int nov;//number of vehicle on that road
	int rno;//road number
public:
	
	road(int x)// sets the co-ordinates of road
	{


		//creates random number of vehicles

		random_device rd{};
		default_random_engine num {rd()};
		uniform_int_distribution<int> rn{ 1,3 };
		nov = rn(num);


		veh = new vehicle[nov];
		
		rno = x;
		if (x == 1)
		{
			rdx1 = 0;
			rdy1 = 250;
			rdx2 = 300;
			rdy2 = 430;

			
		}
		else if (x == 2)
		{
			rdx1 = 300;
			rdy1 = 0;
			rdx2 = 580;
			rdy2 = 250;
		}
		else if (x == 3)
		{
			rdx1 = 580;
			rdy1 = 250;
			rdx2 = 880;
			rdy2 = 430;
		}
		else if (x == 4)
		{
			rdx1 = 300;
			rdy1 = 430;
			rdx2 = 580;
			rdy2 = 680;
		}

	}
	void roadveh()//creates the vehicles of on road
	{
		if (rno == 1)
		{

			if (nov == 1)
			{

				int tco[4];

				tco[0] = 90;
				tco[1] = 370;
				tco[2] = 130;
				tco[3] = 400;
				veh[0].setco(tco);

			}
			else if (nov == 2)
			{
				int tco[4];

				tco[0] = 10;
				tco[1] = 370;
				tco[2] = 50;
				tco[3] = 400;

				veh[1].setco(tco);

				tco[0] = 170;
				tco[1] = 370;
				tco[2] = 210;
				tco[3] = 400;

				veh[0].setco(tco);
			}
			else if (nov == 3)
			{
				int tco[4];

				tco[0] = 10;
				tco[1] = 370;
				tco[2] = 50;
				tco[3] = 400;

				veh[2].setco(tco);

				tco[0] = 90;
				tco[1] = 370;
				tco[2] = 130;
				tco[3] = 400;

				veh[1].setco(tco);

				tco[0] = 170;
				tco[1] = 370;
				tco[2] = 210;
				tco[3] = 400;

				veh[0].setco(tco);


			}
		}
		else if (rno == 2)
		{
			if (nov == 1)
			{
				int tco[4];
				tco[0] = 350;
				tco[1] = 80;
				tco[2] = 380;
				tco[3] = 120;

				veh[0].setco(tco);


			}
			else if (nov == 2)
			{
				int tco[4];
				tco[0] = 350;
				tco[1] = 10;
				tco[2] = 380;
				tco[3] = 50;

				veh[1].setco(tco);

				tco[0] = 350;
				tco[1] = 150;
				tco[2] = 380;
				tco[3] = 190;

				veh[0].setco(tco);
			}
			else if (nov == 3)
			{
				int tco[4];
				tco[0] = 350;
				tco[1] = 10;
				tco[2] = 380;
				tco[3] = 50;

				veh[2].setco(tco);

				tco[0] = 350;
				tco[1] = 80;
				tco[2] = 380;
				tco[3] = 120;

				veh[1].setco(tco);

				tco[0] = 350;
				tco[1] = 150;
				tco[2] = 380;
				tco[3] = 190;

				veh[0].setco(tco);


			}
		}
		else if (rno == 3)
		{
			if (nov == 1)
			{
				int tco[4];
				tco[0] = 790;
				tco[1] = 280;
				tco[2] = 750;
				tco[3] = 310;

				veh[0].setco(tco);

			}
			else if (nov == 2)
			{
				int tco[4];

				tco[0] = 870;
				tco[1] = 280;
				tco[2] = 830;
				tco[3] = 310;

				veh[1].setco(tco);

				tco[0] = 710;
				tco[1] = 280;
				tco[2] = 670;
				tco[3] = 310;

				veh[0].setco(tco);
			}
			else if (nov == 3)
			{
				int tco[4];
				tco[0] = 870;
				tco[1] = 280;
				tco[2] = 830;
				tco[3] = 310;

				veh[2].setco(tco);

				tco[0] = 790;
				tco[1] = 280;
				tco[2] = 750;
				tco[3] = 310;

				veh[1].setco(tco);

				tco[0] = 710;
				tco[1] = 280;
				tco[2] = 670;
				tco[3] = 310;

				veh[0].setco(tco);


			}
		}
		else if (rno == 4)
		{
			if (nov == 1)
			{
				int tco[4];
				
				tco[0] = 530;
				tco[1] = 590;
				tco[2] = 500;
				tco[3] = 550;

				veh[0].setco(tco);


			}
			else if (nov == 2)
			{
				int tco[4];
				tco[0] = 530;
				tco[1] = 670;
				tco[2] = 500;
				tco[3] = 630;

				veh[1].setco(tco);


				tco[0] = 530;
				tco[1] = 510;
				tco[2] = 500;
				tco[3] = 470;

				veh[0].setco(tco);

			}
			else if (nov == 3)
			{
				int tco[4];
				tco[0] = 530;
				tco[1] = 670;
				tco[2] = 500;
				tco[3] = 630;

				veh[2].setco(tco);

				tco[0] = 530;
				tco[1] = 590;
				tco[2] = 500;
				tco[3] = 550;

				veh[1].setco(tco);

				tco[0] = 530;
				tco[1] = 510;
				tco[2] = 500;
				tco[3] = 470;

				veh[0].setco(tco);


			}
		}
		
	}
	vehicle* getveh() { return veh; }
	int getnov() { return nov; }
	int getrno() { return rno; }


};

class trafics
{
	//trafic signal box co-ordinates
	int tfx1 = 0;
	int tfy1 = 0;
	int tfx2 = 0;
	int tfy2 = 0;
	char col = 0;//colour of that signal
	int sno = 0;//signal number (1-4)
public:
	trafics(int x,char tcol = 'y')// x=road number and tcol is color
	{
		

		if (x == 1)
		{
			sno = x;

			tfx1 = 250;
			tfy1 = 440;
			tfx2 = 290;
			tfy2 = 540;

			col = tcol;


		}
		else if (x == 2)
		{
			tfx1 = 190;
			tfy1 = 200;
			tfx2 = 290;
			tfy2 = 240;
			 sno = x;

			col = tcol;


		}
		else if (x == 3)
		{
			tfx1 = 590;
			tfy1 = 140;
			tfx2 = 630;
			tfy2 = 240;
			sno = x;

			col = tcol;


		}

		else if (x == 4)
		{
			tfx1 = 590;
			tfy1 = 440;
			tfx2 = 690;
			tfy2 = 480;

			col = tcol;

			sno = x;


		}
	
		
	}
	void setc(char tcol)//set the specific ellipse to tcol and the remaining are set to default (grey col)
	{
		int x = sno;


		if (x == 1)
		{
			
			col = tcol;

			if (tcol == 'r')
			{
				drawEllipse(w - 592.5, h - 237.5, w - 627.5, h - 207.5, 255, 0, 0, 255, 0, 0);//red signal
				drawEllipse(w - 592.5, h - 205, w - 627.5, h - 175, 255, 255, 0, 255, 255, 255);//yellow signal
				drawEllipse(w - 592.5, h - 172.5, w - 627.5, h - 142.5, 0, 255, 0, 255, 255, 255);//green signal

			}
			
			else if (tcol == 'g')
			{
				drawEllipse(w - 592.5, h - 172.5, w - 627.5, h - 142.5, 0, 255, 0, 0, 255, 0);//green signal
				drawEllipse(w - 592.5, h - 205, w - 627.5, h - 175, 255, 255, 0, 255, 255, 255);//yellow signal
				drawEllipse(w - 592.5, h - 237.5, w - 627.5, h - 207.5, 255, 0, 0, 255, 255, 255);//red signal

			}
			else if (tcol == 'y')
			{
				drawEllipse(w - 592.5, h - 205, w - 627.5, h - 175, 255, 255, 0, 255, 255, 0);//yellow signal
				drawEllipse(w - 592.5, h - 172.5, w - 627.5, h - 142.5, 0, 255, 0, 255, 255, 255);//green signal
				drawEllipse(w - 592.5, h - 237.5, w - 627.5, h - 207.5, 255, 0, 0, 255, 255, 255);//red signal

			}
			else
			{
				drawEllipse(w - 592.5, h - 172.5, w - 627.5, h - 142.5, 0, 255, 0, 255, 255, 255);//green signal
				drawEllipse(w - 592.5, h - 237.5, w - 627.5, h - 207.5, 255, 0, 0, 255, 255, 255);//red signal
				drawEllipse(w - 592.5, h - 205, w - 627.5, h - 175, 255, 255, 0, 255, 255, 255);//yellow signal


			}
		}

		else if (x == 2)
		{

			col = tcol;

			if (tcol == 'r')
			{
				drawEllipse(w - 592.5, h - 442.5, w - 622.5, h - 477.5, 255, 0, 0, 255, 0, 0);//red signal
				drawEllipse(w - 625, h - 442.5, w - 655, h - 477.5, 255, 255, 0, 255, 255, 255);//yellow signal
				drawEllipse(w - 657.5, h - 442.5, w - 687.5, h - 477.5, 0, 255, 0, 255, 255, 255);//green signal
			}
			

			else if (tcol == 'g')
			{
				drawEllipse(w - 657.5, h - 442.5, w - 687.5, h - 477.5, 0, 255, 0, 0, 255, 0);//green signal
				drawEllipse(w - 592.5, h - 442.5, w - 622.5, h - 477.5, 255, 0, 0, 255, 255, 255);//red signal
				drawEllipse(w - 625, h - 442.5, w - 655, h - 477.5, 255, 255, 0, 255, 255, 255);//yellow signal
			}

			else if (tcol == 'y')
			{
				drawEllipse(w - 625, h - 442.5, w - 655, h - 477.5, 255, 255, 0, 255, 255, 0);//yellow signal
				drawEllipse(w - 592.5, h - 442.5, w - 622.5, h - 477.5, 255, 0, 0, 255, 255, 255);//red signal
				drawEllipse(w - 657.5, h - 442.5, w - 687.5, h - 477.5, 0, 255, 0, 255, 255, 255);//green signal


			}
			else
			{
				drawEllipse(w - 657.5, h - 442.5, w - 687.5, h - 477.5, 0, 255, 0, 255, 255, 255);//green signal
				drawEllipse(w - 592.5, h - 442.5, w - 622.5, h - 477.5, 255, 0, 0, 255, 255, 255);//red signal
				drawEllipse(w - 625, h - 442.5, w - 655, h - 477.5, 255, 255, 0, 255, 255, 255);//yellow signal

			}
		}
		else if (x == 3)
		{
			col = tcol;

			if (tcol == 'r')
			{
				drawEllipse(w - 287.5, h - 442.5, w - 252.5, h - 472.5, 255, 0, 0, 255, 0, 0);//red signal
				drawEllipse(w - 287.5, h - 475, w - 252.5, h - 505, 255, 255, 0, 255, 255, 255);//yellow signal
				drawEllipse(w - 287.5, h - 507.5, w - 252.5, h - 537.5, 0, 255, 0, 255, 255, 255);//green signal //green signal size eror
			}
			

			else if (tcol == 'g')
			{
				drawEllipse(w - 287.5, h - 507.5, w - 252.5, h - 537.5, 0, 255, 0, 0, 255, 0);//green signal //green signal size eror
				drawEllipse(w - 287.5, h - 442.5, w - 252.5, h - 472.5, 255, 0, 0, 255, 255, 255);//red signal
				drawEllipse(w - 287.5, h - 475, w - 252.5, h - 505, 255, 255, 0, 255, 255, 255);//yellow signal
			}

			else if (tcol == 'y')
			{
				drawEllipse(w - 287.5, h - 475, w - 252.5, h - 505, 255, 255, 0, 255, 255, 0);//yellow signal
				drawEllipse(w - 287.5, h - 442.5, w - 252.5, h - 472.5, 255, 0, 0, 255, 255, 255);//red signal
				drawEllipse(w - 287.5, h - 507.5, w - 252.5, h - 537.5, 0, 255, 0, 255, 255, 255);//green signal 
			}
			else
			{
				drawEllipse(w - 287.5, h - 507.5, w - 252.5, h - 537.5, 0, 255, 0, 255, 255, 255);//green signal 
				drawEllipse(w - 287.5, h - 442.5, w - 252.5, h - 472.5, 255, 0, 0, 255, 255, 255);//red signal
				drawEllipse(w - 287.5, h - 475, w - 252.5, h - 505, 255, 255, 0, 255, 255, 255);//yellow signal

			}
		}

		else if (x == 4)
		{
			col = tcol;


			if (tcol == 'r')
			{
				drawEllipse(w - 287.5, h - 237.5, w - 257.5, h - 202.5, 255, 0, 0, 255, 0, 0);//red signal
				drawEllipse(w - 255, h - 237.5, w - 225, h - 202.5, 255, 255, 0, 255, 255, 255);//yellow signal
				drawEllipse(w - 222.5, h - 237.5, w - 192.5, h - 202.5, 0, 255, 0, 255, 255, 255);//green signal
			}
			
			else if (tcol == 'g')
			{
				drawEllipse(w - 222.5, h - 237.5, w - 192.5, h - 202.5, 0, 255, 0, 0, 255, 0);//green signal
				drawEllipse(w - 287.5, h - 237.5, w - 257.5, h - 202.5, 255, 0, 0, 255, 255, 255);//red signal
				drawEllipse(w - 255, h - 237.5, w - 225, h - 202.5, 255, 255, 0, 255, 255, 255);//yellow signal
			}

			else if (tcol == 'y')
			{
				drawEllipse(w - 255, h - 237.5, w - 225, h - 202.5, 255, 255, 0, 255, 255, 0);//yellow signal
				drawEllipse(w - 222.5, h - 237.5, w - 192.5, h - 202.5, 0, 255, 0, 255, 255, 255);//green signal
				drawEllipse(w - 287.5, h - 237.5, w - 257.5, h - 202.5, 255, 0, 0, 255, 255, 255);//red signal

			}
			else
			{
				drawEllipse(w - 287.5, h - 237.5, w - 257.5, h - 202.5, 255, 0, 0, 255, 255, 255);//red signal
				drawEllipse(w - 222.5, h - 237.5, w - 192.5, h - 202.5, 0, 255, 0, 255, 255, 255);//green signal
				drawEllipse(w - 255, h - 237.5, w - 225, h - 202.5, 255, 255, 0, 255, 255, 255);//yellow signal

			}
		}
	}
	char getc() { return col; }
	

};

class inters
{
protected:

	//4 roads and trafic signals on an intersection controled  by intersection 
	road rd1;
	road rd2;
	road rd3;
	road rd4;

	
	trafics tfs1;
	trafics tfs2;
	trafics tfs3;
	trafics tfs4;

public:

	inters()  :rd1(1), rd2(2), rd3(3), rd4(4), tfs1(1), tfs2(2), tfs3(3), tfs4(4)//creates the basic structure.
	{
		
		drawRectangle(0, 0, w, h, 255, 0, 255, 0, 255, 255);//Background blue color

		//300*250
		drawRectangle(0, 0, w - 580, h - 430, 0, 0, 255, 0, 255, 0); //top  left
		drawRectangle(0, h, w - 580, h - 250, 0, 0, 255, 0, 255, 0); //bottom right
		drawRectangle(w, 0, w - 300, h - 430, 0, 0, 255, 0, 255, 0); //top right
		drawRectangle(w, h, w - 300, h - 250, 0, 0, 255, 0, 255, 0); //bottom left

		//300*15
		drawRectangle((w - (w / 2)) - 7, 0, (w - (w / 2)) + 8, h - 430, 150, 150, 150, 40, 40, 40);//line in the centre of road n-s
		drawRectangle(0, (h - (h / 2)) - 7, w - 580, (h - (h / 2)) + 8, 150, 150, 150, 40, 40, 40);//line in the centre of road w-e
		drawRectangle((w - (w / 2)) - 7, h, (w - (w / 2)) + 8, h - 250, 150, 150, 150, 40, 40, 40);//line in the centre of road s-n
		drawRectangle(w, (h - (h / 2)) - 7, w - 300, (h - (h / 2)) + 8, 150, 150, 150, 40, 40, 40);//line in the centre of road e-w



		//top left indicator
		drawRectangle(w - 590, h - 440, w - 690, h - 480, 10, 10, 10, 0, 128, 128);// indictaor box
		drawEllipse(w - 592.5, h - 442.5, w - 622.5, h - 477.5, 255, 0, 0, 255, 255, 255);//red signal
		drawEllipse(w - 625, h - 442.5, w - 655, h - 477.5, 255, 255, 0, 255, 255, 255);//yellow signal
		drawEllipse(w - 657.5, h - 442.5, w - 687.5, h - 477.5, 0, 255, 0, 255, 255, 255);//green signal


		//bottom left
		drawRectangle(w - 590, h - 240, w - 630, h - 140, 10, 10, 10, 0, 128, 128);
		drawEllipse(w - 592.5, h - 237.5, w - 627.5, h - 207.5, 255, 0, 0, 255, 255, 255);//red signal
		drawEllipse(w - 592.5, h - 205, w - 627.5, h - 175, 255, 255, 0, 255, 255, 255);//yellow signal
		drawEllipse(w - 592.5, h - 172.5, w - 627.5, h - 142.5, 0, 255, 0, 255, 255, 255);//green signal

		//top right
		drawRectangle(w - 290, h - 440, w - 250, h - 540, 10, 10, 10, 0, 128, 128);//top left
		drawEllipse(w - 287.5, h - 442.5, w - 252.5, h - 472.5, 255, 0, 0, 255, 255, 255);//red signal
		drawEllipse(w - 287.5, h - 475, w - 252.5, h - 505, 255, 255, 0, 255, 255, 255);//yellow signal
		drawEllipse(w - 287.5, h - 507.5, w - 252.5, h - 537.5, 0, 255, 0, 255, 255, 255);//green signal //green signal size eror


		//bottom right
		drawRectangle(w - 290, h - 240, w - 190, h - 200, 10, 10, 10, 0, 128, 128);
		drawEllipse(w - 287.5, h - 237.5, w - 257.5, h - 202.5, 255, 0, 0, 255, 255, 255);//red signal
		drawEllipse(w - 255, h - 237.5, w - 225, h - 202.5, 255, 255, 0, 255, 255, 255);//yellow signal
		drawEllipse(w - 222.5, h - 237.5, w - 192.5, h - 202.5, 0, 255, 0, 255, 255, 255);//green signal


	}
	void settfs1(char c)
	{
		tfs1.setc(c);
	}
	void settfs2(char c)
	{
		tfs2.setc(c);
	}
	void settfs3(char c)
	{
		tfs3.setc(c);
	}
	void settfs4(char c)
	{
		tfs4.setc(c);
	}
	char gettfs1() { return tfs1.getc(); }
	char gettfs2() { return tfs2.getc(); }
	char gettfs3() { return tfs3.getc(); }
	char gettfs4() { return tfs4.getc(); }

	

};


//abstract class 
class st
	:public inters
{
public:
	virtual void run() = 0;
};
//inherited classes from abstract class
class st2v2
	: public st
{
public:
	void run()//overriden function
	{

		vehicle* vehr1;
		vehicle* vehr2;
		vehicle* vehr3;
		vehicle* vehr4;
		vehr1 = rd1.getveh();
		vehr2 = rd2.getveh();
		vehr3 = rd3.getveh();
		vehr4 = rd4.getveh();


		// sets green on opposite roads
		tfs1.setc('g');
		tfs2.setc('r');
		tfs3.setc('g');
		tfs4.setc('r');

		rd1.roadveh();
		rd2.roadveh();
		rd3.roadveh();
		rd4.roadveh();
		int k, l;
		
		for (int j = 0; j < 50; ++j)//let pass only those cars whose signal is green through intersection
		{
			for (int i = 0; i < rd1.getnov(); i++)
			{
				vehr1[i].setvx1(5, 1);
			}
			for (int i = 0; i < rd3.getnov(); i++)
			{
				vehr3[i].setvx1(5, 3);
			}
			k = 0, l = 0;

			for (int i = 0; i < rd2.getnov() && k == l; i++)
			{
				if (vehr2[i].getvy1() < 210)
				{
					vehr2[i].setvy1(5, 2);
					++k;
				}
				++l;

			}

			k = 0, l = 0;
			for (int i = 0; i < rd4.getnov() && k == l; i++)
			{
				if (vehr4[i].getvy1() > 470)
				{
					vehr4[i].setvy1(5, 4);
					++k;
				}
				++l;

			}
			delay(300);
		}


		int c = 0;

		//yellow light
		while (c < 5)
		{
			tfs1.setc('y');
			tfs2.setc('y');
			tfs3.setc('y');
			tfs4.setc('y');
			for (int j = 0; j < 5; ++j)
			{
				for (int i = 0; i < rd1.getnov(); i++)
				{
					if (vehr1[i].getvx1() > 300)
					{
						vehr1[i].setvx1(5, 1);
					}
				}
				for (int i = 0; i < rd3.getnov(); i++)
				{
					if (vehr3[i].getvx1() < 580)
					{
						vehr3[i].setvx1(5, 3);
					}
				}
				k = 0, l = 0;

				for (int i = 0; i < rd2.getnov() && k == l; i++)
				{
					if (vehr2[i].getvy1() < 210)
					{
						vehr2[i].setvy1(5, 2);
						++k;
					}
					++l;

				}

				k = 0, l = 0;
				for (int i = 0; i < rd4.getnov() && k == l; i++)
				{
					if (vehr4[i].getvy1() > 470)
					{
						vehr4[i].setvy1(5, 4);
						++k;
					}
					++l;

				}

				delay(100);
			}
			//blinks the yellow light
			tfs1.setc('d');
			tfs2.setc('d');
			tfs3.setc('d');
			tfs4.setc('d');
			for (int j = 0; j < 5; ++j)
			{
				for (int i = 0; i < rd1.getnov(); i++)
				{
					if (vehr1[i].getvx1() > 300)
					{
						vehr1[i].setvx1(5, 1);
					}
				}
				for (int i = 0; i < rd3.getnov(); i++)
				{
					if (vehr3[i].getvx1() < 580)
					{
						vehr3[i].setvx1(5, 3);
					}
				}
				k = 0, l = 0;

				for (int i = 0; i < rd2.getnov() && k == l; i++)
				{
					if (vehr2[i].getvy1() < 210)
					{
						vehr2[i].setvy1(5, 2);
						++k;
					}
					++l;
				}

				k = 0, l = 0;
				for (int i = 0; i < rd4.getnov() && k == l; i++)
				{
					if (vehr4[i].getvy1() > 470)
					{
						vehr4[i].setvy1(5, 4);
						++k;
					}
					++l;
				}
				delay(100);
			}
			++c;
		}
		tfs1.setc('r');
		tfs2.setc('g');
		tfs3.setc('r');
		tfs4.setc('g');

		for (int j = 0; j < 50; ++j)
		{

			for (int i = 0; i < rd2.getnov(); i++)
			{
				vehr2[i].setvy1(5, 2);
			}
			for (int i = 0; i < rd4.getnov(); i++)
			{
				vehr4[i].setvy1(5, 4);

			}
			for (int i = 0; i < rd1.getnov(); i++)
			{
				if (vehr1[i].getvx1() > 300)
				{
					vehr1[i].setvx1(5, 1);
				}
			}
			for (int i = 0; i < rd3.getnov(); i++)
			{
				if (vehr3[i].getvx1() < 580)
				{
					vehr3[i].setvx1(5, 3);
				}
			}
			delay(300);
		}

		c = 0;
		while (c < 5)
		{
			//yellow light

			tfs1.setc('y');
			tfs2.setc('y');
			tfs3.setc('y');
			tfs4.setc('y');

			for (int j = 0; j < 5; ++j)
			{

				for (int i = 0; i < rd2.getnov(); i++)
				{
					if (vehr2[i].getvy1() > 250)
					{
						vehr2[i].setvy1(5, 2);
					}
				}
				for (int i = 0; i < rd4.getnov(); i++)
				{
					if (vehr4[i].getvy1() < 430)
					{
						vehr4[i].setvy1(5, 4);
					}
				}
				for (int i = 0; i < rd1.getnov(); i++)
				{
					if (vehr1[i].getvx1() > 300)
					{
						vehr1[i].setvx1(5, 1);
					}
				}
				for (int i = 0; i < rd3.getnov(); i++)
				{
					if (vehr3[i].getvx1() < 580)
					{
						vehr3[i].setvx1(5, 3);
					}
				}
				delay(100);
			}
			//delay(500);
			tfs2.setc('d');
			tfs3.setc('d');
			//blinks the light
			for (int j = 0; j < 5; ++j)
			{
				for (int i = 0; i < rd2.getnov(); i++)
				{
					if (vehr2[i].getvy1() > 250)
					{
						vehr2[i].setvy1(5, 2);
					}
				}
				for (int i = 0; i < rd4.getnov(); i++)
				{
					if (vehr4[i].getvy1() < 430)
					{
						vehr4[i].setvy1(5, 4);
					}
				}
				for (int i = 0; i < rd1.getnov(); i++)
				{
					if (vehr1[i].getvx1() > 300)
					{
						vehr1[i].setvx1(5, 1);
					}
				}
				for (int i = 0; i < rd3.getnov(); i++)
				{
					if (vehr3[i].getvx1() < 580)
					{
						vehr3[i].setvx1(5, 3);
					}
				}
				delay(100);
			}
			++c;
		}

		delete[]vehr1;
		delete[]vehr2;
		delete[]vehr3;
		delete[]vehr4;


	}
};
//inherited class from absrtract one(st)
class st1v1
	:public st
{
public:
	void run()//this function will let open signal one by one
	{

		vehicle* vehr1;
		vehicle* vehr2;
		vehicle* vehr3;
		vehicle* vehr4;
		vehr1 = rd1.getveh();
		vehr2 = rd2.getveh();
		vehr3 = rd3.getveh();
		vehr4 = rd4.getveh();

		tfs1.setc('g');
		tfs2.setc('r');
		tfs3.setc('r');
		tfs4.setc('r');

		rd1.roadveh();
		rd2.roadveh();
		rd3.roadveh();
		rd4.roadveh();
		int k = 0, l = 0;
		for (int j = 0; j < 50; ++j)
		{
			for (int i = 0; i < rd1.getnov(); i++)
			{
				vehr1[i].setvx1(5, 1);

			}
			k = 0, l = 0;

			for (int i = 0; i < rd2.getnov() && k == l; i++)
			{
				if (vehr2[i].getvy1() < 210)
				{
					vehr2[i].setvy1(5, 2);
					++k;
				}
				++l;

			}
			k = 0, l = 0;
			for (int i = 0; i < rd3.getnov() && k == l; i++)
			{
				if (vehr3[i].getvx1() > 620)
				{
					vehr3[i].setvx1(5, 3);
					++k;
				}
				++l;

			}
			k = 0, l = 0;
			for (int i = 0; i < rd4.getnov() && k == l; i++)
			{
				if (vehr4[i].getvy1() > 470)
				{
					vehr4[i].setvy1(5, 4);
					++k;
				}
				++l;

			}
			delay(300);
		}





		int c = 0;
		while (c < 5)
		{
			tfs1.setc('y');
			tfs2.setc('y');
			tfs3.setc('r');
			tfs4.setc('r');
			for (int j = 0; j < 5; ++j)
			{
				for (int i = 0; i < rd1.getnov(); i++)
				{
					if (vehr1[i].getvx1() > 300)
					{
						vehr1[i].setvx1(5, 1);
					}

				}
				k = 0, l = 0;

				for (int i = 0; i < rd2.getnov() && k == l; i++)
				{
					if (vehr2[i].getvy1() < 210)
					{
						vehr2[i].setvy1(5, 2);
						++k;
					}
					++l;

				}
				k = 0, l = 0;
				for (int i = 0; i < rd3.getnov() && k == l; i++)
				{
					if (vehr3[i].getvx1() > 620)
					{
						vehr3[i].setvx1(5, 3);
						++k;
					}
					++l;

				}
				k = 0, l = 0;
				for (int i = 0; i < rd4.getnov() && k == l; i++)
				{
					if (vehr4[i].getvy1() > 470)
					{
						vehr4[i].setvy1(5, 4);
						++k;
					}
					++l;

				}
				delay(100);
			}
			tfs1.setc('d');
			tfs2.setc('d');
			for (int j = 0; j < 5; ++j)
			{
				for (int i = 0; i < rd1.getnov(); i++)
				{
					if (vehr1[i].getvx1() > 300)
					{
						vehr1[i].setvx1(5, 1);
					}

				}
				k = 0, l = 0;
				for (int i = 0; i < rd2.getnov() && k == l; i++)
				{
					if (vehr2[i].getvy1() < 210)
					{
						vehr2[i].setvy1(5, 2);
						++k;
					}
					++l;
				}
				k = 0, l = 0;
				for (int i = 0; i < rd3.getnov() && k == l; i++)
				{
					if (vehr3[i].getvx1() > 620)
					{
						vehr3[i].setvx1(5, 3);
						++k;
					}
					++l;

				}
				k = 0, l = 0;
				for (int i = 0; i < rd4.getnov() && k == l; i++)
				{
					if (vehr4[i].getvy1() > 470)
					{
						vehr4[i].setvy1(5, 4);
						++k;
					}
					++l;

				}

				delay(100);
			}
			++c;
		}
		tfs1.setc('r');
		tfs2.setc('g');
		tfs3.setc('r');
		tfs4.setc('r');

		for (int j = 0; j < 50; ++j)
		{
			for (int i = 0; i < rd1.getnov(); i++)
			{
				if (vehr1[i].getvx1() > 300)
				{
					vehr1[i].setvx1(5, 1);
				}

			}
			for (int i = 0; i < rd2.getnov(); i++)
			{
				vehr2[i].setvy1(5, 2);

			}
			delay(300);
		}

		c = 0;
		while (c < 5)
		{
			tfs1.setc('r');
			tfs2.setc('y');
			tfs3.setc('y');
			tfs4.setc('r');

			for (int j = 0; j < 5; ++j)
			{
				for (int i = 0; i < rd1.getnov(); i++)
				{
					if (vehr1[i].getvx1() > 300)
					{
						vehr1[i].setvx1(5, 1);
					}

				}
				for (int i = 0; i < rd2.getnov(); i++)
				{
					if (vehr2[i].getvy1() > 250)
					{
						vehr2[i].setvy1(5, 2);
					}

				}
				delay(100);
			}
			tfs2.setc('d');
			tfs3.setc('d');
			for (int j = 0; j < 5; ++j)
			{
				for (int i = 0; i < rd1.getnov(); i++)
				{
					if (vehr1[i].getvx1() > 300)
					{
						vehr1[i].setvx1(5, 1);
					}

				}
				for (int i = 0; i < rd2.getnov(); i++)
				{
					if (vehr2[i].getvy1() > 250)
					{
						vehr2[i].setvy1(5, 2);
					}

				}
				delay(100);
			}
			++c;
		}
		tfs1.setc('r');
		tfs2.setc('r');
		tfs3.setc('g');
		tfs4.setc('r');

		for (int j = 0; j < 50; ++j)
		{
			for (int i = 0; i < rd1.getnov(); i++)
			{
				if (vehr1[i].getvx1() > 300)
				{
					vehr1[i].setvx1(5, 1);
				}

			}
			for (int i = 0; i < rd2.getnov(); i++)
			{
				if (vehr2[i].getvy1() > 250)
				{
					vehr2[i].setvy1(5, 2);
				}

			}
			for (int i = 0; i < rd3.getnov(); i++)
			{
				vehr3[i].setvx1(5, 3);


			}

			delay(300);
		}




		c = 0;
		while (c < 5)
		{
			tfs1.setc('r');
			tfs2.setc('r');
			tfs3.setc('y');
			tfs4.setc('y');
			for (int j = 0; j < 5; ++j)
			{
				for (int i = 0; i < rd1.getnov(); i++)
				{
					if (vehr1[i].getvx1() > 300)
					{
						vehr1[i].setvx1(5, 1);
					}

				}
				for (int i = 0; i < rd2.getnov(); i++)
				{
					if (vehr2[i].getvy1() > 250)
					{
						vehr2[i].setvy1(5, 2);
					}

				}
				for (int i = 0; i < rd3.getnov(); i++)
				{
					if (vehr3[i].getvx1() < 580)

					{
						vehr3[i].setvx1(5, 3);

					}


				}
				delay(100);
			}
			tfs3.setc('d');
			tfs4.setc('d');

			for (int j = 0; j < 5; ++j)
			{
				for (int i = 0; i < rd1.getnov(); i++)
				{
					if (vehr1[i].getvx1() > 300)
					{
						vehr1[i].setvx1(5, 1);
					}

				}
				for (int i = 0; i < rd2.getnov(); i++)
				{
					if (vehr2[i].getvy1() > 250)
					{
						vehr2[i].setvy1(5, 2);
					}

				}
				for (int i = 0; i < rd3.getnov(); i++)
				{
					if (vehr3[i].getvx1() < 580)

					{
						vehr3[i].setvx1(5, 3);

					}


				}
				delay(100);
			}
			++c;
		}
		tfs1.setc('r');
		tfs2.setc('r');
		tfs3.setc('r');
		tfs4.setc('g');


		for (int j = 0; j < 50; ++j)
		{
			for (int i = 0; i < rd1.getnov(); i++)
			{
				if (vehr1[i].getvx1() > 300)
				{
					vehr1[i].setvx1(5, 1);
				}

			}
			for (int i = 0; i < rd2.getnov(); i++)
			{
				if (vehr2[i].getvy1() > 250)
				{
					vehr2[i].setvy1(5, 2);
				}

			}
			for (int i = 0; i < rd3.getnov(); i++)
			{
				if (vehr3[i].getvx1() < 580)
				{
					vehr3[i].setvx1(5, 3);
				}
			}

			for (int i = 0; i < rd4.getnov(); i++)
			{
				vehr4[i].setvy1(5, 4);

			}


			delay(300);
		}
		c = 0;
		while (c < 5)
		{
			tfs1.setc('y');
			tfs2.setc('r');
			tfs3.setc('r');
			tfs4.setc('y');
			for (int j = 0; j < 5; ++j)
			{
				for (int i = 0; i < rd1.getnov(); i++)
				{
					if (vehr1[i].getvx1() > 300)
					{
						vehr1[i].setvx1(5, 1);
					}

				}
				for (int i = 0; i < rd2.getnov(); i++)
				{
					if (vehr2[i].getvy1() > 250)
					{
						vehr2[i].setvy1(5, 2);
					}

				}
				for (int i = 0; i < rd3.getnov(); i++)
				{
					if (vehr3[i].getvx1() < 580)
					{
						vehr3[i].setvx1(5, 3);
					}
				}

				for (int i = 0; i < rd4.getnov(); i++)
				{
					if (vehr4[i].getvy1() < 430)
					{
						vehr4[i].setvy1(5, 4);

					}

				}


				delay(100);
			}
			tfs1.setc('d');
			tfs4.setc('d');
			for (int j = 0; j < 5; ++j)
			{
				for (int i = 0; i < rd1.getnov(); i++)
				{
					if (vehr1[i].getvx1() > 300)
					{
						vehr1[i].setvx1(5, 1);
					}

				}
				for (int i = 0; i < rd2.getnov(); i++)
				{
					if (vehr2[i].getvy1() > 250)
					{
						vehr2[i].setvy1(5, 2);
					}

				}
				for (int i = 0; i < rd3.getnov(); i++)
				{
					if (vehr3[i].getvx1() < 580)
					{
						vehr3[i].setvx1(5, 3);
					}
				}

				for (int i = 0; i < rd4.getnov(); i++)
				{
					if (vehr4[i].getvy1() < 430)
					{
						vehr4[i].setvy1(5, 4);

					}

				}


				delay(100);
			}
			++c;
		}
		delete[]vehr1;
		delete[]vehr2;
		delete[]vehr3;
		delete[]vehr4;


	}
};

int main()
{

	w = 0;
	h = 0;
	getWindowDimensions(w, h);
	h += 200;
	
	cls();
	showConsoleCursor(false);

	st* strat ;//pointer of abstract class
	cout << "Entre\n"
		<< "1 for 1-by-1 strategy\n"
		<< "2 for 2-by-2 strategy\n";
	int w;
	cin >> w;
	if (w == 1)
	{
		system("cls");
		strat = new st1v1;//stores the data of child class with specified strategy(1-by-1)
		strat->run();//implements the selected strategy

	}
	else if (w == 2)
	{
		system("cls");
		strat = new st2v2;//stores the data of child class with specified strategy(2-by-2)
		strat->run();//implements the selected strategy

	}
}
