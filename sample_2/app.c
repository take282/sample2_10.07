#include "ev3api.h"
#include "app.h"

#define TEMPO 250
#define VOLUME 10

void RingTone(int freq, int time, int vol)
{
	ev3 speaker set volume(vol);
	ev3 speaker play tone(freq, time-50);
	tslp tsk(time);
}

void main task(intptr t unused)
{
	ev3 lcd draw string("START...", 20, 25);
	tslp tsk(10000);

	RingTone(523, TEMPO*2, VOLUME);
	RingTone(587, TEMPO*2, VOLUME);
	RingTone(659, TEMPO*2, VOLUME);
	RingTone(698, TEMPO*2, VOLUME);
	RingTone(659, TEMPO*2, VOLUME);
	RingTone(587, TEMPO*2, VOLUME);
	RingTone(523, TEMPO*2, VOLUME);
	RingTone(659, TEMPO*2, VOLUME);
	RingTone(698, TEMPO*2, VOLUME);
	RingTone(784, TEMPO*2, VOLUME);
	RingTone(880, TEMPO*2, VOLUME);
	RingTone(784, TEMPO*2, VOLUME);
	RingTone(698, TEMPO*2, VOLUME);
	RingTone(659, TEMPO*2, VOLUME);
	tslp tsk(TEMPO*3000);

	RingTone(523, TEMPO*2, VOLUME);
	tslp tsk(TEMPO*2*3000);
	RingTone(523, TEMPO*2, VOLUME);
	tslp tsk(TEMPO*2*3000);
	RingTone(523, TEMPO*2, VOLUME);
	tslp tsk(TEMPO*2*3000);
	RingTone(523, TEMPO*2, VOLUME);
	tslp tsk(TEMPO*2*3000);

	RingTone(523, TEMPO, VOLUME);
	RingTone(523, TEMPO, VOLUME);
	RingTone(587, TEMPO, VOLUME);
	RingTone(587, TEMPO, VOLUME);
	RingTone(659, TEMPO, VOLUME);
	RingTone(659, TEMPO, VOLUME);
	RingTone(698, TEMPO, VOLUME);
	RingTone(698, TEMPO, VOLUME);
	RingTone(659, TEMPO, VOLUME);
	tslp tsk(TAMEPO*3000);
	RingTone(587, TEMPO*2, VOLUME);
	tslp tsk(TAMEPO*3000);
	RingTone(523, TEMPO*3, VOLUME);
	tslp tsk(TEMPO*3000);

	ev3 lcd draw string("THAT'S ALL !", 20, 40);

	ext tsk();
}