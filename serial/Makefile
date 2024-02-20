model=arduino:avr:uno
port=/dev/ttyACM0

main: compile

compile:
	arduino-cli compile --fqbn ${model}

upload:
	arduino-cli compile -u --fqbn ${model} --port ${port}

