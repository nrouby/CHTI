

#include "DriverJeuLaser.h"

int DFT_Module_reel_imag(short int* Signal64ech, char k, short int* addr_tab_cos);
int DFT_module_carre(int reel, int imaginaire);

extern short int LeSignal;
extern short int TabCos;
extern short int TabSin;
// ======
int tab[64];
int tab1[64];
int tab2[64];
short int dma_buf[64];

void Callback_Systick(void){
	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1;
	for (int i = 0; i<64; i++){
			tab[i] = DFT_Module_reel_imag(dma_buf, i, &TabCos);
			tab1[i] = DFT_Module_reel_imag(dma_buf, i, &TabSin);
			tab2[i] = DFT_module_carre(tab[i],tab1[i]);
		}
}

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
	CLOCK_Configure();
	
	//Config Systick
	Systick_Period_ff(360000);
	Systick_Prio_IT(2, Callback_Systick);
	SysTick_On;
	SysTick_Enable_IT;
	
	//Config ADC
	Init_TimingADC_ActiveADC_ff(ADC1, 72);
	Single_Channel_ADC(ADC1, 2);
	Init_Conversion_On_Trig_Timer_ff(ADC1, TIM2_CC2, 225);
	
	//Config DMA
	
	Init_ADC1_DMA1( 0, dma_buf );
	
	while(1){
	}

	
//=======


	
	


//============================================================================	
	
}

