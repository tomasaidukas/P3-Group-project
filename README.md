# P3-Group-project

HOW TO COMPILE GUI
(On the computers in the labs)

Use the version in the 'Electrostatics' folder - this one works

Comment out line 154 from 'ui_mainwindow.h'

Then use these commands:
>qmake -project
>qmake

delete 'eField.cc' from SOURCES in 'Makefile'
delete 'eField.o' from OBJECTS in 'Makefile'

Then use these commands:
>mkdir Plots ElectricField PotentialField
>make
>chmod -x run.sh

Now you can run ./Electrostatics

:)
