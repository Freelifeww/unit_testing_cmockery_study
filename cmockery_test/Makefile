#-c 只激活预处理,编译,和汇编,也就是他只把程序做成obj文件
#学习链接:https://www.runoob.com/w3cnote/gcc-parameter-detail.html

# 第一个版本make
# app: main.c math.c
# 	gcc main.c math.c -o app

#第二个版本make
# app:main.o math.o
# 	gcc main.o math.o -o app
# main.o:main.c
# 	gcc -c main.c -o main.o
# math.o:math.c
# 	gcc -c math.c -o math.o

#第三个版本make
#$<：第一个依赖文件；
#$@：目标；
#$^：所有不重复的依赖文件，以空格分开
# obj = main.o math.o
# target = app
# CC = gcc
# $(target): $(obj)
# 	$(CC) $(obj) -o $(target)
#	@echo "-------------------"
#	@echo $<
#	@echo $@
#	@echo "-------------------"
# %.o: %.c
# 	$(CC) -c $< -o $@
# clean:	
# 	rm -rf *.o
# 	rm -rf app

#在第四版Makefile中，我们隆重推出了两个函数：wildcard和patsubst。
#(1)wildcard：扩展通配符，搜索指定文件。在此我们使用src = $(wildcard ./*.c)，
#代表在当前目录下搜索所有的.c文件，并赋值给src,
#函数执行结束后，src的值为：main.c fun1.c fun2.c。
#(2)patsubst：替换通配符，按指定规则做替换。在此我们使用
#(3)addprefix: 为相关目录增加字符前缀
#(4) $(foreach <var>,<list>,<text>):
#这个函数的意思是，把参数<list>;中的单词逐一取出放到参数<var>;所指定的变量中，
#然后再执行< text>;所包含的表达式。每一次<text>;会返回一个字符串，循环过程中，
#<text>;的所返回的每个字符串会以空格分隔，最后当整个循环结束时，
#<text>;所返回的每个字符串所组成的整个字符串（以空格分隔）将会是foreach函数的返回值。

src = $(wildcard ./*.c)
obj = $(patsubst %.c, %.o, $(src))
target = app
CC = gcc
LD_CMD=$(shell sudo ldconfig) #动态库安装需要加载才能链接运行

CMOCKERY_INCLUDE_DIR = /usr/local/include/google
CMOCKERY_INCS += $(addprefix -I , $(shell find $(CMOCKERY_INCLUDE_DIR)  -type d) )
#CMOCKERY_INCS += $(addprefix -I , $(foreach dir,$(CMOCKERY_INCLUDE_DIR),$(shell find $(dir) -type d)))

CCFLAGS = -g -fPIC -Wall -Werror
CFLAGS = $(CCFLAGS) $(CMOCKERY_INCS) -ffunction-sections -fdata-sections 
CFLAGS += -Wno-unused-but-set-variable -Wno-unused-variable -Wno-unused-function -Wno-pointer-to-int-cast

CMOCKERY_LIB_DIR = /usr/local/lib
LINKFLAGS = -L$(CMOCKERY_LIB_DIR) -lcmockery -pthread -lm #-lasan

$(target): $(obj)
	$(CC) $(obj) $(LINKFLAGS) $(CFLAGS) -o $(target)

%.o: %.c
	$(CC) -c $(CFLAGS) $(LINKFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rf $(obj) $(target)

load_lib:
	@echo $(LD_CMD)

all:
	@echo "-------------------"
	@echo $(CFLAGS)
	@echo $(LINKFLAGS)
	@echo "-------------------"


