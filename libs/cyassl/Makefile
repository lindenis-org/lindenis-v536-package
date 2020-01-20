#
# Copyright (C) 2006-2014 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=wolfssl
PKG_VERSION:=4.1.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://www.wolfssl.com/
PKG_MD5SUM:=d07e6bf7ba971363f776dfa1cd5538ea

PKG_FIXUP:=libtool
PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1
PKG_LICENSE:=GPL-2.0+

include $(BUILD_DIR)/package.mk

define Package/libcyassl
  SECTION:=libs
  SUBMENU:=SSL
  CATEGORY:=Libraries
  TITLE:=CyaSSL library
  URL:=http://www.wolfssl.com/
endef

define Package/libcyassl/description
CyaSSL is an SSL library optimized for small footprint, both on disk and for
memory use.
endef

TARGET_CFLAGS += $(FPIC) -DWOLFSSL_ALLOW_NO_SUITES 

CONFIGURE_ARGS += \
	--without-zlib \
	--enable-singlethreaded \
 	--disable-extended-master \
	--disable-examples

ifdef CONFIG_CYASSL_WITH_STATIC
  CONFIGURE_ARGS += --enable-static
endif

ifdef CONFIG_CYASSL_WITH_DEBUG
  CONFIGURE_ARGS += --enable-debug
endif

ifdef CONFIG_CYASSL_WITH_AFALG
  CONFIGURE_ARGS += --enable-afalg
else
  CONFIGURE_ARGS += --disable-afalg
endif

ifdef CONFIG_CYASSL_WITH_ZERO_COPY
  TARGET_CFLAGS +=  -DWOLFSSL_AFALG_ZERO_COPY
endif

ifdef CONFIG_CYASSL_WITH_SSLV3
  CONFIGURE_ARGS += --enable-sslv3
else
  CONFIGURE_ARGS += --disable-sslv3
endif

ifdef CONFIG_CYASSL_WITH_SINGLETHREADED
  CONFIGURE_ARGS += --enable-singlethreaded
else
  CONFIGURE_ARGS += --disable-singlethreaded
endif


ifdef CONFIG_CYASSL_WITH_OPENSSLCOEXIST
  CONFIGURE_ARGS += --enable-opensslcoexist
else
  CONFIGURE_ARGS += --disable-opensslcoexist
endif

ifdef CONFIG_CYASSL_WITH_OPENSSLALL
  CONFIGURE_ARGS += --enable-opensslall
else
  CONFIGURE_ARGS += --disable-opensslall
endif

ifdef CONFIG_CYASSL_WITH_OPENSSLEXTRA
  CONFIGURE_ARGS += --enable-opensslextra
else
  CONFIGURE_ARGS += --disable-opensslextra
endif

ifdef CYASSL_WITH_FILESYSTEM
  CONFIGURE_ARGS += --enable-filesystem
else
  CONFIGURE_ARGS += --disable-filesystem
endif

ifdef CONFIG_CYASSL_WITH_IDEA
  CONFIGURE_ARGS += --enable-idea
else
  CONFIGURE_ARGS += --disable-idea
endif

ifdef CONFIG_CYASSL_WITH_ARC4
  CONFIGURE_ARGS += --enable-arc4
else
  CONFIGURE_ARGS += --disable-arc4
endif

ifdef CONFIG_CYASSL_WITH_CMAC
  CONFIGURE_ARGS += --enable-cmac
else
  CONFIGURE_ARGS += --disable-cmac
endif

ifdef CONFIG_CYASSL_WITH_AES
  CONFIGURE_ARGS += --enable-aes
else
  CONFIGURE_ARGS += --disable-aes
endif

ifdef CONFIG_CYASSL_WITH_XTS
  CONFIGURE_ARGS += --enable-xts
else
  CONFIGURE_ARGS += --disable-xts
endif

ifdef CONFIG_CYASSL_WITH_AESCBC
  CONFIGURE_ARGS += --enable-aescbc
else
  CONFIGURE_ARGS += --disable-aescbc
endif

ifdef CONFIG_CYASSL_WITH_AESGCM
  CONFIGURE_ARGS += --enable-aesgcm
else
  CONFIGURE_ARGS += --disable-aesgcm
endif

ifdef CONFIG_CYASSL_WITH_AESCTR
  CONFIGURE_ARGS += --enable-aesctr
else
  CONFIGURE_ARGS += --disable-aesctr
endif

ifdef CONFIG_CYASSL_WITH_AESCFB
  CONFIGURE_ARGS += --enable-aescfb
else
  CONFIGURE_ARGS += --disable-aescfb
endif

ifdef CONFIG_CYASSL_WITH_AESNI
  CONFIGURE_ARGS += --enable-aesni
else
  CONFIGURE_ARGS += --disable-aesni
endif

ifdef CONFIG_CYASSL_WITH_AESKEYWRAP
  CONFIGURE_ARGS += --enable-aeskeywrap
else
  CONFIGURE_ARGS += --disable-aeskeywrap
endif

ifdef CONFIG_CYASSL_WITH_HASHDRBG
  CONFIGURE_ARGS += --enable-hashdrbg
else
  CONFIGURE_ARGS += --disable-hashdrbg
endif

ifdef CONFIG_CYASSL_WITH_SHA224
  CONFIGURE_ARGS += --enable-sha224
else
  CONFIGURE_ARGS += --disable-sha224
endif

ifdef CONFIG_CYASSL_WITH_SHA3
  CONFIGURE_ARGS += --enable-sha3
else
  CONFIGURE_ARGS += --disable-sha3
endif

ifdef CONFIG_CYASSL_WITH_SHA512
  CONFIGURE_ARGS += --enable-sha512
else
  CONFIGURE_ARGS += --disable-sha512
endif

ifdef CONFIG_CYASSL_WITH_SHA384
  CONFIGURE_ARGS += --enable-sha384
else
  CONFIGURE_ARGS += --disable-sha384
endif

ifdef CONFIG_CYASSL_WITH_MD2
  CONFIGURE_ARGS += --enable-md2
else
  CONFIGURE_ARGS += --disable-md2
endif

ifdef CONFIG_CYASSL_WITH_MD4
  CONFIGURE_ARGS += --enable-md4
else
  CONFIGURE_ARGS += --disable-md4
endif

ifdef CONFIG_CYASSL_WITH_MD5
  CONFIGURE_ARGS += --enable-md5
else
  CONFIGURE_ARGS += --disable-md5
endif

ifdef CONFIG_CYASSL_WITH_SHA
  CONFIGURE_ARGS += --enable-sha
else
  CONFIGURE_ARGS += --disable-sha
endif

ifdef CONFIG_CYASSL_WITH_OAEP
  CONFIGURE_ARGS += --enable-oaep
else
  CONFIGURE_ARGS += --disable-oaep
endif

ifdef CONFIG_CYASSL_WITH_RSAVFY
  CONFIGURE_ARGS += --enable-rsavfy
else
  CONFIGURE_ARGS += --disable-rsavfy
endif

ifdef CONFIG_CYASSL_WITH_RSAPSS
  CONFIGURE_ARGS += --enable-rsapss
else
  CONFIGURE_ARGS += --disable-rsapss
endif

ifdef CONFIG_CYASSL_WITH_DH
  CONFIGURE_ARGS += --enable-dh
else
  CONFIGURE_ARGS += --disable-dh
endif

ifdef CONFIG_CYASSL_WITH_ASN
	
  ifdef CONFIG_CYASSL_WITH_RSA
    CONFIGURE_ARGS += --enable-rsa
  else
    CONFIGURE_ARGS += --disable-rsa
  endif

  ifdef CONFIG_CYASSL_WITH_DSA
    CONFIGURE_ARGS += --enable-dsa
  else
    CONFIGURE_ARGS += --disable-dsa
  endif

  ifdef CONFIG_CYASSL_WITH_ECC
    CONFIGURE_ARGS += --enable-ecc
  else
    CONFIGURE_ARGS += --disable-ecc
  endif

  CONFIGURE_ARGS += --enable-asn
else

  CONFIGURE_ARGS += --disable-asn
  CONFIGURE_ARGS += --disable-rsa
  CONFIGURE_ARGS += --disable-dsa
  CONFIGURE_ARGS += --disable-ecc
  CONFIGURE_ARGS += --enable-psk

endif

ifdef CONFIG_CYASSL_WITH_ECCSHAMIR
  CONFIGURE_ARGS += --enable-eccshamir
else
  CONFIGURE_ARGS += --disable-eccshamir
endif

ifdef CONFIG_CYASSL_WITH_PKCS7
  CONFIGURE_ARGS += --enable-pkcs7
else
  CONFIGURE_ARGS += --disable-pkcs7
endif

ifdef CONFIG_CYASSL_WITH_PKCS11
  CONFIGURE_ARGS += --enable-pkcs11
else
  CONFIGURE_ARGS += --disable-pkcs11
endif

ifdef CONFIG_CYASSL_WITH_PKCS12
  CONFIGURE_ARGS += --enable-pkcs12
else
  CONFIGURE_ARGS += --disable-pkcs12
endif

ifneq ($(CONFIG_TARGET_x86),)
	CONFIGURE_ARGS += --enable-intelasm
endif
ifneq ($(CONFIG_TARGET_x86_64),)
	CONFIGURE_ARGS += --enable-intelasm
endif

ifndef CONFIG_CYASSL_WITH_POLY1305
 CONFIGURE_ARGS += --disable-poly1305
endif

ifndef CONFIG_CYASSL_WITH_CHACHA
 CONFIGURE_ARGS += --disable-chacha  
endif


define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include
	$(CP) $(PKG_INSTALL_DIR)/usr/include/* $(1)/usr/include/

	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libwolfssl.{so*,la} $(1)/usr/lib/
	ln -s libwolfssl.so $(1)/usr/lib/libcyassl.so
	ln -s libwolfssl.la $(1)/usr/lib/libcyassl.la
endef

define Package/libcyassl/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/libwolfssl.so* $(1)/usr/lib/
	ln -s libwolfssl.so $(1)/usr/lib/libcyassl.so
endef

define Package/libcyassl/config
source "$(SOURCE)/Config.in"
endef

$(eval $(call BuildPackage,libcyassl))
