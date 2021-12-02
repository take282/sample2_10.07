#include "ev3api.h"
#include "app.h"

#define COLOR_SENSOR_PORT EV3_PORT_2
#define SONAR_PORT EV3_PORT_3

void main_task(intptr_t exinf) {
	colorid_t color;
    uint32_t power = 30;                /* 回転スピード（パワー）-100～+100 */
    int16_t distance;                                      /* 距離の値[cm] */
    char distance_str[32];                                 /* 距離を表示するための文字列 */

    ev3_sensor_config(COLOR_SENSOR_PORT, COLOR_SENSOR);
	ev3_sensor_config(SONAR_PORT, ULTRASONIC_SENSOR);      /* ポートに超音波センサを設定 */
    ev3_lcd_set_font(EV3_FONT_MEDIUM);         /* LCDフォント設定 */

	ev3_motor_config(EV3_PORT_A, LARGE_MOTOR); /* PORT AにモーターLを設定 */
	ev3_motor_config(EV3_PORT_B, LARGE_MOTOR); /* PORT BにモーターLを設定 */

    while(1){
	color = ev3_color_sensor_get_color(COLOR_SENSOR_PORT);     /* カラー情報の取得 */
    distance = ev3_ultrasonic_sensor_get_distance(SONAR_PORT); /* 距離の値を取得 */
    
    sprintf(distance_str, "DISTANCE: %3d [cm]", distance);
	ev3_lcd_draw_string(distance_str, 0, 10);                  /* 距離を表示 */
	
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
	ext_tsk();                                 /* タスク終了処理 */
}
	
