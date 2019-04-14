#include "../include/printf.h"

int		main()
{
	//ft_printf("%dhello%dez%d\n",523,10,987);
	printf("HANDLE_INT\n");
	
	ft_printf("hello%+05.5dtest\n",5);
	printf("hello%+0dtest\n",5);
	ft_printf("hello%+0dtest\n",-5);
	printf("hello%+0dtest\n",-5);
	
	ft_printf("hello%ldtest\n",1);
	ft_printf("hello%+2.*lldtest\n",1,9);
	ft_printf("test = %s\n","hello");


	return (0);
}
