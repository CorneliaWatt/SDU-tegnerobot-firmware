main: compile

compile:
	arduino-cli compile --fqbn arduino:avr:mega

upload: compile
	arduino-cli upload --fqbn arduino:avr:mega --port /dev/ttyUSB0

