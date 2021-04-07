	PRESERVE8
	THUMB   
		

	EXPORT CallbackSon
	import Son
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
	ldr R1,[R4] ;R1 = indice
	ldrsh R3,[R0,R1,lsl#1]
	add R1,#1
	str R1,[R4]
	strh R3,[R0]
	pop {R4-R11, lr}
	bx lr
	endp




		
		
	END	