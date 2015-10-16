This is a basic PDM mic to USB project for P5LP.

Adapted from project here: http://www.element14.com/community/thread/28830/l/psoc-4-pioneer-kit-community-project102-usb-audio-using-the-psoc-5lp?displayFullThread=true
PDF write up on original project: http://www.element14.com/community/servlet/JiveServlet/download/95654-122697/PioneerKit_P5LP_USB_Audio_UserGuide.pdf

Main changes: 
1. Removed Audio out path to I2C codec (for speaker playback)
2. Changed PDM data pin from P0[0] to P3[5], for some reason P0[0] was not working

Kit: 5LP host on the 4200-pioneer kit (bootloaded)
Creator: Last built on 3.0 SP2