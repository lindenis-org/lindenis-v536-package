Target = tmetadataretrieverdemo

SourceIncludePath := -I$(STAGING_DIR)/usr/include/allwinner/include -I$(STAGING_DIR)/usr/include/allwinner
CompileFlags = $(CFLAGS) $(SourceIncludePath)

LoadFlags +=  -ltmetadataretriever -lcdx_parser -lcdx_base -lcdx_stream -lcdx_common -lvdecoder -ladecoder -lVE \
		-lMemAdapter -lcdc_base -ldl -lm

$(Target): tmetadataretrieverdemo.c
	$(CC) -o $@ $^ $(CompileFlags) $(LDFLAGS) $(LoadFlags)
