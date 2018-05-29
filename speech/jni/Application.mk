# 指定编译器查找android.mk的位置
# APP_PROJECT_PATH

# 配置编译使用的库
# 没有这个配置可能会报很多文件找不着 比如 string file not found
# c++_static stlport_static
APP_STL := c++_static

# APP_PLATFORM := android-14
# APP_ABI := armeabi-v7a
# APP_ABI := all