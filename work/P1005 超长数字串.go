package main

import (
	"fmt"
	"strconv"
	"strings"
)

func endlessEnumerate(a string) int {
	var s string
	var result int
	var bit uint = 15
	for i, j := 1, 1<<bit; i <= j; i++ {
		s += strconv.Itoa(i)
	}
	result = strings.Index(s, a) + 1
	length := len(s)
	offset := len(a)
	s = s[length-offset:]
	for ; result == 0; {
		for i, j := (1<<bit)+1, 1<<(bit+1); i <= j; i++ {
			s += strconv.Itoa(i)
		}
		result = strings.Index(s, a) + 1
		if result > 0 {
			result = length - offset + result
		}
		length += len(s)
		s = s[len(s)-offset:]
	}
	return result
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func validateBitAndOffset(bit, offset int, a string) int64 {
	// 长度为 bit，在 a 中偏移量为 offset 的 num 是否符合条件，满足条件返回 num。否则返回 -1
	numStr := a[offset : offset+bit]
	if strings.HasPrefix(numStr, "0") {
		return -1
	}

	num, _ := strconv.ParseInt(numStr, 10, 64)
	var n int64
	var left, right int
	// 检测左边是否满足条件，最多只需要检测一次
	n = num - 1
	right = offset
	if right > 0 {
		if n < 1 {
			return -1
		}
		nStr := strconv.FormatInt(n, 10)
		left = max(0, offset-len(nStr))
		if a[left:right] != nStr[len(nStr)-(right-left):] {
			return -1
		}
	}
	// 检测右边是否满足条件
	n = num + 1
	left = offset + bit
	length := len(a)
	for left < length {
		nStr := strconv.FormatInt(n, 10)
		right = min(length, left+len(nStr))
		if a[left:right] != nStr[0:right-left] {
			return -1
		}
		left += len(nStr)
		n++
	}

	return num
}

func getBitNumOffset(bit int) int64 {
	if bit < 1 {
		return 0
	}
	if bit == 1 {
		return 9
	}
	var n int64 = 1
	for i := 1; i < bit; i++ {
		n *= 10
	}
	n = n * 9
	return n * int64(bit)
}

func getNumberPosition(num int64, offset int) int64 {
	// 获得这个数字前面计算 offset 之后出现的位置
	result := int64(offset)
	if num < 10 {
		result += num
		return result
	}

	numStr := strconv.FormatInt(num, 10)
	length := len(numStr)
	var start int64 = 1
	for i := 1; i < length; i++ {
		result += getBitNumOffset(i)
		start *= 10
	}
	result += int64(length)*(num-start) + 1
	return result
}

func main() {
	var a string
	_, _ = fmt.Scanf("%s", &a)
	n, _ := strconv.ParseInt(a, 10, 64)
	var result int64
	if n == 0 {
		num, _ := strconv.ParseInt("1"+a, 10, 64)
		result = getNumberPosition(num, -1)
	} else {
		for i, j := 1, len(a); i <= j && result == 0; i++ {
			for offset := 0; offset < i && result == 0; offset++ {
				num := validateBitAndOffset(i, offset, a)
				if num > 0 {
					result = getNumberPosition(num, offset)
				}
			}
		}
	}
	fmt.Println(result)
	//fmt.Println(endlessEnumerate(a)) // debug
}
