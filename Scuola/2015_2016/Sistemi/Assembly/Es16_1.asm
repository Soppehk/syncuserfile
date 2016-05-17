
     .MODEL SMALL
     .STACK 
      
     .DATA
            
			Car1 DB 'A'
			Car2 DB 01000010b ; carattere ascii 66 è il codice del carattere ‘B’
			Mes1 DB "Inserisci iniziale del tuo nome e cognome",10,13,'$'   ;10 nuova linea; 13 carriage return servono per andare a capo
			MesNome DB 10,13,"iniziale nome: $"
			MesCognome DB 10,13,"iniziale cognome: $"
			ACapo DB 10,13,'$'
	 .CODE
BEGIN:
	MOV ax,@data
	MOV DS,AX
	
	MOV DX,OFFSET Mes1
	MOV AH,09h
	INT 21h
	
	MOV DX,OFFSET MesNome
	MOV AH,09h
	INT 21h
	
	MOV AH,08h
	INT 21h
	
	MOV Car1,AL
	
	MOV DX,OFFSET MesCognome
	MOV AH,09h
	INT 21h
	
	MOV AH,08h
	INT 21h
	
	MOV Car2,AL
	
	MOV DX,OFFSET ACapo
	MOV AH,09h
	INT 21h
	
	MOV AH,02h
	MOV DL,Car1
	INT 21h
	
	MOV DL,Car2
	MOV AH,02h
	INT 21h
	   
    mov AH,4CH   ;Queste due istruzioni serve a far terminare correttamente il programma
    int 21H      ; Ritorno al Sistema Operativo
END BEGIN
