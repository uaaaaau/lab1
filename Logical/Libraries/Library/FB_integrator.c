
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
void FB_integrator(struct FB_integrator* inst)
{
	/*TODO: Add your code here*/
	inst->out = inst->dt * inst->in + inst->out;
	inst->prev_value = inst->out;
}
