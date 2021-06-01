#include "DriverJeuLaser.h"
#include "Affichage_Valise.h"

int DFT_module_carre(short int* Signal, int k);
void StartSon(void);

extern short int LeSignal;
extern short int TabCos;
extern short int TabSin;
// ======
void CallbackSon(void);
int tab[64];
int tab1[64];
int tab2[64];
int scores[4];
short int dma_buf[64];
int compteur[4];

void Callback_Systick(void){
	Start_DMA1(64);
	Wait_On_End_Of_DMA1();
	Stop_DMA1;
	for (int i = 0; i<64; i++){
		tab2[i] = DFT_module_carre(dma_buf, i);
	}
	if (tab2[18] < 10000000){
		compteur[0] = 0;
	}
	else{
		compteur[0]++;
		if(compteur[0] > 15){
			scores[0]++;
			Prepare_Afficheur(1, scores[0]);
			compteur[0] = 0;
			//StartSon();
			//CallbackSon();
		}
	}
	if (tab2[20] < 10000000){
		compteur[1] = 0;
	}
	else{
		compteur[1]++;
		if(compteur[1] > 15){
			scores[1]++;
			Prepare_Afficheur(2, scores[1]);
			compteur[1] = 0;
			//StartSon();
			//CallbackSon();
		}
	}
	if (tab2[23] < 10000000){
		compteur[2] = 0;
	}
	else{
		compteur[2]++;
		if(compteur[2] > 15){
			scores[2]++;
			Prepare_Afficheur(3, scores[2]);
			compteur[2] = 0;
			//StartSon();
			//CallbackSon();
		}
	}
	if (tab2[24] < 10000000){
		compteur[3] = 0;
	}
	else{
		compteur[3]++;
		if(compteur[3] > 15){
			scores[3]++;
			Prepare_Afficheur(4, scores[3]);
			compteur[3] = 0;
			//StartSon();
			//CallbackSon();
		}
	}
	Mise_A_Jour_Afficheurs_LED();
}

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================
	//init scores
	for (int i = 0; i < 4; i++){
		scores[i]=0;
	}
// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
	CLOCK_Configure();
	
	//Config Systick
	Systick_Period_ff(360000);
	Systick_Prio_IT(10, Callback_Systick);
	SysTick_On;
	SysTick_Enable_IT;
	
	//Config ADC
	Init_TimingADC_ActiveADC_ff(ADC1, 72);
	Single_Channel_ADC(ADC1, 2);
	Init_Conversion_On_Trig_Timer_ff(ADC1, TIM2_CC2, 225);
	
	//Config DMA
	Init_ADC1_DMA1( 0, dma_buf );
	
	
	//init afficheur
	Init_Affichage();
	Prepare_Afficheur(1, 0);
	Prepare_Afficheur(2, 0);
	Prepare_Afficheur(3, 0);
	Prepare_Afficheur(4, 0);
	Mise_A_Jour_Afficheurs_LED();
	
	while(1){
	}

	
//=======


	
	


//============================================================================	
	
}

