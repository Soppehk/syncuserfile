import turtle
import math


def quadrato(t, lunghezza):
	t = turtle.Turtle()
	for contatore in range(4):
		t.fd(lunghezza)
		t.lt(90)


def poligono(t, lunghezza, n):
	t = turtle.Turtle()
	for contatore in range(n):
		t.fd(lunghezza)
		t.lt(360 / n)


def cerchio(t, r):
	n = 50
	lunghezza = r * r * math.pi / n
	poligono(t, lunghezza, n)


cerchio("bob", 10)
