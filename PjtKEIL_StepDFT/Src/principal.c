

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

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();
for (int i = 0; i<64; i++){
	tab[i] = DFT_Module_reel_imag(&LeSignal, i, &TabCos);
	tab1[i] = DFT_Module_reel_imag(&LeSignal, i, &TabSin);
	tab2[i] = DFT_module_carre(tab[i],tab1[i]);
}


	
//=======


	
	


//============================================================================	
	
	
while	(1)
	{
	}
}

