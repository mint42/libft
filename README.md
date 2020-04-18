# LIBFT

Libft is the foundation for all beginner projects in the 42 curriculum. FT stands for the Forty-Two library. This is a recreation of all of the most fundamental functions from C's standard libraries. I have chosen to break this library up into modules for easy navigation, and to make it more efficient when linking it with other projects.

According to the rules of the libft project, the only allowed functions for creating this library are malloc(), free(), and write(). Any other functions you might want to use must be recreated yourself.

## GETTING STARTED

To set up this project, run `git clone https://github.com/mint42/libft` in the folder of your choosing. Then run the `make` command in the root of the repository. The Makefile will build the libft.a file which can be linked to a test main or project.

## MODULES

This section is taken from MODS variable in [config.mk](https://github.com/mint42/libft/blog/master/config.mk) Makefile, and you can remove modules from being compiled into a project by commenting them out there.

MODULES | DEPENDENCIES
--- | ---
ft_binarytree | ft_mem
ft_conv | ft_math, ft_str, ft_utils
ft_double_array | ft_mem, ft_str
ft_list | ft_mem
ft_math
ft_mem
ft_parse | ft_utils
ft_printf | ft_conv, ft_mem, ft_str, ft_utils
ft_put | ft_str
ft_queue | ft_mem
ft_stack | ft_mem
ft_str | ft_mem, ft_utils
ft_utils
get_next_line | ft_list, ft_mem, ft_str

## AUTHOR

[Ari Reedy](https://github.com/mint42)
