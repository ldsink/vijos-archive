/*
ZHOU Cheng <c.zhou@live.com>
2019-5-18 22:48:21
*/
package main

import (
	"fmt"
	"math/big"
	"regexp"
	"strings"
)

var zero = big.NewInt(0)
var one = big.NewInt(1)
var ten = big.NewInt(10)

func getBigInt(s string) *big.Int {
	i, _ := new(big.Int).SetString(s, 10)
	return i
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

// 获取填充 0 的长度为 n 的数值字符串
func getZeroString(value *big.Int, n int) string {
	s := value.String()
	for n = n - len(s); n > 0; n-- {
		s = "0" + s
	}
	return s
}

// 长度为 bit，在 a 中偏移量为 offset 的 num 是否符合条件。不符合返回 zero
func validateBitAndOffset(bit, offset int, a string) *big.Int {
	// 零开头的，不符合要求，直接返回 zero
	if strings.HasPrefix(a[offset:], "0") {
		return zero
	}

	// 当目前的长度少于期望的长度，使用前面的值来填充
	if offset+bit > len(a) {
		missBit := offset + bit - len(a)
		prevStr := a[offset-missBit : offset]
		p := new(big.Int)
		// 全 9 特殊处理，填充 0
		if match, _ := regexp.MatchString("^9*$", prevStr); match {
			p.SetInt64(0)
		} else {
			p.SetString(prevStr, 10)
			p.Add(p, one)
		}
		a += getZeroString(p, missBit)
	}

	num := getBigInt(a[offset : offset+bit])
	n := new(big.Int)
	var left, right int
	// 检测左边是否满足条件
	n.Sub(num, one)
	right = offset
	for right > 0 {
		if n.Cmp(one) < 0 {
			return zero
		}
		nStr := n.String()
		left = max(0, right-len(nStr))
		if a[left:right] != nStr[len(nStr)-(right-left):] {
			return zero
		}
		right -= len(nStr)
		n.Sub(n, one)
	}
	// 检测右边是否满足条件
	n.Add(num, one)
	left = offset + bit
	length := len(a)
	for left < length {
		nStr := n.String()
		right = min(length, left+len(nStr))
		if a[left:right] != nStr[0:right-left] {
			return zero
		}
		left += len(nStr)
		n.Add(n, one)
	}
	return num
}

// 计算数字出现的位置
func getNumberPosition(num *big.Int, offset int) *big.Int {
	result := big.NewInt(0 - int64(offset))
	if num.Cmp(ten) < 0 {
		result.Add(result, num)
		return result
	}

	length := len(num.String())
	start := big.NewInt(1)
	for i := 1; i < length; i++ {
		count := big.NewInt(9)
		count.Mul(count, start)
		count.Mul(count, big.NewInt(int64(i)))
		result.Add(result, count)
		start.Mul(start, ten)
	}

	start.Sub(num, start)
	curr := big.NewInt(int64(length))
	curr.Mul(curr, start)
	curr.Add(curr, big.NewInt(1))
	result.Add(result, curr)
	return result
}

func main() {
	var a string
	_, _ = fmt.Scanf("%s", &a)

	// 全 0 特殊处理
	if match, _ := regexp.MatchString("^0*$", a); match {
		num := getBigInt("1" + a)
		fmt.Println(getNumberPosition(num, -1))
		return
	}

	best := big.NewInt(0)
	for i, j := 1, len(a); i <= j; i++ {
		for offset := i - 1; offset >= 0; offset-- {
			num := validateBitAndOffset(i, offset, a)
			if num.Cmp(zero) > 0 {
				curr := getNumberPosition(num, offset)
				if best.Cmp(zero) == 0 || best.Cmp(curr) > 0 {
					best = curr
				}
			}
		}
		// 当前位数寻找到最优结果，打印并结束循环
		if best.Cmp(zero) > 0 {
			fmt.Println(best.String())
			break
		}
	}
}
