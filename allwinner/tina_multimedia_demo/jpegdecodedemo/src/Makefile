Target = jpegdecodedemo

SourceIncludePath := -I$(STAGING_DIR)/usr/include/allwinner/include -I$(STAGING_DIR)/usr/include/allwinner
CompileFlags = $(CFLAGS) $(SourceIncludePath)

LoadFlags +=  -ljpegdecode  -lvdecoder -lVE \
		-lMemAdapter -lcdc_base -ldl

$(Target): jpegdecodedemo.c
	$(CC) -o $@ $^ $(CompileFlags) $(LDFLAGS) $(LoadFlags)
