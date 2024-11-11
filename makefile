all:
	gcc ./src/*.c -I./include -o jogo-pif.out -lm

run:
	./jogo-pif.out

clean:
	rm jogo-pif.out