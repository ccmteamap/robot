#General
This part of the robot will have to empty the bucket, filled with water by the pump, in a reservoir.
The bucket will be attached to some kind of rollercoastercar.
The car will be pulled upwards with the DC-motor using bearings and two rails.

#Design
The rails in wich the car moves will go straight up.
At the end of the rails, they will bend over the reservoir so the bucket can be emptied.
Because the bucket is fixed to the moving car, the bend will enable us to empty the bucket.

#Software

##Master-Arduino
The Arduino used for driving the robot (master)  will communicate to the Arduino for emptying the bucket (slave).
When the master knows that the robot is standing against the reservoir using distance sensors, it will send a signal to the slave so that the filled bucket can be emptied.

##Slow start
To make sure we don't spill a lot of water, the start of the emptying-part will be slow. The motor will start pulling the car upwards.

##Middle
Because time is essential in this assignment, we have a powerfull motor that can pull the bucket fastly to the bended part in the rails.

##Emptying
When the bucket is at the bended part of the rails, water will begin to be poured out of the bucket.
The motor will then slowly pull the car until the end of the rail is reached so the water is poured in the reservoir and nothing is spilled over.

##Empty bucket
When there's no more water in the bucket, the microcontroller will have to send a signal to the master so that the robot can already drive towards the water supply.
While driving, the bucket will be let down back to it's original place.
When the bucket is down, the Arduino will again send a signal to the master so that the master can let the pump fill the bucket again.
