# Luke-s-lightbox

Using a beetle (tiniest arduino leonardo board) to simulate neon flickering and unstability for an LED public signage type light box for Luke Drozd.

One digital output sends PWMsignal to a N-Channel MOSFET (IRL540NPBF) to control the brightness of several dimmable LED strips running at 24VDC 
for full brightness,

A buck converter is used to power convert 24VDC to an acceptable 5VDC for the microcontroller.

The codes uses an analog input (A0) of the board as a source of noise to generate a random seed for timing. The rest of the glitches are
programmed going through an integers table or switching between LOW-HIGH values to give an impression of unstability. 

The series of glitches are interrupted here and there by few seconds to minutes of stability (at different values) generated using the random seed.
