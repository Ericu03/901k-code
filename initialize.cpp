#include "main.h"
#include "config.hpp"
#include "auton_functions.h"



/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
//from 81k
 lv_obj_t * myButton;
 lv_obj_t * myButtonLabel;

 lv_obj_t * myLabel;

 lv_style_t myButtonStyleREL; //relesed style
 lv_style_t myButtonStylePR; //pressed style

 lv_obj_t * Redbutton;
 lv_obj_t * RedButtonlabel;
 lv_obj_t * label2;

 lv_style_t myButtonStyleRELEASED;
 lv_style_t myButtonStylePRESSED;
 static lv_res_t btn_click_action(lv_obj_t*btn)
 {
	 uint8_t id = lv_obj_get_free_num(btn); //for multible buttons
	 if(id==0)
	 {
		 char buffer[100];

		 //sprintf(buffer, "Blue close is clicked",pros::millis());
		 lv_label_set_text(myLabel, buffer);
	 }

	 else if(id==1)
	 {
		 char buffer[100];

		 //sprintf(buffer,"Redclose is clicked",pros::millis());
		 lv_label_set_text(label2,buffer);
	 }
	 return LV_RES_OK;
 }

void initialize() {
	lv_style_copy(&myButtonStyleREL, &lv_style_plain);//first button BLUE CLOSE
	myButtonStyleREL.body.main_color = LV_COLOR_MAKE(150,0,0);
	myButtonStyleREL.body.grad_color = LV_COLOR_MAKE(0,0,150);
	myButtonStyleREL.body.radius = 0;
	myButtonStyleREL.text.color = LV_COLOR_MAKE(255,255,255);

	lv_style_copy(&myButtonStylePR, &lv_style_plain);
	myButtonStylePR.body.main_color = LV_COLOR_MAKE(200,0,0);
	myButtonStylePR.body.grad_color = LV_COLOR_MAKE(0,0,200);
	myButtonStylePR.body.radius = 0;
	myButtonStylePR.text.color = LV_COLOR_MAKE(255,255,255);

	myButton = lv_btn_create(lv_scr_act(), NULL);
	lv_obj_set_free_num(myButton, 0); //set button to 0
	lv_btn_set_action(myButton,LV_BTN_ACTION_CLICK, btn_click_action);//set function to be called on clicked
	lv_btn_set_style(myButton, LV_BTN_STYLE_REL, &myButtonStyleREL); //set the relesed style
  lv_btn_set_style(myButton, LV_BTN_STYLE_PR, &myButtonStylePR); //set the pressed style
	lv_obj_set_size(myButton, 300, 100); //set the button size
  lv_obj_align(myButton, NULL, LV_ALIGN_IN_TOP_LEFT, 10, 10); //set the position to top mid

	myButtonLabel = lv_label_create(myButton, NULL);
	lv_label_set_text(myButtonLabel, "BLUECLOSE");

	myLabel = lv_label_create(myButton, NULL);
	lv_label_set_text(myLabel, "Button has not been clicked");
	lv_obj_align(myLabel,NULL,LV_ALIGN_IN_LEFT_MID, 10, 0);

	lv_style_copy(&myButtonStyleRELEASED, &lv_style_plain);
	myButtonStyleRELEASED.body.main_color = LV_COLOR_MAKE(0,0,150);
	myButtonStyleRELEASED.body.grad_color = LV_COLOR_MAKE(150,0,0);
	myButtonStyleRELEASED.body.radius = 0;
	myButtonStyleRELEASED.text.color = LV_COLOR_MAKE(255,255,255);

	lv_style_copy(&myButtonStylePR, &lv_style_plain);
	myButtonStylePRESSED.body.main_color = LV_COLOR_MAKE(0,0,200);
	myButtonStylePRESSED.body.grad_color = LV_COLOR_MAKE(200,0,0);
	myButtonStylePRESSED.body.radius = 0;
	myButtonStylePRESSED.text.color = LV_COLOR_MAKE(255,255,255);
	Redbutton = lv_btn_create(lv_scr_act(), NULL);

	lv_obj_set_free_num(Redbutton, 0);
	lv_btn_set_action(Redbutton,LV_BTN_ACTION_CLICK, btn_click_action);
	lv_btn_set_style(Redbutton,LV_BTN_STYLE_REL, &myButtonStyleRELEASED);
	lv_btn_set_style(Redbutton, LV_BTN_STYLE_PR, &myButtonStylePRESSED);
	lv_obj_set_size(Redbutton, 300, 100); //set the button size
  lv_obj_align(Redbutton, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 10, 10);


	RedButtonlabel = lv_label_create(Redbutton,NULL);
	lv_label_set_text(RedButtonlabel, "REDCLOSE");

		label2 = lv_label_create(Redbutton, NULL);
		lv_label_set_text(label2, "Red button has not been clicked");
		lv_obj_align(label2,NULL,LV_ALIGN_IN_TOP_MID,20,0);



}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
