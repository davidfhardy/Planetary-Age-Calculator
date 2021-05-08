# Planetary Age Calculator
C++ application which can calculate your age on all the planets of the Solar System (and Pluto).
Qt Framework was used to create the GUI. 

# Features
1. Fully functional menu: users can select options from the "File" and "Edit" tabs.
   They may also hover over the "Help" tab to get a brief explanation on using the program.
   The "File" and "Edit" tabs display shortcuts which can be used.
2. Pushbuttons: Users can click on the pushbuttons (labelled "Calculate") to calculate their age  
   on the corresponding planet.
3. Spinner Box: users can enter data in the spin boxes labelled "day" and "year".
4. Frames: frames are used to emphasize text and separate pieces of information.
5. Combobox: users can select a month from the drop-down menu from the combo box labelled "month".
6. Planetary ages are calculated by getting the person's age on earth (in days or years) and
   dividing it by the orbital period of the planet (in the same units). 
7. NOTE: you may notice that for planets after Jupiter (Saturn, Uranus, ...), you may click
   the Calculate button, but the output will still be zero. This is just because these planets
   have very large orbital periods, so your age on the planets will usually be less than 1 yo (which are.
   rounded to 0) However, if you make the year very small, you will get numbers which are not zero, so you can
   indeed see that these buttons actually work. They are not broken!
