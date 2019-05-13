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

func main() {
	var a string
	_, _ = fmt.Scanf("%s", &a)
	fmt.Println(endlessEnumerate(a))
}
