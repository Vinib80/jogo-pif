all:
	gcc ./src/*.c -I./include -o jogo-pif.out -lm

run:
	./jogo-pif.out

clean:
	rm jogo-pif.out

#Para compilar:
#Digitar make e apertar enter;
#Digitar make run e apertar enter'''