	PRESERVE8
	THUMB   
		
	extern GPIOB_Set
	extern GPIOB_Clear

	EXPORT timer_callback
	EXPORT FlagCligno
; ====================== zone de réservation de données,  ======================================
;Section RAM (read only) :
	area    mesdata,data,readonly


;Section RAM (read write):
	area    maram,data,readwrite
		

	
; ===============================================================================================

		
;Section ROM code (read only) :		
	area    moncode,code,readonly
; écrire le code ici		

FlagCligno dcd 0

timer_callback proc
	push {r4-r11, lr}
	
	ldr r1, =FlagCligno
	ldr r0, [r1]
	cmp r0, #0
	bne diffzero
	mov r1, #1
	b fin
	
diffzero
	mov r1, #0
	bl GPIOB_Clear
	
fin
	str r1, [r0]
	bl GPIOB_Clear
	pop {r4-r11, lr}
	bx lr
	endp	
		
	END	