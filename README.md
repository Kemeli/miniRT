# miniRT

## Configurando para testes

Para rodar os testes precisamos retirar o arquivo `main.o` da variável **OBJS** do [Makefile](./Makefile). E rodamos o comando:

```
make test
```

## Configurando para compilar o miniRT

Para compilar o miniRT precisamos incluir o arquivo `main.o` na variável **OBJS** do [Makefile](./Makefile). E rodamos o comando:

```
make re
```

## Obs

1. Alteramos o `epsilon` na função `compare_doubles` para comparar 5 casas decimais! (antes comparava 6)
2. arquivo `render.c` está comentado no `makefile`
