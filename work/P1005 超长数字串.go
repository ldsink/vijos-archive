package main

import (
	"fmt"
	"math/big"
	"strings"
)

var zero = new(big.Int).SetInt64(0)
var one = new(big.Int).SetInt64(1)
var ten = new(big.Int).SetInt64(10)

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

func validateBitAndOffset(bit, offset int, a string) *big.Int {
	// 长度为 bit，在 a 中偏移量为 offset 的 num 是否符合条件，满足条件返回 num。否则返回 -1
	numStr := a[offset : offset+bit]
	if strings.HasPrefix(numStr, "0") {
		return zero
	}

	num := getBigInt(numStr)
	n := new(big.Int)
	var left, right int
	// 检测左边是否满足条件，最多只需要检测一次
	n.Sub(num, one)
	right = offset
	if right > 0 {
		if n.Cmp(one) < 0 {
			return zero
		}
		nStr := n.String()
		left = max(0, offset-len(nStr))
		if a[left:right] != nStr[len(nStr)-(right-left):] {
			return zero
		}
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

func getNumberPosition(num *big.Int, offset int) *big.Int {
	// 获得这个数字前面计算 offset 之后出现的位置
	result := big.NewInt(0 - int64(offset))
	if num.Cmp(ten) < 0 {
		result.Add(result, num)
		return result
	}

	numStr := num.String()
	length := len(numStr)
	start := one
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
	//fmt.Println(endlessEnumerate(a)) // debug

	n := getBigInt(a)
	if n.Cmp(zero) == 0 {
		num := getBigInt("1" + a)
		fmt.Println(getNumberPosition(num, -1))
		return
	}
	for i, j := 1, len(a); i <= j; i++ {
		for offset := 0; offset < i; offset++ {
			num := validateBitAndOffset(i, offset, a)
			if num.Cmp(zero) > 0 {
				fmt.Println(getNumberPosition(num, offset))
				return
			}
		}
	}
}
