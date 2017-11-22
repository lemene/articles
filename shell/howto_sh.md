## 读取按键
`read -p`可读取一个按键。

```Shell

read -p "Press a key, then press return:" KEY

case $KEY in
	[a-z]|[A-Z])
		echo "It's a letter"
		;;
	[0-9])
		echo "It's a digit"
		;;
	*)
		echo "It's function or other keys"
esac
```

## 子命令

```Shell
case $1 in
	start)
		echo "start command"
		;;
	stop)
		echo "stop command"
		;;
	help)
		echo "help command"
		;;
	*)
		echo "unkown command"
		;;
esac
```

## 判断系统类型
```Shell

SYSTEM=`uname -s`

case $SYSTEM in
	Linux)
		echo "My system is Linux"
		;;
	Windows)
		echo "My system is Windows"
		;;
	*)
		echo "Unknown system is $SYSTEM"
		;;

esac


```
