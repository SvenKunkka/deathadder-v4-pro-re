.PHONY: all check
all:
	$(MAKE) -C recovered-code/portable

check: all
	cd analysis && python3 -m unittest -v test_handshake_codec
