/*
ZHOU Cheng <c.zhou@live.com>
2019-5-11 16:12:46
*/
package main

import (
	"bufio"
	"fmt"
	"os"
	"regexp"
	"strconv"
	"strings"
)

var operatorOrder = map[string]int{}

const Number = "1234567890"
const Mark = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

func filterExpression(expression string) string {
	// 只允许 a 数字 + - * ^ ( )
	reg, _ := regexp.Compile("[a\\d\\+\\-\\*\\^\\(\\)]+")
	mapping := func(r rune) rune {
		if reg.MatchString(string(r)) {
			return r
		}
		return -1
	}
	return strings.Map(mapping, expression)
}

func getNumOrOperator(expression string, offset int) (string, int) {
	c := expression[offset : offset+1]
	if c == "a" {
		return c, offset + 1
	}
	if _, ok := operatorOrder[c]; ok {
		return c, offset + 1
	}
	length := len(expression)
	number := ""
	for ; offset < length; offset++ {
		c := expression[offset : offset+1]
		if !strings.Contains(Number, c) {
			break
		}
		number += c
	}
	return number, offset
}

const prime = 16769023

func powerMod(x, y int64) int64 {
	var i int64 = 1
	for j := x; y > 0; j = j * j % prime {
		if y&1 == 1 {
			i = i * j % prime
		}
		y = y >> 1
	}
	return i
}

func multiMod(x, y int64) int64 {
	return x * y % prime
}

func calculateValue(val1, val2 int64, op string) int64 {
	switch op {
	case "+":
		return val1 + val2
	case "-":
		return val1 - val2
	case "*":
		return multiMod(val1, val2)
	case "^":
		return powerMod(val1, val2)
	default:
		return 0
	}
}

func calculateExpression(expression string, value int64) int64 {
	numStack := [50]int64{}
	numStackTop := 0
	opStack := [50]string{}
	opStackTop := 0

	curStr := ""
	offset := 0
	length := len(expression)
	for ; offset < length; {
		curStr, offset = getNumOrOperator(expression, offset)
		if curStr == "a" {
			numStackTop++
			numStack[numStackTop] = value
			continue
		}
		if _, ok := operatorOrder[curStr]; ok {
			curOrder, _ := operatorOrder[curStr]
			for opStackTop > 0 {
				topOrder, _ := operatorOrder[opStack[opStackTop]]
				// 如果优先级小于前面操作符，计算上一个值
				if curOrder <= topOrder && opStack[opStackTop] != "(" {
					num1, num2 := numStack[numStackTop-1], numStack[numStackTop]
					numStackTop -= 2
					topOp := opStack[opStackTop]
					opStackTop--

					numStackTop++
					numStack[numStackTop] = calculateValue(num1, num2, topOp)
				} else {
					break
				}
			}
			opStackTop++
			opStack[opStackTop] = curStr

			// 检测结尾如果是 )，弹出两个括号。
			if opStack[opStackTop] == ")" {
				opStackTop--
				// 详细判断，兼容一个错误的测试用例
				if opStackTop > 0 && opStack[opStackTop] == "(" {
					opStackTop--
				}
			}
			continue
		}
		// 最后处理数字
		num, _ := strconv.ParseInt(curStr, 10, 64)
		numStackTop++
		numStack[numStackTop] = num
	}

	// 还需要计算一次
	for ; opStackTop > 0; {
		num1, num2 := numStack[numStackTop-1], numStack[numStackTop]
		numStackTop -= 2
		op := opStack[opStackTop]
		opStackTop--

		numStackTop++
		numStack[numStackTop] = calculateValue(num1, num2, op)
	}
	return numStack[numStackTop]
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	scanner.Scan()
	baseExpression := scanner.Text()
	baseExpression = filterExpression(baseExpression)

	scanner.Scan()
	nStr := scanner.Text()
	n, _ := strconv.Atoi(nStr)

	operatorOrder["+"] = 1
	operatorOrder["-"] = 1
	operatorOrder["*"] = 2
	operatorOrder["^"] = 3
	operatorOrder["("] = 4
	operatorOrder[")"] = 0

	const caseNum = 1
	values := [caseNum]int64{5}
	result := [caseNum]int64{}
	for i := 0; i < caseNum; i++ {
		result[i] = calculateExpression(baseExpression, values[i])
	}

	for offset := 0; offset < n; offset++ {
		scanner.Scan()
		expression := scanner.Text()
		expression = filterExpression(expression)
		same := true
		for i := 0; same && i < caseNum; i++ {
			r := calculateExpression(expression, values[i])
			if r != result[i] {
				same = false
				break
			}
		}
		if same {
			fmt.Print(Mark[offset : offset+1])
		}
	}
}
