#include "ev3api.h"
#include "app.h"

#define COLOR_SENSOR_PORT EV3_PORT_2
#define SONAR_PORT EV3_PORT_3

void main_task(intptr_t exinf) {
	colorid_t color;
    uint32_t power = 30;                /* ��]�X�s�[�h�i�p���[�j-100�`+100 */
    int16_t distance;                                      /* �����̒l[cm] */
    char distance_str[32];                                 /* ������\�����邽�߂̕����� */

    ev3_sensor_config(COLOR_SENSOR_PORT, COLOR_SENSOR);
	ev3_sensor_config(SONAR_PORT, ULTRASONIC_SENSOR);      /* �|�[�g�ɒ����g�Z���T��ݒ� */
    ev3_lcd_set_font(EV3_FONT_MEDIUM);         /* LCD�t�H���g�ݒ� */

	ev3_motor_config(EV3_PORT_A, LARGE_MOTOR); /* PORT A�Ƀ��[�^�[L��ݒ� */
	ev3_motor_config(EV3_PORT_B, LARGE_MOTOR); /* PORT B�Ƀ��[�^�[L��ݒ� */

    while(1){
	color = ev3_color_sensor_get_color(COLOR_SENSOR_PORT);     /* �J���[���̎擾 */
    distance = ev3_ultrasonic_sensor_get_distance(SONAR_PORT); /* �����̒l���擾 */
    
    sprintf(distance_str, "DISTANCE: %3d [cm]", distance);
	ev3_lcd_draw_string(distance_str, 0, 10);                  /* ������\�� */
	
    if(distance==20){
           
    }
    switch(color) {
	    case COLOR_BLACK:
		ev3_motor_set_power(EV3_PORT_A, 16);
        ev3_motor_set_power(EV3_PORT_B, 11);
        break;

	    case COLOR_WHITE:
		ev3_motor_set_power(EV3_PORT_A, 6);
        ev3_motor_set_power(EV3_PORT_B, 11);
        break;

        case COLOR_GREEN:
		ev3_motor_set_power(EV3_PORT_A, 0);
        ev3_motor_set_power(EV3_PORT_B, 0);
        break;

    }
    tslp_tsk(100000);

    }
	ext_tsk();                                 /* �^�X�N�I������ */
}
	
