#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
## 支持宏使用
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_SRCDIR([version.h])
AC_CONFIG_HEADERS([config.h])

## 不需要生成静态库
AC_DISABLE_STATIC
AM_SILENT_RULES([yes])
## support as
AM_PROG_AS

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AM_PROG_AR
## use libtool
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_CPP

AC_ARG_ENABLE(hls,
		[AC_HELP_STRING([--enable-hls],[enable hls build])],
		[ case "${enableval}" in
		  yes) hls=true ;;
		  no)  hls=false ;;
          *)   AC_MSG_ERROR(bad value ${enableval} for --enable-hls) ;;
	esac],
	[hls=true])
 AM_CONDITIONAL([HLS_ENABLE],  [test x$hls = xtrue])

 AC_ARG_ENABLE(https,
		[AC_HELP_STRING([--enable-https],[enable https build])],
		[ case "${enableval}" in
		  yes) https=true ;;
		  no)  https=false ;;
          *)   AC_MSG_ERROR(bad value ${enableval} for --enable-https) ;;
	esac],
	[https=true])
 AM_CONDITIONAL([HTTPS_ENABLE],  [test x$https = xtrue])

AC_ARG_ENABLE(xplayerdemo,
		[AC_HELP_STRING([--enable-xplayerdemo],[build xplayerdemo])],
		[ case "${enableval}" in
		  yes) xplayerdemo=true ;;
		  no)  xplayerdemo=false ;;
          *)   AC_MSG_ERROR(bad value ${enableval} for --enable-xplayerdemo) ;;
	esac],
	[xplayerdemo=false])
 AM_CONDITIONAL([XPLAYERDEMO_ENABLE],  [test x$xplayerdemo = xtrue])

AC_ARG_ENABLE(xplayerdemo-de2,
		[AC_HELP_STRING([--enable-xplayerdemo-de2],[DE 2.0 layer control for xplayerdemo])],
		[ case "${enableval}" in
		  yes) xplayerdemo_de2=true ;;
		  no)  xplayerdemo_de2=false ;;
          *)   AC_MSG_ERROR(bad value ${enableval} for --enable-xplayerdemo-de2) ;;
	esac],
	[xplayerdemo_de2=false])
 AM_CONDITIONAL([XPLAYERDEMO_DE2_ENABLE],  [test x${xplayerdemo_de2} = xtrue])
echo "${xplayerdemo_de2} TJDEBUG1"

 AC_ARG_ENABLE(rtsp_client,
		[AC_HELP_STRING([--enable-rtsp_client],[enable enable rtsp client])],
		[ case "${enableval}" in
		  yes) rtsp_client=true ;;
		  no)  rtsp_client=false ;;
          *)   AC_MSG_ERROR(bad value ${enableval} for --enable-rtsp_client) ;;
	esac],
	[rtsp_client=false])
 AM_CONDITIONAL([RTSP_CLIENT_ENABLE],  [test x$rtsp_client = xtrue])

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h inttypes.h limits.h locale.h malloc.h memory.h netdb.h netinet/in.h stddef.h stdint.h stdlib.h string.h strings.h sys/ioctl.h sys/socket.h sys/time.h sys/timeb.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_TYPE_UID_T
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_INT8_T
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_C_RESTRICT
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_STRUCT_TIMEZONE
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_UINT8_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_MKTIME
AC_FUNC_STRTOD
AC_CHECK_FUNCS([bzero clock_gettime gethostbyname gettimeofday memchr memmove memset mkdir select socket strcasecmp strchr strdup strerror strncasecmp strrchr strspn strstr strtol strtoul strtoull])

AC_CONFIG_FILES([Makefile
		xmetadataretriever/Makefile
		awrecorder/Makefile
		xplayer/Makefile
		demo/Makefile
		demo/muxtest/Makefile
		demo/xmetademo/Makefile
		demo/jpegdemo/Makefile
		demo/recoderdemo/Makefile
		demo/parserdemo/Makefile
		demo/demoVdecoder/Makefile
		demo/demoVencoder/Makefile
		demo/xplayerdemo/Makefile
		demo/demoOmxVenc/Makefile
		demo/demoOmxVdec/Makefile
		libcore/Makefile
		libcore/playback/Makefile
		libcore/common/Makefile
		libcore/stream/Makefile
		libcore/stream/customer/Makefile
		libcore/stream/file/Makefile
		libcore/stream/http/Makefile
		libcore/stream/udp/Makefile
		libcore/stream/tcp/Makefile
		libcore/stream/ssl/Makefile
		libcore/stream/aes/Makefile
		libcore/stream/rtsp/Makefile
		libcore/stream/base/Makefile
		libcore/parser/Makefile
		libcore/parser/ts/Makefile
		libcore/parser/flv/Makefile
		libcore/parser/avi/Makefile
		libcore/parser/mov/Makefile
		libcore/parser/mkv/Makefile
		libcore/parser/asf/Makefile
		libcore/parser/remux/Makefile
		libcore/parser/hls/Makefile
		libcore/parser/ogg/Makefile
		libcore/parser/mpg/Makefile
		libcore/parser/ape/Makefile
		libcore/parser/flac/Makefile
		libcore/parser/amr/Makefile
		libcore/parser/mp3/Makefile
		libcore/parser/aac/Makefile
		libcore/parser/wav/Makefile
		libcore/parser/id3v2/Makefile
		libcore/parser/pls/Makefile
		libcore/parser/base/Makefile
		libcore/parser/AwRawStream/Makefile
		libcore/muxer/Makefile
		libcore/muxer/aac/Makefile
		libcore/muxer/mp4/Makefile
		libcore/muxer/ts/Makefile
		libcore/muxer/base/Makefile
		libcore/base/Makefile
		])
AC_OUTPUT

#plugin compile
#		libcore/libplugin/Makefile
#		libcore/libplugin/rxx/Makefile
#		libcore/libplugin/rtp/Makefile
