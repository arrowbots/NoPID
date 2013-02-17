#include <cmath>
#include "auto_encoders.h"

auto_encoders::auto_encoders() {
   /* 
	hw_info left1=info.left1;
    hw_info left2=info.left2;
    hw_info right1=info.right1;
    hw_info right2=info.right2;
    */
	
    winch_encoder = new Encoder(1, 1, 1, 2, true);
    //right_encoder = new Encoder(right1.moduleNumber, right1.channel, right2.moduleNumber, right2.channel);
   winch_encoder->SetDistancePerPulse(1);
    //right_encoder->SetDistancePerPulse(SLOPE);
    winch_encoder->Start();
    //right_encoder->Start();
}
auto_encoders::~auto_encoders() {
    winch_encoder->Stop(); //Stop encoder
    //right_encoder->Stop();
    delete winch_encoder; //Delete instance of winch_encoder to further stop using it or to free memory
   // delete right_encoder;
}
/*double auto_encoders::get_distance() {
    return get_winch_dist();
}
*/

double auto_encoders::get_winch_dist() {
    return winch_encoder->GetDistance();
}

/*
double auto_encoders::get_right_dist() {
    return right_encoder->GetDistance();
}
*/
/*
void auto_encoders::reset_left_distance() {
    left_encoder->Reset();
}
*/
/*
void auto_encoders::reset_right_distance() {
    right_encoder->Reset();
}
*/
//Reset the distance
void auto_encoders::reset_distance(){
    winch_encoder->Reset();
   // right_encoder->Reset();
}
