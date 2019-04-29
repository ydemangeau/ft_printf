#include "../include/printf.h"

int		main()
{
	printf("hello%3.5dtest%.4d\n",15,-5);
	ft_printf("hello%3.5dtest%.4d\n",15,-5);
	printf("hello%5.3dtest%.4d\n",15,-5);
	ft_printf("hello%5.3dtest%.4d\n",15,-5);
	printf("hello%+10.5dtest%.4d\n",15,-5);
	ft_printf("hello%+10.5dtest%.4d\n",15,-5);
	printf("hello%10.5dtest%.4d\n",15,-5);
	ft_printf("hello%10.5dtest%.4d\n",15,-5);
	printf("%+10dtest%ld\n",-15,(long int)500);
	ft_printf("%+10dtest%ld\n",-15,(long int)500);
	printf("%+010dtest%ld\n",15,(long int)500);
	ft_printf("%+010dtest%ld\n",15,(long int)500);
	printf("%+0dtest%ld\n",15,(long int)500);
	ft_printf("%+0dtest%ld\n",15,(long int)500);
	printf("%-5dtest%ld\n",15,(long int)500);
	ft_printf("%-5dtest%ld\n",15,(long int)500);
	printf("%+-5dtest%ld\n",15,(long int)500);
	ft_printf("%+-5dtest%ld\n",15,(long int)500);
	printf("%+-5.3dtest%ld\n",15,(long int)500);
	ft_printf("%+-5.3dtest%ld\n",15,(long int)500);
	printf("%+-5.3dtest%ld\n",15,(long int)500);
	ft_printf("%+-5.3dtest%ld\n",15,(long int)500);
	printf("%dtest%lld\n",15,(long long)500);
	ft_printf("%dtest%lld\n",15,(long long)500);

	
	printf("%utest\n",-15);
	ft_printf("%utest\n",-15);
	printf("%utest\n",15);
	ft_printf("%utest\n",15);
	printf("%utest\n",15);
	ft_printf("%utest\n",15);

	printf("%5utest\n",1500);
	ft_printf("%5utest\n",1500);
	printf("%5utest\n",-1500);
	ft_printf("%5utest\n",-1500);
	//printf("%+utest\n",1500);
	//ft_printf("%+utest\n",1500);
	//printf("% utest\n",1500);
	//ft_printf("% utest\n",1500);
	printf("%-utest\n",1500);
	ft_printf("%-utest\n",1500);
	printf("%-utest\n",-15);
	ft_printf("%-utest\n",-15);
	printf("%-7utest\n",-1500);
	ft_printf("%-7utest\n",-1500);

	printf("%o\n",7);
	ft_printf("%o\n",7);
	printf("%o\n",8);
	ft_printf("%o\n",8);
	printf("%o\n",9);
	ft_printf("%o\n",9);
	printf("%o\n",10);
	ft_printf("%o\n",10);
	printf("%o\n",74);
	ft_printf("%o\n",74);
	printf("%o\n",-74);
	ft_printf("%o\n",-74);

	printf("%05o\n",74);
	ft_printf("%05o\n",74);
	printf("%5o\n",74);
	ft_printf("%5o\n",74);
	printf("%-5o\n",74);
	ft_printf("%-5o\n",74);

	printf("%#5o\n",74);
	ft_printf("%#5o\n",74);

	printf("%x\n",42);
	ft_printf("%x\n",42);
	printf("%X\n",-42);
	ft_printf("%X\n",-42);
	printf("%#x\n",42);
	ft_printf("%#x\n",42);
	printf("%#X\n",42);
	ft_printf("%#X\n",42);
	printf("%#5X\n",-4861);
	ft_printf("%#5X\n",-4861);
	printf("%#05X\n",42);
	ft_printf("%#05X\n",42);
	printf("%05X\n",42);
	ft_printf("%05X\n",42);
	printf("%5.7X\n",452);
	ft_printf("%5.7X\n",452);
	printf("%7.5x\n",452);
	ft_printf("%7.5x\n",452);
	//ft_printf("%x\n",7,4);
	printf("%hx\n",-42);
	ft_printf("%hx\n",-42);
	
	printf("str =%s\n","test");
	ft_printf("str =%s\n","test");
	printf("str =%.0s\n","test");
	ft_printf("str =%.0s\n","test");

	printf("str =%.2s\n","test");
	ft_printf("str =%.2s\n","test");
	printf("str =%2s\n","test");
	ft_printf("str =%2s\n","test");
	//printf("str = %+s\n","test");
	printf("str =%-7s\n","test");
	ft_printf("str =%-7s\n","test");
	//printf("str = %0s\n","test");
	//printf("str = %#s\n","test");
	printf("str =%7s\n","test");
	ft_printf("str =%7s\n","test");
	printf("str =%.5s\n","test");
	ft_printf("str =%.5s\n","test");
	printf("str =%5.6s\n","test");
	ft_printf("str =%5.6s\n","test");
	printf("str =%6.3s\n","test");
	ft_printf("str =%6.3s\n","test");

	printf("c =%c\n", 'a');
	ft_printf("c =%c\n", 'a');
	printf("c =%5c\n", 'a');
	ft_printf("c =%5c\n", 'a');
	
		printf("%llx\n",(long long int)-42);
	ft_printf("%llx\n",(long long int)-42);
	printf("%hx\n",(short int)42);
	ft_printf("%hx\n",(short int)42);
	printf("%lx\n",(long int)-42);
	ft_printf("%lx\n",(long int)-42);
	printf("%x\n",-42);
	ft_printf("%x\n",-42);

	printf("c =%p\n", (void *)42);
	ft_printf("c =%p\n", (void *)42);
	printf("c =%-15p\n", (void *)123);
	ft_printf("c =%-15p\n", (void *)123);
	printf("c =%15p\n", (void *)123);
	ft_printf("c =%15p\n\n", (void *)123);

	printf("%.2f\n",1.2);
	ft_printf("%.2f\n",1.2);
	printf("%6.2f\n",1.2);
	ft_printf("%6.2f\n",1.2);
	printf("%+.2f\n",1.2);
	ft_printf("%+.2f\n",1.2);
	printf("%+-8.2f\n",1.2);
	ft_printf("%+-8.2f\n",1.2);
	printf("% -8.2f\n",1.2);
	ft_printf("% -8.2f\n",1.2);
	printf("% 8.2f\n",1.2);
	ft_printf("% 8.2f\n",1.2);

	printf("%020.3f\n",1.2);
	ft_printf("%020.3f\n",1.2);
	printf("%020f\n",1.5);
	ft_printf("%020f\n",1.5);

	printf("%.f\n",1.2);
	ft_printf("%.f\n",1.2);
	printf("%f\n",-10.56);
	ft_printf("%f\n",-10.56);
	printf("%%\n");
	ft_printf("%%\n");
	
	printf("%020.3f\n",1.2);
	ft_printf("%020.3f\n",1.2);
	printf("f=%f\n",10.56);
	ft_printf("f=%f\n",10.56);
	char *str = NULL;
	printf("s= %s\n",str);
	ft_printf("s= %s\n",str);
	printf("c= %-5c\n",42);
	ft_printf("c= %-5c\n",42);
	printf("%x\n",0);
	ft_printf("%x\n",0);
	printf("%#x\n",0);
	ft_printf("%#x\n",0);
	//printf("%-05d\n",42);
	//ft_printf("%-05d\n",42);
	//printf("%#-08x\n",-42);
	//ft_printf("%#-08x\n",-42);
	printf("ok\n");
	printf("%-5.10o\n",2500);
	ft_printf("%-5.10o\n",2500);
	printf("%-5.10d\n",2500);
	ft_printf("%-5.10d\n",2500);
	
	printf("%5.10d\n",2500);
	ft_printf("%5.10d\n",2500);
	printf("%-10.5d\n",2500);
	ft_printf("%-10.5d\n",2500);
	printf("%-3.4d\n",2500);
	ft_printf("%-3.4d\n",2500);
	//printf("%#-08x\n",42);
	ft_printf("%#-08x\n",42);
	ft_printf("%\n",42);
	ft_printf("% hP%\n");
	ft_printf("% hZ%");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("% Z ", "test");
	ft_printf("\n");
	ft_printf("% Z%");
	ft_printf("\n");
	ft_printf("% Z%s");
return (0);
}


