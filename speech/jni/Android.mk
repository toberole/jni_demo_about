# 一个Android.mk文件首先必须定义好LOCAL_PATH变量，用于在开发树中查找源文件。
# 在这个例子中，宏函数my-dir由编译系统提供，用于返回当前路径（即包含Android.mk文件的目录）。
LOCAL_PATH := $(call my-dir)

# CLEAR_VARS由编译系统提供，指定让GNU MAKEFILE清除了LOCAL_PATH变量外的
# 许多LOCAL_***变量（例如：LOCAL_MODULE、LOCAL_SRC_FILES等）。
# 这是非常有必要的，因为所有的编译文件都在同一个GUN MKAE执行环境中，所有的变量都是全局变量，不清除容易引起解析错误。
include $(CLEAR_VARS)

# LOCAL_MODULE变量必须定义，用来标识在Android.mk文件描述的每一个模块。
# 而且名称必须是唯一的，并且不能包含空格。编译系统会自动产生合适的前缀和后缀，
# 比如一个被命名为hello的共享库模块，将会生成libhello.so文件。如果把库命名为libhello，
# 编译系统将不会添加任何lib前缀，也会生成libhello.so文件。
LOCAL_MODULE := libspecch

# 指定so的输出路径
NDK_APP_DST_DIR := ./../app/src/main/jniLibs/$(TARGET_ARCH_ABI)

# LOCAL_SRC_FILES变量必须包含将要编译打包进模块中的源代码文件。
# MY_CPP_LIST := $(wildcard $(LOCAL_PATH)/*)
# LOCAL_SRC_FILES := ./files/JNIDemo.c
# LOCAL_SRC_FILES := $(MY_CPP_LIST:$(LOCAL_PATH)/
# LOCAL_SRC_FILES := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)

# 扫描目录下的所有源文件
MY_FILES_PATH  :=  $(LOCAL_PATH)
# 文件后缀
MY_FILES_SUFFIX := %.cpp %.c %.cc

My_All_Files := $(foreach src_path,$(MY_FILES_PATH), $(shell find "$(src_path)" -type f) )
My_All_Files := $(My_All_Files:$(MY_CPP_PATH)/./%=$(MY_CPP_PATH)%)
MY_SRC_LIST  := $(filter $(MY_FILES_SUFFIX),$(My_All_Files))
MY_SRC_LIST  := $(MY_SRC_LIST:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES := $(MY_SRC_LIST)




# 编译模块时要使用的附加的链接器选项 原生模块与日志库进行链接
LOCAL_LDLIBS += -llog

# BUILD_SHARED_LIBRARY是编译系统提供的变量，指向一个GNU Makefile脚本
#（应该就是build/core目录下的shared_library.mk）,负责收集自从上次调用
# include $(CLEAR_VARS)以来，定义在LOCAL_***变量中的所有信息，并且决定编译什么，
# 如何正确地去做，并根据其规则生成动态库。
include $(BUILD_SHARED_LIBRARY)


# Android.mk中可以定义多个编译模块，每个编译模块都是以include $(CLEAR_VARS)开始以include $(BUILD_XXX)结束