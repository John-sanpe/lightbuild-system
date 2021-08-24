# light-build(v0.1)

## 上手指南:

LightBuild是一个上手简单的项目构建系统,适用于汇编/c/c++项目的项目构建系统特性如下：

1. 递归多项目编译，通过递归可以生成多个子项目
2. 多种预定义编译接口,可以大大减少规则量
3. 多线程编译,自定义输出路径
4. 多种kconfig配置，自定义配置文件位置
6. 系统规则使用全路径模式

### 食用方法:

```bash
make 
make O=/path/			#定义输出路径
make V=1				#显示编译过程
make W=1				#开启编译提示
make -j16				#多线程编译
```

## 规则介绍:

lightbuild具有丰富的规则接口, 阅读规则介绍可以帮助快速了解这些接口

### clean:

clean-y:

​	留给用户的自定义清理规则接口,可以自动匹配文件或者文件夹

​	clean-y += test.map 

在每次运行make clean的时候都会删除 test.map

clean-subdir-y :



## 附录一:    系统规则表

```
所属组		  规则名称             规则介绍

submake:	project-y			子项目声明
submake:    project-include-y   项目级自动扩展路径的头文件(文件夹)声明
submake:    project-include-direct-y 项目级全路径的头文件(文件夹)声明

-------------------------------------------------------------------

main:		obj-y				输入文件声明(自动匹配扩展名)
main:       include-y           自动扩展路径的头文件(文件夹)声明
main:       include-direct-y    全路径的头文件(文件夹)声明
main:       CROSS_COMPILE		交叉编译器选择(默认空)
main:		AS 					AS编译器选择(默认为gcc)
main:		CC 					CC编译器选择(默认为gcc)
main:		CPP 				CPP编译器选择(默认为g++)
main:		LD 					链接工具选择(默认为ld)
main:       asflags-y           本层AS参数
main:       asflags-sub-y       向下递归的AS参数
main:       ccflags-y           CC参数
main:       ccflags-sub-y       向下递归的CC参数
main:       acflags-y           本层AS CC参数
main:       acflags-sub-y       向下递归的AS CC参数
main:       cxxflags-y          CPP参数
main:       cxxflags-sub-y      向下递归的CPP参数
main:       ldflags-y			LD参数
main:       ldflags-sub-y		向下递归的LD参数			

-------------------------------------------------------------------

elf:		elf					elf声明被动接口
elf:		elf-always-y	 	elf声明主动接口
elf:		MKELF				elf工具选择
elf:		xxx-flags-y			elf参数
elf:		xxx-obj-y	 		自动扩展路径的输入文件
elf:		xxx-direct-y	 	全路径的输入文件

bin:		bin					bin声明被动接口
bin:		bin-always-y	 	bin声明主动接口
bin:		OBJCOPY				bin工具选择
bin:		xxx-flags-y			bin参数
bin:		xxx-obj-y	 		自动扩展路径的输入文件
bin:		xxx-direct-y	 	全路径的输入文件

dump:		dump				dump声明被动接口
dump:		dump-always-y	 	dump声明主动接口
dump:		OBJDUMP				dump工具选择
dump:		xxx-flags-y		dump参数
dump:		xxx-obj-y	 		自动扩展路径的输入文件
dump:		xxx-direct-y	 	全路径的输入文件

-------------------------------------------------------------------

clean:		clean-y          	用户自定义的清理接口
clean:		clean-subdir-y      用户自定义的下层递归接口

-------------------------------------------------------------------

hook:		hook_build			编译钩子接口
hook:		hook_clean			清除钩子接口
```

## 附录二:    系统命令



## 附录三:    参与开发

项目地址 :  https://github.com/John-sanpe/lightbuild-core
