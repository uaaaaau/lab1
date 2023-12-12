
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	fb_motor.dt = 0.01;
	fb_motor.k_e = 0.24;
	fb_motor.T_m = 0.03;
	fb_motor.u = 0;
	fb_motor.integrator.dt = 0.01;

	fb_motor2.dt = 0.01;
	fb_motor2.k_e = 0.24;
	fb_motor2.T_m = 0.03;
	fb_motor2.u = 0;
	fb_motor2.integrator.dt = 0.01;

	fb_controller.dt = 0.01;
	fb_controller.integrator.dt = 0.01;
	fb_controller.k_i = 24;
	fb_controller.k_p = 0.24*3;
	fb_controller.max_abs_value = 24.0;

	speed = 0;
	counter = 0;
	enable=1;


}

void _CYCLIC ProgramCyclic(void)
{
	if (enable)
	{
		if (counter == 100)
		{
			speed = 50;
		}
		else if (counter == 250)
		{
			speed = 0;
			counter = 0;
		}
		counter++;

		fb_controller.e = speed - fb_motor.w;
		FB_controller(&fb_controller);

		fb_motor.u = fb_controller.u;

		fb_motor2.u = speed * fb_motor2.k_e;

		FB_motor(&fb_motor);
		FB_motor(&fb_motor2);

	}
}

void _EXIT ProgramExit(void)
{

}

