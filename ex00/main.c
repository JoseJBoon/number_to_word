/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboon <jboon@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/06/22 12:50:39 by jboon         #+#    #+#                 */
/*   Updated: 2025/06/22 12:50:39 by jboon         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "rush02.h"

int	main(int argc, char *argv[])
{
	const char	*filename;
	const char	*num_str;
	t_node		*dict;

	if (!validate_input(argc, argv, &filename, &num_str)
		|| !handle_dictionary(filename, &dict))
		return (1);
	num_str = ft_skipchar(num_str, '0');
	num_str -= (*num_str == '\0');
	if (!number_to_words(dict, num_str, ft_strlen(num_str)))
	{
		ft_puterr("Failed to convert ", num_str, "!\n");
		ft_lstclear(dict);
		return (1);
	}
	ft_lstclear(dict);
	return (0);
}
