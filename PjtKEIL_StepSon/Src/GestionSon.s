	PRESERVE8
	THUMB   
		

	EXPORT CallbackSon
	EXPORT SortieSon
	EXPORT Index
	import Son
	import LongueurSon
; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly
		


;Section RAM (read write):
	area    maram,data,readwrite
		
SortieSon dcw 0
Index dcd 0
	
; ===============================================================================================
	


		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		



CallbackSon proc 
	push {R4-R11, lr}
	ldr R2,=SortieSon
	ldr R4,=Index
	ldr R0,=Son
	ldr R5,=LongueurSon
	ldr R5,[R5]
	sub R5,#1
	cmp R5, R4
	beq End_tab
	ldr R1,[R4] ;R1 = indice
	ldrsh R3,[R0,R1,lsl#1] ;recupere la valeur du son dans r3
	add R1,#1 ;increment index
	;mise en forme
	add R3,#32768
	mov R6,#720
	mul R3,R6
	mov R6,#65535
	udiv R3,R6
	
	
	str R1,[R4]
	strh R3,[R2]
	
End_tab
	pop {R4-R11, lr}
	bx lr
	endp




		
		
	END	