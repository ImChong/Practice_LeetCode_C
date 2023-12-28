# Bash Shell Prompt Color 颜色修改

将下列代码写入./bashrc文件并重启./bashrc以完成bash shell各模块显示颜色的修改：

```shell
export PS1="\[\e[32m\][\[\e[m\]\[\e[31m\]\u\[\e[m\]\[\e[33m\]@\[\e[m\]\[\e[32m\]\h\[\e[m\]:\[\e[36m\]\w\[\e[m\]\[\e[32m\]]\[\e[m\]\[\e[32;47m\]\\$\[\e[m\]"
```
