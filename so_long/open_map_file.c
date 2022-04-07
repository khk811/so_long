#include "so_long.h"

int	is_file_ext_ber(const char *dir)
{
	char	*file_ext;
	unsigned int    ext_start;

    ext_start = (unsigned int)(ft_strlen(dir) - 4);
	file_ext = ft_substr(dir, ext_start, 4);
	if (ft_strncmp(file_ext, ".ber", 4) != 0)
	{
		ft_free(file_ext);
		print_error("is_file_ext_ber()", "Wrong file extension");
		return (0);
	}
	ft_free(file_ext);
	return (1);
}

int open_map_file(const char *dir, int *fd)
{
    *fd = -1;
    if (!is_file_ext_ber(dir))
        return (0);
    *fd = open(dir, O_RDONLY);
    if (*fd < 0)
        return (print_error("open_map_file()", strerror(errno)));
    return (1);
}
