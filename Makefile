

strlen:
	nasm -f elf64 src/ft_strlen.s -o obj/ft_strlen.o
	gcc	tests/ft_strlen.c obj/ft_strlen.o -o exec/ft_strlen

strcpy:
	nasm -f elf64 src/ft_strcpy.s -o obj/ft_strcpy.o
	gcc	tests/ft_strcpy.c obj/ft_strcpy.o -o exec/ft_strcpy

strcmp:
	nasm -f elf64 src/ft_strcmp.s -o obj/ft_strcmp.o
	gcc	tests/ft_strcmp.c obj/ft_strcmp.o -o exec/ft_strcmp