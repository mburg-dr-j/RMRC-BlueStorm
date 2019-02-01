# Mechanical Design

In this document you will see a bolded list of every aspect of the design that was changed from the 2018 competition. Underneath the bolded section will be an explanation of why it was changed and what benefits and disadvantages it provided.

**Thickness:**

>In the 2018 competition our robot was rather thick, allowing for easy placement of components and greater surface area to distribute stress. However, this also came with some disadvantages. While traversing the harder terrains, our robot would start to pivot on the main body due to a lack of clearance room and in the future if we were to transition to fish eye cameras (as was planned), the thickness would block part of our field of view(F.O.V.). The new design is 47mm tall.  This allows for an extraordinary clearance room combined with the slightly extended claw wheels, along with greatly improved field of view with our new fish eye cameras. The only two disadvantages over last years robot is that everything has to be placed in extremely efficient ways, and there is less surface area to distribute stress along.

**Less Rounded corners:**

>The iconic, bubble like robot from 2018 could handle stress extremely well due to the amount of surface area on the corners(where the most stress builds up). However this wasted an enormous amount of space and set our wheels so far back we could not fathom even attempting align. The new design is much more efficient with space, but distributes more stress(from the robots increased weight) along less surface area. This would be fatal to our goal of a 1,5 or even 2 meter drop if it were not for what I will explain in the “Motor Extrusions” section.

**Motor Extrusions:**

>An obvious difference from the 2018 robot is the extrusions into each corner of the robot. These are due to our new motor, the dynamixel XM410W-350T. These motors, unlike the AX-12A’s, because they have 4 mounting points on either side of the motor, rather than the front and back as with the AX series. This seemed to be an inconvenience at first until I thought through the distribution of stress in a fall. Due to the new design the stress is no longer exerted directly through the layer lines of the print, it is now exerted into the base and top layers and then distributed much more evenly among the surface area of the robot allowing for much more stress to be exerted, given the stress does not compromise the mechanical integrity of the motors.

**Angled camera slots:**

>In conjunction with the new fish eye cameras, the tilted design allows us to see where one side of the wheel contacts the ground on either side of the robot. This improved placement of the cameras will allow our robot to (yet to be tested) complete align.

**Claw wheels:**

>We have slightly increased the diameter of the wheel allow for greater reach on the tougher terrain, while also getting rid of the sharp overhang in the previous design that lead to the wheels getting caught on the course.


In this part of the document you will see a bolded list of every aspect of the components that were changed from the 2018 competition. Underneath the bolded section will be an explanation of why it was changed and what benefits and disadvantages it provided.

**Udoo X86:**

>This is the new powerhouse of the Blue-Storm robot. It is replacing the Raspberry Pi B3+ and Arduino Mega from last year. 

**Arm:**

>We have designed this 3 degree of freedom(D.O.F) arm to be as simple as can be so that it takes up as little space as possible within the robot. The claw has 3 grippers in the shape of an equilateral triangle so that it may have optimal contact with the hexagonal cap.
                technical specs with motors and capabilities

**CO2 sensor:**

>As the name implies, this is just a basic CO2 sensor.

**Microphone:**

>The respeaker microphone array V2 is a far-field microphone designed with systems such as Alexa and Google Home in mind. There are lots of algorithms and libraries available to rent from google, but we will just be using the most basic functionalities to determine the direction of sound and of course the microphone.

**PCU:**

>This is our abbreviation of Power Control Unit otherwise known as a 12v step up step down regulator. This board is where we wire power to all of the robots components.

**Speaker:**

>This is a 9v speaker from an old screen that we are wiring to 12v for a lack of other power options. It is rather powerful and should be much better than the speaker we ripped out of the 1 USD house phone in Montrael.

**Dynamixel Board:**

>This board is for communication between the Udoo and dynamixels. It is simply a much easier solution than trying to get the system to run through the Arduino.

**Pi 0:**

>This boards sole purpose is to run the thermal camera because the built in Arduino on the Udoo lacks the necessary communication pins.

**USB fish eye camera:**

>These new cameras increase the field of view from about 70 degrees to about 185 degrees. This allows the driver greater spatial awareness on the course, which we have found to be absolutely crucial on any robot.

**USB 8 megapixel camera:**

>Because the drive cameras are distorted due to the fisheye effect, this camera is dedicated to run all of the image based algorithms on the robot.

**Ethernet Port:**

>We are adding an external ethernet port so if need be we can easily tether the robot with an ethernet cable.

**XM430W-350T:**

>These are apart of the new Dynamixel X series motors. These specific motors have 4.1 Nm of torque and 46 rpm, compared to the AX-12A’s 1.5 Nm of torque and 59 rpm. They also have an aluminum casing that allows for a better heatsink capabilities and metal gears for better durability.
