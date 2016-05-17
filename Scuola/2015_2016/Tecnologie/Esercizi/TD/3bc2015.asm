	.model	small		;direttive per l'assemblatore
	.stack	100h		;segmento stack

	.data			;segmento dati
str1	db	"Primo programma"
num1	db	5
num2   	db	-4
ris	db	?
car1	db	'a'
car2	db	'A'
car3	db	?
num11	dw	30000
num22	dw	-20000
num33	dw	?
unof	dd	-8.5
duef	dd	0.25	

	.code			;segmento codice
inizio:	mov	ax,@data		;inizializza registri segmento
	mov	ds,ax
	mov	es,ax
	sub	ax,ax
	mov	al,num1
	mov	bl,num2
	add	al,bl
	mov	ris,al
	mov	al,100
	add	al,150
	mov	cl,car1
	inc	cl
	mov	car3,cl
	mov	dx,num11
	add	dx,num22
	mov	num33,dx

esci:	mov	ah,4ch                  ;esce e torna al dos
	int	21h
	end	inizio
