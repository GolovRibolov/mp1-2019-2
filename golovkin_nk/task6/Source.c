#define _USE_MATH_DEFINES
#define N 25

#include <stdio.h>
#include <math.h>
#include <locale.h>

int viberite_rezim()
{
	int a;
	printf("�������� ������ ��� �����\n");
	printf("1 - ����������� ������ ������� � �������� �����\n");
	printf("2 - �������� �����������");
	scanf_s("%i", &a);
	return a;
}
int viberite_fynkciy()
{
	int a;
	printf("�������� �������\n");
	printf("1 - sin(x)\n");
	printf("2 - cos(x)\n");
	printf("3 - exp(x)\n");
	printf("4 - sinh(x)\n");
	scanf_s("%i", &a);
	return a;
}
/////////////////////////////////////////////////////////////////////////////////////
void sinysik(double x, float E, int k)
{
	int i;
	double sin_c = sin(x), func = x, delta = fabs(sin_c - func), term = x;
	for (i = 2; (i <= k) && (delta >= E); i++)
	{
		term = (-1) * term * x * x / ((2 * i - 1) * (2 * i - 2));
		func = func + term;
		delta = fabs(sin_c - func);
	}
	printf("%16d   %26.7lf   %32.6lf\n", i - 1, func, delta);
}
//////////////////////////////////////////////////////////////////////////////////////
void cosinysik(double x, float E, int k)
{
	int i;

	double cos_c = cos(x), func = 1, delta = fabs(cos_c - func), term = 1;
	for (i = 2; (i <= k) && (delta >= E); i++)
	{
		term = (-1) * term * x * x / ((2 * i - 2) * (2 * i - 3));
		func = func + term;
		delta = fabs(cos_c - func);
	}
	printf("%16d   %26.7lf   %32.6lf\n", i - 1, func, delta);
}
////////////////////////////////////////////////////////////////////////////////////////
void exponentik(double x, float E, int k)
{
	int i;
	double exp_c = exp(x), func = 1, delta = fabs(exp_c - func), term = 1;
	for (i = 2; (i <= k) && (delta >= E); i++)
	{
		term = term * x / (i - 1);
		func = func + term;
		delta = fabs(exp_c - func);
	}
	printf("%16d   %26.7lf   %32.6lf\n", i - 1, func, delta);
}
//////////////////////////////////////////////////////////////////////////////////////
void gipersinysik(double x, float E, int k)
{
	int i;
	double sh_c = sinh(x), func = x, delta = fabs(sh_c - func), term = x;
	for (i = 2; (i <= k) && (delta >= E); i++)
	{
		term = term * x * x / ((2 * i - 1) * (2 * i - 2));
		func = func + term;
		delta = fabs(sh_c - func);
	}
	printf("%16d   %26.7lf   %32.6lf\n", i - 1, func, delta);
}
/////////////////////////////////////////////////////////////////////////////////////
void perviy_rezim(void(*f)(double, float, int), double x, double func)
{
	float E;
	int k;
	printf("������� �������� ���������� (>= 0,000001)\n");
	scanf_s("%f", &E);
	printf("������� ���������� ��������� �� 1 �� 1000\n");
	scanf_s("%i", &k);
	printf("��������� ��������: %lf\n", func);
	printf("���-�� ���������   ����������� ������ �������   ������� ����� ������� � ��������\n");
	f(x, E, k);
}
////////////////////////////////////////////////////////////////////////////////////////
void vtoroy_rezim(void(*f)(double, float, int), double x, double func)
{
	float E[N];
	int k[N], opit, i;
	printf("������� ���������� ������������� �� 1 �� 25?\n");
	scanf_s("%i", &opit);
	for (i = 0; i < opit; i++)
	{
		printf("������� �������� ���������� (>= 0,000001) ��� %i-��� ������������\n", i + 1);
		scanf_s("%f", &E[i]);
		printf("������� ���������� ��������� �� 1 �� 1000 ��� %i-��� ������������\n", i + 1);
		scanf_s("%di", &k[i]);
	}
	printf("��������� ��������: %lf\n", func);
	printf("���-�� ���������   ����������� ������ �������   ������� ����� ������� � ��������\n");
	for (i = 0; i < k[i]; i++)
		f(x, E[i], k[i]);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void main()
{
	setlocale(LC_ALL, "Rus");
	int n, regime;
	void(*f)(double, float, int) = NULL;
	double x, func;
	regime = viberite_rezim();
	n = viberite_fynkciy();
	printf("������� x\n");
	scanf_s("%lf", &x);
	switch (n)
	{
	case 1:
		f = sinysik;
		x = x / 180 * M_PI;
		func = sin(x);
		break;
	case 2:
		f = cosinysik;
		x = x / 180 * M_PI;
		func = cos(x);
		break;
	case 3:
		f = exponentik;
		func = exp(x);
		break;
	case 4:
		f = gipersinysik;
		func = sinh(x);
		break;
	}
	if (regime == 1)
		perviy_rezim(f, x, func);
	else
		vtoroy_rezim(f, x, func);
	system("pause");
}