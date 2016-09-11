#Delta Board - Text Entry Device

The Delta Board uses a key-based text entry technique where a universal delta key is used to toggle between the different rows of characters for all of the input keys. The current code consists of 4 states to give a maximum of 28 characters (7x4) and two keys are reserved for space and enter. This method allows for easy addition of more states to include a greater capacity of characters. The code also includes a debouncing feature to filter out possible noise from the toggle of the switches. Furthermore, after a character is selected, the system resets to the initial state, similar to the multi-tap method for mobile phones. 

The switches are all each assigned to a digital input pin for the ease of assembly and wiring. For the current setup, four LEDs are used to display the current state of the Delta Board for the user to identify what are the current row of characters assigned to the switches. Lastly, labeling of each of the characters for the corresponding row is attached to the device to aid in the selecting of the desired character. 

