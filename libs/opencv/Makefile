#
# Copyright (C) 2015 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=opencv
PKG_VERSION:=3.3.1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).zip
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)

PKG_EXTRA_NAME:=opencv_contrib
PKG_EXTRA_SOURCE:=$(PKG_EXTRA_NAME)-$(PKG_VERSION).zip
PKG_EXTRA_SOURCE_SUBDIR:=$(PKG_EXTRA_NAME)-$(PKG_VERSION)

PKG_SOURCE_VERSION:=v$(PKG_VERSION)

PKG_LICENSE:=BSD

PKG_INSTALL:=1

CONFIGURE_ARGS += \
        --enable-shared \
        --enable-static \

include $(BUILD_DIR)/package.mk
include $(BUILD_DIR)/cmake.mk

CMAKE_SOURCE_DIR:=$(PKG_BUILD_DIR)/opencv_build/
CMAKE_OPTIONS += -DCMAKE_INSTALL_PREFIX=$(PKG_INSTALL_DIR)/usr/
CMAKE_OPTIONS += -DWITH_GTK=OFF
CMAKE_OPTIONS += -DWITH_TIFF=OFF
CMAKE_OPTIONS += -DWITH_QT=OFF
CMAKE_OPTIONS += -DWITH_GSTREAMER=OFF
CMAKE_OPTIONS += -DCMAKE_BUILD_TYPE=Release
CMAKE_OPTIONS += -DCMAKE_CONFIGURATION_TYPES=Release
CMAKE_OPTIONS += -DBUILD_PERF_TESTS=OFF
CMAKE_OPTIONS += -DBUILD_TESTS=OFF
CMAKE_OPTIONS += -DQt5Core_DIR=$(STAGING_DIR)/usr/lib/cmake/Qt5Core
CMAKE_OPTIONS += -DQt5Gui_DIR=$(STAGING_DIR)/usr/lib/cmake/Qt5Gui
CMAKE_OPTIONS += -DQt5Test_DIR=$(STAGING_DIR)/usr/lib/cmake/Qt5Test
CMAKE_OPTIONS += -DQt5Widgets_DIR=$(STAGING_DIR)/usr/lib/cmake/Qt5Widgets
CMAKE_OPTIONS += -DOPENCV_EXTRA_MODULES_PATH=$(PKG_BUILD_DIR)/$(PKG_EXTRA_SOURCE_SUBDIR)/modules

#opencv modules
CMAKE_OPTIONS += -DBUILD_opencv_apps=ON
CMAKE_OPTIONS += -DBUILD_opencv_calib3d=ON
CMAKE_OPTIONS += -DBUILD_opencv_features2d=ON
CMAKE_OPTIONS += -DBUILD_opencv_flann=ON
CMAKE_OPTIONS += -DBUILD_opencv_highgui=ON
CMAKE_OPTIONS += -DBUILD_opencv_imgcodecs=ON
CMAKE_OPTIONS += -DBUILD_opencv_imgproc=ON
CMAKE_OPTIONS += -DBUILD_opencv_ml=ON
CMAKE_OPTIONS += -DBUILD_opencv_objdetect=ON
CMAKE_OPTIONS += -DBUILD_opencv_photo=ON
CMAKE_OPTIONS += -DBUILD_opencv_shape=ON
CMAKE_OPTIONS += -DBUILD_opencv_stitching=ON
CMAKE_OPTIONS += -DBUILD_opencv_superres=ON
CMAKE_OPTIONS += -DBUILD_opencv_video=ON
CMAKE_OPTIONS += -DBUILD_opencv_videoio=ON
CMAKE_OPTIONS += -DBUILD_opencv_videostab=ON
CMAKE_OPTIONS += -DBUILD_opencv_viz=ON
TARGET_CFLAGS += -I$(STAGING_DIR)/usr/include/harfbuzz/

define Package/$(PKG_NAME)
  SECTION:=libs
  CATEGORY:=Libraries
  DEPENDS:=+libstdcpp +libpng +libjpeg +zlib +libfreetype +harfbuzz +libwebp
  TITLE:=opencv libs
  URL:=https://opencv.org/releases.html
endef

define Build/Compile
        +$(MAKE) -j4 -C $(PKG_BUILD_DIR) \
                CC=$(TARGET_CC) \
                FC=$(TARGET_FORTRAN) \
                HOSTCC=$(HOSTCC) \
                PREFIX=$(PKG_INSTALL_DIR) \
                CFLAGS="$(TARGET_CFLAGS)" \
                LDFLAGS="$(TARGET_LDFLAGS)" \
                all install
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)/opencv_build/
	mkdir -p $(PKG_BUILD_DIR)/opencv_build/patches
	unzip -d $(PKG_BUILD_DIR)/opencv_build/ $(DL_DIR)/$(PKG_SOURCE)
	unzip -d $(PKG_BUILD_DIR)/ $(DL_DIR)/$(PKG_EXTRA_SOURCE)
	mv $(PKG_BUILD_DIR)/opencv_build/$(PKG_SOURCE_SUBDIR)/* $(PKG_BUILD_DIR)/opencv_build/
	cp ./patches/* $(PKG_BUILD_DIR)/opencv_build/patches
	patch -p1 -d $(PKG_BUILD_DIR)/opencv_build/ < $(PKG_BUILD_DIR)/opencv_build/patches/*.patch

	## add xfeatures2d related header file
	mkdir -p $(PKG_BUILD_DIR)/opencv2/
	cp $(PKG_BUILD_DIR)/$(PKG_EXTRA_SOURCE_SUBDIR)/modules/xfeatures2d/include/opencv2/* $(PKG_BUILD_DIR)/opencv2/ -rf
endef

define Package/$(PKG_NAME)/description
OpenCV (Open Source Computer Vision Library) is an open source computer vision and machine learning software library. OpenCV was built to provide a common infrastructure for computer vision applications and to accelerate the use of machine perception in the commercial products. Being a BSD-licensed product, OpenCV makes it easy for businesses to utilize and modify the code.
endef

define Build/InstallDev
	mkdir -p $(PKG_INSTALL_DIR)
	$(INSTALL_DIR) $(PKG_INSTALL_DIR)/usr/lib
	$(INSTALL_DIR) $(PKG_INSTALL_DIR)/usr/include

	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/*.so* $(STAGING_DIR)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/include/* $(STAGING_DIR)/usr/include/

	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(CP) $(PKG_INSTALL_DIR)/usr/lib/pkgconfig/* $(1)/usr/lib/pkgconfig
	$(INSTALL_DIR) $(1)/usr/share
	$(CP) $(PKG_INSTALL_DIR)/usr/share/* $(1)/usr/share

	$(CP) $(PKG_INSTALL_DIR)/usr $(1)/usr
endef

define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DIR) $(1)/usr/include
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/lib/*.so* $(1)/usr/lib/
	$(CP) $(PKG_INSTALL_DIR)/usr/include/* $(1)/usr/include/
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
