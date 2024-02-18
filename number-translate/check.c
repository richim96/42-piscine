#include <unistd.h>
//#include <stdio.h>

char	*ft_find_word(char ***dict, int n_keys, char *to_find);

/* Checks the first digit of the triple */
int	ft_first_digit_check(char ***dict, char *digits, int n_keys)
{
	char	tmp_digit[2];

	if (digits[0] == '0')
		return (0);
	tmp_digit[0] = digits[0];
	tmp_digit[1] = '\0';
	if (ft_find_word(dict, n_keys, tmp_digit) == NULL)
		return (1);
	return (0);
}

/* Checks second digit of the triple */
int	ft_second_digit_check(char ***dict, char *digits, int n_keys)
{
	char	tmp_digit[3];

	if (digits[1] == '0')
		return (0);
	tmp_digit[0] = digits[1];
	if (tmp_digit[0] == '1')
		tmp_digit[1] = digits[2];
	else
		tmp_digit[1] = '0';
	tmp_digit[2] = '\0';
	if (ft_find_word(dict, n_keys, tmp_digit) == NULL)
		return (1);
	return (0);
}

/* Checks the third and last digit of the triple */
int	ft_third_digit_check(char ***dict, char *digits, int n_keys)
{
	char	tmp_digit[2];
	char	*word;

	if (digits[2] == '0' || digits[1] == '1')
		return (0);
	tmp_digit[0] = digits[2];
	tmp_digit[1] = '\0';
	if (ft_find_word(dict, n_keys, tmp_digit) == NULL)
		return (1);
	return (0);
}

/* Checks number classifier */
int	ft_classifiers_check(int n, char ***dict, int n_keys)
{
	int		i;
	char	tmp_digit[500];
	char	*word;

	i = 1;
	tmp_digit[0] = '1';
	while (i <= n)
	{
		tmp_digit[i] = '0';
		i++;
	}
	tmp_digit[i] = '\0';
	if (ft_find_word(dict, n_keys, tmp_digit) == NULL)
		return (1);
	return (0);
}


/*DELETE!!
int	main(void)
{
	char	input[] = "143";
	char	*dict0[2] = {"1", "one"};
	char	*dict1[2] = {"100", "hundred"};
	char	*dict2[2] = {"20", "twenty"};
	char	*dict3[2] = {"3", "three"};
	char	*dict4[2] = {"1000", "thousand"};
	char	**dict[5] = {dict0, dict1, dict2, dict3, dict4};

	printf("%d\n", ft_first_digit_check(dict, input, 5));
	printf("%d\n", ft_second_digit_check(dict, input, 5));
	printf("%d\n", ft_third_digit_check(dict, input, 5));
	printf("%d\n", ft_classifiers_check(3, dict, 5));
}
*/
