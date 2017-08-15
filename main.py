# coffeetimer is a raspberry pi contraption to help me make syphon coffee
# here's what i want this thing to do
#   keep track of how long it takes water to rise
#     track water temp before the rise phase
#   keep track of how long the coffee is brewing
#     track slurry temperature
#   keep track of how long the draw down phase took
#     measure temperature to drawn down water

# So it looks like I'll need two temperature sensors: one for the base and one for the slurry
# I'll also need some sort of trigger to tell coffeetimer when i put the top of the syphon on
# and threw the grounds in. maybe a physical button


# here's some pseudocode

import  RPi.GPIO as GPIO
import thermistor

thermistor.set_pin(4)


