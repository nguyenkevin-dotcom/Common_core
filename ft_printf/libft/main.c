/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevnguye <kevnguye@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:28:35 by kevnguye          #+#    #+#             */
/*   Updated: 2025/11/14 14:56:55 by kevnguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	str_ft_strlen[] = "mi bomboclat";
	char	str_memset[] = "Champions League";
	char	str_bzero[] = "Yabadabadoo";
	char	str_src_memcpy[] = "memcpy";
	char	str_dest_memcpy[6];
	char	str_src_memmove[] = "Ronaldo";
	char	str_dest_memmove[100] = "Messi";
	char	str_src_strlcpy[] = "aint no wai";
	char	str_dst_strlcpy[50];
	char	str_src_strlcat[] = "Verstappen";
	char	str_dst_strlcat[] = "Max";
	char	a_toupper = 'a';
	char	b_toupper = 'B';
	char	str_strchr[] = "Cucurella";
	
	printf("Testing my libft library");
	// ft_isalpha
	printf("\nft_isalpha:\n");
	printf("------------------------------------------\n");
	printf("Is \'A\' a letter?: %d\n", ft_isalpha('A'));
	printf("Is \'$\' a letter?: %d\n", ft_isalpha('$'));
	printf("------------------------------------------\n");
	printf("\n");
	// ft_isdigit
	printf("ft_isdigit:\n");
	printf("------------------------------------------\n");
	printf("Is 9 a digit?: %d\n", ft_isdigit(9));
	printf("Is A a digit?: %d\n", ft_isdigit('A'));
	printf("------------------------------------------\n");
	printf("\n");
	// ft_isalnum
	printf("ft_isalnum:\n");
	printf("------------------------------------------\n");
	printf("Is A a alnum?: %d\n", ft_isalnum('A'));
	printf("Is %% a alnum?: %d\n", ft_isalnum('%'));
	printf("Is 7 a alnum?: %d\n", ft_isalnum(7));
	printf("------------------------------------------\n");
	printf("\n");
	// ft_isascii
	printf("ft_isascii:\n");
	printf("------------------------------------------\n");
	printf("Is @ in ascii?: %d\n", ft_isascii('@'));
	printf("Is value 128 in ascii?: %d\n", ft_isascii(128));
	printf("------------------------------------------\n");
	printf("\n");
	// ft_isprint
	printf("ft_isprint:\n");
	printf("------------------------------------------\n");
	printf("Is * printable?: %d\n", ft_isprint('*'));
	printf("Is \'\\n\' printable?: %d\n", ft_isprint('\n'));
	printf("------------------------------------------\n");
	printf("\n");
	// ft_strlen
	printf("ft_strlen:\n");
	printf("------------------------------------------\n");
	printf("The length of \'mi bomboclat\' must be 12: %ld\n", ft_strlen(str_ft_strlen));
	printf("------------------------------------------\n");
	printf("\n");
	// ft_memset
	printf("ft_memset:\n");
	printf("------------------------------------------\n");
	printf("String before ft_memset(): %s\n", str_memset);
	ft_memset(str_memset, '#', 9);
	printf("String after ft_memset(): %s\n", str_memset);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_bzero
	printf("ft_bzero:\n");
	printf("------------------------------------------\n");
	printf("String before ft_bzero(): %s\n", str_bzero);
	ft_bzero(str_bzero, 5);
	printf("String after ft_bzero(): %s\n", str_bzero);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_memcpy
	printf("ft_memcpy:\n");
	printf("------------------------------------------\n");
	ft_memcpy(str_dest_memcpy, str_src_memcpy, 6);
	printf("String dest: %s\n", str_dest_memcpy);
	printf("String src: %s\n", str_src_memcpy);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_memmove
	printf("ft_memmove:\n");
	printf("------------------------------------------\n");
	printf("Dest before: %s\n", str_dest_memmove);
	ft_memmove(str_dest_memmove, str_src_memmove, 3);
	printf("Dest after: %s\n", str_dest_memmove);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_strlcpy
	printf("ft_strlcpy:\n");
	printf("------------------------------------------\n");
	int	a;

	a = ft_strlcpy(str_dst_strlcpy, str_src_strlcpy, 6);
	printf("Copied \'%s\' into \'%s\', length %d\n", str_src_strlcpy, str_dst_strlcpy, a);
	printf("------------------------------------------\n");
	printf("\n");
	// strlcat
	printf("ft_strlcat:\n");
	printf("------------------------------------------\n");
	int	b;

	b = ft_strlcat(str_dst_strlcat, str_src_strlcat, 9);
	printf("cat \'%s\' create \'%s\', length %d\n", str_src_strlcat, str_dst_strlcat, b);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_toupper
	printf("ft_toupper:\n");
	printf("------------------------------------------\n");
	printf("Letter before ft_toupper(): %c\n", a_toupper);
	printf("Letter after ft_toupper(): %c\n", ft_toupper(a_toupper));
	printf("\n");
	printf("Letter before ft_toupper(): %c\n", b_toupper);
	printf("Letter after ft_toupper(): %c\n", ft_toupper(b_toupper));
	printf("------------------------------------------\n");
	printf("\n");
	// ft_tolower
	printf("ft_tolower:\n");
	printf("------------------------------------------\n");
	printf("Letter before ft_tolower(): %c\n", a_toupper);
	printf("Letter after ft_tolower(): %c\n", ft_tolower(a_toupper));
	printf("\n");
	printf("Letter before ft_tolower(): %c\n", b_toupper);
	printf("Letter after ft_tolower(): %c\n", ft_tolower(b_toupper));
	printf("------------------------------------------\n");
	printf("\n");
	// ft_strchr
	printf("ft_strchr:\n");
	printf("------------------------------------------\n");
	const char	ch = 'l';
	char	*ret;
	
	ret = ft_strchr(str_strchr, ch);
	printf("String \'%s\' after \'%c\' is \'%s\'\n", str_strchr, ch, ret);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_strrchr
	printf("ft_strrchr:\n");
	printf("------------------------------------------\n");
	char	*retr;
	
	retr = ft_strrchr(str_strchr, ch);
	printf("String \'%s\' after \'%c\' is \'%s\'\n", str_strchr, ch, retr);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_strncmp
	printf("ft_strncmp:\n");
	printf("------------------------------------------\n");
	char	str_strncmp1[] = "ABC";
	char	str_strncmp2[] = "ABZ";
	int		diff;
	int		size = 6;
	
	diff = ft_strncmp(str_strncmp1, str_strncmp2, size);
	printf("String \'%s\' compared to \'%s\' on size %d -> the diff is: %d\n", str_strncmp1, str_strncmp2, size, diff);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_memchr
	printf("ft_memchr:\n");
	printf("------------------------------------------\n");
	char	*memchr_test;
	int		size_memchr = 7;
	
	memchr_test = ft_memchr(str_strchr, ch, size_memchr);
	printf("String \'%s\' after character \'%c\' and size %d is: %s\n", str_strchr, ch, size_memchr, memchr_test);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_memcmp
	printf("ft_memcmp:\n");
	printf("------------------------------------------\n");
	char	memcmp_test1[] = "ABC";
	char	memcmp_test2[] = "AB";
	int		size_memcmp = 0;
	int		memcmp_diff;
	
	memcmp_diff = ft_memcmp(memcmp_test1, memcmp_test2, size_memcmp);
	printf("String \'%s\' compared to string \'%s\' and size %d, the difference is: %d\n", memcmp_test1, memcmp_test2, size_memcmp, memcmp_diff);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_strnstr
	printf("ft_strnstr:\n");
	printf("------------------------------------------\n");
	char	*retur;
	char	big[] = "Cucurella Marc";
	char	little[] = "M";
	int		size_strnstr = 1;
	
	retur = ft_strnstr(big, little, size_strnstr);
	printf("In String little \'%s\', function ft_strnstr() locates in the string big \'%s\' with size \'%d\': \'%s\'\n", little, big, size_strnstr, retur);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_atoi
	printf("ft_atoi:\n");
	printf("------------------------------------------\n");
	char	before_atoi[] = "      -012f36atoi";
	int		result;

	result = ft_atoi(before_atoi);
	printf("From string \'%s\', with function ft_atoi() i get: %d\n", before_atoi, result);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_calloc
	printf("ft_calloc:\n");
	printf("------------------------------------------\n");
	int	n_calloc = 5;
	int	*array_calloc;
	int	i_calloc;

	array_calloc = (int *)ft_calloc(n_calloc, sizeof(int));
	i_calloc = 0;
	printf("Array elements after with ft_calloc(%d, sizeof(int)): ", n_calloc);
	while (i_calloc < n_calloc)
	{
		printf("%d ", array_calloc[i_calloc]);
		i_calloc++;
	}
	free(array_calloc);
	printf("\n");
	printf("------------------------------------------\n");
	printf("\n");
	// ft_strdup
	printf("ft_strdup:\n");
	printf("------------------------------------------\n");
	char	*str_strdup = "Helloworld";
	char	*result_strdup;

	result_strdup = ft_strdup(str_strdup);
	printf("The string: %s\n", result_strdup);
	free(result_strdup);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_substr
	printf("ft_substr:\n");
	printf("------------------------------------------\n");
	char	string_substr[] = "Champions League";
	char	*substring_substr;
	int		start_substr = 10;
	int		len_substr = 6;

	substring_substr = ft_substr(string_substr, start_substr, len_substr);
	printf("substring of string \'%s\' by using ft_substr(string, %d, %d) is: \'%s\'\n", string_substr, start_substr, len_substr, substring_substr);
	free(substring_substr);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_strjoin
	printf("ft_strjoin:\n");
	printf("------------------------------------------\n");
	char	s1_strjoin[] = "Chelsea ";
	char	s2_strjoin[] = "CF";
	char	*s3;

	s3 = ft_strjoin(s1_strjoin, s2_strjoin);
	printf("Concatenating s1: \'%s\' and s2: \'%s\' with function ft_strjoin() creates: \'%s\' \n", s1_strjoin, s2_strjoin, s3);
	free(s3);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_strtrim
	printf("ft_strtrim:\n");
	printf("------------------------------------------\n");
	char	*trimmed;
	char	s1_ftstrtrim[] = "ababaaaMy name is CFCbbaaabbab";
	char	set_ftstrtrim[] = "ab";

	trimmed = ft_strtrim(s1_ftstrtrim, set_ftstrtrim);
	printf("s1: \'%s\' and set: \'%s\' creates: %s\n", s1_ftstrtrim, set_ftstrtrim, trimmed);
	free(trimmed);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_split
	printf("ft_split:\n");
	printf("------------------------------------------\n");
	char	string_ftsplit[] = "hello\nfuck\nyou";
	char	c_ftsplit = '\n';
	int		i_ftsplit;
	int		count;
	char	**splitted;

	i_ftsplit = 0;
	count = 3;
	splitted = ft_split(string_ftsplit, c_ftsplit);
	while (i_ftsplit < count)
	{
		printf("word on splitted[%d]: %s\n", i_ftsplit, splitted[i_ftsplit]);
		i_ftsplit++;
	}
	i_ftsplit = 0;
	while (splitted[i_ftsplit])
	{
		free(splitted[i_ftsplit]);
		i_ftsplit++;
	}
	free(splitted);
	printf("------------------------------------------\n");
	printf("\n");
	// ft_itoa
	printf("ft_split:\n");
	printf("------------------------------------------\n");
	int	n_ftatoi = 120;
	char	*inttostr;

	inttostr = ft_itoa(n_ftatoi);
	printf("The int n = %d, with function ft_itoa turns into string: \'%s\'\n", n_ftatoi, inttostr);
	free(inttostr);
	printf("------------------------------------------\n");
	printf("\n");
	return (0);
}
