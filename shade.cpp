#include "iostream"
#include "math.h"
#include "stdlib.h"
#include "stdio.h"
#define PI 3.1415926
#define M 1000000
using namespace std;
double x, y, degree, xi[1000], yi[1000], zi[1000], ri[1000], xx, yy; int num, n; long m, mm;
double distance(double x1, double y1, double x2, double y2)
{
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}
int panduan(double x1, double y1)
{
	int kai;
	kai = 1;
	for (n = 0; n<num; n++)
	{
		if (distance(x1, y1, xi[n], yi[n])<ri[n]) { kai = 0; break; }
	}
	return kai;
}
int main()
{
	/*
	for(n=0;n<10;n++)
	{
	cout<<double(rand())/100000<<endl;
	}*/
	cin >> x; cin >> y; cin >> degree; cin >> num;
	degree = degree / 180 * PI;
	for (n = 0; n<num; n++)
	{
		cin >> xi[n]; cin >> yi[n]; cin >> zi[n]; cin >> ri[n]; xi[n] = xi[n] + zi[n] / tan(degree);
	}
	mm = 0;
	for (m = 0; m<M; m++)
	{
		xx = rand() % int(x) + double(rand()) / 100000;
		yy = rand() % int(y) + double(rand()) / 100000;
		if (panduan(xx, yy)) mm++;
	}
	//cout<<x*y*mm/M<<endl;
	printf("%.2f", x*y*mm / M);

	int tmpp;
	cin >> tmpp;
		return 0;
}