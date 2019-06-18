# Default password training
## Goal
A confidential message is stored on the firmware but protected by a default password.

## Guidelines
* Make a wordlist of password or take the provided one
* Write a script to brute force password over serial
* When the password is found, stop the script

## Tips
Tips :
* Password valid, the DVID answers "ok"
* Password wrong, the DVID answers "ko"
* Add a sleep of 2 seconds between each try
* Serial buffer is unpredictable, use "if xx in buffer" to check the DVID return

## Result
The password is an animal name.
