#!/bin/sh
export DYLIB=libexpat_d.dylib

if [ ! -d "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/Frameworks" ]; then

mkdir "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/Frameworks"
# Control will enter here if $DIRECTORY doesn't exist.
fi

cp -f "$SRCROOT/$DYLIB" "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/Frameworks"
install_name_tool -change @executable_path/$DYLIB @loader_path/../Frameworks/$DYLIB "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/MacOS/$PRODUCT_NAME"

export DYLIB=libfreetype_d.dylib
cp -f "$SRCROOT/$DYLIB" "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/Frameworks"
install_name_tool -change @executable_path/$DYLIB @loader_path/../Frameworks/$DYLIB "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/MacOS/$PRODUCT_NAME"

export DYLIB=libglew_d.dylib
cp -f "$SRCROOT/$DYLIB" "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/Frameworks"
install_name_tool -change @executable_path/$DYLIB @loader_path/../Frameworks/$DYLIB "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/MacOS/$PRODUCT_NAME"

<<<<<<< Updated upstream
=======
export DYLIB=libCEGUIOpenGLRenderer-0_d.dylib
cp -f "$SRCROOT/$DYLIB" "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/Frameworks"
install_name_tool -change @executable_path/$DYLIB @loader_path/../Frameworks/$DYLIB "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/MacOS/$PRODUCT_NAME"
>>>>>>> Stashed changes

export DYLIB=libglfw_d.dylib
cp -f "$SRCROOT/$DYLIB" "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/Frameworks"
install_name_tool -change @executable_path/$DYLIB @loader_path/../Frameworks/$DYLIB "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/MacOS/$PRODUCT_NAME"

<<<<<<< Updated upstream
=======
export DYLIB=libCEGUIFreeImageImageCodec_d.dylib
cp -f "$SRCROOT/$DYLIB" "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/Frameworks"
install_name_tool -change @executable_path/$DYLIB @loader_path/../Frameworks/$DYLIB "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/MacOS/$PRODUCT_NAME"

>>>>>>> Stashed changes
export DYLIB=libjpeg_d.dylib
cp -f "$SRCROOT/$DYLIB" "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/Frameworks"
install_name_tool -change @executable_path/$DYLIB @loader_path/../Frameworks/$DYLIB "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/MacOS/$PRODUCT_NAME"

export DYLIB=libpcre_d.dylib
cp -f "$SRCROOT/$DYLIB" "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/Frameworks"
install_name_tool -change @executable_path/$DYLIB @loader_path/../Frameworks/$DYLIB "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/MacOS/$PRODUCT_NAME"

export DYLIB=libpng_d.dylib
cp -f "$SRCROOT/$DYLIB" "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/Frameworks"
install_name_tool -change @executable_path/$DYLIB @loader_path/../Frameworks/$DYLIB "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/MacOS/$PRODUCT_NAME"

export DYLIB=libSILLY_d.dylib
cp -f "$SRCROOT/$DYLIB" "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/Frameworks"
install_name_tool -change @executable_path/$DYLIB @loader_path/../Frameworks/$DYLIB "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/MacOS/$PRODUCT_NAME"

export DYLIB=libzlib_d.dylib
cp -f "$SRCROOT/$DYLIB" "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/Frameworks"
install_name_tool -change @executable_path/$DYLIB @loader_path/../Frameworks/$DYLIB "$TARGET_BUILD_DIR/$TARGET_NAME.app/Contents/MacOS/$PRODUCT_NAME"
