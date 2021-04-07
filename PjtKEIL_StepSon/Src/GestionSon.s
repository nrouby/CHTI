	PRESERVE8
	THUMB   
		
	EXPORT CallbackSon		
	EXPORT SortieSon
; ====================== zone de r�servation de donn�es,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
		

	
; ===============================================================================================

		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; �crire le code ici		

SortieSon dcw 0

CallbackSon proc
	push {r4-r11, lr}
	ldr R1,#0
		
	pop {r4-r11, lr}
	bx lr
	endp
	END	