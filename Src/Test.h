#pragma once
/*
*  Copyright (c) Vahe Danielyan <danielyan.vahe@gmail.com>
*  12.12.2014 
*
*/

#include <iostream>
#include <math.h>
using namespace std;

struct cord
{
	int x, y;
};

#define pi 3.14
namespace program
{
	class Figure
	{
		friend std::istream& operator>>(std::istream& is, Figure &fig)
		{
			int x;
			std::cout << "Enter Number of Points:";
			is >> x;
			fig.setpionts(x);
			cout << "Enter Points X1,Y1 etc.." << endl;
			for (int i(0); i < x; i++)
			{
				is >> fig.Points[i].x >> fig.Points[i].y;
			}
			return is;
		}


		friend std::ostream& operator<<(std::ostream& os, Figure &fig)
		{
			if (!(fig.pointsflag))
				os << "Number of Points:" << fig.getpointsnum() << endl;
			os << "Points:" << endl;
			for (int i(0); i < fig.getpointsnum(); i++)
			{
				os  << "X:" <<  fig.Points[i].x << " " << "Y:" << fig.Points[i].y << endl;
			}
			return os;
		}
		private:
			cord* Points;
			int pointsnum;
			bool pointsflag;
		public:
			Figure()
			{
				
			}
			Figure(int pointsnum, cord *ptr)
			{
				Figure::pointsnum = pointsnum;
				pointsflag = true;
				Points = ptr;
			}
			~Figure()
			{
			};
			void setpionts(int a)
			{
				pointsnum = a;
				if (!pointsflag)
				{
					Points = new cord[a];
					pointsflag = true;
				}
				else
					return;
			}
			void setpointsvalues(cord* ptr)
			{
				if (pointsflag)
					Points = ptr;
				else
					cout << "Please Enter Amount of Points First:" << endl;
			}
			int getpointsnum()
			{
				return pointsnum;
			}
			double distance(int p1, int p2)
			{
				if (p1 < pointsnum && p2 < pointsnum)
					return sqrt(pow((Points[p1].x - Points[p2].x), 2) + pow((Points[p1].y - Points[p2].y), 2));
				else
					return -99999;
			}

	};

	class Geo_object
	{

		public:
			Geo_object()
			{

			};
			virtual double area()
			{
				return 0;
			};
			Figure Obj;
		private:
			
	};

	class Square : public Geo_object
	{

		friend std::istream& operator>>(std::istream& is, Square &Sq)
		{
			int a, b;
			cord ptr[4];
			cout << "Enter Points X1,Y1 etc.." << endl;
			for (int i = 0; i < 4; i++)
			{
				is >> a >> b;
				ptr[i].x = a;ptr[i].y = b;
			}
			Sq.Obj.setpointsvalues(ptr);
			return is;
		}
	public:
		Square()
		{
			Obj.setpionts(4);
		}
		~Square()
		{

		};
		Square(cord *ptr)
		{
			Obj.setpionts(4);
			Obj.setpointsvalues(ptr);
		};
		virtual double area()
		{
			side = Obj.distance(0, 1);
			return (double)side*side;
		}
		double ankyunagic()
		{
			return side * sqrt(2);
		}/* will be changed */

	private:
		double side;
	};

	class Circle : public  Geo_object
	{
		
		friend std::istream& operator>>(std::istream& is, Circle &Cq)
		{
			cord* a = new cord[1];
			cout << "Enter Center Coordinates:";
			is >> a[0].x >> a[0].y;
			Cq.Center.x = a[0].x;
			Cq.Center.y = a[0].y;
			Cq.Obj.setpointsvalues(a);
			cout << "Enter Radirus:";
			is >> Cq.rad;
			return is;
		}
	public:
		Circle()
		{
			Obj.setpionts(1);
		}
		double lenght()
		{
			return 2 * pi * rad;
		}
		virtual double area()
		{
			return pi * rad * rad;
		}
		void printhavasarum() /*I will change this ))*/
		{
			cout << rad*rad << "=" << "(x - " << Center.x << ")^2 + (y - " << Center.y << ")^2" << endl;
		}
	private:
		double rad;
		cord Center;
	};


}

