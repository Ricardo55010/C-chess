main:
	gcc ./Chess/Test/Test.c -o test
	./test
	gcc ./Chess/main.c ./Chess/board/board.c ./Chess/movements/movements.c ./Chess/rules/rules.c ./Chess/menu/menu.c  -o chess
	./chess