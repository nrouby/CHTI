	PRESERVE8
	THUMB   
		
	EXPORT CallbackSon		
	EXPORT SortieSon
; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
		

	
; ===============================================================================================

		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		

SortieSon dcw 0

CallbackSon proc
	push {r4-r11, lr}
	ldr R1,#0
		
	pop {r4-r11, lr}
	bx lr
	endp
	END	