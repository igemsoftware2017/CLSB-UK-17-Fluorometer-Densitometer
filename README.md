# Combined fluorometer and densitometer
For our proof of concept, we need to prove the economic viability of a screening programme with our toehold switches. Barriers include the high cost and immobility of most fluorometers. Building upon previous iGEM designs, we created a cheap, portable and effective fluorometer.

Our combined fluorometer and densitometer costs just $6 in parts, using low-cost components and a small 3D-printed cuvette holder. To minimize costs, we didn’t use a display and instead built software to interpret the results. It gives a live readout, processes results and acts as a datalogger, exporting results to a spreadsheet for further analysis. The software can be run on any computer, tablet or even smartphone.

More information, including usage instructions are available on our [iGEM wiki](http://2017.igem.org/Team:CLSB-UK/Hardware).

## How it works

The Digispark pretends to be a keyboard, that types the results extremely quickly into the computer, tablet or smartphone it’s plugged into. The interpreter software can intercept this, along with other keyboard events for changing the settings to display and process the results.

## Benefits

Data analysis is much easier as readings can be automatically logged and exported to spreadsheets. With Judd-UK’s feedback, readings can be marked with ‘recording numbers’, making it easy to do batch measurements. Also based off their feedback, we added a button to export only the ‘recorded’ data to csv.

The device easier to modify as a few lines can be changed on the webpage rather than reconfiguring the Arduino board or rewiring the circuit with different components. This in turn also reduces the risk of irreversibly damaging the hardware through bugs in the code.

Website programming is much more forgiving than Arduino programming, allowing people with less experience to modify the software. It is also much easier to debug as computers can spit out error messages to the screen.

Moving the complicated processing to the device it is plugged into also means cheaper components can be used in the fluorometer, further reducing the cost. It allows smaller and fewer components to be used, making the device more portable and easier to build.

The interpreter is designed to be used continuously. While the fluorometer is logging data, you can use the keyboard shortcuts to change the options.

While crucial to our proof of concept, a low cost, easy to build and powerful combined fluorometer and densitometer offers massive advantages to synthetic biology as a whole.

## Installation

### digispark.cpp

This is the code for our new combined fluorometer and densitometer. To upload the code you'll need the Arduino IDE set up in a very specific way - see the [Digistump wiki](https://digistump.com/wiki/digispark/tutorials/connecting) for instructions. If this link is broken, use the [Wayback Machine save](https://web.archive.org/web/20171021122058/http://digistump.com/wiki/digispark/tutorials/connecting).

Do make sure you follow the steps exactly, don’t just skim them and assume it’ll be alright! Although Digisparks are generally pretty hardy, messing up could still fry them, making it harder to troubleshoot and wasting your time and money.

Once you’ve got your environment set up, simply copy the code into the Arduino window, click upload and plug in the Digispark when prompted. It’s just a one time set up, if you’re uploading to multiple chips at once it’s very quick - just repeat the upload step for each Digispark.

### interpreter.html

This is simply a webpage - you can open it up in a good browser, like Google Chrome or Mozilla Firefox. Technically it's not valid HTML because this is from our wiki, but it works just as well.

To view it directly on our wiki so you don't need to download it, [click here](http://2017.igem.org/Team:CLSB-UK/Hardware/Interpreter).

### denverbiolabs.cpp

As our new design is vastly superior, we don't reccomend trying to build this one. However, if you do decide to build this we have a simplified version of the circuit diagram on our wiki.

To install the code, use the Arduino IDE. Ensure you've set the board type to Arduino/Genuino Uno, and have installed the LCD16x2 and Wire libraries.

## Structure

* `digispark.cpp` is the code to put on our fluorometer
* `interpreter.html` is the code to run on the device it's plugged into
* `denverbiolabs.cpp` is the code from [Denver Biolabs 2014](https://github.com/denverbiolabs/od-f) with our bugfixes

## Contributing

Please do submit pull requests and add issues if you find any. Please note that any code you submit as part of a pull request will inherit the project license, GPLv3.

## Credits

Built by Adam Jones ([domdomegg](https://github.com/domdomegg)) and George Smith ([gsmith1729](https://github.com/gsmith1729)) for CLSB-UK's iGEM, 2017.
