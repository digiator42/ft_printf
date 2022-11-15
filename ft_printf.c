#include "libft.h"
#include <stdarg.h>

char print_char(int c)
{
    write(1, &c,1);
    return 0;
}

int print_str(char *c)
{
    int i = 0;
    while(c[i])
    {
        write(1, &c[i],1);
        i++;
    }
    return i;
}
int    ft_printhex(char current, unsigned int c)
{
	int	prints;

	prints = 1;
	if (c >= 16)
		prints += ft_printhex(current, c / 16);
	c %= 16;
	if(current == 'X')
	    write(1, &"0123456789ABCDEF"[c], 1);
	else     
	    write(1, &"0123456789abcdef"[c], 1);
	return (prints);
}

int ft_format(va_list args,char previous, char current)
{
    int result;
    result = 0;

    if(current == 'd' || current == 'i')
            ft_putnbr_fd(va_arg(args, int), 1);
    else if(current == 'c')
        result += print_char(va_arg(args, int));
    else if(current == 'p'){
        result += print_str("0x");
        result += ft_printhex(current, va_arg(args, int));
    }
    else if(current == 's')
        result += print_str(va_arg(args, char *));
    else if(current == 'x' || current == 'X')
        result += ft_printhex(current, va_arg(args, int));
    else if(current == '\n'){
        print_str("%\n");
    }
    else
        result += print_char(previous);              
    return result;    

}

int ft_printf(char *input, ...)
{
    int result;
    int i;
    va_list args;

    va_start(args, input);
    i = 0;
    int j;
    result = 0;
    while (input[i])
    {
       if(input[i] == '%')
       {
            j = i;
            result += ft_format(args, input[j], input[++i]);
       }
       else
            result += print_char(input[i]);      
       i++;  
    }
    // print_char(input[i-1]);
    va_end(args);
    return result;
}

// int main()
// {
//     int *i = 0;
//     // ft_printf("%d\nMohamed Monier\n%c\n%s\n", -12312313, 'a', "OMGGGGGGG");
//     // write(1, "--------------------\n", 22);
//     // printf("%d\nMohamed Monier\n%c\n%s\n", -12312313, 'a', "OMGGGGGGG");

//     ft_printf("%%\nfdf\n%p\n%i\n%c\n%%s\n", 65021, 2, 'c', "dd");
//     write(1, "--------------------\n", 22);
//     printf("%%\nfdf\n%p\n%i\n%c\n%%s\n", 65021, 2, 'c', "dd");

//     //%\n new line is not printed
// }