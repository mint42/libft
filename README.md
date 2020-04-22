# LIBFT

Libft is the foundation for all beginner projects in the 42 curriculum. FT stands for the Forty-Two library. This is a recreation of all of the most fundamental functions from C's standard libraries. This implementation of libft can be [compiled modularly](#MODULAR-COMPILATION).

According to the rules of the libft project, the only allowed functions for creating this library are malloc(), free(), and write(). Any other functions you might want to use must be recreated yourself.

## GETTING STARTED

To set up this project, run `git clone https://github.com/mint42/libft` in the folder of your choosing. Then run the `make` command in the root of the repository. The Makefile will build the libft.a file which can be linked to a test main or project.

## MODULES

This section is taken from `ALL_MODS` variable in [config.mk](https://github.com/mint42/libft/blob/master/config.mk) Makefile, and you can remove modules from being compiled into a project by commenting them out there.

MODULES | DEPENDENCIES
--- | ---
ft_binarytree | ft_mem
ft_conv | ft_math, ft_str, ft_utils
ft_double_array | ft_mem, ft_printf, ft_str
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

## MODULAR COMPILATION

By default, libft will compile all modules into a single `.a` file. To request that only certain modules be compiled, set up a file named `libft_mods.mk` in this repository's parent directory. This file should contain one variable named `MODS` which is a list of the requested modules. The libft's Makefile will handle it's own dependencies, so no need to include anything in this file that a project does not explicitly need. If you're unfamiliar with makefile format, feel free to use this template and comment out what you don't need:

```
# Makefile comment

MODS += ft_binarytree
MODS += ft_conv
MODS += ft_double_array
MODS += ft_list
MODS += ft_math
MODS += ft_mem
MODS += ft_parse
MODS += ft_printf
MODS += ft_put
MODS += ft_queue
MODS += ft_stack
MODS += ft_str
MODS += ft_utils
MODS += get_next_line
```

## AUTHOR

[Ari Reedy](https://github.com/mint42)
