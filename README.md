# music
It contains code for conversion of Keyboard to music producing device.
The key2note.cpp program is a code used to convert QWERTYU keys into synthesizer.
The code works only on Linux.
To work this code you must know your keyboard event file
and run it the following way.

After compiling it. Run it as:
sudo ./key2note /dev/input/eventX | aplay
.

The code is still very raw. It does not produce enough amount of data to fill the soundcard buffer hece it causses an underrun.

I am always open to suggestions.
