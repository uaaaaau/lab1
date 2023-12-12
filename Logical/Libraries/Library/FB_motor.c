
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_motor(struct FB_motor* inst)
{
	/*TODO: Add your code here*/
	REAL a = inst->u / inst->k_e - inst->w;
	REAL b = a / inst->T_m;
	
	inst->integrator.in = b;
	FB_integrator(&inst->integrator);
	
	inst->w = inst->integrator.out;

}
