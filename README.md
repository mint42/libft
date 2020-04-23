# LIBFT

Libft is the foundation for all beginner projects in the 42 curriculum. FT stands for the Forty-Two library. This is a recreation of all of the most fundamental functions from C's standard libraries. This implementation of libft can be [compiled modularly](#MODULAR-COMPILATION).

According to the rules of the libft project, the only allowed functions for creating this library are malloc(), free(), and write(). Any other functions you might want to use must be recreated yourself.

## GETTING STARTED

To set up this project, run `git clone https://github.com/mint42/libft` in the folder of your choosing.

### BASIC COMPILATION
Then run the `make` command in the root of the repository. The Makefile will build the libft.a file which can be linked to a test main or project. All of the necessary public include files are symlinked at compile time to the `includes` folder at the root of the repository for ease of linking.

### MODULAR COMPILATION

By default, libft will compile all modules into a single `.a` file. To request that only certain modules be compiled, set up a file named `libft_mods.mk` in your repository's parent directory. This file should contain one variable named `MODS` which is a list of the requested modules. The libft's Makefile will handle its own dependencies, so no need to include anything in this file that a project does not explicitly need. If you're unfamiliar with makefile format, feel free to use this template and comment out what you don't need:

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

## MODULES

MODULE | DESCRIPTION | DEPENDENCIES
--- | --- | ---
ft_binarytree | _void *_ binary tree implementation | ft_mem
ft_conv | Data type conversions | ft_math, ft_str, ft_utils
ft_double_array | _void *_ Double array implementation | ft_mem, ft_printf, ft_str
ft_list | _void *_ linked list implemenation | ft_mem
ft_math | Math operations
ft_mem | _void *_ memory manipulation
ft_parse | _char *_ word and whitespace parsing | ft_utils
ft_printf | System printf() implementation | ft_conv, ft_mem, ft_str, ft_utils
ft_put | Wrappers for write() | ft_str
ft_queue | _void *_ queue implementation | ft_mem
ft_stack | _void *_ stack implementation |  ft_mem
ft_str | _char *_ manipulation | ft_mem, ft_utils
ft_utils | Simple utilities
get_next_line | System getline() implementation | ft_list, ft_mem, ft_str

## AUTHOR

[Ari Reedy](https://github.com/mint42)
