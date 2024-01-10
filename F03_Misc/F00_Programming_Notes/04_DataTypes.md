# C语言基础数据类型及大小范围

```c
# define INT8_MAX            INT8_C(127)
# define INT8_MIN          (-INT8_C(127)-1)
# define UINT8_MAX          UINT8_C(255)

#define INT16_MAX            INT16_C(32767)
#define INT16_MIN          (-INT16_C(32767)-1)
#define UINT16_MAX          UINT16_C(65535)

# define INT32_MAX           INT32_C(2147483647)
# define INT32_MIN         (-INT32_C(2147483647)-1)
# define UINT32_MAX         UINT32_C(4294967295)

# define INT64_MAX           INT64_C( 9223372036854775807)
# define INT64_MIN         (-INT64_C( 9223372036854775807)-1)
# define UINT64_MAX         UINT64_C(18446744073709551615)
```

## 数据类型大小

> ```shell
> size_of_arr[5]: 20
> size_of_int: 4
> size_of_int*: 8
> size_of_arrList[2][3]: 24
> size_of_*ptrArrList[2]: 16
> size_of_**ptrArr: 8
> ```
