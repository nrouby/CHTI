

#include "DriverJeuLaser.h"

int DFT_Module_reel_imag(short int* Signal64ech, char k, short int* addr_tab_cos);
extern short int LeSignal;
extern short int TabCos;
extern short int TabSin;

int main(void)
{

// ===========================================================================
// ============= INIT PERIPH (faites qu'une seule fois)  =====================
// ===========================================================================

// Après exécution : le coeur CPU est clocké à 72MHz ainsi que tous les timers
CLOCK_Configure();
int a = DFT_Module_reel_imag(&LeSignal, 12, &TabSin);


	

//============================================================================	
	
	
while	(1)
	{
	}
}

