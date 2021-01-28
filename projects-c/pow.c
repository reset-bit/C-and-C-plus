double my_pow(double x, double y)
{
	register double ret, value;
    double r = 1.0;
	long p = (long) y;
	if (x == 0.0 && y > 0.0)
		return 0.0;
	if (y == (double) p)
	{
		if (p == 0)
			return 1.0;
		if (p < 0)
		{
			p = -p;
			x = 1.0 / x;
		}
		while (1)
		{
			if (p & 1)
				r *= x;
			p >>= 1;
			if (p == 0)
				return r;
			x *= x;
		}

	}

	 __asm__
	(
		"fmul %%st(1);"
		fst %%st(1);"
		"frndint;/n/t"
		"fxch;/n/t"
		"fsub %%st(1);/n/t"
		f2xm1;/n/t"
		 "=t" (ret), "=u" (value)
		: "0" (log2 (x)), "1" (y)
	);
	ret += 1.0;
	__asm__
	(
		"fscale"
		: "=t" (ret)
		: "0" (ret), "u" (value)
	);

 return ret;

}

//����һ����x��y���ݵĺ�������ΪҪ���Ǹ��������͵ģ����Դ��븴������ࡣ

//�����������������x��y���ݣ���ô�ͼ�����ࡣ

int main()

{
	printf("%f/n",my_pow(0.0,0.0));
	printf("%f/n",my_pow(1024.0,0.0));
	printf("%f/n",my_pow(2.0,10.0));
	printf("%f/n",pow(2.5,12.6));
	printf("%f/n",my_pow(2.5,12.6));
	system("pause");
	return 0;
}
